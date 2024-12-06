#pragma once

#include "SmSdk/Physics/AreaTriggerProxy.hpp"
#include "SmSdk/bullet_include.hpp"
#include "SmSdk/Base/Task.hpp"

#include <DirectXMath.h>
#include <concrt.h>

#include <unordered_map>
#include <vector>

struct AreaTrigger
{
	/* 0x0000 */ __int32 m_id;
	/* 0x0004 */ __int16 m_worldId;
private:
	/* 0x0006 */ char pad_0x6[0xE];
public:
	/* 0x0014 */ unsigned __int32 m_filter;
private:
	/* 0x0018 */ char pad_0x18[0xC];
public:
	/* 0x0024 */ unsigned __int32 m_someFlag;
private:
	/* 0x0028 */ char pad_0x28[0x4];
public:
	/* 0x002C */ bool m_bWaterTrigger;
private:
	/* 0x002D */ char pad_0x2D[0x3];
public:
	/* 0x0030 */ btBoxShape* m_pBoxShape;
	/* 0x0038 */ btPairCachingGhostObject* m_pGhostObject;
	/* 0x0040 */ AreaTriggerProxy* m_pPhysicsProxy;
private:
	/* 0x0048 */ char pad_0x48[0x100];
public:
	/* 0x0148 */ DirectX::XMFLOAT3 m_position;
	/* 0x0154 */ DirectX::XMFLOAT4 m_rotation;
	/* 0x0164 */ DirectX::XMFLOAT3 m_size;
private:
	/* 0x0170 */ char pad_0x170[0x8];
}; // Size: 0x178

static_assert(offsetof(AreaTrigger, AreaTrigger::m_id) == 0x0, "AreaTrigger::m_id: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_worldId) == 0x4, "AreaTrigger::m_worldId: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_filter) == 0x14, "AreaTrigger::m_filter: Incorrect offset");
static_assert(offsetof(AreaTrigger, AreaTrigger::m_someFlag) == 0x24, "AreaTrigger::m_someFlag: Incorrect offset");
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
	/* 0x0000 */ unsigned __int16 m_worldId;
private:
	/* 0x0002 */ char pad_0x2[0x6];
public:
	/* 0x0008 */ std::map<int, AreaTrigger*> m_mapAreaTriggers;
	/* 0x0018 */ std::vector<AreaTrigger*> m_vecAreaTriggerQueue;
private:
	/* 0x0030 */ char pad_0x30[0x18];
}; // Size: 0x48

static_assert(offsetof(AreaTriggerWorld, AreaTriggerWorld::m_worldId) == 0x0, "AreaTriggerWorld::m_worldId: Incorrect offset");
static_assert(offsetof(AreaTriggerWorld, AreaTriggerWorld::m_mapAreaTriggers) == 0x8, "AreaTriggerWorld::m_mapAreaTriggers: Incorrect offset");
static_assert(offsetof(AreaTriggerWorld, AreaTriggerWorld::m_vecAreaTriggerQueue) == 0x18, "AreaTriggerWorld::m_vecAreaTriggerQueue: Incorrect offset");

static_assert(sizeof(AreaTriggerWorld) == 0x48, "AreaTriggerWorld: Incorrect Size");



struct AreaTriggerManager : public Task
{
    static AreaTriggerManager* GetInstance();

	/* 0x0008 */ Concurrency::event m_event;
	/* 0x0050 */ unsigned __int32 m_areaTriggerIdCounter;
private:
	/* 0x0054 */ char pad_0x54[0x4];
public:
	/* 0x0058 */ std::unordered_map<std::uint16_t, AreaTriggerWorld> m_mapAreaTriggerWorlds;
	/* 0x0098 */ std::vector<AreaTrigger*> m_vecAreaTriggers;
private:
	/* 0x00B0 */ char pad_0xB0[0x10];

}; // Size: 0xC0

static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_event) == 0x8, "AreaTriggerManager::m_event: Incorrect offset");
static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_areaTriggerIdCounter) == 0x50, "AreaTriggerManager::m_areaTriggerIdCounter: Incorrect offset");
static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_mapAreaTriggerWorlds) == 0x58, "AreaTriggerManager::m_mapAreaTriggerWorlds: Incorrect offset");
static_assert(offsetof(AreaTriggerManager, AreaTriggerManager::m_vecAreaTriggers) == 0x98, "AreaTriggerManager::m_vecAreaTriggers: Incorrect offset");

static_assert(sizeof(AreaTriggerManager) == 0xC0, "AreaTriggerManager: Incorrect Size");