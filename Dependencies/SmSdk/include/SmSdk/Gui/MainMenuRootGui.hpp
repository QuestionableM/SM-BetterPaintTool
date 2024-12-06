#pragma once

#include "CompoundButton.hpp"
#include "GuiBase.hpp"

class MainMenuRootGui : public GuiBase
{
private:
	/* 0x0018 */ char pad_0x18[0x8];
public:
	/* 0x0020 */ struct MenuState* menu_state;
private:
	/* 0x0028 */ char pad_0x28[0x10];
public:
	/* 0x0038 */ std::vector<std::shared_ptr<CompoundButton>> compound_buttons;
	/* 0x0050 */ std::vector<GuiBase*> guis;
	/* 0x0068 */ GuiBase* current_gui_element;
	/* 0x0070 */ struct ChooseGameModeMenu* choose_game_mode_menu;
	/* 0x0078 */ struct CreativeModeMenu* creative_mode_menu;
	/* 0x0080 */ struct SurvivalModeMenu* survival_mode_menu;
	/* 0x0088 */ struct ChallengeModeMenu* challenge_mode_menu;
	/* 0x0090 */ struct CustomGameModeMenu* custom_game_mode_menu;
	/* 0x0098 */ struct CharacterCustomizationMenu* character_customization_menu;
	/* 0x00A0 */ class OptionsMenu* options_menu;

}; // Size: 0xA8

static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::menu_state) == 0x20, "MainMenuRootGui::menu_state: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::compound_buttons) == 0x38, "MainMenuRootGui::compound_buttons: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::guis) == 0x50, "MainMenuRootGui::guis: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::current_gui_element) == 0x68, "MainMenuRootGui::current_gui_element: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::choose_game_mode_menu) == 0x70, "MainMenuRootGui::choose_game_mode_menu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::creative_mode_menu) == 0x78, "MainMenuRootGui::creative_mode_menu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::survival_mode_menu) == 0x80, "MainMenuRootGui::survival_mode_menu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::challenge_mode_menu) == 0x88, "MainMenuRootGui::challenge_mode_menu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::custom_game_mode_menu) == 0x90, "MainMenuRootGui::custom_game_mode_menu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::character_customization_menu) == 0x98, "MainMenuRootGui::character_customization_menu: Incorrect offset");
static_assert(offsetof(MainMenuRootGui, MainMenuRootGui::options_menu) == 0xA0, "MainMenuRootGui::options_menu: Incorrect offset");

static_assert(sizeof(MainMenuRootGui) == 0xA8, "MainMenuRootGui: Incorrect Size");