#pragma once

#include "SmSdk/boost_include.hpp"
#include <unordered_map>

struct ContainerEntry
{
	/* 0x0000 */ boost::uuids::uuid m_itemUuid;
	/* 0x0010 */ __int32 m_itemId;
	/* 0x0014 */ __int32 m_itemQuantity;
}; // Size: 0x18

static_assert(offsetof(ContainerEntry, ContainerEntry::m_itemUuid) == 0x0, "ContainerEntry::m_itemUuid: Incorrect offset");
static_assert(offsetof(ContainerEntry, ContainerEntry::m_itemId) == 0x10, "ContainerEntry::m_itemId: Incorrect offset");
static_assert(offsetof(ContainerEntry, ContainerEntry::m_itemQuantity) == 0x14, "ContainerEntry::m_itemQuantity: Incorrect offset");

static_assert(sizeof(ContainerEntry) == 0x18, "ContainerEntry: Incorrect Size");



struct ContainerItems
{
	/* 0x0000 */ unsigned __int16 m_uMaxStackSize;
private:
	/* 0x0002 */ char pad_0x2[0x6];
public:
	/* 0x0008 */ std::vector<ContainerEntry> m_vecEntries;
}; // Size: 0x20

static_assert(offsetof(ContainerItems, ContainerItems::m_uMaxStackSize) == 0x0, "ContainerItems::m_uMaxStackSize: Incorrect offset");
static_assert(offsetof(ContainerItems, ContainerItems::m_vecEntries) == 0x8, "ContainerItems::m_vecEntries: Incorrect offset");

static_assert(sizeof(ContainerItems) == 0x20, "ContainerItems: Incorrect Size");



struct Container2 : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ ContainerItems m_clientItems;
	/* 0x0050 */ ContainerItems m_serverItems;
	/* 0x0070 */ ContainerItems container_items3;
private:
	/* 0x0090 */ char pad_0x90[0x4];
public:
	/* 0x0094 */ __int32 update_counter;
	/* 0x0098 */ __int32 last_update_tick;
private:
	/* 0x009C */ char pad_0x9C[0x34];
public:
	/* 0x00D0 */ std::vector<boost::uuids::uuid> m_vecFilters;
	/* 0x00E8 */ bool m_bAllowSpend;
private:
	/* 0x00E9 */ char pad_0xE9[0x7];
}; // Size: 0xF0

static_assert(offsetof(Container2, Container2::m_clientItems) == 0x30, "Container2::m_clientItems: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_serverItems) == 0x50, "Container2::m_serverItems: Incorrect offset");
static_assert(offsetof(Container2, Container2::container_items3) == 0x70, "Container2::container_items3: Incorrect offset");
static_assert(offsetof(Container2, Container2::update_counter) == 0x94, "Container2::update_counter: Incorrect offset");
static_assert(offsetof(Container2, Container2::last_update_tick) == 0x98, "Container2::last_update_tick: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_vecFilters) == 0xD0, "Container2::m_vecFilters: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_bAllowSpend) == 0xE8, "Container2::m_bAllowSpend: Incorrect offset");

static_assert(sizeof(Container2) == 0xF0, "Container2: Incorrect Size");



struct ContainerManager
{
	static ContainerManager* GetInstance();

private:
	/* 0x0000 */ char pad_0x0[0x28];
public:
	/* 0x0028 */ bool m_bOngoingTransaction;
private:
	/* 0x0029 */ char pad_0x29[0x7];
public:
	/* 0x0030 */ std::shared_ptr<Container2> some_container;
	/* 0x0040 */ std::unordered_map<int, std::shared_ptr<Container2>> m_worldContainerMap;
private:
	/* 0x0080 */ char pad_0x80[0x18];
}; // Size: 0x98

static_assert(offsetof(ContainerManager, ContainerManager::m_bOngoingTransaction) == 0x28, "ContainerManager::m_bOngoingTransaction: Incorrect offset");
static_assert(offsetof(ContainerManager, ContainerManager::some_container) == 0x30, "ContainerManager::some_container: Incorrect offset");
static_assert(offsetof(ContainerManager, ContainerManager::m_worldContainerMap) == 0x40, "ContainerManager::m_worldContainerMap: Incorrect offset");

static_assert(sizeof(ContainerManager) == 0x98, "ContainerManager: Incorrect Size");