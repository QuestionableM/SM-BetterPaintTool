#pragma once

#include "OptionsSubMenuBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

class AudioOptionsMenu : public OptionsSubMenuBase
{
public:
	AudioOptionsMenu()
	{
		OptionsSubMenuBase::GameConstructor(this);
		Memory::OverwriteVftable(this, SM_VTBL_AUDIO_OPTIONS_MENU_OFFSET);
	}

	virtual ~AudioOptionsMenu() = default;
	void restoreDefaults() override { /* implemented by the game */ }

}; // Size: 0x168

static_assert(sizeof(AudioOptionsMenu) == 0x168, "AudioOptionsMenu: Incorrect Size");