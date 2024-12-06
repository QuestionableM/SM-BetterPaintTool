#include <SmSdk/Util/Memory.hpp>
#include <SmSdk/offsets.hpp>

#include "OptionsSubMenuBase.hpp"

class GameplayOptionsMenu : public OptionsSubMenuBase
{
public:
	GameplayOptionsMenu()
	{
		OptionsSubMenuBase::GameConstructor(this);
	#if defined(_SM_VERSION_070_771)
		std::memset(this->someData, 0, sizeof(this->someData));
	#endif
		Memory::OverwriteVftable(this, SM_VTBL_GAMEPLAY_OPTIONS_MENU_OFFSET);
	}

	virtual ~GameplayOptionsMenu() = default;
	void restoreDefaults() override { /* implemented by the game */ }

#if defined(_SM_VERSION_070_771)
	char someData[16];
#endif

}; // Size: 0x168

static_assert(sizeof(GameplayOptionsMenu) == 0x168, "GameplayOptionsMenu: Incorrect Size");