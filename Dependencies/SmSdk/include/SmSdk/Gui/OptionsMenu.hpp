#pragma once

#include "OptionsSubMenuBase.hpp"
#include "CompoundButton.hpp"
#include "RadioButtonSet.hpp"
#include "GuiBase.hpp"

class OptionsMenu : public GuiBase
{
public:
	/* 0x0018 */ class MainMenuRootGui* m_pMenuRootGui;
	/* 0x0020 */ bool m_bSomeFlag;
	/* 0x0021 */ bool is_server;
private:
	/* 0x0022 */ char pad_0x22[0x6];
public:
	/* 0x0028 */ std::shared_ptr<CompoundButton> compound_button;
	/* 0x0038 */ std::shared_ptr<RadioButtonSet> radio_btn_set;
	/* 0x0048 */ std::shared_ptr<OptionsSubMenuBase> m_currentTab;
	/* 0x0058 */ std::map<std::string, std::shared_ptr<OptionsSubMenuBase>> m_mapSubMenus;
}; // Size: 0x68

static_assert(offsetof(OptionsMenu, OptionsMenu::m_pMenuRootGui) == 0x18, "OptionsMenu::m_pMenuRootGui: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_bSomeFlag) == 0x20, "OptionsMenu::m_bSomeFlag: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::is_server) == 0x21, "OptionsMenu::is_server: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::compound_button) == 0x28, "OptionsMenu::compound_button: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::radio_btn_set) == 0x38, "OptionsMenu::radio_btn_set: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_currentTab) == 0x48, "OptionsMenu::m_currentTab: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_mapSubMenus) == 0x58, "OptionsMenu::m_mapSubMenus: Incorrect offset");

static_assert(sizeof(OptionsMenu) == 0x68, "OptionsMenu: Incorrect Size");