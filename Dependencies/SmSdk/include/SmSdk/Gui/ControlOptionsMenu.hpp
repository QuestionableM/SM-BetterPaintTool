#pragma once

#include "SmSdk/Gui/OptionsSubMenuBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

SMSDK_BEGIN_NAMESPACE

class ControlOptionsMenu : public OptionsSubMenuBase
{
	SDK_PUB ControlOptionsMenu()
	{
		using fSelfConstructor = void (*)(ControlOptionsMenu*);
		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET)(this);
	}

	SDK_PUB virtual ~ControlOptionsMenu() = default;
	SDK_PUB void restoreDefaults() override { /* implemented by the game */ }
	/* 0x0168 */ SDK_PRI char pad_0x168[0x20];
}; // Size: 0x188

static_assert(sizeof(ControlOptionsMenu) == 0x188, "ControlOptionsMenu: Incorrect Size");

SMSDK_END_NAMESPACE