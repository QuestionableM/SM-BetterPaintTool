#pragma once

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

#include <MyGUI.h>

#include <functional>
#include <vector>

class RadioButtonSet
{
public:
	RadioButtonSet(const std::vector<MyGUI::Button*>& buttons)
	{
		using fSelfConstructor = void (*)(RadioButtonSet*,
			const std::function<void(MyGUI::Widget*)>&, const std::vector<MyGUI::Button*>&);

		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_RADIO_BUTTON_SET_OFFSET)(
			this, [](MyGUI::Widget*) -> void {}, buttons);
	}

private:
	/* 0x0000 */ char pad_0x0[0x60];
}; // Size: 0x60

static_assert(sizeof(RadioButtonSet) == 0x60, "RadioButtonSet: Incorrect Size");