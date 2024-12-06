#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/Base/NetObj.hpp"
#include "SmSdk/offsets.hpp"

#include <DirectXMath.h>

#include <vector>
#include <memory>
#include <string>

struct CharacterScriptData
{
	/* 0x0000 */ bool has_client_onGraphicsLoaded;
	/* 0x0001 */ bool has_client_onGraphicsUnloaded;
	/* 0x0002 */ bool has_client_canInteract;
	/* 0x0003 */ bool has_client_onInteract;
	/* 0x0004 */ bool has_client_onProjectile;
	/* 0x0005 */ bool has_client_onMelee;
	/* 0x0006 */ bool has_client_onCollision;
	/* 0x0007 */ char pad_0x7[0x1];
}; // Size: 0x8

static_assert(sizeof(CharacterScriptData) == 0x8, "CharacterScriptData: Incorrect Size");

#if defined(_SM_VERSION_070_771)
struct CharacterControllerData
{
	/* 0x0000 */ float m_fWalkSpeed;
	/* 0x0004 */ float m_fAimSpeed;
	/* 0x0008 */ float m_fCrouchSpeed;
	/* 0x000C */ float m_fSprintSpeed;
	/* 0x0010 */ float m_fJumpStrength;
	/* 0x0014 */ float m_fRadius;
	/* 0x0018 */ float m_fHeight;
	/* 0x001C */ float m_fHeightCrouch;
	/* 0x0020 */ float m_fMass;
	/* 0x0024 */ char pad_0x24[0xC];
	/* 0x0030 */ bool m_bCanSwim;
	/* 0x0031 */ char pad_0x31[0x3];
}; // Size: 0x34

static_assert(sizeof(CharacterControllerData) == 0x34, "CharacterControllerData: Incorrect Size");

class Character : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ __int16 world_id;
private:
	/* 0x0032 */ char pad_0x32[0x6];
public:
	/* 0x0038 */ __int64 owner_steam_id;
	/* 0x0040 */ bool is_player;
private:
	/* 0x0041 */ char pad_0x41[0x3];
public:
	/* 0x0044 */ __int32 unit_id;
	/* 0x0048 */ boost::uuids::uuid uuid;
	/* 0x0058 */ bool is_downed;
	/* 0x0059 */ bool is_swimming;
	/* 0x005A */ bool is_diving;
private:
	/* 0x005B */ char pad_0x5B[0x1];
public:
	/* 0x005C */ bool is_climbing;
	/* 0x005D */ bool is_tumbling;
private:
	/* 0x005E */ char pad_0x5E[0x2];
public:
	/* 0x0060 */ float movement_speed_fraction;
private:
	/* 0x0064 */ char pad_0x64[0x4];
public:
	/* 0x0068 */ std::vector<std::string> animation_list;
	/* 0x0080 */ DirectX::XMFLOAT3 spawn_position;
private:
	/* 0x008C */ char pad_0x8C[0x1C];
public:
	/* 0x00A8 */ DirectX::XMFLOAT3 velocity;
	/* 0x00B4 */ DirectX::XMFLOAT3 acceleration;
private:
	/* 0x00C0 */ char pad_0xC0[0x14];
public:
	/* 0x00D4 */ __int32 control_key_sum;
	/* 0x00D8 */ float walk_direction_radians;
	/* 0x00DC */ float yaw;
	/* 0x00E0 */ float pitch;
	/* 0x00E4 */ float yaw2;
	/* 0x00E8 */ float pitch2;
	/* 0x00EC */ DirectX::XMFLOAT3 up_direction_cpy;
	/* 0x00F8 */ DirectX::XMFLOAT3 up_direction;
	/* 0x0104 */ float yaw3;
	/* 0x0108 */ float pitch3;
private:
	/* 0x010C */ char pad_0x10C[0x4];
public:
	/* 0x0110 */ __int32 locking_interactable_id;
private:
	/* 0x0114 */ char pad_0x114[0x1C];
public:
	/* 0x0130 */ bool is_on_ground;
private:
	/* 0x0131 */ char pad_0x131[0x3];
public:
	/* 0x0134 */ float air_time;
	/* 0x0138 */ DirectX::XMFLOAT3 ground_normal;
private:
	/* 0x0144 */ char pad_0x144[0xC];
public:
	/* 0x0150 */ boost::uuids::uuid selected_tool_uuid;
	/* 0x0160 */ __int32 selected_tool_id;
	/* 0x0164 */ boost::uuids::uuid prev_selected_tool_uuid;
	/* 0x0174 */ __int32 prev_selected_tool_id;
private:
	/* 0x0178 */ char pad_0x178[0x2];
public:
	/* 0x017A */ __int8 crouch_state;
private:
	/* 0x017B */ char pad_0x17B[0x9CD];
public:
	/* 0x0B48 */ std::shared_ptr<struct CharacterController> m_pController;
	/* 0x0B58 */ std::shared_ptr<struct CharacterPhysicsProxy> m_pPhysicsProxy;
	/* 0x0B68 */ std::shared_ptr<struct RagdollPhysicsProxy> m_pRagdollPhysicsProxy;
private:
	/* 0x0B78 */ char pad_0xB78[0xAC];
public:
	/* 0x0C24 */ CharacterControllerData m_controllerData;
	/* 0x0C58 */ CharacterScriptData script_data;
private:
	/* 0x0C60 */ char pad_0xC60[0x10];
public:
	/* 0x0C70 */ std::string script_path;
	/* 0x0C90 */ std::string script_class;
	/* 0x0CB0 */ __int32 script_ref;
private:
	/* 0x0CB4 */ char pad_0xCB4[0x8];
public:
	/* 0x0CBC */ DirectX::XMFLOAT4 color;
	/* 0x0CCC */ DirectX::XMFLOAT3 tumbling_extent;
	/* 0x0CD8 */ DirectX::XMFLOAT3 tumbling_world_position;
	/* 0x0CE4 */ DirectX::XMFLOAT4 tumbling_world_rotation;
	/* 0x0CF4 */ DirectX::XMFLOAT3 tumbling_linear_velocity;
private:
	/* 0x0D00 */ char pad_0xD00[0xA0];
public:
	/* 0x0DA0 */ std::string name_tag;
	/* 0x0DC0 */ bool name_tag_requires_line_of_sight;
private:
	/* 0x0DC1 */ char pad_0xDC1[0x3];
public:
	/* 0x0DC4 */ DirectX::XMFLOAT4 name_tag_color;
	/* 0x0DD4 */ float name_tag_fade_distance;
	/* 0x0DD8 */ float name_tag_render_distance;
	/* 0x0DDC */ __int32 name_tag_update_counter;
}; // Size: 0xDE0

static_assert(sizeof(Character) == 0xDE0, "Character: Incorrect Size");
#else
class Character : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ __int16 world_id;
private:
	/* 0x0032 */ char pad_0x32[0x6];
public:
	/* 0x0038 */ __int64 owner_steam_id;
	/* 0x0040 */ bool is_player;
private:
	/* 0x0041 */ char pad_0x41[0x3];
public:
	/* 0x0044 */ __int32 unit_id;
	/* 0x0048 */ boost::uuids::uuid uuid;
	/* 0x0058 */ bool is_downed;
	/* 0x0059 */ bool is_swimming;
	/* 0x005A */ bool is_diving;
private:
	/* 0x005B */ char pad_0x5B[0x1];
public:
	/* 0x005C */ bool is_climbing;
	/* 0x005D */ bool is_tumbling;
private:
	/* 0x005E */ char pad_0x5E[0x2];
public:
	/* 0x0060 */ float movement_speed_fraction;
private:
	/* 0x0064 */ char pad_0x64[0x4];
public:
	/* 0x0068 */ std::vector<std::string> animation_list;
	/* 0x0080 */ DirectX::XMFLOAT3 spawn_position;
private:
	/* 0x008C */ char pad_0x8C[0x1C];
public:
	/* 0x00A8 */ DirectX::XMFLOAT3 velocity;
	/* 0x00B4 */ DirectX::XMFLOAT3 acceleration;
private:
	/* 0x00C0 */ char pad_0xC0[0x14];
public:
	/* 0x00D4 */ __int32 control_key_sum;
	/* 0x00D8 */ float walk_direction_radians;
	/* 0x00DC */ float yaw;
	/* 0x00E0 */ float pitch;
	/* 0x00E4 */ float yaw2;
	/* 0x00E8 */ float pitch2;
	/* 0x00EC */ DirectX::XMFLOAT3 up_direction_cpy;
	/* 0x00F8 */ DirectX::XMFLOAT3 up_direction;
	/* 0x0104 */ float yaw3;
	/* 0x0108 */ float pitch3;
private:
	/* 0x010C */ char pad_0x10C[0x4];
public:
	/* 0x0110 */ __int32 locking_interactable_id;
private:
	/* 0x0114 */ char pad_0x114[0x1C];
public:
	/* 0x0130 */ bool is_on_ground;
private:
	/* 0x0131 */ char pad_0x131[0x3];
public:
	/* 0x0134 */ float air_time;
	/* 0x0138 */ DirectX::XMFLOAT3 ground_normal;
private:
	/* 0x0144 */ char pad_0x144[0xC];
public:
	/* 0x0150 */ boost::uuids::uuid selected_tool_uuid;
	/* 0x0160 */ __int32 selected_tool_id;
	/* 0x0164 */ boost::uuids::uuid prev_selected_tool_uuid;
	/* 0x0174 */ __int32 prev_selected_tool_id;
private:
	/* 0x0178 */ char pad_0x178[0x2];
public:
	/* 0x017A */ __int8 crouch_state;
private:
	/* 0x017B */ char pad_0x17B[0x1D];
public:
	/* 0x0198 */ std::shared_ptr<struct CharacterController> m_pController;
	/* 0x01A8 */ std::shared_ptr<struct CharacterPhysicsProxy> m_pPhysicsProxy;
	/* 0x01B8 */ std::shared_ptr<struct RagdollPhysicsProxy> m_pRagdollPhysicsProxy;
private:
	/* 0x01C8 */ char pad_0x1C8[0xB8];
public:
	/* 0x0280 */ float walk_speed;
	/* 0x0284 */ float aim_speed;
	/* 0x0288 */ float crouch_speed;
	/* 0x028C */ float sprint_speed;
	/* 0x0290 */ float jump_strength;
	/* 0x0294 */ float radius;
	/* 0x0298 */ float height;
	/* 0x029C */ float height_crouch;
	/* 0x02A0 */ float mass;
private:
	/* 0x02A4 */ char pad_0x2A4[0xC];
public:
	/* 0x02B0 */ bool can_swim;
private:
	/* 0x02B1 */ char pad_0x2B1[0x3];
public:
	/* 0x02B4 */ CharacterScriptData script_data;
private:
	/* 0x02BC */ char pad_0x2BC[0x4];
public:
	/* 0x02C0 */ std::string script_path;
	/* 0x02E0 */ std::string script_class;
	/* 0x0300 */ __int32 script_ref;
private:
	/* 0x0304 */ char pad_0x304[0x8];
public:
	/* 0x030C */ DirectX::XMFLOAT4 color;
	/* 0x031C */ DirectX::XMFLOAT3 tumbling_extent;
	/* 0x0328 */ DirectX::XMFLOAT3 tumbling_world_position;
	/* 0x0334 */ DirectX::XMFLOAT4 tumbling_world_rotation;
	/* 0x0344 */ DirectX::XMFLOAT3 tumbling_linear_velocity;
private:
	/* 0x0350 */ char pad_0x350[0x20];
public:
	/* 0x0370 */ std::string name_tag;
	/* 0x0390 */ bool name_tag_requires_line_of_sight;
private:
	/* 0x0391 */ char pad_0x391[0x3];
public:
	/* 0x0394 */ DirectX::XMFLOAT4 name_tag_color;
	/* 0x03A4 */ float name_tag_fade_distance;
	/* 0x03A8 */ float name_tag_render_distance;
	/* 0x03AC */ __int32 name_tag_update_counter;
}; // Size: 0x3B0

static_assert(sizeof(Character) == 0x3B0, "Character: Incorrect Size");
#endif