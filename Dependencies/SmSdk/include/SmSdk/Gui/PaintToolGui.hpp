#pragma once

#include "GuiBase.hpp"

class PaintToolGui : public GuiBase
{
public:
	/* 0x0018 */ MyGUI::ItemBox* m_pItemBox;

}; // Size: 0x20

static_assert(sizeof(PaintToolGui) == 0x20, "PaintToolGui: Incorrect Size");