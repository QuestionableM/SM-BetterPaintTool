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

#if _SM_VERSION_NUM >= 070771
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

enum ECharacterMovementState : __int8
{
	ECharacterMovementState_Standing = 1,
	ECharacterMovementState_Crouching = 2,
	ECharacterMovementState_Sitting = 3
};

class Character : public NetObj
{
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ __int16 m_worldId;
private:
	/* 0x0032 */ char pad_0x32[0x6];
public:
	/* 0x0038 */ __int64 m_ownerSteamId;
	/* 0x0040 */ bool m_isPlayer;
private:
	/* 0x0041 */ char pad_0x41[0x3];
public:
	/* 0x0044 */ __int32 m_unitId;
	/* 0x0048 */ boost::uuids::uuid m_uuid;
	/* 0x0058 */ bool m_bDowned;
	/* 0x0059 */ bool m_bSwimming;
	/* 0x005A */ bool m_bDiving;
private:
	/* 0x005B */ char pad_0x5B[0x1];
public:
	/* 0x005C */ bool m_bClimbing;
	/* 0x005D */ bool m_bTumbling;
private:
	/* 0x005E */ char pad_0x5E[0x2];
public:
	/* 0x0060 */ float m_fMovementSpeedFraction;
private:
	/* 0x0064 */ char pad_0x64[0x4];
public:
	/* 0x0068 */ std::vector<std::string> m_vecAnimations;
	/* 0x0080 */ DirectX::XMFLOAT3 m_spawnPosition;
private:
	/* 0x008C */ char pad_0x8C[0x1C];
public:
	/* 0x00A8 */ DirectX::XMFLOAT3 m_position;
	/* 0x00B4 */ DirectX::XMFLOAT3 m_velocityDirection;
	/* 0x00C0 */ DirectX::XMFLOAT3 m_velocity;
	/* 0x00CC */ DirectX::XMFLOAT3 m_acceleration;
private:
	/* 0x00D8 */ char pad_0xD8[0x7CC];
public:
	/* 0x08A4 */ DirectX::XMFLOAT3 m_upDirection;
private:
	/* 0x08B0 */ char pad_0x8B0[0x8];
public:
	/* 0x08B8 */ __int32 m_nextLockingInteractableId;
	/* 0x08BC */ __int32 m_lockingInteractableId;
private:
	/* 0x08C0 */ char pad_0x8C0[0x18];
public:
	/* 0x08D8 */ bool m_isOnGround;
private:
	/* 0x08D9 */ char pad_0x8D9[0x3];
public:
	/* 0x08DC */ float m_fAirTime;
	/* 0x08E0 */ DirectX::XMFLOAT3 m_groundNormal;
private:
	/* 0x08EC */ char pad_0x8EC[0xC];
public:
	/* 0x08F8 */ boost::uuids::uuid m_selectedToolUuid;
	/* 0x0908 */ __int32 m_selectedToolId;
	/* 0x090C */ boost::uuids::uuid m_prevSelectedToolUuid;
	/* 0x091C */ __int32 m_prevSelectedToolId;
private:
	/* 0x0920 */ char pad_0x920[0x2];
public:
	/* 0x0922 */ ECharacterMovementState m_charMovementState;
private:
	/* 0x0923 */ char pad_0x923[0x225];
public:
	/* 0x0B48 */ std::shared_ptr<struct CharacterController> m_pController;
	/* 0x0B58 */ std::shared_ptr<struct CharacterPhysicsProxy> m_pPhysicsProxy;
	/* 0x0B68 */ std::shared_ptr<struct RagdollPhysicsProxy> m_pRagdollPhysicsProxy;
private:
	/* 0x0B78 */ char pad_0xB78[0xAC];
public:
	/* 0x0C24 */ CharacterControllerData m_controllerData;
	/* 0x0C58 */ CharacterScriptData m_scriptData;
	/* 0x0C60 */ bool m_bCanSwim;
private:
	/* 0x0C61 */ char pad_0xC61[0xF];
public:
	/* 0x0C70 */ std::string m_scriptPath;
	/* 0x0C90 */ std::string m_scriptClass;
	/* 0x0CB0 */ __int32 m_scriptRef;
	/* 0x0CB4 */ __int32 m_publicDataScriptRef;
private:
	/* 0x0CB8 */ char pad_0xCB8[0x88];
public:
	/* 0x0D40 */ DirectX::XMFLOAT4 m_color;
	/* 0x0D50 */ DirectX::XMFLOAT3 m_tumblingExtent;
	/* 0x0D5C */ DirectX::XMFLOAT3 m_tumblingWorldPosition;
	/* 0x0D68 */ DirectX::XMFLOAT4 m_tumblingWorldRotation;
	/* 0x0D78 */ DirectX::XMFLOAT3 m_tumblingLinearVelocity;
private:
	/* 0x0D84 */ char pad_0xD84[0x1C];
public:
	/* 0x0DA0 */ std::string m_nameTag;
	/* 0x0DC0 */ bool m_nameTagRequiresLineOfSight;
private:
	/* 0x0DC1 */ char pad_0xDC1[0x3];
public:
	/* 0x0DC4 */ DirectX::XMFLOAT4 m_nameTagColor;
	/* 0x0DD4 */ float m_nameTagFadeDistance;
	/* 0x0DD8 */ float m_nameTagRenderDistance;
	/* 0x0DDC */ __int32 m_nameTagUpdateCounter;
}; // Size: 0xDE0


static_assert(offsetof(Character, Character::m_worldId) == 0x30, "Character::m_worldId: Incorrect offset");
static_assert(offsetof(Character, Character::m_ownerSteamId) == 0x38, "Character::m_ownerSteamId: Incorrect offset");
static_assert(offsetof(Character, Character::m_isPlayer) == 0x40, "Character::m_isPlayer: Incorrect offset");
static_assert(offsetof(Character, Character::m_unitId) == 0x44, "Character::m_unitId: Incorrect offset");
static_assert(offsetof(Character, Character::m_uuid) == 0x48, "Character::m_uuid: Incorrect offset");
static_assert(offsetof(Character, Character::m_bDowned) == 0x58, "Character::m_bDowned: Incorrect offset");
static_assert(offsetof(Character, Character::m_bSwimming) == 0x59, "Character::m_bSwimming: Incorrect offset");
static_assert(offsetof(Character, Character::m_bDiving) == 0x5A, "Character::m_bDiving: Incorrect offset");
static_assert(offsetof(Character, Character::m_bClimbing) == 0x5C, "Character::m_bClimbing: Incorrect offset");
static_assert(offsetof(Character, Character::m_bTumbling) == 0x5D, "Character::m_bTumbling: Incorrect offset");
static_assert(offsetof(Character, Character::m_fMovementSpeedFraction) == 0x60, "Character::m_fMovementSpeedFraction: Incorrect offset");
static_assert(offsetof(Character, Character::m_vecAnimations) == 0x68, "Character::m_vecAnimations: Incorrect offset");
static_assert(offsetof(Character, Character::m_spawnPosition) == 0x80, "Character::m_spawnPosition: Incorrect offset");
static_assert(offsetof(Character, Character::m_position) == 0xA8, "Character::m_position: Incorrect offset");
static_assert(offsetof(Character, Character::m_velocityDirection) == 0xB4, "Character::m_velocityDirection: Incorrect offset");
static_assert(offsetof(Character, Character::m_velocity) == 0xC0, "Character::m_velocity: Incorrect offset");
static_assert(offsetof(Character, Character::m_acceleration) == 0xCC, "Character::m_acceleration: Incorrect offset");
static_assert(offsetof(Character, Character::m_upDirection) == 0x8A4, "Character::m_upDirection: Incorrect offset");
static_assert(offsetof(Character, Character::m_nextLockingInteractableId) == 0x8B8, "Character::m_nextLockingInteractableId: Incorrect offset");
static_assert(offsetof(Character, Character::m_lockingInteractableId) == 0x8BC, "Character::m_lockingInteractableId: Incorrect offset");
static_assert(offsetof(Character, Character::m_isOnGround) == 0x8D8, "Character::m_isOnGround: Incorrect offset");
static_assert(offsetof(Character, Character::m_fAirTime) == 0x8DC, "Character::m_fAirTime: Incorrect offset");
static_assert(offsetof(Character, Character::m_groundNormal) == 0x8E0, "Character::m_groundNormal: Incorrect offset");
static_assert(offsetof(Character, Character::m_selectedToolUuid) == 0x8F8, "Character::m_selectedToolUuid: Incorrect offset");
static_assert(offsetof(Character, Character::m_selectedToolId) == 0x908, "Character::m_selectedToolId: Incorrect offset");
static_assert(offsetof(Character, Character::m_prevSelectedToolUuid) == 0x90C, "Character::m_prevSelectedToolUuid: Incorrect offset");
static_assert(offsetof(Character, Character::m_prevSelectedToolId) == 0x91C, "Character::m_prevSelectedToolId: Incorrect offset");
static_assert(offsetof(Character, Character::m_charMovementState) == 0x922, "Character::m_charMovementState: Incorrect offset");
static_assert(offsetof(Character, Character::m_pController) == 0xB48, "Character::m_pController: Incorrect offset");
static_assert(offsetof(Character, Character::m_pPhysicsProxy) == 0xB58, "Character::m_pPhysicsProxy: Incorrect offset");
static_assert(offsetof(Character, Character::m_pRagdollPhysicsProxy) == 0xB68, "Character::m_pRagdollPhysicsProxy: Incorrect offset");
static_assert(offsetof(Character, Character::m_controllerData) == 0xC24, "Character::m_controllerData: Incorrect offset");
static_assert(offsetof(Character, Character::m_scriptData) == 0xC58, "Character::m_scriptData: Incorrect offset");
static_assert(offsetof(Character, Character::m_bCanSwim) == 0xC60, "Character::m_bCanSwim: Incorrect offset");
static_assert(offsetof(Character, Character::m_scriptPath) == 0xC70, "Character::m_scriptPath: Incorrect offset");
static_assert(offsetof(Character, Character::m_scriptClass) == 0xC90, "Character::m_scriptClass: Incorrect offset");
static_assert(offsetof(Character, Character::m_scriptRef) == 0xCB0, "Character::m_scriptRef: Incorrect offset");
static_assert(offsetof(Character, Character::m_publicDataScriptRef) == 0xCB4, "Character::m_publicDataScriptRef: Incorrect offset");
static_assert(offsetof(Character, Character::m_color) == 0xD40, "Character::m_color: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingExtent) == 0xD50, "Character::m_tumblingExtent: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingWorldPosition) == 0xD5C, "Character::m_tumblingWorldPosition: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingWorldRotation) == 0xD68, "Character::m_tumblingWorldRotation: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingLinearVelocity) == 0xD78, "Character::m_tumblingLinearVelocity: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTag) == 0xDA0, "Character::m_nameTag: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTagRequiresLineOfSight) == 0xDC0, "Character::m_nameTagRequiresLineOfSight: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTagColor) == 0xDC4, "Character::m_nameTagColor: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTagFadeDistance) == 0xDD4, "Character::m_nameTagFadeDistance: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTagRenderDistance) == 0xDD8, "Character::m_nameTagRenderDistance: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTagUpdateCounter) == 0xDDC, "Character::m_nameTagUpdateCounter: Incorrect offset");

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