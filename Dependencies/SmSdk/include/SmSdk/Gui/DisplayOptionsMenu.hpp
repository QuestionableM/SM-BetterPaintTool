#pragma once

#include "SmSdk/Gui/OptionsSubMenuBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

SMSDK_BEGIN_NAMESPACE

class DisplayOptionsMenu : public OptionsSubMenuBase
{
	SDK_PUB DisplayOptionsMenu()
	{
		using fSelfConstructor = void (*)(DisplayOptionsMenu*);
		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET)(this);
	}

	SDK_PUB virtual ~DisplayOptionsMenu() = default;
	SDK_PUB void restoreDefaults() override { /* implemented by the game */ }

	/* 0x0168 */ SDK_PRI char pad_0x168[0xD0];
}; // Size: 0x238

static_assert(sizeof(DisplayOptionsMenu) == 0x238, "DisplayOptionsMenu: Incorrect Size");

SMSDK_END_NAMESPACE