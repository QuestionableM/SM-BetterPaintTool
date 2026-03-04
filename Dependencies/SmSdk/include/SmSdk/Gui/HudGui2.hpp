#pragma once

#include "SmSdk/Gui/GuiBase.hpp"

#include <vector>
#include <string>

SMSDK_BEGIN_NAMESPACE

class HudGui2 : public GuiBase
{
	/* 0x0018 */ SDK_PRI char pad_0x18[0x80];
	/* 0x0098 */ SDK_PUB std::vector<std::vector<std::string>> m_vecInteractionTexts;
	/* 0x00B0 */ SDK_PRI char pad_0xB0[0x24];
	/* 0x00D4 */ SDK_PUB float m_fAlertTextTimer;
	/* 0x00D8 */ SDK_PUB std::string m_alertText;
	/* 0x00F8 */ SDK_PRI char pad_0xF8[0x30];
}; // Size: 0x128

static_assert(sizeof(HudGui2) == 0x128, "HudGui2: Incorrect Size");

SMSDK_END_NAMESPACE