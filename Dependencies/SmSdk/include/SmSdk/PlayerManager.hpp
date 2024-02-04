#pragma once

#include "Player.hpp"

#include <unordered_map>
#include <memory>

class PlayerManager
{
public:
	static PlayerManager* GetInstance();

	inline Player* _getPlayer(int player_id)
	{
		auto v_iter = id_to_player_map.find(player_id);
		if (v_iter == id_to_player_map.end())
			return nullptr;

		return v_iter->second.get();
	}

	inline Player* _getPlayerFromSteamId(std::uint64_t steam_id)
	{
		auto v_iter = steamid_to_playerid_map.find(steam_id);
		if (v_iter == steamid_to_playerid_map.end())
			return nullptr;

		return this->_getPlayer(v_iter->second);
	}

	inline static Player* GetPlayer(int player_id)
	{
		PlayerManager* v_pPlMgr = PlayerManager::GetInstance();
		if (!v_pPlMgr) return nullptr;

		return v_pPlMgr->_getPlayer(player_id);
	}

	inline static Player* GetPlayerFromSteamId(std::uint64_t steam_id)
	{
		PlayerManager* v_pPlMgr = PlayerManager::GetInstance();
		if (!v_pPlMgr) return nullptr;

		return v_pPlMgr->_getPlayerFromSteamId(steam_id);
	}

	/* 0x0000 */ __int32 tick;
	/* 0x0004 */ char pad_0x4[0x4];
	/* 0x0008 */ std::unordered_map<int, std::shared_ptr<Player>> id_to_player_map;
	/* 0x0048 */ std::unordered_map<std::uint64_t, int> steamid_to_playerid_map;
	/* 0x0088 */ char pad_0x88[0xC0];

}; // Size: 0x148

static_assert(sizeof(PlayerManager) == 0x148, "PlayerManager: Incorrect Size");