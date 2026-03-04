#pragma once

#include "SmSdk/Gui/OptionsSubMenuBase.hpp"
#include "SmSdk/Util/Memory.hpp"

#include "SmSdk/mygui_include.hpp"
#include "SmSdk/offsets.hpp"

#include <string>

SMSDK_BEGIN_NAMESPACE

struct OptionsItemDropDown;

class GraphicsOptionsMenu : public OptionsSubMenuBase
{
public:
	GraphicsOptionsMenu()
	{
		using fSelfConstructor = void (*)(GraphicsOptionsMenu*);
		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET)(this);
	}

	virtual ~GraphicsOptionsMenu() = default;
	void restoreDefaults() override { /* implemented by the game */ }

	/* 0x0168 */ SDK_PRI MyGUI::Button* m_pSomeButton;
	/* 0x0170 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pShaderQualityDropdown;
	/* 0x0180 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pReflectionQualityDropdown;
	/* 0x0190 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pShadowResolutionDropdown;
	/* 0x01A0 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pShadowQualityDropdown;
	/* 0x01B0 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pSsaoDropdown;
	/* 0x01C0 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pFoliageDropdown;
	/* 0x01D0 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pTextureQualityDropdown;
	/* 0x01E0 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pDrawDistanceDropdown;
	/* 0x01F0 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pTexFilteringDropdown;
	/* 0x0200 */ SDK_PUB std::shared_ptr<OptionsItemDropDown> m_pParticleQualityDropdown;
	/* 0x0210 */ SDK_PUB std::vector<std::string> m_vecQualityLevelLabels;
	/* 0x0228 */ SDK_PRI char pad_0x228[0x20];
}; // Size: 0x248

static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pShaderQualityDropdown) == 0x170, "GraphicsOptionsMenu::m_pShaderQualityDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pReflectionQualityDropdown) == 0x180, "GraphicsOptionsMenu::m_pReflectionQualityDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pShadowResolutionDropdown) == 0x190, "GraphicsOptionsMenu::m_pShadowResolutionDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pShadowQualityDropdown) == 0x1A0, "GraphicsOptionsMenu::m_pShadowQualityDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pSsaoDropdown) == 0x1B0, "GraphicsOptionsMenu::m_pSsaoDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pFoliageDropdown) == 0x1C0, "GraphicsOptionsMenu::m_pFoliageDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pTextureQualityDropdown) == 0x1D0, "GraphicsOptionsMenu::m_pTextureQualityDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pDrawDistanceDropdown) == 0x1E0, "GraphicsOptionsMenu::m_pDrawDistanceDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pTexFilteringDropdown) == 0x1F0, "GraphicsOptionsMenu::m_pTexFilteringDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_pParticleQualityDropdown) == 0x200, "GraphicsOptionsMenu::m_pParticleQualityDropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::m_vecQualityLevelLabels) == 0x210, "GraphicsOptionsMenu::m_vecQualityLevelLabels: Incorrect offset");
static_assert(sizeof(GraphicsOptionsMenu) == 0x248, "GraphicsOptionsMenu: Incorrect Size");

SMSDK_END_NAMESPACE