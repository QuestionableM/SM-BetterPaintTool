#pragma once

#include "SmSdk/mygui_include.hpp"
#include "SmSdk/Gui/GuiBase.hpp"

SMSDK_BEGIN_NAMESPACE

struct InventoryGui : public GuiBase
{
	/* 0x0018 */ SDK_PRI char pad_0x18[0x7B0];
	/* 0x07C8 */ SDK_PUB MyGUI::IntCoord m_pos;
	/* 0x07D8 */ SDK_PRI char pad_0x7D8[0x20];
}; // Size: 0x7F8

static_assert(sizeof(InventoryGui) == 0x7F8, "InventoryGui: Incorrect Size");

SMSDK_END_NAMESPACE