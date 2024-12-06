#pragma once

#include "SteamNetworkSend.hpp"
#include "NetworkClient.hpp"

struct SteamNetworkClient : public NetworkClient
{
	/* 0x0130 */ char pad_0x130[0x8];
	/* 0x0138 */ __int64 host_steam_id;
	/* 0x0140 */ char pad_0x140[0x78];
	/* 0x01B8 */ HSteamNetConnection host_connection;
	/* 0x01BC */ char pad_0x1BC[0x2C];
	/* 0x01E8 */ std::string passphrase;
	/* 0x0208 */ char pad_0x208[0x28];
}; // Size: 0x230

static_assert(sizeof(SteamNetworkClient) == 0x230, "SteamNetworkClient: Incorrect Size");