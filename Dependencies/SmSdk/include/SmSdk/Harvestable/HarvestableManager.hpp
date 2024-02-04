#pragma once

#include "SmSdk/config.hpp"
#include "Harvestable.hpp"

#include <unordered_map>
#include <memory>

class HarvestableManager
{
	REMOVE_COPY_CONSTRUCTORS(HarvestableManager);

public:
	virtual ~HarvestableManager() = default;

	static HarvestableManager* GetInstance();

	inline Harvestable* _getHarvestable(int hvs_idx)
	{
		auto v_iter = this->hvs_map.find(hvs_idx);
		if (v_iter == this->hvs_map.end())
			return nullptr;

		return v_iter->second.get();
	}

	inline static Harvestable* GetHarvestable(int hvs_idx)
	{
		HarvestableManager* v_pHvsMgr = HarvestableManager::GetInstance();
		if (!v_pHvsMgr) return nullptr;

		return v_pHvsMgr->_getHarvestable(hvs_idx);
	}

private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ std::unordered_map<int, std::shared_ptr<Harvestable>> hvs_map;
private:
	/* 0x0050 */ char pad_0x50[0x50];
public:
	/* 0x00A0 */ std::unordered_map<int, struct HarvestableCollision> hvs_collision_data;
	/* 0x00E0 */ std::unordered_map<boost::uuids::uuid, std::shared_ptr<struct HarvestableData>> hvs_data_map;
	/* 0x0120 */ std::shared_ptr<struct HarvestableData> hvs_data;
private:
	/* 0x0130 */ char pad_0x130[0x70];

}; // Size: 0x1A0

static_assert(sizeof(HarvestableManager) == 0x1A0, "HarvestableManager: Incorrect Size");