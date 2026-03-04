#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"

SMSDK_BEGIN_NAMESPACE

struct AreaTriggerProxy : public PhysicsProxy
{
	/* 0x0030 */ SDK_PUB std::int32_t m_iAreaTriggerId;
	/* 0x0034 */ SDK_PRI char pad_0x34[0xC];
}; // Size: 0x40

static_assert(offsetof(AreaTriggerProxy, AreaTriggerProxy::m_iAreaTriggerId) == 0x30, "AreaTriggerProxy::m_iAreaTriggerId: Incorrect offset");

static_assert(sizeof(AreaTriggerProxy) == 0x40, "AreaTriggerProxy: Incorrect Size");


struct WaterAreaTriggerProxy : public AreaTriggerProxy
{
}; // Size: 0x40

static_assert(sizeof(WaterAreaTriggerProxy) == 0x40, "WaterAreaTriggerProxy: Incorrect Size");

SMSDK_END_NAMESPACE