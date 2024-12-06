#pragma once

#include "SmSdk/mygui_include.hpp"
#include "GuiBase.hpp"

struct InventoryGui : public GuiBase
{
private:
	/* 0x0018 */ char pad_0x18[0x7B0];
public:
	/* 0x07C8 */ MyGUI::IntCoord pos;
private:
	/* 0x07D8 */ char pad_0x7D8[0x20];
}; // Size: 0x7F8

static_assert(sizeof(InventoryGui) == 0x7F8, "InventoryGui: Incorrect Size");