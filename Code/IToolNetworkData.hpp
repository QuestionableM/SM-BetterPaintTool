#pragma once

class IToolNetworkData
{
public:
	virtual ~IToolNetworkData() = default;

private:
	/* 0x0008 */ char pad_0x8[0x8];
}; // Size: 0x10

static_assert(sizeof(IToolNetworkData) == 0x10, "IToolNetworkData: Incorrect Size");