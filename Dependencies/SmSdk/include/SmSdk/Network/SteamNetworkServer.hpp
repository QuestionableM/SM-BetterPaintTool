#pragma once

#include "NetworkServer.hpp"

struct SteamNetworkServer : public NetworkServer
{
	/* 0x0030 */ char pad_0x30[0xF8];
}; // Size: 0x128

static_assert(sizeof(SteamNetworkServer) == 0x128, "SteamNetworkServer: Incorrect Size");