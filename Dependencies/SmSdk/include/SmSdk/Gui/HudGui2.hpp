#pragma once

#include "GuiBase.hpp"
#include <string>

struct HudGui2 : public GuiBase
{
private:
	/* 0x0018 */ char pad_0x18[0xBC];
public:
	/* 0x00D4 */ float m_alertTextTimer;
	/* 0x00D8 */ std::string m_alertText;
private:
	/* 0x00F8 */ char pad_0xF8[0x30];
}; // Size: 0x128

static_assert(sizeof(HudGui2) == 0x128, "HudGui2: Incorrect Size");