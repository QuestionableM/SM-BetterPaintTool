#pragma once

#include "SmSdk/mygui_include.hpp"
#include "SmSdk/win_include.hpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <map>

SMSDK_BEGIN_NAMESPACE

class GuiSystemManager
{
	SDK_PUB static GuiSystemManager* GetInstance();

	SDK_PUB static bool IsMouseVisible()
	{
		GuiSystemManager* pGuiSystemManager = GuiSystemManager::GetInstance();
		if (!pGuiSystemManager)
			return false;

		return pGuiSystemManager->m_bMouseVisible;
	}

	SDK_PUB float getOptionItemSize() const
	{
		return float(m_iScreenHeight) * (1.0f / 720.0f);
	}

	SDK_PUB float getOptionItemSize2() const
	{
		return float(m_iScreenHeight) * (1.0f / 1080.0f);
	}

	SDK_PRI static int ProcessScroll(
	    int unknownVal,
	    int scrollDistance,
	    int topPos,
	    int scrollVal,
	    float itemSize)
	{
		if (unknownVal <= 0)
			return 0;

		const int vScrollClamped = (scrollVal <= 0)
		    ? -scrollDistance
		    : scrollDistance;

		const int vVal = topPos - int(vScrollClamped * -itemSize);

		return std::min(std::max(-unknownVal, vVal), 0);
	}

	/* 0x0000 */ SDK_PRI char pad_0x0[0x18];
	/* 0x0018 */ SDK_PUB std::shared_ptr<MyGUI::DirectX11Platform> m_pMyGUIDx11Platform;
	/* 0x0028 */ SDK_PUB std::shared_ptr<MyGUI::Gui> m_pGui;
	/* 0x0038 */ SDK_PUB struct CreateTextureCallback* m_pCreateTextureCallback;
	/* 0x0040 */ SDK_PUB std::shared_ptr<struct CommonGuiAdditions> m_pCommonGuiAdditions;
	/* 0x0050 */ SDK_PRI char pad_0x50[0x10];
	/* 0x0060 */ SDK_PUB std::vector<std::string> m_vecFontNames;
	/* 0x0078 */ SDK_PUB std::vector<std::string> m_vecFonts;
	/* 0x0090 */ SDK_PUB std::vector<struct SystemTexture*> m_vecFontTextures;
	/* 0x00A8 */ SDK_PUB std::unordered_map<std::string, struct SystemTexture*> m_mapFontNameToTexture;
	/* 0x00E8 */ SDK_PUB std::int32_t m_iScreenWidth;
	/* 0x00EC */ SDK_PUB std::int32_t m_iScreenHeight;
	/* 0x00F0 */ SDK_PUB std::int32_t m_iScreenLeft;
	/* 0x00F4 */ SDK_PUB std::int32_t m_iScreenTop;
	/* 0x00F8 */ SDK_PUB std::string m_guiLanguage;
	/* 0x0118 */ SDK_PRI char pad_0x118[0x28];
	/* 0x0140 */ SDK_PUB std::map<std::string, struct TextureResource*> m_mapPathToTexture;
	/* 0x0150 */ SDK_PRI char pad_0x150[0x10];
	/* 0x0160 */ SDK_PUB std::unordered_map<std::string, std::string> m_mapWidgetNameToPath;
	/* 0x01A0 */ SDK_PUB std::unordered_map<uint8_t, HCURSOR> m_mapCursors;
	/* 0x01E0 */ SDK_PUB bool m_bMouseState;
	/* 0x01E1 */ SDK_PUB bool m_bMouseVisible;
	/* 0x01E2 */ SDK_PRI char pad_0x1E2[0x6];
}; // Size: 0x1E8

static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_pMyGUIDx11Platform) == 0x18, "GuiSystemManager::m_pMyGUIDx11Platform: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_pGui) == 0x28, "GuiSystemManager::m_pGui: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_pCreateTextureCallback) == 0x38, "GuiSystemManager::m_pCreateTextureCallback: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_pCommonGuiAdditions) == 0x40, "GuiSystemManager::m_pCommonGuiAdditions: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_vecFontNames) == 0x60, "GuiSystemManager::m_vecFontNames: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_vecFonts) == 0x78, "GuiSystemManager::m_vecFonts: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_vecFontTextures) == 0x90, "GuiSystemManager::m_vecFontTextures: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_mapFontNameToTexture) == 0xA8, "GuiSystemManager::m_mapFontNameToTexture: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_iScreenWidth) == 0xE8, "GuiSystemManager::m_iScreenWidth: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_iScreenHeight) == 0xEC, "GuiSystemManager::m_iScreenHeight: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_iScreenLeft) == 0xF0, "GuiSystemManager::m_iScreenLeft: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_iScreenTop) == 0xF4, "GuiSystemManager::m_iScreenTop: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_guiLanguage) == 0xF8, "GuiSystemManager::m_guiLanguage: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_mapPathToTexture) == 0x140, "GuiSystemManager::m_mapPathToTexture: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_mapWidgetNameToPath) == 0x160, "GuiSystemManager::m_mapWidgetNameToPath: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_mapCursors) == 0x1A0, "GuiSystemManager::m_mapCursors: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_bMouseState) == 0x1E0, "GuiSystemManager::m_bMouseState: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_bMouseVisible) == 0x1E1, "GuiSystemManager::m_bMouseVisible: Incorrect offset");

static_assert(sizeof(GuiSystemManager) == 0x1E8, "GuiSystemManager: Incorrect Size");

SMSDK_END_NAMESPACE