#include "BetterPaintTool.hpp"

#include <SmSdk/Harvestable/HarvestablePhysicsProxy.hpp>
#include <SmSdk/Harvestable/HarvestableManager.hpp>
#include <SmSdk/Creation/BodyJointPhysicsProxy.hpp>
#include <SmSdk/Creation/CreationManager.hpp>
#include <SmSdk/Gui/InGameGuiManager.hpp>
#include <SmSdk/Physics/PhysicsProxy.hpp>
#include <SmSdk/Physics/Physics.hpp>
#include <SmSdk/PlayerManager.hpp>
#include <SmSdk/AudioManager.hpp>
#include <SmSdk/InputManager.hpp>
#include <SmSdk/StaticValues.hpp>
#include <SmSdk/Util/Color.hpp>
#include <SmSdk/MyPlayer.hpp>

#include <SmSdk/CharacterManager.hpp>
#include <SmSdk/Character.hpp>

#include "BetterPaintToolGui.hpp"
#include "ColorPreset.hpp"

#include "Utils/MathUtils.hpp"
#include "Utils/Console.hpp"

#include <BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>

#pragma comment(lib, "User32.lib")

BetterPaintTool::t_process_inputs BetterPaintTool::o_processInputs = nullptr;
BetterPaintTool::t_init_sig BetterPaintTool::o_initialize = nullptr;
BetterPaintTool::t_update_sig BetterPaintTool::o_update = nullptr;

static bool g_isPaintToolHoldingObject = false;

void BetterPaintTool::h_processInputs(SM::InputManager* self)
{
	//Prevent the game from switching the tool while painting/erasing
	if (g_isPaintToolHoldingObject)
	{
		//Filter out all the scroll events
		for (auto i = self->m_deqInputQueue.begin(); i != self->m_deqInputQueue.end();)
		{
			if (i->m_eventType == SM::InputEventType_MouseScroll)
				i = self->m_deqInputQueue.erase(i);
			else
				i++;
		}

		g_isPaintToolHoldingObject = false;
	}

	BetterPaintTool::o_processInputs(self);
}

bool BetterPaintTool::h_initialize(BetterPaintTool* self)
{
	const bool v_out = BetterPaintTool::o_initialize(self);

	if (self->m_pGuiInterface)
	{
		self->m_pGuiInterface->m_mapStringToFunction.emplace("HexInput",
			[self](const std::string& str) -> void
			{
				self->setColor(str);
			}
		);

		self->m_pGuiInterface->m_mapStringToFunction.emplace("InitFunc",
			[self](const std::string& str) -> void
			{
				ColorPresetStorage::LoadFromFile();

				SM::GuiBase* v_pGui = self->m_pGuiInterface->m_pGuiBase.get();
				reinterpret_cast<BetterPaintToolGui*>(v_pGui)->initParams(self);
			}
		);

		self->m_pGuiInterface->m_mapMapCallbackStorage["ColorGrid"][""] =
			[self](std::size_t idx, const Json::Value& jsonData)
			{
				// Every time we close the paint tool we save the custom presets to the file
				//ColorPresetStorage::SaveToFile();

				const SM::Color v_newColor = ColorPresetStorage::GetCurrentPreset().colors[idx];
				const SM::Color v_currentColor = self->m_pNetworkData->m_paintColor;

				if (v_currentColor.data != v_newColor.data)
				{
					self->setColor(v_newColor);
					SM::AudioManager::PlaySound("PaintTool - ColorPick");
				}

				self->m_pGuiInterface->close();
			};

		const auto v_callbackCopy = self->m_pGuiInterface->m_closeCallback;
		self->m_pGuiInterface->m_closeCallback =
			[self, oldCallback = v_callbackCopy]() -> void
			{
				// Run the old callback first
				if (oldCallback)
					oldCallback();

				// Then run our code to save the tool
				ColorPresetStorage::SaveToFile();
			};
	}

	return v_out;
}

struct ColorIndexRayResult : public btCollisionWorld::RayResultCallback
{
	int m_triangleIndex = -1;
	SM::Character* m_charToIgnore = nullptr;

	bool checkCollisionAllowed(const btCollisionObject* obj) const
	{
		SM::PhysicsProxy* v_pProxy = reinterpret_cast<SM::PhysicsProxy*>(obj->getUserPointer());
		if (!v_pProxy) return false;

		if (v_pProxy->getProxyType() == SM::PhysicsProxyType_Character)
		{
			SM::Character* v_cur_char = SM::CharacterManager::GetCharacter(obj->getUserIndex());
			return v_cur_char != m_charToIgnore;
		}

		return true;
	}

	btScalar addSingleResult(btCollisionWorld::LocalRayResult& rayResult, bool normalInWorldSpace) override
	{
		if (this->checkCollisionAllowed(rayResult.m_collisionObject))
		{
			m_closestHitFraction = rayResult.m_hitFraction;
			m_collisionObject = rayResult.m_collisionObject;

			m_triangleIndex = (rayResult.m_localShapeInfo != nullptr)
				? rayResult.m_localShapeInfo->m_triangleIndex : -1;
		}

		return rayResult.m_hitFraction;
	}
};

void BetterPaintTool::h_update(BetterPaintTool* self, float dt)
{
	BetterPaintTool::o_update(self, dt);

	//The game doesn't like it when multiple animations use the same animation file
	if (self->m_fpAnims.m_currentAnim != "color_picker" &&
		self->m_fpAnims.m_currentAnim != "color_picker_end")
	{
		self->m_fpAnims.removeAnimation("color_picker");
		self->m_fpAnims.removeAnimation("color_picker_end");
	}

	if (!self->isEquipped())
		return;

	SM::MyPlayer* v_pPlayer = SM::MyPlayer::GetInstance();
	if (self->m_pTool->m_iOwnerId != v_pPlayer->m_player->m_iId)
		return;

	self->updateSelectionData(self->m_paintSelection);
	self->updateSelectionData(self->m_eraseSelection);

	if (!self->isErasingOrPainting() && SM::InputManager::IsMouseButtonPressed(SM::EMouseButton_Middle))
	{
		SM::Physics* v_pPhysics = SM::Physics::GetInstance();
		if (!v_pPhysics) return;

		btCollisionWorld* v_pCollWorld = v_pPhysics->m_pPhysicsBase->m_pCollisionWorld2;
		if (!v_pCollWorld) return;

		const btVector3 v_ray_start(v_pPlayer->camera.position.x,
			v_pPlayer->camera.position.y, v_pPlayer->camera.position.z);
		const btVector3 v_direction(v_pPlayer->camera.direction.x,
			v_pPlayer->camera.direction.y, v_pPlayer->camera.direction.z);
		const btVector3 v_ray_end = v_ray_start + v_direction * 7.0f;

		ColorIndexRayResult v_callback;
		v_callback.m_collisionFilterMask = SM::PhysicsFilterMask_DynamicBody
			| SM::PhysicsFilterMask_StaticBody
			| SM::PhysicsFilterMask_Character
			| SM::PhysicsFilterMask_Harvestable
			| SM::PhysicsFilterMask_Joints;

		v_callback.m_charToIgnore = v_pPlayer->getCharacter();
		v_callback.m_collisionFilterGroup = -1;
		v_callback.m_flags = 0;

		v_pCollWorld->rayTest(v_ray_start, v_ray_end, v_callback);
		if (v_callback.hasHit())
		{
			SM::Color v_obj_color;

			if (BetterPaintTool::getColorFromCollisionObject(
				v_callback.m_collisionObject, v_callback.m_triangleIndex, v_obj_color))
			{
				char v_buffer[0x40];
				const int v_buffer_sz = sprintf_s(v_buffer, "Color copied: #%02X%02X%02X%02X%02X%02X",
					(std::uint32_t)v_obj_color.r, (std::uint32_t)v_obj_color.g, (std::uint32_t)v_obj_color.b,
					(std::uint32_t)v_obj_color.r, (std::uint32_t)v_obj_color.g, (std::uint32_t)v_obj_color.b);

				SM::InGameGuiManager::DisplayAlertText(std::string(v_buffer, v_buffer_sz), 2.0f);
				SM::AudioManager::PlaySound("PaintTool - ColorPick");

				self->m_fpAnims.resetAnimation("pick");
				self->m_fpAnims.addNewAnimation("color_picker", "painttool_colorpick_idle", "color_picker_end", 0.0f, 1.0f, 5.0f);
				self->m_fpAnims.addNewAnimation("color_picker_end", "painttool_colorpick", "idle", 0.0f, 0.7f, 1.0f);
				self->setFpAnimation("color_picker");

				self->setColor(v_obj_color);
			}
		}
	}
}

std::uint32_t BetterPaintTool::getLimiterAxisIndex(const DirectX::XMINT3& limiter)
{
	return std::uint32_t(std::abs(limiter.x))
		+ (std::uint32_t(std::abs(limiter.y)) * 2)
		+ (std::uint32_t(std::abs(limiter.z)) * 3);
}

void BetterPaintTool::updateSelectionData(SM::PaintToolSelectionData& sel_data)
{
	if (!this->isObjectSelected(sel_data))
		return;

	g_isPaintToolHoldingObject = true;
	const std::uint32_t v_limiter_idx = this->getLimiterAxisIndex(sel_data.m_selectionBoxLimiter);

	const std::int32_t v_scroll_val = SM::InputManager::GetMouseScrollDelta();
	if (v_scroll_val != 0)
	{
		const std::int32_t v_scroll_add = std::abs(v_scroll_val) / 130;
		const std::int32_t v_normalized_scroll = (v_scroll_val > 0)
			? (1 + v_scroll_add) : (-1 - v_scroll_add);
		
		if (v_limiter_idx > 0 && v_limiter_idx <= 3)
		{
			const std::uint32_t v_actual_idx = v_limiter_idx - 1;
			const std::int32_t v_limiter_size = SM::StaticValues::sm_paintToolPaintLimiter;

			std::int32_t* v_max_arr = reinterpret_cast<std::int32_t*>(&sel_data.m_selectionBoxMax);
			std::int32_t* v_min_arr = reinterpret_cast<std::int32_t*>(&sel_data.m_selectionBoxMin);
			std::int32_t* v_lim_arr = reinterpret_cast<std::int32_t*>(&sel_data.m_selectionBoxLimiter);

			const std::int32_t v_max_val = v_max_arr[v_actual_idx];
			const std::int32_t v_min_val = v_min_arr[v_actual_idx];
			const std::int32_t v_dist_to_lim1 = std::abs((v_max_val + v_limiter_size) - v_min_val);
			const std::int32_t v_dist_to_lim2 = std::abs((v_max_val - v_limiter_size) - v_min_val);

			const std::int32_t v_mul_scroll = v_normalized_scroll * v_lim_arr[v_actual_idx];
			const std::int32_t v_fixed_adder = (v_mul_scroll > 0)
				? std::min(v_mul_scroll, v_dist_to_lim1)
				: std::max(v_mul_scroll, -v_dist_to_lim2);

			v_min_arr[v_limiter_idx - 1] += v_fixed_adder;
		}
	}

	DirectX::FXMVECTOR v_bBoxMin = DirectX::XMLoadSInt3(&sel_data.m_selectionBoxMin);
	DirectX::FXMVECTOR v_bBoxMax = DirectX::XMLoadSInt3(&sel_data.m_selectionBoxMax);
	DirectX::FXMVECTOR v_bBoxResult = DirectX::XMVectorAdd(
		DirectX::XMVectorAbs(DirectX::XMVectorSubtract(v_bBoxMax, v_bBoxMin)),
		DirectX::XMVectorSet(1.0f, 1.0f, 1.0f, 1.0f));

	DirectX::XMINT3 v_bBoxSizeInt;
	DirectX::XMStoreSInt3(&v_bBoxSizeInt, v_bBoxResult);

	//To show the X and Y size properly
	switch (v_limiter_idx)
	{
	case 1:
		std::swap(v_bBoxSizeInt.x, v_bBoxSizeInt.y);
	case 2:
		std::swap(v_bBoxSizeInt.y, v_bBoxSizeInt.z);
		break;
	default:
		break;
	}

	char v_text_buffer[0x100];
	const int v_buff_sz = sprintf_s(v_text_buffer, "<p textShadow='false' bg='gui_keybinds_bg' color='#ffffff' spacing='7'>Selection size: %ix%ix%i</p>",
		v_bBoxSizeInt.x, v_bBoxSizeInt.y, v_bBoxSizeInt.z);
	
	SM::InGameGuiManager::SetInteractionText({ std::string(v_text_buffer, v_buff_sz), "" });
	SM::InGameGuiManager::SetInteractionText({
		"<img bg='gui_keybinds_bg' spacing='0'>icon_keybinds_scroll_up.png</img>",
		"<p textShadow='true' bg='gui_keybinds_bg' color='#ffffff' spacing='15'>To adjust selection depth</p>"
	});
}

bool BetterPaintTool::isObjectSelected(const SM::PaintToolSelectionData& sel_data)
{
	return sel_data.m_iObjectId != -1 && sel_data.m_iObjectType > 0;
}

bool BetterPaintTool::isErasingOrPainting() const
{
	return this->isObjectSelected(m_paintSelection)
		|| this->isObjectSelected(m_eraseSelection);
}

SM::Color BetterPaintTool::getInterpolatedColor()
{
	const float v_lerp_factor = std::min(std::max((this->m_fTimeSinceLastChange - 0.3f) * 2.22f, 0.0f), 1.0f);

	const float v_prev_r = this->m_prevPaintColor.getFloat(0);
	const float v_prev_g = this->m_prevPaintColor.getFloat(1);
	const float v_prev_b = this->m_prevPaintColor.getFloat(2);

	const float v_cur_r = this->m_visualizationColor.getFloat(0);
	const float v_cur_g = this->m_visualizationColor.getFloat(1);
	const float v_cur_b = this->m_visualizationColor.getFloat(2);

	SM::Color v_output;
	v_output.setFloat(0, MathUtil::lerp(v_prev_r, v_cur_r, v_lerp_factor));
	v_output.setFloat(1, MathUtil::lerp(v_prev_g, v_cur_g, v_lerp_factor));
	v_output.setFloat(2, MathUtil::lerp(v_prev_b, v_cur_b, v_lerp_factor));
	v_output.a = 0xFF;

	return v_output;
}

void BetterPaintTool::setColor(SM::Color color)
{
	if (m_pNetworkData->m_paintColor == color)
		return;

	m_pNetworkData->m_paintColor = color;
	m_pNetworkData->m_bDataChanged = true;
	m_pNetworkData->m_bColorUpdated = true;

	this->m_prevPaintColor = this->getInterpolatedColor();
	this->m_visualizationColor = m_pNetworkData->m_paintColor;
	this->m_fTimeSinceLastChange = 0.3f;
	this->m_paintColor = m_pNetworkData->m_paintColor;
}

bool BetterPaintTool::getColorFromShape(int obj_idx, int tri_idx, SM::Color& out_color)
{
	if (tri_idx == -1) return false;

	SM::BodyState* v_pBodyState = SM::CreationManager::GetBodyState(obj_idx);
	if (!v_pBodyState) return false;

	SM::RigidBody* v_pRigidBody = v_pBodyState->m_pBody.get();
	if (!v_pRigidBody) return false;

	SM::ChildShape* v_pChild = v_pRigidBody->getChildShape(tri_idx);
	if (!v_pChild) return false;

	out_color = v_pChild->getColor();
	return true;
}

bool BetterPaintTool::getColorFromJoint(SM::PhysicsProxy* proxy, int tri_idx, SM::Color& out_color)
{
	SM::BodyJointPhysicsProxy* v_pJointProxy = reinterpret_cast<SM::BodyJointPhysicsProxy*>(proxy);
	if (tri_idx < 0 || tri_idx > v_pJointProxy->m_compoundShape.getNumChildShapes())
		return false;

	btCollisionShape* v_pJointShape = v_pJointProxy->m_compoundShape.getChildShape(tri_idx);
	if (!v_pJointShape) return false;

	SM::Joint* v_pJoint = reinterpret_cast<SM::Joint*>(v_pJointShape->getUserPointer());
	if (!v_pJoint) return false;

	out_color = v_pJoint->m_color;
	out_color.a = 0xFF;

	return true;
}

bool BetterPaintTool::getColorFromCharacter(int char_idx, SM::Color& out_color)
{
	SM::Character* v_char_data = SM::CharacterManager::GetCharacter(char_idx);
	if (!v_char_data) return false;

	out_color.setFloat(0, v_char_data->m_color.x);
	out_color.setFloat(1, v_char_data->m_color.y);
	out_color.setFloat(2, v_char_data->m_color.z);
	out_color.a = 0xFF;

	return true;
}

bool BetterPaintTool::getColorFromHarvestable(int hvs_idx, SM::Color& out_color)
{
	SM::Harvestable* v_hvs_data = SM::HarvestableManager::GetHarvestable(hvs_idx);
	if (!v_hvs_data) return false;

	out_color.setFloat(0, v_hvs_data->m_color.x);
	out_color.setFloat(1, v_hvs_data->m_color.y);
	out_color.setFloat(2, v_hvs_data->m_color.z);
	out_color.a = 0xFF;

	return true;
}

bool BetterPaintTool::getColorFromCollisionObject(
	const btCollisionObject* obj, int tri_idx, SM::Color& out_color)
{
	if (!obj) return false;

	SM::PhysicsProxy* v_pProxy = reinterpret_cast<SM::PhysicsProxy*>(obj->getUserPointer());
	if (!v_pProxy) return false;

	switch (v_pProxy->getProxyType())
	{
	case SM::PhysicsProxyType_Shape:
		return BetterPaintTool::getColorFromShape(obj->getUserIndex(), tri_idx, out_color);
	case SM::PhysicsProxyType_Joint:
		return BetterPaintTool::getColorFromJoint(v_pProxy, tri_idx, out_color);
	case SM::PhysicsProxyType_Character:
		return BetterPaintTool::getColorFromCharacter(obj->getUserIndex(), out_color);
	case SM::PhysicsProxyType_Harvestable:
		return BetterPaintTool::getColorFromHarvestable(
			reinterpret_cast<SM::HarvestablePhysicsProxy*>(v_pProxy)->m_iHarvestableId, out_color);
	}

	return false;
}