#pragma once

#include "SmSdk/Tool/IToolNetworkData.hpp"
#include "SmSdk/Tool/IToolImpl.hpp"

#include "SmSdk/Base/NetObj.hpp"

SMSDK_BEGIN_NAMESPACE

class Tool : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
	/* 0x0030 */ SDK_PUB char uuid[16];
	/* 0x0040 */ SDK_PUB std::int32_t m_iOwnerId;
	/* 0x0044 */ SDK_PRI char pad_0x44[0x4];
	/* 0x0048 */ SDK_PUB std::shared_ptr<IToolImpl> m_pImplementation;
	/* 0x0058 */ SDK_PUB IToolNetworkData* m_pNetworkData;
	/* 0x0060 */ SDK_PUB bool m_bMovementSlowDown;
	/* 0x0061 */ SDK_PRI char pad_0x61[0xF];
}; // Size: 0x70

static_assert(sizeof(Tool) == 0x70, "Tool: Incorrect Size");

SMSDK_END_NAMESPACE