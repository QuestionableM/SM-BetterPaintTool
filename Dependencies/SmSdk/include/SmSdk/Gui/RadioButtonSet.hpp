#pragma once

#include "SmSdk/Util/Memory.hpp"

#include "SmSdk/mygui_include.hpp"
#include "SmSdk/offsets.hpp"

#include <functional>
#include <vector>

SMSDK_BEGIN_NAMESPACE

class RadioButtonSet
{
	SDK_PUB RadioButtonSet(const std::vector<MyGUI::Button*>& buttons)
	{
		using fSelfConstructor = void (*)(RadioButtonSet*, const std::function<void(MyGUI::Widget*)>&, const std::vector<MyGUI::Button*>&);

		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_RADIO_BUTTON_SET_OFFSET)(
		    this, [](MyGUI::Widget*) -> void {}, buttons);
	}

	/* 0x0000 */ SDK_PRI char pad_0x0[0x60];
}; // Size: 0x60

static_assert(sizeof(RadioButtonSet) == 0x60, "RadioButtonSet: Incorrect Size");

SMSDK_END_NAMESPACE