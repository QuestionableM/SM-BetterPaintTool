#pragma once

#include "SmSdk/Gui/OptionsSubMenuBase.hpp"
#include "SmSdk/Gui/CompoundButton.hpp"
#include "SmSdk/Gui/RadioButtonSet.hpp"
#include "SmSdk/Gui/GuiBase.hpp"

SMSDK_BEGIN_NAMESPACE

class OptionsMenu : public GuiBase
{
	/* 0x0018 */ SDK_PUB class MainMenuRootGui* m_pMenuRootGui;
	/* 0x0020 */ SDK_PRI bool m_bSomeFlag;
	/* 0x0021 */ SDK_PUB bool m_bIsServer;
	/* 0x0022 */ SDK_PRI char pad_0x22[0x6];
	/* 0x0028 */ SDK_PUB std::shared_ptr<CompoundButton> m_pCompoundButton;
	/* 0x0038 */ SDK_PUB std::shared_ptr<RadioButtonSet> m_pRadioButtonSet;
	/* 0x0048 */ SDK_PUB std::shared_ptr<OptionsSubMenuBase> m_pCurrentTab;
	/* 0x0058 */ SDK_PUB std::map<std::string, std::shared_ptr<OptionsSubMenuBase>> m_mapSubMenus;
}; // Size: 0x68

static_assert(offsetof(OptionsMenu, OptionsMenu::m_pMenuRootGui) == 0x18, "OptionsMenu::m_pMenuRootGui: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_bSomeFlag) == 0x20, "OptionsMenu::m_bSomeFlag: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_bIsServer) == 0x21, "OptionsMenu::m_bIsServer: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_pCompoundButton) == 0x28, "OptionsMenu::m_pCompoundButton: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_pRadioButtonSet) == 0x38, "OptionsMenu::m_pRadioButtonSet: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_pCurrentTab) == 0x48, "OptionsMenu::m_pCurrentTab: Incorrect offset");
static_assert(offsetof(OptionsMenu, OptionsMenu::m_mapSubMenus) == 0x58, "OptionsMenu::m_mapSubMenus: Incorrect offset");

static_assert(sizeof(OptionsMenu) == 0x68, "OptionsMenu: Incorrect Size");

SMSDK_END_NAMESPACE