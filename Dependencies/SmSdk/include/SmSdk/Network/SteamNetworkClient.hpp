#pragma once

#include "SmSdk/Network/SteamNetworkSend.hpp"
#include "SmSdk/Network/NetworkClient.hpp"
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

struct SteamNetworkClient : public NetworkClient
{
	/* 0x0130 */ SDK_PRI char pad_0x130[0x8];
	/* 0x0138 */ SDK_PUB std::int64_t m_iHostSteamId;
	/* 0x0140 */ SDK_PRI char pad_0x140[0x78];
	/* 0x01B8 */ SDK_PUB HSteamNetConnection m_hostConnection;
	/* 0x01BC */ SDK_PRI char pad_0x1BC[0x2C];
	/* 0x01E8 */ SDK_PUB std::string m_passphrase;
	/* 0x0208 */ SDK_PRI char pad_0x208[0x28];
}; // Size: 0x230

static_assert(sizeof(SteamNetworkClient) == 0x230, "SteamNetworkClient: Incorrect Size");

SMSDK_END_NAMESPACE