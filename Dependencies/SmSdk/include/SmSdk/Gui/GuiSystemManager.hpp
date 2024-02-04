#pragma once

#include "MyGUI.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

namespace MyGUI
{
	class DirectX11Platform {};
}

#pragma pack(push, 1)
struct GuiSystemManager
{
public:
	static GuiSystemManager* GetInstance();

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
private:
	/* 0x01A0 */ char pad_0x1A0[0x48];
}; // Size: 0x1E8
#pragma pack(pop)

static_assert(sizeof(GuiSystemManager) == 0x1E8, "GuiSystemManager: Incorrect Size");