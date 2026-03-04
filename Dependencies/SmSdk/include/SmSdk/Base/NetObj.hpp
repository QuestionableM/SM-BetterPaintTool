#pragma once

#include "SmSdk/config.hpp"

#include <memory>

SMSDK_BEGIN_NAMESPACE

class NetObj
{
	SDK_PUB virtual ~NetObj() = default;
	SDK_PRI virtual void func2() {}
	SDK_PUB virtual char getObjectType() { return 0; }
	SDK_PUB virtual void updateObject() {}

	/* 0x0008 */ SDK_PRI char pad_0x8[0x8];
	/* 0x0010 */ SDK_PUB std::shared_ptr<NetObj> m_pSelf;
	/* 0x0020 */ SDK_PUB std::int32_t m_iId;
	/* 0x0024 */ SDK_PUB std::int32_t m_iRevision;
}; // Size: 0x28

static_assert(sizeof(NetObj) == 0x28, "NetObj: Incorrect Size");

SMSDK_END_NAMESPACE