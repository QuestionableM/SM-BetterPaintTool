#pragma once

#include "SmSdk/Physics/AreaTriggerProxy.hpp"
#include "SmSdk/bullet_include.hpp"
#include "SmSdk/Base/Task.hpp"

#include <DirectXMath.h>
#include <concrt.h>

#include <unordered_map>
#include <vector>

SMSDK_BEGIN_NAMESPACE

struct AreaTrigger
{
	/* 0x0000 */ SDK_PUB std::int32_t m_iId;
	/* 0x0004 */ SDK_PUB std::int16_t m_iWorldId;
	/* 0x0006 */ SDK_PRI char pad_0x6[0xE];
	/* 0x0014 */ SDK_PUB std::uint32_t m_uFilter;
	/* 0x0018 */ SDK_PRI char pad_0x18[0xC];
	/* 0x0024 */ SDK_PRI std::uint32_t m_uSomeFlag;
	/* 0x0028 */ SDK_PRI char pad_0x28[0x4];
	/* 0x002C */ SDK_PUB bool m_bWaterTrigger;
	/* 0x002D */ SDK_PRI char pad_0x2D[0x3];
	/* 0x0030 */ SDK_PUB btBoxShape* m_pBoxShape;
	/* 0x0038 */ SDK_PUB btPairCachingGhostObject* m_pGhostObject;
	/* 0x0040 */ SDK_PUB AreaTriggerProxy* m_pPhysicsProxy;
	/* 0x0048 */ SDK_PRI char pad_0x48[0x100];
	/* 0x0148 */ SDK_PUB DirectX::XMFLOAT3 m_position;
	/* 0x0154 */ SDK_PUB DirectX::XMFLOAT4 m_rotation;
	/* 0x0164 */ SDK_PUB DirectX::XMFLOAT3 m_size;
	/* 0x0170 */ SDK_PRI char pad_0x170[0x8];
}; // Size: 0x178

static_assert(offsetof(AreaTrigger, AreaTrigger::m_iId) == 0x0, "AreaTrigger::m_iId: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_iWorldId) == 0x4, "AreaTrigger::m_iWorldId: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_uFilter) == 0x14, "AreaTrigger::m_uFilter: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_bWaterTrigger) == 0x2C, "AreaTrigger::m_bWaterTrigger: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_pBoxShape) == 0x30, "AreaTrigger::m_pBoxShape: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_pGhostObject) == 0x38, "AreaTrigger::m_pGhostObject: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_pPhysicsProxy) == 0x40, "AreaTrigger::m_pPhysicsProxy: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_position) == 0x148, "AreaTrigger::m_position: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_rotation) == 0x154, "AreaTrigger::m_rotation: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_size) == 0x164, "AreaTrigger::m_size: Incorrect offset");

static_assert(sizeof(AreaTrigger) == 0x178, "AreaTrigger: Incorrect Size");


struct AreaTriggerWorld
{
	/* 0x0000 */ uint16_t m_iWorldId;
private:
	/* 0x0002 */ char pad_0x2[0x6];
public:
	/* 0x0008 */ std::map<int, AreaTrigger*> m_mapAreaTriggers;
	/* 0x0018 */ std::vector<AreaTrigger*> m_vecAreaTriggerQueue;
private:
	/* 0x0030 */ char pad_0x30[0x18];
}; // Size: 0x48

static_assert(offsetof(AreaTriggerWorld, AreaTriggerWorld::m_iWorldId) == 0x0, "AreaTriggerWorld::m_iWorldId: Incorrect offset");
static_assert(offsetof(AreaTriggerWorld, AreaTriggerWorld::m_mapAreaTriggers) == 0x8, "AreaTriggerWorld::m_mapAreaTriggers: Incorrect offset");
static_assert(offsetof(AreaTriggerWorld, AreaTriggerWorld::m_vecAreaTriggerQueue) == 0x18, "AreaTriggerWorld::m_vecAreaTriggerQueue: Incorrect offset");

static_assert(sizeof(AreaTriggerWorld) == 0x48, "AreaTriggerWorld: Incorrect Size");


struct AreaTriggerManager : public Task
{
	static AreaTriggerManager* GetInstance();

	/* 0x0008 */ Concurrency::event m_event;
	/* 0x0050 */ uint32_t m_iAreaTriggerIdCounter;
private:
	/* 0x0054 */ char pad_0x54[0x4];
public:
	/* 0x0058 */ std::unordered_map<uint16_t, AreaTriggerWorld> m_mapAreaTriggerWorlds;
	/* 0x0098 */ std::vector<AreaTrigger*> m_vecAreaTriggers;
private:
	/* 0x00B0 */ char pad_0xB0[0x10];
}; // Size: 0xC0

static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_event) == 0x8, "AreaTriggerManager::m_event: Incorrect offset");
static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_iAreaTriggerIdCounter) == 0x50, "AreaTriggerManager::m_iAreaTriggerIdCounter: Incorrect offset");
static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_mapAreaTriggerWorlds) == 0x58, "AreaTriggerManager::m_mapAreaTriggerWorlds: Incorrect offset");
static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_vecAreaTriggers) == 0x98, "AreaTriggerManager::m_vecAreaTriggers: Incorrect offset");

static_assert(sizeof(AreaTriggerManager) == 0xC0, "AreaTriggerManager: Incorrect Size");

SMSDK_END_NAMESPACE