#pragma once

#include "SmSdk/steamapi_include.hpp"

#include <unordered_map>
#include <memory>
#include <string>

struct NetworkClient
{
	/* 0x0000 */ char pad_0x0[0x8];
	/* 0x0008 */ std::shared_ptr<SteamNetworkSend> network_send;
	/* 0x0018 */ __int32 connection_state;
	/* 0x001C */ char pad_0x1C[0x2C];
	/* 0x0048 */ std::string some_string1;
	/* 0x0068 */ char pad_0x68[0x80];
	/* 0x00E8 */ std::shared_ptr<struct TickLag> tick_lag;
	/* 0x00F8 */ char pad_0xF8[0x38];

	HSteamNetConnection getConnectionFromSteamId(std::uint64_t steam_id) const
	{
		if (this->network_send == nullptr)
			return 0;

		return this->network_send->getConnectionFromSteamId(steam_id);
	}

}; // Size: 0x130

static_assert(sizeof(NetworkClient) == 0x130, "NetworkClient: Incorrect Size");