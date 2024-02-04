#pragma once

#include "InventoryGui.hpp"

class InGameGuiManager
{
public:
	static InGameGuiManager* GetInstance();

private:
	/* 0x0000 */ char pad_0x0[0x30];
public:
	/* 0x0030 */ std::shared_ptr<InventoryGui> m_pInventory;
private:
	/* 0x0040 */ char pad_0x40[0x18];
	/* 0x0058 */ char pad_0x58[0x198];
}; // Size: 0x1F0

static_assert(sizeof(InGameGuiManager) == 0x1F0, "InGameGuiManager: Incorrect Size");