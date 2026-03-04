#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/bullet_include.hpp"

SMSDK_BEGIN_NAMESPACE

struct JointPhysicsProxy : public PhysicsProxy
{
	/* 0x0030 */ SDK_PRI char pad_0x30[0x8];
	/* 0x0038 */ SDK_PUB btHingeConstraint* m_pHingeConstraint;
}; // Size: 0x40

static_assert(sizeof(JointPhysicsProxy) == 0x40, "JointPhysicsProxy: Incorrect Size");

SMSDK_END_NAMESPACE