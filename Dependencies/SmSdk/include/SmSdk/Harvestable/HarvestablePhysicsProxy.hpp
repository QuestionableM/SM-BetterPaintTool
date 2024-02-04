#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"

class HarvestablePhysicsProxy : public PhysicsProxy
{
public:
	/* 0x0030 */ __int32 harvestable_id;
private:
	/* 0x0034 */ char pad_0x34[0x8C];

}; // Size: 0xC0

static_assert(sizeof(HarvestablePhysicsProxy) == 0xC0, "HarvestablePhysicsProxy: Incorrect Size");