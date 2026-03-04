#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"

#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

struct CharacterPhysicsProxy : public PhysicsProxy
{
	/* 0x0030 */ SDK_PRI char pad_0x30[0x8];
	/* 0x0038 */ SDK_PUB struct CharacterController* m_pController;
	/* 0x0040 */ SDK_PRI char pad_0x40[0x38];
	/* 0x0078 */ SDK_PUB btCollisionObject* m_pCollisionObj2;
	/* 0x0080 */ SDK_PUB btCollisionObject* m_pCollisionObj3;
	/* 0x0088 */ SDK_PRI char pad_0x88[0x8];
	/* 0x0090 */ SDK_PUB DirectX::XMFLOAT3 m_position;
	/* 0x009C */ SDK_PRI char pad_0x9C[0x34];
}; // Size: 0xD0

static_assert(sizeof(CharacterPhysicsProxy) == 0xD0, "CharacterPhysicsProxy: Incorrect Size");

SMSDK_END_NAMESPACE