#pragma once

#include "SmSdk/bullet_include.hpp"

enum PhysicsProxyType : unsigned char
{
	PhysicsProxyType_Border = 1,
	PhysicsProxyType_TerrainGround = 2,
	PhysicsProxyType_TerrainAsset = 3,
	PhysicsProxyType_Shape = 4,
	PhysicsProxyType_Joint = 5,
	PhysicsProxyType_Lift = 6,
	PhysicsProxyType_Character = 7,
	PhysicsProxyType_Harvestable = 9,
	PhysicsProxyType_AreaTrigger = 11
};

__declspec(align(16)) class PhysicsProxy
{
public:
	virtual char getProxyType() { return 0; }

private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ btRigidBody* m_pDynamicsWorldRigidBody;
	/* 0x0018 */ btRigidBody* m_pTickRaycastCollisionObject;
	/* 0x0020 */ btCollisionObject* m_pInterpolatedRaycastCollisionObject;
	/* 0x0028 */ __int16 world_id;
private:
	/* 0x002A */ char pad_0x2A[0x6];

}; //Size=0x0030

static_assert(sizeof(PhysicsProxy) == 0x30, "PhysicsProxy: Incorrect Size");