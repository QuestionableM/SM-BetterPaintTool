#pragma once

#include "SmSdk/bullet_include.hpp"

SMSDK_BEGIN_NAMESPACE

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
	SDK_PUB virtual char getProxyType() { return 0; }

	/* 0x0008 */ SDK_PRI char pad_0x8[0x8];
	/* 0x0010 */ SDK_PUB btRigidBody* m_pDynamicsWorldRigidBody;
	/* 0x0018 */ SDK_PUB btRigidBody* m_pTickRaycastCollisionObject;
	/* 0x0020 */ SDK_PUB btCollisionObject* m_pInterpolatedRaycastCollisionObject;
	/* 0x0028 */ SDK_PUB std::int16_t m_iWorldId;
	/* 0x002A */ SDK_PRI char pad_0x2A[0x6];
}; // Size: 0x30

static_assert(sizeof(PhysicsProxy) == 0x30, "PhysicsProxy: Incorrect Size");

SMSDK_END_NAMESPACE