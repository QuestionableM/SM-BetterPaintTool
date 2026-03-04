#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/bullet_include.hpp"

SMSDK_BEGIN_NAMESPACE

class BodyJointPhysicsProxy : public PhysicsProxy
{
	/* 0x0030 */ SDK_PUB btCompoundShape m_compoundShape;
	/* 0x00B0 */ SDK_PRI char pad_0xB0[0x20];
}; // Size: 0xD0

static_assert(sizeof(BodyJointPhysicsProxy) == 0xD0, "BodyJointPhysicsProxy: Incorrect Size");

SMSDK_END_NAMESPACE