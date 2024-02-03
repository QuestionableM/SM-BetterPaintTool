#pragma once

#include "GuiInterface.hpp"
#include "MyGUI.h"

class GuiBase
{
public:
	virtual ~GuiBase() = default;

	/* 0x0008 */ MyGUI::Widget* m_pWidget;
	/* 0x0010 */ GuiInterface* m_pGuiInterface;

}; // Size: 0x18