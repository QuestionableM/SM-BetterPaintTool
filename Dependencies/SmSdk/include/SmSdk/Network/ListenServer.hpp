#pragma once

#include "SteamNetworkServer.hpp"

struct ListenServer
{
	/* 0x0000 */ SteamNetworkServer* network_server;
	/* 0x0008 */ char pad_0x8[0x1B8];
}; // Size: 0x1C0

static_assert(sizeof(ListenServer) == 0x1C0, "ListenServer: Incorrect Size");