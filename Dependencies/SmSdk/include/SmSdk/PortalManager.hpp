#pragma once

#include "SmSdk/AreaTriggerManager.hpp"

#include <DirectXMath.h>

#include <unordered_map>
#include <memory>

struct Portal : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ DirectX::XMFLOAT3 m_position;
private:
	/* 0x003C */ char pad_0x3C[0x4];
public:
	/* 0x0040 */ AreaTrigger* m_pAreaTriggerA;
	/* 0x0048 */ AreaTrigger* m_pAreaTriggerB;
}; // Size: 0x50

static_assert(offsetof(Portal, Portal::m_position) == 0x30, "Portal::m_position: Incorrect offset");
static_assert(offsetof(Portal, Portal::m_pAreaTriggerA) == 0x40, "Portal::m_pAreaTriggerA: Incorrect offset");
static_assert(offsetof(Portal, Portal::m_pAreaTriggerB) == 0x48, "Portal::m_pAreaTriggerB: Incorrect offset");

static_assert(sizeof(Portal) == 0x50, "Portal: Incorrect Size");



struct PortalManager
{
    static PortalManager* GetInstance();

	/* 0x0000 */ std::unordered_map<int, std::shared_ptr<Portal>> m_mapPortals;
private:
	/* 0x0040 */ char pad_0x40[0x58];
    
}; // Size: 0x98

static_assert(offsetof(PortalManager, PortalManager::m_mapPortals) == 0x0, "PortalManager::m_mapPortals: Incorrect offset");

static_assert(sizeof(PortalManager) == 0x98, "PortalManager: Incorrect Size");