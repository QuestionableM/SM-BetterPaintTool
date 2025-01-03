#pragma once

class IToolNetworkData
{
public:
	virtual ~IToolNetworkData() = default;

	/* 0x0008 */ bool m_bDataChanged;

}; // Size: 0x10

static_assert(offsetof(IToolNetworkData, IToolNetworkData::m_bDataChanged) == 0x8, "IToolNetworkData::m_bDataChanged: Incorrect offset");
static_assert(sizeof(IToolNetworkData) == 0x10, "IToolNetworkData: Incorrect Size");