#pragma once

#include "SmSdk/Network/SteamNetworkSend.hpp"
#include "SmSdk/config.hpp"

#include <memory>

SMSDK_BEGIN_NAMESPACE

struct NetworkServer
{
	/* 0x0000 */ SDK_PRI virtual void func1() {}
	/* 0x0008 */ SDK_PUB std::shared_ptr<SteamNetworkSend> m_pNetworkSend;
	/* 0x0018 */ SDK_PUB std::shared_ptr<struct ClientCommunication> m_pClientCommunication;
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
}; // Size: 0x30

static_assert(sizeof(NetworkServer) == 0x30, "NetworkServer: Incorrect Size");

SMSDK_END_NAMESPACE