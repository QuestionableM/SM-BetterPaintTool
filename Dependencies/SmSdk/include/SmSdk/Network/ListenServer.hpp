#pragma once

#include "SteamNetworkServer.hpp"
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

struct ListenServer
{
	/* 0x0000 */ SDK_PUB SteamNetworkServer* m_pNetworkServer;
	/* 0x0008 */ SDK_PRI char pad_0x8[0x1B8];
}; // Size: 0x1C0

static_assert(sizeof(ListenServer) == 0x1C0, "ListenServer: Incorrect Size");

SMSDK_END_NAMESPACE