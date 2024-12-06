#pragma once

#include "SmSdk/steamapi_include.hpp"
#include <unordered_map>

struct NetworkSendInterface
{
	virtual void func1() {}

	/* 0x0008 */ char pad_0x8[0x10];
	/* 0x0018 */ __int64 tick;
	/* 0x0020 */ __int64 tick2;
}; // Size: 0x28

static_assert(sizeof(NetworkSendInterface) == 0x28, "NetworkSendInterface: Incorrect Size");

struct SteamNetworkSend : public NetworkSendInterface
{
	/* 0x0028 */ std::unordered_map<uint64_t, HSteamNetConnection> steam_id_to_connection;
	/* 0x0068 */ char pad_0x68[0xC0];

	HSteamNetConnection getConnectionFromSteamId(std::uint64_t steam_id) const
	{
		auto v_iter = this->steam_id_to_connection.find(steam_id);
		if (v_iter == this->steam_id_to_connection.end())
			return 0;

		return v_iter->second;
	}

}; // Size: 0x128

static_assert(sizeof(SteamNetworkSend) == 0x128, "SteamNetworkSend: Incorrect Size");