#pragma once

#include "IToolImpl.hpp"
#include "Tool.hpp"

#include <unordered_map>
#include <string>
#include <memory>

class ClientTool;

enum AnimationFlag : std::uint32_t
{
	AnimationFlag_None = 0,
	AnimationFlag_Repeat = 1
};

struct ToolAnimationEntry
{
	/* 0x0000 */ std::string anim_name;
	/* 0x0020 */ std::string next_anim;
	/* 0x0040 */ float anim_begin;
	/* 0x0044 */ float anim_end;
	/* 0x0048 */ float anim_time;
	/* 0x004C */ float weight;
	/* 0x0050 */ float playback_speed;
	/* 0x0054 */ std::uint32_t flags;

}; // Size: 0x58

static_assert(sizeof(ToolAnimationEntry) == 0x58, "ToolAnimationEntry: Incorrect Size");

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
	void setAnimation(const std::string& name)
	{
		auto v_iter = this->animation_data.find(name);
		if (v_iter == this->animation_data.end())
			return;

		this->current_anim = name;
		v_iter->second.anim_time = 0.0f;
		this->anim_begin = 0.2f;
	}

	bool hasAnimation(const std::string& name) const
	{
		return this->animation_data.find(name) != this->animation_data.end();
	}

	void resetAnimation(const std::string& name)
	{
		auto v_iter = this->animation_data.find(name);
		if (v_iter == this->animation_data.end())
			return;

		v_iter->second.anim_time = 0.0f;
		v_iter->second.weight = 0.0f;
	}

	void addNewAnimation(
		const std::string& name,
		const std::string& start_anim,
		const std::string& next_anim,
		float anim_begin = 0.0f,
		float anim_end = 1.0f,
		float playback_speed = 1.0f,
		std::uint32_t flags = 256)
	{
		ToolAnimationEntry v_new_entry;
		v_new_entry.anim_name = start_anim;
		v_new_entry.next_anim = next_anim;
		v_new_entry.anim_time = 0.0f;
		v_new_entry.anim_begin = anim_begin;
		v_new_entry.anim_end = anim_end;
		v_new_entry.weight = 0.0f;
		v_new_entry.playback_speed = playback_speed;
		v_new_entry.flags = flags;

		this->animation_data.emplace(name, v_new_entry);
	}

	void removeAnimation(const std::string& name)
	{
		auto v_iter = this->animation_data.find(name);
		if (v_iter != this->animation_data.end())
			this->animation_data.erase(v_iter);
	}

	/* 0x0000 */ ClientTool* tool_ptr;
	/* 0x0008 */ std::unordered_map<std::string, ToolAnimationEntry> animation_data;
	/* 0x0048 */ std::string current_anim;
	/* 0x0068 */ ToolAnimationList tool_anim_list;
	/* 0x0288 */ float anim_begin;
private:
	/* 0x028C */ char pad_0x28C[0x4];

}; // Size: 0x290

static_assert(sizeof(ToolAnimationData) == 0x290, "ToolAnimationData: Incorrect Size");

class ClientTool : public IToolImpl
{
public:
	inline void setTpAnimation(const std::string& name)
	{
		m_tpAnims.setAnimation(name);
	}

	inline void setFpAnimation(const std::string& name)
	{
		m_fpAnims.setAnimation(name);
	}

	inline void setFpAndTpAnimation(const std::string& name)
	{
		this->setFpAnimation(name);
		this->setTpAnimation(name);
	}

	/* 0x0008 */ ToolAnimationData m_tpAnims;
	/* 0x0298 */ ToolAnimationData m_fpAnims;
	/* 0x0528 */ std::shared_ptr<Tool> tool;
	/* 0x0538 */ bool block_sprint;
	/* 0x0539 */ char pad_0x539[0x3];
	/* 0x053C */ float dispersion_fraction;
	/* 0x0540 */ float crosshair_alpha;
	/* 0x0544 */ bool interaction_text_suppressed;
	/* 0x0545 */ char pad_0x545[0x3];

}; // Size: 0x548

static_assert(sizeof(ClientTool) == 0x548, "ClientTool: Incorrect Size");