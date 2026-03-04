#pragma once

#include "SmSdk/AreaTriggerManager.hpp"

#include <DirectXMath.h>

#include <unordered_map>
#include <memory>

SMSDK_BEGIN_NAMESPACE

struct Portal : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
	/* 0x0030 */ SDK_PUB DirectX::XMFLOAT3 m_position;
	/* 0x003C */ SDK_PRI char pad_0x3C[0x4];
	/* 0x0040 */ SDK_PUB AreaTrigger* m_pAreaTriggerA;
	/* 0x0048 */ SDK_PUB AreaTrigger* m_pAreaTriggerB;
}; // Size: 0x50

static_assert(offsetof(Portal, Portal::m_position) == 0x30, "Portal::m_position: Incorrect offset");
static_assert(offsetof(Portal, Portal::m_pAreaTriggerA) == 0x40, "Portal::m_pAreaTriggerA: Incorrect offset");
static_assert(offsetof(Portal, Portal::m_pAreaTriggerB) == 0x48, "Portal::m_pAreaTriggerB: Incorrect offset");

static_assert(sizeof(Portal) == 0x50, "Portal: Incorrect Size");


struct PortalManager
{
	SDK_PUB static PortalManager* GetInstance();

	/* 0x0000 */ SDK_PUB std::unordered_map<int, std::shared_ptr<Portal>> m_mapPortals;
	/* 0x0040 */ SDK_PRI char pad_0x40[0x58];
}; // Size: 0x98

static_assert(offsetof(PortalManager, PortalManager::m_mapPortals) == 0x0, "PortalManager::m_mapPortals: Incorrect offset");

static_assert(sizeof(PortalManager) == 0x98, "PortalManager: Incorrect Size");

SMSDK_END_NAMESPACE