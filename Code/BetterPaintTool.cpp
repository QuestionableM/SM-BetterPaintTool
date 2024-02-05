#include "BetterPaintTool.hpp"

#include "SmSdk/Harvestable/HarvestablePhysicsProxy.hpp"
#include "SmSdk/Harvestable/HarvestableManager.hpp"
#include "SmSdk/Creation/BodyJointPhysicsProxy.hpp"
#include "SmSdk/Creation/CreationManager.hpp"
#include "SmSdk/Gui/InGameGuiManager.hpp"
#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/Physics/Physics.hpp"
#include "SmSdk/PlayerManager.hpp"
#include "SmSdk/AudioManager.hpp"
#include "SmSdk/MyPlayer.hpp"

#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/Character.hpp"

#include "BetterPaintToolGui.hpp"
#include "Utils/MathUtils.hpp"
#include "Utils/Console.hpp"

#include <BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>

#pragma comment(lib, "User32.lib")

BetterPaintTool::t_init_sig BetterPaintTool::o_initialize = nullptr;
BetterPaintTool::t_update_sig BetterPaintTool::o_update = nullptr;

bool BetterPaintTool::h_initialize(BetterPaintTool* self)
{
	sizeof(std::deque<int>);

	const bool v_out = BetterPaintTool::o_initialize(self);

	if (self->m_pGuiInterface)
	{
		self->m_pGuiInterface->m_mapStringToFunction.emplace("HexInput",
			[self](const std::string& str) -> void {
				self->setColor(str);
			}
		);

		self->m_pGuiInterface->m_mapStringToFunction.emplace("InitFunc",
			[self](const std::string& str) -> void {
				GuiBase* v_gui_ptr = self->m_pGuiInterface->m_pGuiBase.get();
				reinterpret_cast<BetterPaintToolGui*>(v_gui_ptr)->initParams(self);
			}
		);
	}

	return v_out;
}

struct ColorIndexRayResult : public btCollisionWorld::RayResultCallback
{
	int m_triangleIndex = -1;
	Character* m_charToIgnore = nullptr;

	bool checkCollisionAllowed(const btCollisionObject* obj) const
	{
		PhysicsProxy* v_pProxy = reinterpret_cast<PhysicsProxy*>(obj->getUserPointer());
		if (!v_pProxy) return false;

		if (v_pProxy->getProxyType() == PhysicsProxyType_Character)
		{
			Character* v_cur_char = CharacterManager::GetCharacter(obj->getUserIndex());
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
	if (self->m_fpAnims.current_anim != "color_picker" && self->m_fpAnims.current_anim != "color_picker_end")
	{
		self->m_fpAnims.removeAnimation("color_picker");
		self->m_fpAnims.removeAnimation("color_picker_end");
	}

	if (self->is_equipped() && (GetAsyncKeyState(VK_MBUTTON) & 1))
	{
		Physics* v_pPhysics = Physics::GetInstance();
		if (!v_pPhysics) return;

		PhysicsBase* v_pPhysBase = v_pPhysics->physics_base;
		if (!v_pPhysBase->collision_world2) return;

		btCollisionWorld* v_pCollWorld = v_pPhysBase->collision_world2;

		MyPlayer* v_pPlayer = MyPlayer::GetInstance();
		const btVector3 v_ray_start = *reinterpret_cast<btVector3*>(&v_pPlayer->camera.position);
		const btVector3 v_direction = *reinterpret_cast<btVector3*>(&v_pPlayer->camera.direction);
		const btVector3 v_ray_end = v_ray_start + v_direction * 7.0f;

		ColorIndexRayResult v_callback;
		v_callback.m_collisionFilterMask = PhysicsFilterMask_DynamicBody
			| PhysicsFilterMask_StaticBody | PhysicsFilterMask_Character | PhysicsFilterMask_Harvestable | PhysicsFilterMask_Joints;

		v_callback.m_charToIgnore = v_pPlayer->getCharacter();
		v_callback.m_collisionFilterGroup = -1;
		v_callback.m_flags = 0;

		v_pCollWorld->rayTest(v_ray_start, v_ray_end, v_callback);
		if (v_callback.hasHit())
		{
			Color v_obj_color;

			if (BetterPaintTool::getColorFromCollisionObject(
				v_callback.m_collisionObject, v_callback.m_triangleIndex, v_obj_color))
			{
				char v_buffer[0x40];
				const int v_buffer_sz = sprintf_s(v_buffer, "Color copied: #%02X%02X%02X%02X%02X%02X",
					(std::uint32_t)v_obj_color.r, (std::uint32_t)v_obj_color.g, (std::uint32_t)v_obj_color.b,
					(std::uint32_t)v_obj_color.r, (std::uint32_t)v_obj_color.g, (std::uint32_t)v_obj_color.b);

				InGameGuiManager::DisplayAlertText(std::string(v_buffer, v_buffer_sz), 2.0f);
				AudioManager::PlaySound("PaintTool - ColorPick");

				self->m_fpAnims.resetAnimation("pick");
				self->m_fpAnims.addNewAnimation("color_picker", "painttool_colorpick_idle", "color_picker_end", 0.0f, 1.0f, 5.0f);
				self->m_fpAnims.addNewAnimation("color_picker_end", "painttool_colorpick", "idle", 0.0f, 0.7f, 1.0f);
				self->setFpAndTpAnimation("color_picker");

				self->setColor(v_obj_color);
			}
		}
	}
}

Color BetterPaintTool::getInterpolatedColor()
{
	const float v_lerp_factor = std::min(std::max((this->time_since_last_change - 0.3f) * 2.22f, 0.0f), 1.0f);

	const float v_prev_r = this->prev_paint_color.getFloat(0);
	const float v_prev_g = this->prev_paint_color.getFloat(1);
	const float v_prev_b = this->prev_paint_color.getFloat(2);

	const float v_cur_r = this->visualization_color.getFloat(0);
	const float v_cur_g = this->visualization_color.getFloat(1);
	const float v_cur_b = this->visualization_color.getFloat(2);

	Color v_output;
	v_output.setFloat(0, MathUtil::lerp(v_prev_r, v_cur_r, v_lerp_factor));
	v_output.setFloat(1, MathUtil::lerp(v_prev_g, v_cur_g, v_lerp_factor));
	v_output.setFloat(2, MathUtil::lerp(v_prev_b, v_cur_b, v_lerp_factor));
	v_output.a = 0xFF;

	return v_output;
}

void BetterPaintTool::setColor(Color color)
{
	if (m_pNetworkData->paint_color == color)
		return;

	m_pNetworkData->paint_color = color;
	m_pNetworkData->m_bColorUpdated = true;

	this->prev_paint_color = this->getInterpolatedColor();
	this->visualization_color = m_pNetworkData->paint_color;
	this->time_since_last_change = 0.3f;
	this->paint_color = m_pNetworkData->paint_color;
}

bool BetterPaintTool::getColorFromShape(int obj_idx, int tri_idx, Color& out_color)
{
	if (tri_idx == -1) return false;

	BodyStructure* v_body_data = CreationManager::GetBodyData(obj_idx);
	if (!v_body_data) return false;

	RigidBody* v_pRigidBody = v_body_data->body.get();
	if (!v_pRigidBody) return false;

	ChildShape* v_pChild = v_pRigidBody->getChildShape(tri_idx);
	if (!v_pChild) return false;

	out_color = v_pChild->getColor();
	return true;
}

bool BetterPaintTool::getColorFromJoint(PhysicsProxy* proxy, int tri_idx, Color& out_color)
{
	BodyJointPhysicsProxy* v_pJointProxy = reinterpret_cast<BodyJointPhysicsProxy*>(proxy);
	if (tri_idx < 0 || tri_idx > v_pJointProxy->m_compoundShape.getNumChildShapes())
		return false;

	btCollisionShape* v_pJointShape = v_pJointProxy->m_compoundShape.getChildShape(tri_idx);
	if (!v_pJointShape) return false;

	Joint* v_pJoint = reinterpret_cast<Joint*>(v_pJointShape->getUserPointer());
	if (!v_pJoint) return false;

	out_color = v_pJoint->m_color;
	out_color.a = 0xFF;

	return true;
}

bool BetterPaintTool::getColorFromCharacter(int char_idx, Color& out_color)
{
	Character* v_char_data = CharacterManager::GetCharacter(char_idx);
	if (!v_char_data) return false;

	out_color.setFloat(0, v_char_data->color.x);
	out_color.setFloat(1, v_char_data->color.y);
	out_color.setFloat(2, v_char_data->color.z);
	out_color.a = 0xFF;

	return true;
}

bool BetterPaintTool::getColorFromHarvestable(int hvs_idx, Color& out_color)
{
	Harvestable* v_hvs_data = HarvestableManager::GetHarvestable(hvs_idx);
	if (!v_hvs_data) return false;

	out_color.setFloat(0, v_hvs_data->color.x);
	out_color.setFloat(1, v_hvs_data->color.y);
	out_color.setFloat(2, v_hvs_data->color.z);
	out_color.a = 0xFF;

	return true;
}

bool BetterPaintTool::getColorFromCollisionObject(
	const btCollisionObject* obj, int tri_idx, Color& out_color)
{
	if (!obj) return false;

	PhysicsProxy* v_pProxy = reinterpret_cast<PhysicsProxy*>(obj->getUserPointer());
	if (!v_pProxy) return false;

	switch (v_pProxy->getProxyType())
	{
	case PhysicsProxyType_Shape:
		return BetterPaintTool::getColorFromShape(obj->getUserIndex(), tri_idx, out_color);
	case PhysicsProxyType_Joint:
		return BetterPaintTool::getColorFromJoint(v_pProxy, tri_idx, out_color);
	case PhysicsProxyType_Character:
		return BetterPaintTool::getColorFromCharacter(obj->getUserIndex(), out_color);
	case PhysicsProxyType_Harvestable:
		return BetterPaintTool::getColorFromHarvestable(
			reinterpret_cast<HarvestablePhysicsProxy*>(v_pProxy)->harvestable_id, out_color);
	}

	return false;
}