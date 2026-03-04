#pragma once

#include "SmSdk/steamapi_include.hpp"
#include "SmSdk/config.hpp"

#include <unordered_map>

SMSDK_BEGIN_NAMESPACE

struct NetworkSendInterface
{
	/* 0x0000 */ SDK_PRI virtual void func1() {}

	/* 0x0008 */ SDK_PRI char pad_0x8[0x10];
	/* 0x0018 */ SDK_PUB std::int64_t m_iTick;
	/* 0x0020 */ SDK_PUB std::int64_t m_iTick2;
}; // Size: 0x28

static_assert(sizeof(NetworkSendInterface) == 0x28, "NetworkSendInterface: Incorrect Size");

struct SteamNetworkSend : public NetworkSendInterface
{
	HSteamNetConnection getConnectionFromSteamId(const std::uint64_t uSteamId) const
	{
		auto iter = m_mapSteamIdToConnection.find(uSteamId);
		if (iter == m_mapSteamIdToConnection.end())
			return 0;

		return iter->second;
	}

	/* 0x0028 */ SDK_PUB std::unordered_map<std::uint64_t, HSteamNetConnection> m_mapSteamIdToConnection;
	/* 0x0068 */ SDK_PRI char pad_0x68[0xC0];
}; // Size: 0x128

static_assert(sizeof(SteamNetworkSend) == 0x128, "SteamNetworkSend: Incorrect Size");

SMSDK_END_NAMESPACE