#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/config.hpp"

#include "SmSdk/Base/Aligned16Base.hpp"
#include "SmSdk/Base/InputTarget.hpp"
#include "SmSdk/Player.hpp"

#include <DirectXMath.h>

#include <memory>

struct PlayerCamera
{
	/* 0x0000 */ DirectX::XMFLOAT3 cam_character_pos;
	/* 0x000C */ DirectX::XMFLOAT3 some_vector;
	/* 0x0018 */ DirectX::XMFLOAT3 position;
	/* 0x0024 */ DirectX::XMFLOAT3 direction;
	/* 0x0030 */ DirectX::XMFLOAT3 up;
	/* 0x003C */ DirectX::XMFLOAT3 some_vector2;
	/* 0x0048 */ DirectX::XMFLOAT4 some_quat;
	/* 0x0058 */ float up_offset;
	/* 0x005C */ float pullback;
	/* 0x0060 */ float fov;
	/* 0x0064 */ float shake;
}; // Size: 0x68

static_assert(sizeof(PlayerCamera) == 0x68, "PlayerCamera: Incorrect Size");

class Viewer : public Aligned16Base
{
public:
	virtual ~Viewer() = default;

	/* 0x0010 */ bool going_forwards;
	/* 0x0011 */ bool going_backwards;
	/* 0x0012 */ bool going_left;
	/* 0x0013 */ bool going_right;
private:
	/* 0x0014 */ char pad_0x14[0x4];
public:
	/* 0x0018 */ double yaw;
	/* 0x0020 */ double pitch;
	/* 0x0028 */ double delta_yaw;
	/* 0x0030 */ double delta_pitch;
	/* 0x0038 */ double yaw_no_clamp;
	/* 0x0040 */ double pitch_no_clamp;
	/* 0x0048 */ double delta_yaw2;
	/* 0x0050 */ double delta_pitch2;
private:
	/* 0x0058 */ char pad_0x58[0x8];
}; // Size: 0x60

static_assert(sizeof(Viewer) == 0x60, "Viewer: Incorrect Size");

class Character;

class MyPlayer : public InputTarget, public Viewer
{
	REMOVE_COPY_CONSTRUCTORS(MyPlayer);

public:
	static MyPlayer* GetInstance();

	Character* getCharacter() const;

	/* 0x0070 */ std::shared_ptr<Player> player;
	/* 0x0080 */ __int8 control_character_sum;
private:
	/* 0x0081 */ char pad_0x81[0x3];
public:
	/* 0x0084 */ float walk_direction_radians;
	/* 0x0088 */ float yaw_float;
	/* 0x008C */ float pitch_float;
	/* 0x0090 */ PlayerCamera camera;
	/* 0x00F8 */ std::shared_ptr<struct Effect> some_effect;
	/* 0x0108 */ char pad_0x108[0x28];
	/* 0x0130 */ DirectX::XMMATRIX camera_matrix;
	/* 0x0170 */ float camera_fov2;
private:
	/* 0x0174 */ char pad_0x174[0x4];
public:
	/* 0x0178 */ std::shared_ptr<struct FirstPersonHands> first_person_hands;
private:
	/* 0x0188 */ char pad_0x188[0x38];
public:
	/* 0x01C0 */ std::shared_ptr<struct Inventory> inventory;
	/* 0x01D0 */ std::shared_ptr<struct ToolBox> tool_box;
	/* 0x01E0 */ std::shared_ptr<struct Construction> construction;
	/* 0x01F0 */ std::shared_ptr<struct Destruction> destruction;
private:
	/* 0x0200 */ char pad_0x200[0x10];
public:
	/* 0x0210 */ bool is_raycast_valid;
private:
	/* 0x0211 */ char pad_0x211[0xD7];
public:
	/* 0x02E8 */ __int32 owned_lift_id;
private:
	/* 0x02EC */ char pad_0x2EC[0x34];
public:
	/* 0x0320 */ __int32 camera_pullback_index;
private:
	/* 0x0324 */ char pad_0x324[0x4];
public:
	/* 0x0328 */ std::shared_ptr<struct AudioEvent> audio_event;
private:
	/* 0x0338 */ char pad_0x338[0x1];
public:
	/* 0x0339 */ bool is_downed;
private:
	/* 0x033A */ char pad_0x33A[0x6];
public:
	/* 0x0340 */ boost::uuids::uuid selected_tool_uuid;
	/* 0x0350 */ __int32 selected_tool_id;
	/* 0x0354 */ boost::uuids::uuid prev_selected_tool_uuid;
	/* 0x0364 */ __int32 prev_selected_tool_id;
private:
	/* 0x0368 */ char pad_0x368[0x8];

}; //Size=0x0370

static_assert(sizeof(MyPlayer) == 0x370, "MyPlayer: Incorrect Size");