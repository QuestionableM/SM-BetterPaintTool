#pragma once

#include "SmSdk/config.hpp"
#include "SmSdk/Harvestable/Harvestable.hpp"

#include <unordered_map>
#include <memory>

SMSDK_BEGIN_NAMESPACE

class HarvestableManager
{
	REMOVE_COPY_CONSTRUCTORS(HarvestableManager);

	SDK_PUB virtual ~HarvestableManager() = default;

	SDK_PUB static HarvestableManager* GetInstance();

	SDK_PUB inline Harvestable* _getHarvestable(const std::uint32_t uHvsIdx)
	{
		auto iter = m_mapHarvestables.find(uHvsIdx);
		if (iter == m_mapHarvestables.end())
			return nullptr;

		return iter->second.get();
	}

	SDK_PUB inline static Harvestable* GetHarvestable(const std::uint32_t uHvsIdx)
	{
		HarvestableManager* pHarvestableManager = HarvestableManager::GetInstance();
		if (!pHarvestableManager)
			return nullptr;

		return pHarvestableManager->_getHarvestable(uHvsIdx);
	}

	/* 0x0008 */ SDK_PRI char pad_0x8[0x8];
	/* 0x0010 */ SDK_PUB std::unordered_map<std::uint32_t, std::shared_ptr<Harvestable>> m_mapHarvestables;
	/* 0x0050 */ SDK_PRI char pad_0x50[0x50];
	/* 0x00A0 */ SDK_PUB std::unordered_map<std::uint32_t, struct HarvestableCollision> m_mapHarvestableCollisions;
	/* 0x00E0 */ SDK_PUB std::unordered_map<boost::uuids::uuid, std::shared_ptr<struct HarvestableData>> m_mapHarvestableData;
	/* 0x0120 */ SDK_PUB std::shared_ptr<struct HarvestableData> m_pHarvestableData;
	/* 0x0130 */ SDK_PRI char pad_0x130[0x70];
}; // Size: 0x1A0

static_assert(sizeof(HarvestableManager) == 0x1A0, "HarvestableManager: Incorrect Size");

SMSDK_END_NAMESPACE