#pragma once

#include "PhysicsProxy.hpp"

#include <DirectXMath.h>

struct CharacterPhysicsProxy : public PhysicsProxy
{
	/* 0x0030 */ char pad_0x30[0x8];
	/* 0x0038 */ struct CharacterController* controller;
	/* 0x0040 */ char pad_0x40[0x38];
	/* 0x0078 */ btCollisionObject* coll_obj2;
	/* 0x0080 */ btCollisionObject* coll_obj3;
	/* 0x0088 */ char pad_0x88[0x8];
	/* 0x0090 */ DirectX::XMFLOAT3 position;
	/* 0x009C */ char pad_0x9C[0x34];
}; // Size: 0xD0

static_assert(sizeof(CharacterPhysicsProxy) == 0xD0, "CharacterPhysicsProxy: Incorrect Size");