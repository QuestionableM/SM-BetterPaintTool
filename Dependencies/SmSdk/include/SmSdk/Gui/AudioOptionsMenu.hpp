#pragma once

#include "SmSdk/Gui/OptionsSubMenuBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

SMSDK_BEGIN_NAMESPACE

class AudioOptionsMenu : public OptionsSubMenuBase
{
	SDK_PUB AudioOptionsMenu()
	{
		OptionsSubMenuBase::GameConstructor(this);
		Memory::OverwriteVftable(this, SM_VTBL_AUDIO_OPTIONS_MENU_OFFSET);
	}

	SDK_PUB virtual ~AudioOptionsMenu() = default;
	SDK_PUB void restoreDefaults() override { /* implemented by the game */ }
}; // Size: 0x168

static_assert(sizeof(AudioOptionsMenu) == 0x168, "AudioOptionsMenu: Incorrect Size");

SMSDK_END_NAMESPACE