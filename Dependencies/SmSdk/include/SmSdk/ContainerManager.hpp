#pragma once

#include "SmSdk/boost_include.hpp"
#include <unordered_map>

SMSDK_BEGIN_NAMESPACE

struct ContainerEntry
{
	/* 0x0000 */ SDK_PUB boost::uuids::uuid m_itemUuid;
	/* 0x0010 */ SDK_PUB std::int32_t m_iItemId;
	/* 0x0014 */ SDK_PUB std::int32_t m_iItemQuantity;
}; // Size: 0x18

static_assert(offsetof(ContainerEntry, ContainerEntry::m_itemUuid) == 0x0, "ContainerEntry::m_itemUuid: Incorrect offset");
static_assert(offsetof(ContainerEntry, ContainerEntry::m_iItemId) == 0x10, "ContainerEntry::m_iItemId: Incorrect offset");
static_assert(offsetof(ContainerEntry, ContainerEntry::m_iItemQuantity) == 0x14, "ContainerEntry::m_iItemQuantity: Incorrect offset");

static_assert(sizeof(ContainerEntry) == 0x18, "ContainerEntry: Incorrect Size");


struct ContainerItems
{
	/* 0x0000 */ SDK_PUB std::uint16_t m_uMaxStackSize;
	/* 0x0002 */ SDK_PRI char pad_0x2[0x6];
	/* 0x0008 */ SDK_PUB std::vector<ContainerEntry> m_vecEntries;
}; // Size: 0x20

static_assert(offsetof(ContainerItems, ContainerItems::m_uMaxStackSize) == 0x0, "ContainerItems::m_uMaxStackSize: Incorrect offset");
static_assert(offsetof(ContainerItems, ContainerItems::m_vecEntries) == 0x8, "ContainerItems::m_vecEntries: Incorrect offset");

static_assert(sizeof(ContainerItems) == 0x20, "ContainerItems: Incorrect Size");


struct Container2 : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
	/* 0x0030 */ SDK_PUB ContainerItems m_clientItems;
	/* 0x0050 */ SDK_PUB ContainerItems m_serverItems;
	/* 0x0070 */ SDK_PUB ContainerItems m_containerItems3;
	/* 0x0090 */ SDK_PRI char pad_0x90[0x4];
	/* 0x0094 */ SDK_PUB std::int32_t m_iUpdateCounter;
	/* 0x0098 */ SDK_PUB std::int32_t m_iLastUpdateTick;
	/* 0x009C */ SDK_PRI char pad_0x9C[0x34];
	/* 0x00D0 */ SDK_PUB std::vector<boost::uuids::uuid> m_vecFilters;
	/* 0x00E8 */ SDK_PUB bool m_bAllowSpend;
	/* 0x00E9 */ SDK_PRI char pad_0xE9[0x7];
}; // Size: 0xF0

static_assert(offsetof(Container2, Container2::m_clientItems) == 0x30, "Container2::m_clientItems: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_serverItems) == 0x50, "Container2::m_serverItems: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_containerItems3) == 0x70, "Container2::m_containerItems3: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_iUpdateCounter) == 0x94, "Container2::m_iUpdateCounter: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_iLastUpdateTick) == 0x98, "Container2::m_iLastUpdateTick: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_vecFilters) == 0xD0, "Container2::m_vecFilters: Incorrect offset");
static_assert(offsetof(Container2, Container2::m_bAllowSpend) == 0xE8, "Container2::m_bAllowSpend: Incorrect offset");

static_assert(sizeof(Container2) == 0xF0, "Container2: Incorrect Size");


struct ContainerManager
{
	SDK_PUB static ContainerManager* GetInstance();

	/* 0x0000 */ SDK_PRI char pad_0x0[0x28];
	/* 0x0028 */ SDK_PUB bool m_bOngoingTransaction;
	/* 0x0029 */ SDK_PRI char pad_0x29[0x7];
	/* 0x0030 */ SDK_PRI std::shared_ptr<Container2> m_pSomeContainer;
	/* 0x0040 */ SDK_PUB std::unordered_map<int, std::shared_ptr<Container2>> m_worldContainerMap; // NOTE: this naming inconsistency is intentional to match the original binary
	/* 0x0080 */ SDK_PRI char pad_0x80[0x18];
}; // Size: 0x98

static_assert(offsetof(ContainerManager, ContainerManager::m_bOngoingTransaction) == 0x28, "ContainerManager::m_bOngoingTransaction: Incorrect offset");
static_assert(offsetof(ContainerManager, ContainerManager::m_worldContainerMap) == 0x40, "ContainerManager::m_worldContainerMap: Incorrect offset");

static_assert(sizeof(ContainerManager) == 0x98, "ContainerManager: Incorrect Size");

SMSDK_END_NAMESPACE