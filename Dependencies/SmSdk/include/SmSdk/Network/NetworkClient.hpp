#pragma once

#include "SmSdk/steamapi_include.hpp"

#include <unordered_map>
#include <memory>
#include <string>

SMSDK_BEGIN_NAMESPACE

class NetworkClient
{
	SDK_PUB HSteamNetConnection getConnectionFromSteamId(const std::uint64_t steamId) const
	{
		if (m_pNetworkSend == nullptr)
			return 0;

		return m_pNetworkSend->getConnectionFromSteamId(steamId);
	}

	/* 0x0000 */ SDK_PRI char pad_0x0[0x8];
	/* 0x0008 */ SDK_PUB std::shared_ptr<SteamNetworkSend> m_pNetworkSend;
	/* 0x0018 */ SDK_PUB std::int32_t m_iConnectionState;
	/* 0x001C */ SDK_PRI char pad_0x1C[0x2C];
	/* 0x0048 */ SDK_PRI std::string m_someString1;
	/* 0x0068 */ SDK_PRI char pad_0x68[0x80];
	/* 0x00E8 */ SDK_PUB std::shared_ptr<struct TickLag> m_pTickLag;
	/* 0x00F8 */ SDK_PRI char pad_0xF8[0x38];
}; // Size: 0x130

static_assert(sizeof(NetworkClient) == 0x130, "NetworkClient: Incorrect Size");

SMSDK_END_NAMESPACE