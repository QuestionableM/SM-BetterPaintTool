#pragma once

#include "OptionsSubMenuBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

#include <string>

struct OptionsItemDropDown;

class GraphicsOptionsMenu : public OptionsSubMenuBase
{
public:
	GraphicsOptionsMenu()
	{
		using fSelfConstructor = void(*)(GraphicsOptionsMenu*);
		Memory::Read<fSelfConstructor>(SM_CONSTRUCTOR_GRAPHICS_OPTIONS_MENU_OFFSET)(this);
	}

	virtual ~GraphicsOptionsMenu() = default;
	void restoreDefaults() override { /* implemented by the game */ }

public:
	/* 0x0168 */ MyGUI::Button* some_button;
	/* 0x0170 */ std::shared_ptr<OptionsItemDropDown> shader_quality_dropdown;
	/* 0x0180 */ std::shared_ptr<OptionsItemDropDown> reflection_quality_dropdown;
	/* 0x0190 */ std::shared_ptr<OptionsItemDropDown> shadow_resolution_dropdown;
	/* 0x01A0 */ std::shared_ptr<OptionsItemDropDown> shadow_quality_dropdown;
	/* 0x01B0 */ std::shared_ptr<OptionsItemDropDown> ssao_dropdown;
	/* 0x01C0 */ std::shared_ptr<OptionsItemDropDown> foliage_dropdown;
	/* 0x01D0 */ std::shared_ptr<OptionsItemDropDown> texture_quality_dropdown;
	/* 0x01E0 */ std::shared_ptr<OptionsItemDropDown> draw_distance_dropdown;
	/* 0x01F0 */ std::shared_ptr<OptionsItemDropDown> tex_filtering_dropdown;
	/* 0x0200 */ std::shared_ptr<OptionsItemDropDown> particle_quality_dropdown;
	/* 0x0210 */ std::vector<std::string> quality_level_labels;
private:
	/* 0x0228 */ char pad_0x228[0x20];

}; // Size: 0x248

static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::some_button) == 0x168, "GraphicsOptionsMenu::some_button: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::shader_quality_dropdown) == 0x170, "GraphicsOptionsMenu::shader_quality_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::reflection_quality_dropdown) == 0x180, "GraphicsOptionsMenu::reflection_quality_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::shadow_resolution_dropdown) == 0x190, "GraphicsOptionsMenu::shadow_resolution_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::shadow_quality_dropdown) == 0x1A0, "GraphicsOptionsMenu::shadow_quality_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::ssao_dropdown) == 0x1B0, "GraphicsOptionsMenu::ssao_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::foliage_dropdown) == 0x1C0, "GraphicsOptionsMenu::foliage_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::texture_quality_dropdown) == 0x1D0, "GraphicsOptionsMenu::texture_quality_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::draw_distance_dropdown) == 0x1E0, "GraphicsOptionsMenu::draw_distance_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::tex_filtering_dropdown) == 0x1F0, "GraphicsOptionsMenu::tex_filtering_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::particle_quality_dropdown) == 0x200, "GraphicsOptionsMenu::particle_quality_dropdown: Incorrect offset");
static_assert(offsetof(GraphicsOptionsMenu, GraphicsOptionsMenu::quality_level_labels) == 0x210, "GraphicsOptionsMenu::quality_level_labels: Incorrect offset");
static_assert(sizeof(GraphicsOptionsMenu) == 0x248, "GraphicsOptionsMenu: Incorrect Size");