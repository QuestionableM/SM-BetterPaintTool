#pragma once

#include "GuiBase.hpp"

#include <vector>
#include <string>

class HudGui2 : public GuiBase
{
private:
	/* 0x0018 */ char pad_0x18[0x80];
public:
	/* 0x0098 */ std::vector<std::vector<std::string>> m_vecInteractionTexts;
private:
	/* 0x00B0 */ char pad_0xB0[0x24];
public:
	/* 0x00D4 */ float m_alertTextTimer;
	/* 0x00D8 */ std::string m_alertText;
private:
	/* 0x00F8 */ char pad_0xF8[0x30];

}; // Size: 0x128

static_assert(sizeof(HudGui2) == 0x128, "HudGui2: Incorrect Size");