#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/bullet_include.hpp"

class BodyJointPhysicsProxy : public PhysicsProxy
{
public:
	/* 0x0030 */ btCompoundShape m_compoundShape;
private:
	/* 0x00B0 */ char pad_0xB0[0x20];
}; // Size: 0xD0

static_assert(sizeof(BodyJointPhysicsProxy) == 0xD0, "BodyJointPhysicsProxy: Incorrect Size");