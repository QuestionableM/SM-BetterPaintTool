#include "BetterPaintTool.hpp"

#include "SmSdk/Harvestable/HarvestablePhysicsProxy.hpp"
#include "SmSdk/Harvestable/HarvestableManager.hpp"
#include "SmSdk/Creation/CreationManager.hpp"
#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/Physics/Physics.hpp"
#include "SmSdk/PlayerManager.hpp"
#include "SmSdk/MyPlayer.hpp"

#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/Character.hpp"

#include "BetterPaintToolGui.hpp"
#include "Utils/Console.hpp"

#include <BulletCollision/NarrowPhaseCollision/btRaycastCallback.h>

#pragma comment(lib, "User32.lib")

BetterPaintTool::t_init_sig BetterPaintTool::o_initialize = nullptr;
BetterPaintTool::t_update_sig BetterPaintTool::o_update = nullptr;

bool BetterPaintTool::h_initialize(BetterPaintTool* self)
{
	const bool v_out = BetterPaintTool::o_initialize(self);

	if (self->m_pGuiInterface)
	{
		self->m_pGuiInterface->m_mapStringToFunction.emplace("HexInput",
			[self](const std::string& str) -> void {
				Color v_color(str);

				self->visualization_color = v_color;
				self->paint_color = v_color;
				self->network_data->paint_color = v_color;
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
				self->network_data->paint_color = v_obj_color;
				self->visualization_color = v_obj_color;
			}
		}
	}
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

bool BetterPaintTool::getColorFromJoint(int obj_idx, int tri_idx, Color& out_color)
{
	if (tri_idx == -1) return false;

	BodyStructure* v_body_data = CreationManager::GetBodyData(obj_idx);
	if (!v_body_data) return false;

	Joint* v_jnt_data = v_body_data->body->getJoint(tri_idx);
	if (!v_jnt_data) return false;

	out_color = v_jnt_data->m_color;
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
		return BetterPaintTool::getColorFromJoint(obj->getUserIndex(), tri_idx, out_color);
	case PhysicsProxyType_Character:
		return BetterPaintTool::getColorFromCharacter(obj->getUserIndex(), out_color);
	case PhysicsProxyType_Harvestable:
		return BetterPaintTool::getColorFromHarvestable(
			reinterpret_cast<HarvestablePhysicsProxy*>(v_pProxy)->harvestable_id, out_color);
	}

	return false;
}