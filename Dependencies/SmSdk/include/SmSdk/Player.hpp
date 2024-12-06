#pragma once

#include <memory>
#include <string>

#include "SmSdk/boost_include.hpp"
#include <DirectXMath.h>

struct PlayerGarments
{
	/* 0x0000 */ __int8 is_female;
	/* 0x0001 */ boost::uuids::uuid head_uuid;
	/* 0x0011 */ boost::uuids::uuid hair_uuid;
	/* 0x0021 */ boost::uuids::uuid facial_hair_uuid;
	/* 0x0031 */ boost::uuids::uuid torso_uuid;
	/* 0x0041 */ boost::uuids::uuid gloves_uuid;
	/* 0x0051 */ boost::uuids::uuid shoes_uuid;
	/* 0x0061 */ boost::uuids::uuid legs_uuid;
	/* 0x0071 */ boost::uuids::uuid hat_uuid;
	/* 0x0081 */ boost::uuids::uuid backpack_uuid;
	/* 0x0091 */ char pad_0x91[0x3];
	/* 0x0094 */ __int32 head_color;
	/* 0x0098 */ __int32 hair_color;
	/* 0x009C */ __int32 facial_hair_color;
	/* 0x00A0 */ __int32 torso_color;
	/* 0x00A4 */ __int32 gloves_color;
	/* 0x00A8 */ __int32 shoes_color;
	/* 0x00AC */ __int32 legs_color;
	/* 0x00B0 */ __int32 hat_color;
	/* 0x00B4 */ __int32 backpack_color;
}; // Size: 0xB8

static_assert(sizeof(PlayerGarments) == 0xB8, "PlayerGarments: Incorrect Size");

struct PlayerScriptData
{
	/* 0x0000 */ bool has_server_onRefresh;
	/* 0x0001 */ bool has_server_onProjectile;
	/* 0x0002 */ bool has_server_onExplosion;
	/* 0x0003 */ bool has_server_onMelee;
	/* 0x0004 */ bool has_server_onCollision;
	/* 0x0005 */ bool has_server_onCollisionCrush;
	/* 0x0006 */ bool has_server_onShapeRemoved;
	/* 0x0007 */ bool has_server_onInventoryChanges;
}; // Size: 0x8

static_assert(sizeof(PlayerScriptData) == 0x8, "PlayerScriptData: Incorrect Size");

class Character;

class Player
{
public:
	Character* getCharacter() const;
	bool characterExists() const;

	/* 0x0000 */ std::shared_ptr<Player> self_ptr;
	/* 0x0010 */ __int32 id;
	/* 0x0014 */ __int32 character_id;
	/* 0x0018 */ __int16 world_id;
	/* 0x001A */ char pad_0x1A[0x2];
	/* 0x001C */ DirectX::XMFLOAT3 character_position;
	/* 0x0028 */ DirectX::XMFLOAT3 character_velocity;
	/* 0x0034 */ float character_yaw;
	/* 0x0038 */ float character_pitch;
	/* 0x003C */ char pad_0x3C[0x4];
	/* 0x0040 */ __int64 steam_id;
	/* 0x0048 */ std::string name;
	/* 0x0068 */ char pad_0x68[0x4];
	/* 0x006C */ PlayerGarments garments;
	/* 0x0124 */ __int32 garment_change_counter;
	/* 0x0128 */ char pad_0x128[0x10];
	/* 0x0138 */ __int32 script_ref;
	/* 0x013C */ PlayerScriptData script_data;
	/* 0x0144 */ char pad_0x144[0xC];

}; // Size: 0x150

static_assert(sizeof(Player) == 0x150, "Player: Incorrect Size");