#pragma once

#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

class IToolNetworkData
{
	SDK_PUB virtual ~IToolNetworkData() = default;

	/* 0x0008 */ SDK_PUB bool m_bDataChanged;
}; // Size: 0x10

static_assert(offsetof(IToolNetworkData, IToolNetworkData::m_bDataChanged) == 0x8, "IToolNetworkData::m_bDataChanged: Incorrect offset");
static_assert(sizeof(IToolNetworkData) == 0x10, "IToolNetworkData: Incorrect Size");

SMSDK_END_NAMESPACE