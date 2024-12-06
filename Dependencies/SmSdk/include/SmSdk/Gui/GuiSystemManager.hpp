#pragma once

#include "SmSdk/mygui_include.hpp"
#include "SmSdk/win_include.hpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <map>

class GuiSystemManager
{
public:
	static GuiSystemManager* GetInstance();

	static bool IsMouseVisible()
	{
		GuiSystemManager* v_gui_sys_mgr = GuiSystemManager::GetInstance();
		if (!v_gui_sys_mgr) return false;

		return v_gui_sys_mgr->m_bMouseVisible;
	}

	float getOptionItemSize() const
	{
		return float(this->screen_height) * (1.0f / 720.0f);
	}

	float getOptionItemSize2() const
	{
		return float(this->screen_height) * (1.0f / 1080.0f);
	}

	static int ProcessScroll(
		int some_val,
		int scroll_distance,
		int top_pos,
		int scroll_val,
		float item_size)
	{
		if (some_val <= 0)
			return 0;

		const int v_scroll_clamped = (scroll_val <= 0)
			? -scroll_distance : scroll_distance;

		const int v_val = top_pos - int(v_scroll_clamped * -item_size);

		return std::min(std::max(-some_val, v_val), 0);
	}

private:
	/* 0x0000 */ char pad_0x0[0x18];
public:
	/* 0x0018 */ std::shared_ptr<MyGUI::DirectX11Platform> mygui_dx11_platform;
	/* 0x0028 */ std::shared_ptr<MyGUI::Gui> gui;
	/* 0x0038 */ struct CreateTextureCallback* create_texture_callback;
	/* 0x0040 */ std::shared_ptr<struct CommonGuiAdditions> common_gui_additions;
private:
	/* 0x0050 */ char pad_0x50[0x10];
public:
	/* 0x0060 */ std::vector<std::string> font_name_list;
	/* 0x0078 */ std::vector<std::string> font_list;
	/* 0x0090 */ std::vector<struct SystemTexture*> font_textures;
	/* 0x00A8 */ std::unordered_map<std::string, struct SystemTexture*> font_name_to_texture;
	/* 0x00E8 */ __int32 screen_width;
	/* 0x00EC */ __int32 screen_height;
	/* 0x00F0 */ __int32 screen_left;
	/* 0x00F4 */ __int32 screen_top;
	/* 0x00F8 */ std::string gui_language;
private:
	/* 0x0118 */ char pad_0x118[0x28];
public:
	/* 0x0140 */ std::map<std::string, struct TextureResource*> path_to_texture;
private:
	/* 0x0150 */ char pad_0x150[0x10];
public:
	/* 0x0160 */ std::unordered_map<std::string, std::string> widget_name_to_path;
	/* 0x01A0 */ std::unordered_map<std::uint8_t, HCURSOR> m_mapCursors;
	/* 0x01E0 */ bool m_bMouseState;
	/* 0x01E1 */ bool m_bMouseVisible;
private:
	/* 0x01E2 */ char pad_0x1E2[0x6];
}; // Size: 0x1E8

static_assert(offsetof(GuiSystemManager, GuiSystemManager::mygui_dx11_platform) == 0x18, "GuiSystemManager::mygui_dx11_platform: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::gui) == 0x28, "GuiSystemManager::gui: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::create_texture_callback) == 0x38, "GuiSystemManager::create_texture_callback: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::common_gui_additions) == 0x40, "GuiSystemManager::common_gui_additions: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::font_name_list) == 0x60, "GuiSystemManager::font_name_list: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::font_list) == 0x78, "GuiSystemManager::font_list: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::font_textures) == 0x90, "GuiSystemManager::font_textures: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::font_name_to_texture) == 0xA8, "GuiSystemManager::font_name_to_texture: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::screen_width) == 0xE8, "GuiSystemManager::screen_width: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::screen_height) == 0xEC, "GuiSystemManager::screen_height: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::screen_left) == 0xF0, "GuiSystemManager::screen_left: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::screen_top) == 0xF4, "GuiSystemManager::screen_top: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::gui_language) == 0xF8, "GuiSystemManager::gui_language: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::path_to_texture) == 0x140, "GuiSystemManager::path_to_texture: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::widget_name_to_path) == 0x160, "GuiSystemManager::widget_name_to_path: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_mapCursors) == 0x1A0, "GuiSystemManager::m_mapCursors: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_bMouseState) == 0x1E0, "GuiSystemManager::m_bMouseState: Incorrect offset");
static_assert(offsetof(GuiSystemManager, GuiSystemManager::m_bMouseVisible) == 0x1E1, "GuiSystemManager::m_bMouseVisible: Incorrect offset");

static_assert(sizeof(GuiSystemManager) == 0x1E8, "GuiSystemManager: Incorrect Size");