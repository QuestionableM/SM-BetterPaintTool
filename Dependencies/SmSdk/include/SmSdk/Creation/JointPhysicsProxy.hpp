#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/bullet_include.hpp"

struct JointPhysicsProxy : public PhysicsProxy
{
private:
	/* 0x0030 */ char pad_0x30[0x8];
public:
	/* 0x0038 */ btHingeConstraint* hinge_constraint;
}; // Size: 0x40

static_assert(sizeof(JointPhysicsProxy) == 0x40, "JointPhysicsProxy: Incorrect Size");