#pragma once

#include "PhysicsProxy.hpp"

struct AreaTriggerProxy : public PhysicsProxy
{
	/* 0x0030 */ __int32 m_areaTriggerId;
private:
	/* 0x0034 */ char pad_0x34[0xC];
    
}; // Size: 0x40

static_assert(offsetof(AreaTriggerProxy, AreaTriggerProxy::m_areaTriggerId) == 0x30, "AreaTriggerProxy::m_areaTriggerId: Incorrect offset");

static_assert(sizeof(AreaTriggerProxy) == 0x40, "AreaTriggerProxy: Incorrect Size");



struct WaterAreaTriggerProxy : public AreaTriggerProxy
{
}; // Size: 0x40

static_assert(sizeof(WaterAreaTriggerProxy) == 0x40, "WaterAreaTriggerProxy: Incorrect Size");