#pragma once

#include "SmSdk/mygui_include.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

SMSDK_BEGIN_NAMESPACE

class CompoundButton
{
	SDK_PUB CompoundButton(MyGUI::Widget* parent)
	{
		using fSelfConstructor = void (*)(CompoundButton*, MyGUI::Widget*);
		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_COMPOUND_BUTTON_OFFSET)(this, parent);
	}

	/* 0x0000 */ SDK_PUB MyGUI::Widget* m_pBaseWidget;
	/* 0x0008 */ SDK_PUB MyGUI::Button* m_pButton;
}; // Size: 0x10

static_assert(offsetof(CompoundButton, CompoundButton::m_pBaseWidget) == 0x0, "CompoundButton::m_pBaseWidget: Incorrect offset");
static_assert(offsetof(CompoundButton, CompoundButton::m_pButton) == 0x8, "CompoundButton::m_pButton: Incorrect offset");
static_assert(sizeof(CompoundButton) == 0x10, "CompoundButton: Incorrect Size");

SMSDK_END_NAMESPACE