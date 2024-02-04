#pragma once

#include "IToolImpl.hpp"
#include "Tool.hpp"

#include <unordered_map>
#include <string>
#include <memory>

class ClientTool;

struct ToolAnimationEntry
{
	/* 0x0000 */ std::string full_anim_name;
	/* 0x0020 */ std::string next_anim_name;
}; // Size: 0x40

static_assert(sizeof(ToolAnimationEntry) == 0x40, "ToolAnimationEntry: Incorrect Size");

struct ToolAnimationList
{
	/* 0x0000 */ std::string tool_idle;
	/* 0x0020 */ std::string tool_idle_relaxed;
	/* 0x0040 */ std::string tool_run_fwd;
	/* 0x0060 */ std::string tool_run_bwd;
	/* 0x0080 */ std::string tool_sprint;
	/* 0x00A0 */ std::string tool_jump;
	/* 0x00C0 */ std::string tool_jump_up;
	/* 0x00E0 */ std::string tool_jump_down;
	/* 0x0100 */ std::string tool_jump_land;
	/* 0x0120 */ std::string tool_jump_land_fwd;
	/* 0x0140 */ std::string tool_jump_land_bwd;
	/* 0x0160 */ std::string tool_crouch_idle;
	/* 0x0180 */ std::string tool_crouch_fwd;
	/* 0x01A0 */ std::string tool_crouch_bwd;
	/* 0x01C0 */ std::string some_string1;
	/* 0x01E0 */ std::string some_string2;
	/* 0x0200 */ std::string some_string3;
}; // Size: 0x220

static_assert(sizeof(ToolAnimationList) == 0x220, "ToolAnimationList: Incorrect Size");

struct ToolAnimationData
{
	/* 0x0000 */ ClientTool* tool_ptr;
	/* 0x0008 */ std::unordered_map<std::string, ToolAnimationEntry> animation_data;
	/* 0x0048 */ std::string idle_anim;
	/* 0x0068 */ ToolAnimationList tool_anim_list;
	/* 0x0288 */ char pad_0x288[0x8];
}; // Size: 0x290

static_assert(sizeof(ToolAnimationData) == 0x290, "ToolAnimationData: Incorrect Size");

class ClientTool : public IToolImpl
{
	/* 0x0008 */ ToolAnimationData anim_data1;
	/* 0x0298 */ ToolAnimationData anim_data2;
	/* 0x0528 */ std::shared_ptr<Tool> tool;
	/* 0x0538 */ bool block_sprint;
	/* 0x0539 */ char pad_0x539[0x3];
	/* 0x053C */ float dispersion_fraction;
	/* 0x0540 */ float crosshair_alpha;
	/* 0x0544 */ bool interaction_text_suppressed;
	/* 0x0545 */ char pad_0x545[0x3];
}; // Size: 0x548

static_assert(sizeof(ClientTool) == 0x548, "ClientTool: Incorrect Size");