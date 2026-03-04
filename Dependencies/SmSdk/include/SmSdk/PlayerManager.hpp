#pragma once

#include "SmSdk/Player.hpp"

#include <unordered_map>
#include <memory>

SMSDK_BEGIN_NAMESPACE

class PlayerManager
{
	SDK_PUB static PlayerManager* GetInstance();

	SDK_PUB inline Player* _getPlayer(int player_id)
	{
		auto iter = m_mapIdToPlayers.find(player_id);
		if (iter == m_mapIdToPlayers.end())
			return nullptr;

		return iter->second.get();
	}

	SDK_PUB inline Player* _getPlayerFromSteamId(uint64_t steam_id)
	{
		auto iter = m_mapSteamIdToPlayer.find(steam_id);
		if (iter == m_mapSteamIdToPlayer.end())
			return nullptr;

		return this->_getPlayer(iter->second);
	}

	SDK_PUB inline static Player* GetPlayer(int player_id)
	{
		PlayerManager* pPlayerMgr = PlayerManager::GetInstance();
		if (!pPlayerMgr)
			return nullptr;

		return pPlayerMgr->_getPlayer(player_id);
	}

	SDK_PUB inline static Player* GetPlayerFromSteamId(uint64_t steam_id)
	{
		PlayerManager* pPlayerMgr = PlayerManager::GetInstance();
		if (!pPlayerMgr)
			return nullptr;

		return pPlayerMgr->_getPlayerFromSteamId(steam_id);
	}

	/* 0x0000 */ SDK_PUB std::int32_t m_iTick;
	/* 0x0004 */ SDK_PRI char pad_0x4[0x4];
	/* 0x0008 */ SDK_PUB std::unordered_map<int, std::shared_ptr<Player>> m_mapIdToPlayers;
	/* 0x0048 */ SDK_PUB std::unordered_map<uint64_t, int> m_mapSteamIdToPlayer;
	/* 0x0088 */ SDK_PRI char pad_0x88[0xC0];
}; // Size: 0x148

static_assert(sizeof(PlayerManager) == 0x148, "PlayerManager: Incorrect Size");

SMSDK_END_NAMESPACE