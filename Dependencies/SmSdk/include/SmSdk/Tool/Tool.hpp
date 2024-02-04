#pragma once

#include "SmSdk/Tool/IToolNetworkData.hpp"
#include "SmSdk/Tool/IToolImpl.hpp"

#include "SmSdk/Base/NetObj.hpp"

class Tool : public NetObj
{
public:
	/* 0x0028 */ char pad_0x28[0x8];
	/* 0x0030 */ char uuid[16];
	/* 0x0040 */ __int32 owner_id;
	/* 0x0044 */ char pad_0x44[0x4];
	/* 0x0048 */ std::shared_ptr<IToolImpl> implementation;
	/* 0x0058 */ IToolNetworkData* network_data;
	/* 0x0060 */ bool movement_slow_down;
	/* 0x0061 */ char pad_0x61[0xF];

}; // Size: 0x70

static_assert(sizeof(Tool) == 0x70, "Tool: Incorrect Size");