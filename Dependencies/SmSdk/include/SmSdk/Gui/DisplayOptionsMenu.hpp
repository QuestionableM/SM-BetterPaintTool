#pragma once

#include "OptionsSubMenuBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

class DisplayOptionsMenu : public OptionsSubMenuBase
{
public:
	DisplayOptionsMenu()
	{
		using fSelfConstructor = void(*)(DisplayOptionsMenu*);
		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_DISPLAY_OPTIONS_MENU_OFFSET)(this);
	}

	virtual ~DisplayOptionsMenu() = default;
	void restoreDefaults() override { /* implemented by the game */ }

private:
	/* 0x0168 */ char pad_0x168[0xD0];
}; // Size: 0x238

static_assert(sizeof(DisplayOptionsMenu) == 0x238, "DisplayOptionsMenu: Incorrect Size");