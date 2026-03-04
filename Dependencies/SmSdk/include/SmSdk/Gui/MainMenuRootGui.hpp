#pragma once

#include "SmSdk/Gui/CompoundButton.hpp"
#include "SmSdk/Gui/GuiBase.hpp"

SMSDK_BEGIN_NAMESPACE

class MainMenuRootGui : public GuiBase
{
	/* 0x0018 */ SDK_PRI char pad_0x18[0x8];
	/* 0x0020 */ SDK_PUB struct MenuState* m_pMenuState;
	/* 0x0028 */ SDK_PRI char pad_0x28[0x10];
	/* 0x0038 */ SDK_PUB std::vector<std::shared_ptr<CompoundButton>> m_vecCompoundButtons;
	/* 0x0050 */ SDK_PUB std::vector<GuiBase*> m_vecGuis;
	/* 0x0068 */ SDK_PUB GuiBase* m_pCurrentGuiElement;
	/* 0x0070 */ SDK_PUB struct ChooseGameModeMenu* m_pChooseGameModeMenu;
	/* 0x0078 */ SDK_PUB struct CreativeModeMenu* m_pCreativeModeMenu;
	/* 0x0080 */ SDK_PUB struct SurvivalModeMenu* m_pSurvivalModeMenu;
	/* 0x0088 */ SDK_PUB struct ChallengeModeMenu* m_pChallengeModeMenu;
	/* 0x0090 */ SDK_PUB struct CustomGameModeMenu* m_pCustomGameModeMenu;
	/* 0x0098 */ SDK_PUB struct CharacterCustomizationMenu* m_pCharacterCustomizationMenu;
	/* 0x00A0 */ SDK_PUB class OptionsMenu* m_pOptionsMenu;
}; // Size: 0xA8

static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pMenuState) == 0x20, "MainMenuRootGui::m_pMenuState: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_vecCompoundButtons) == 0x38, "MainMenuRootGui::m_vecCompoundButtons: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_vecGuis) == 0x50, "MainMenuRootGui::m_vecGuis: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pCurrentGuiElement) == 0x68, "MainMenuRootGui::m_pCurrentGuiElement: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pChooseGameModeMenu) == 0x70, "MainMenuRootGui::m_pChooseGameModeMenu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pCreativeModeMenu) == 0x78, "MainMenuRootGui::m_pCreativeModeMenu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pSurvivalModeMenu) == 0x80, "MainMenuRootGui::m_pSurvivalModeMenu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pChallengeModeMenu) == 0x88, "MainMenuRootGui::m_pChallengeModeMenu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pCustomGameModeMenu) == 0x90, "MainMenuRootGui::m_pCustomGameModeMenu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pCharacterCustomizationMenu) == 0x98, "MainMenuRootGui::m_pCharacterCustomizationMenu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::m_pOptionsMenu) == 0xA0, "MainMenuRootGui::m_pOptionsMenu: Incorrect offset");

static_assert(sizeof(MainMenuRootGui) == 0xA8, "MainMenuRootGui: Incorrect Size");

SMSDK_END_NAMESPACE