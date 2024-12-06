#pragma once

#include "SteamNetworkSend.hpp"

#include <memory>

struct NetworkServer
{
	virtual void func1() {}

	/* 0x0008 */ std::shared_ptr<SteamNetworkSend> network_send;
	/* 0x0018 */ std::shared_ptr<struct ClientCommunication> client_communication;
	/* 0x0028 */ char pad_0x28[0x8];

}; // Size: 0x30

static_assert(sizeof(NetworkServer) == 0x30, "NetworkServer: Incorrect Size");