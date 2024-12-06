#pragma once

#include "OptionsSubMenuBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

class ControlOptionsMenu : public OptionsSubMenuBase
{
public:
	ControlOptionsMenu()
	{
		using fSelfConstructor = void (*)(ControlOptionsMenu*);
		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_CONTROL_OPTIONS_MENU_OFFSET)(this);
	}

	virtual ~ControlOptionsMenu() = default;
	void restoreDefaults() override { /* implemented by the game */ }

private:
	/* 0x0168 */ char pad_0x168[0x20];
}; // Size: 0x188

static_assert(sizeof(ControlOptionsMenu) == 0x188, "ControlOptionsMenu: Incorrect Size");