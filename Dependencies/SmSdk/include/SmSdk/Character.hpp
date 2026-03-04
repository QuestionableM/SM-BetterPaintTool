#pragma once

#include "SmSdk/bullet_include.hpp"
#include "SmSdk/boost_include.hpp"
#include "SmSdk/Base/NetObj.hpp"
#include "SmSdk/offsets.hpp"

#include <DirectXMath.h>

#include <vector>
#include <memory>
#include <string>

SMSDK_BEGIN_NAMESPACE

struct CharacterScriptData
{
	/* 0x0000 */ SDK_PUB bool m_bHasClientOnGraphicsLoaded;
	/* 0x0001 */ SDK_PUB bool m_bHasClientOnGraphicsUnloaded;
	/* 0x0002 */ SDK_PUB bool m_bHasClientCanInteract;
	/* 0x0003 */ SDK_PUB bool m_bHasClientOnInteract;
	/* 0x0004 */ SDK_PUB bool m_bHasClientOnProjectile;
	/* 0x0005 */ SDK_PUB bool m_bHasClientOnMelee;
	/* 0x0006 */ SDK_PUB bool m_bHasClientOnCollision;
	/* 0x0007 */ SDK_PRI char pad_0x7[0x1];
}; // Size: 0x8

static_assert(sizeof(CharacterScriptData) == 0x8, "CharacterScriptData: Incorrect Size");

class CharacterController : public btActionInterface
{
	/* 0x0008 */ SDK_PRI char pad_0x8[0x8];
	/* 0x0010 */ SDK_PUB float m_fGroundTraction;
	/* 0x0014 */ SDK_PUB float m_fAirTraction;
	/* 0x0018 */ SDK_PRI std::int32_t m_iUnk1;
	/* 0x001C */ SDK_PRI float m_fUnk1;
	/* 0x0020 */ SDK_PRI float m_fUnk2;
	/* 0x0024 */ SDK_PUB float m_fStepOverHeight;
	/* 0x0028 */ SDK_PRI float m_fUnk3;
	/* 0x002C */ SDK_PUB float m_fGravity;
	/* 0x0030 */ SDK_PUB float m_fMass;
	/* 0x0034 */ SDK_PRI float m_fUnk4;
	/* 0x0038 */ SDK_PUB btPairCachingGhostObject* m_pPairCachingGhostObject;
	/* 0x0040 */ SDK_PUB float m_fFallVelocity;
	/* 0x0044 */ SDK_PUB float m_fFallAcceleration;
	/* 0x0048 */ SDK_PUB float m_fJumpStrength;
	/* 0x004C */ SDK_PRI float m_fUnk5;
	/* 0x0050 */ SDK_PRI char pad_0x50[0x10];
	/* 0x0060 */ SDK_PUB btVector3 m_targetMovementVelocity;
	/* 0x0070 */ SDK_PUB btVector3 m_movementVelocity;
	/* 0x0080 */ SDK_PRI char pad_0x80[0x20];
	/* 0x00A0 */ SDK_PUB btVector3 m_targetFinalWorldMovement;
	/* 0x00B0 */ SDK_PUB btVector3 m_finalWorldMovement;
	/* 0x00C0 */ SDK_PUB btVector3 m_worldMovement2;
	/* 0x00D0 */ SDK_PRI char pad_0xD0[0x40];
	/* 0x0110 */ SDK_PUB btVector3 m_surfaceNormal;
	/* 0x0120 */ SDK_PUB float m_fStepOverHeightCpy;
	/* 0x0124 */ SDK_PUB std::uint32_t m_uTicksInAir;
	/* 0x0128 */ SDK_PRI char pad_0x128[0x8];
	/* 0x0130 */ SDK_PUB std::uint8_t m_eSurfaceType;
	/* 0x0131 */ SDK_PRI char pad_0x131[0x7];
	/* 0x0138 */ SDK_PUB std::uint32_t m_uBodyId;
	/* 0x013C */ SDK_PRI char pad_0x13C[0x14];
	/* 0x0150 */ SDK_PUB btVector3 m_lastTouchedGlobalPos;
	/* 0x0160 */ SDK_PUB btVector3 m_lastTouchedLocalPos;
	/* 0x0170 */ SDK_PUB bool m_bInAir;
	/* 0x0171 */ SDK_PRI char pad_0x171[0x2F];
}; // Size: 0x1A0

static_assert(offsetof(CharacterController, CharacterController::m_fGroundTraction) == 0x10, "CharacterController::m_fGroundTraction: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fAirTraction) == 0x14, "CharacterController::m_fAirTraction: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fStepOverHeight) == 0x24, "CharacterController::m_fStepOverHeight: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fGravity) == 0x2C, "CharacterController::m_fGravity: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fMass) == 0x30, "CharacterController::m_fMass: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_pPairCachingGhostObject) == 0x38, "CharacterController::m_pPairCachingGhostObject: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fFallVelocity) == 0x40, "CharacterController::m_fFallVelocity: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fFallAcceleration) == 0x44, "CharacterController::m_fFallAcceleration: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fJumpStrength) == 0x48, "CharacterController::m_fJumpStrength: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_targetMovementVelocity) == 0x60, "CharacterController::m_targetMovementVelocity: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_movementVelocity) == 0x70, "CharacterController::m_movementVelocity: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_targetFinalWorldMovement) == 0xA0, "CharacterController::m_targetFinalWorldMovement: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_finalWorldMovement) == 0xB0, "CharacterController::m_finalWorldMovement: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_worldMovement2) == 0xC0, "CharacterController::m_worldMovement2: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_surfaceNormal) == 0x110, "CharacterController::m_surfaceNormal: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_fStepOverHeightCpy) == 0x120, "CharacterController::m_fStepOverHeightCpy: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_uTicksInAir) == 0x124, "CharacterController::m_uTicksInAir: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_eSurfaceType) == 0x130, "CharacterController::m_eSurfaceType: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_uBodyId) == 0x138, "CharacterController::m_uBodyId: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_lastTouchedGlobalPos) == 0x150, "CharacterController::m_lastTouchedGlobalPos: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_lastTouchedLocalPos) == 0x160, "CharacterController::m_lastTouchedLocalPos: Incorrect offset");
static_assert(offsetof(CharacterController, CharacterController::m_bInAir) == 0x170, "CharacterController::m_bInAir: Incorrect offset");

static_assert(sizeof(CharacterController) == 0x1A0, "CharacterController: Incorrect Size");

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
private:
	/* 0x0024 */ char pad_0x24[0xC];
public:
	/* 0x0030 */ bool m_bCanSwim;
private:
	/* 0x0031 */ char pad_0x31[0x3];
}; // Size: 0x34

static_assert(sizeof(CharacterControllerData) == 0x34, "CharacterControllerData: Incorrect Size");

enum ECharacterMovementState : std::int8_t
{
	ECharacterMovementState_Standing = 1,
	ECharacterMovementState_Crouching = 2,
	ECharacterMovementState_Sitting = 3
};

class Character : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
	/* 0x0030 */ SDK_PUB std::int16_t m_iWorldId;
	/* 0x0032 */ SDK_PRI char pad_0x32[0x6];
	/* 0x0038 */ SDK_PUB std::int64_t m_iOwnerSteamId;
	/* 0x0040 */ SDK_PUB bool m_bIsPlayer;
	/* 0x0041 */ SDK_PRI char pad_0x41[0x3];
	/* 0x0044 */ SDK_PUB std::int32_t m_iUnitId;
	/* 0x0048 */ SDK_PUB boost::uuids::uuid m_uuid;
	/* 0x0058 */ SDK_PUB bool m_bDowned;
	/* 0x0059 */ SDK_PUB bool m_bSwimming;
	/* 0x005A */ SDK_PUB bool m_bDiving;
	/* 0x005B */ SDK_PRI char pad_0x5B[0x1];
	/* 0x005C */ SDK_PUB bool m_bClimbing;
	/* 0x005D */ SDK_PUB bool m_bTumbling;
	/* 0x005E */ SDK_PRI char pad_0x5E[0x2];
	/* 0x0060 */ SDK_PUB float m_fMovementSpeedFraction;
	/* 0x0064 */ SDK_PRI char pad_0x64[0x4];
	/* 0x0068 */ SDK_PUB std::vector<std::string> m_vecAnimations;
	/* 0x0080 */ SDK_PUB DirectX::XMFLOAT3 m_spawnPosition;
	/* 0x008C */ SDK_PRI char pad_0x8C[0x1C];
	/* 0x00A8 */ SDK_PUB DirectX::XMFLOAT3 m_position;
	/* 0x00B4 */ SDK_PUB DirectX::XMFLOAT3 m_velocityDirection;
	/* 0x00C0 */ SDK_PUB DirectX::XMFLOAT3 m_velocity;
	/* 0x00CC */ SDK_PUB DirectX::XMFLOAT3 m_acceleration;
	/* 0x00D8 */ SDK_PRI char pad_0xD8[0x7CC];
	/* 0x08A4 */ SDK_PUB DirectX::XMFLOAT3 m_upDirection;
	/* 0x08B0 */ SDK_PRI char pad_0x8B0[0x8];
	/* 0x08B8 */ SDK_PUB std::int32_t m_iNextLockingInteractableId;
	/* 0x08BC */ SDK_PUB std::int32_t m_iLockingInteractableId;
	/* 0x08C0 */ SDK_PRI char pad_0x8C0[0x18];
	/* 0x08D8 */ SDK_PUB bool m_bIsOnGround;
	/* 0x08D9 */ SDK_PRI char pad_0x8D9[0x3];
	/* 0x08DC */ SDK_PUB float m_fAirTime;
	/* 0x08E0 */ SDK_PUB DirectX::XMFLOAT3 m_groundNormal;
	/* 0x08EC */ SDK_PRI char pad_0x8EC[0xC];
	/* 0x08F8 */ SDK_PUB boost::uuids::uuid m_selectedToolUuid;
	/* 0x0908 */ SDK_PUB std::int32_t m_iSelectedToolId;
	/* 0x090C */ SDK_PUB boost::uuids::uuid m_prevSelectedToolUuid;
	/* 0x091C */ SDK_PUB std::int32_t m_iPrevSelectedToolId;
	/* 0x0920 */ SDK_PRI char pad_0x920[0x2];
	/* 0x0922 */ SDK_PUB ECharacterMovementState m_charMovementState;
	/* 0x0923 */ SDK_PRI char pad_0x923[0x225];
	/* 0x0B48 */ SDK_PUB std::shared_ptr<CharacterController> m_pController;
	/* 0x0B58 */ SDK_PUB std::shared_ptr<struct CharacterPhysicsProxy> m_pPhysicsProxy;
	/* 0x0B68 */ SDK_PUB std::shared_ptr<struct RagdollPhysicsProxy> m_pRagdollPhysicsProxy;
	/* 0x0B78 */ SDK_PRI char pad_0xB78[0xAC];
	/* 0x0C24 */ SDK_PUB CharacterControllerData m_controllerData;
	/* 0x0C58 */ SDK_PUB CharacterScriptData m_scriptData;
	/* 0x0C60 */ SDK_PUB bool m_bCanSwim;
	/* 0x0C61 */ SDK_PRI char pad_0xC61[0xF];
	/* 0x0C70 */ SDK_PUB std::string m_scriptPath;
	/* 0x0C90 */ SDK_PUB std::string m_scriptClass;
	/* 0x0CB0 */ SDK_PUB std::int32_t m_iScriptRef;
	/* 0x0CB4 */ SDK_PUB std::int32_t m_iPublicDataScriptRef;
	/* 0x0CB8 */ SDK_PRI char pad_0xCB8[0x88];
	/* 0x0D40 */ SDK_PUB DirectX::XMFLOAT4 m_color;
	/* 0x0D50 */ SDK_PUB DirectX::XMFLOAT3 m_tumblingExtent;
	/* 0x0D5C */ SDK_PUB DirectX::XMFLOAT3 m_tumblingWorldPosition;
	/* 0x0D68 */ SDK_PUB DirectX::XMFLOAT4 m_tumblingWorldRotation;
	/* 0x0D78 */ SDK_PUB DirectX::XMFLOAT3 m_tumblingLinearVelocity;
	/* 0x0D84 */ SDK_PRI char pad_0xD84[0x1C];
	/* 0x0DA0 */ SDK_PUB std::string m_nameTag;
	/* 0x0DC0 */ SDK_PUB bool m_nameTagRequiresLineOfSight;
	/* 0x0DC1 */ SDK_PRI char pad_0xDC1[0x3];
	/* 0x0DC4 */ SDK_PUB DirectX::XMFLOAT4 m_nameTagColor;
	/* 0x0DD4 */ SDK_PUB float m_fNameTagFadeDistance;
	/* 0x0DD8 */ SDK_PUB float m_fNameTagRenderDistance;
	/* 0x0DDC */ SDK_PUB std::int32_t m_iNameTagUpdateCounter;
}; // Size: 0xDE0

static_assert(offsetof(Character, Character::m_iWorldId) == 0x30, "Character::m_iWorldId: Incorrect offset");
static_assert(offsetof(Character, Character::m_iOwnerSteamId) == 0x38, "Character::m_iOwnerSteamId: Incorrect offset");
static_assert(offsetof(Character, Character::m_bIsPlayer) == 0x40, "Character::m_bIsPlayer: Incorrect offset");
static_assert(offsetof(Character, Character::m_iUnitId) == 0x44, "Character::m_iUnitId: Incorrect offset");
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
static_assert(offsetof(Character, Character::m_iNextLockingInteractableId) == 0x8B8, "Character::m_iNextLockingInteractableId: Incorrect offset");
static_assert(offsetof(Character, Character::m_iLockingInteractableId) == 0x8BC, "Character::m_iLockingInteractableId: Incorrect offset");
static_assert(offsetof(Character, Character::m_bIsOnGround) == 0x8D8, "Character::m_bIsOnGround: Incorrect offset");
static_assert(offsetof(Character, Character::m_fAirTime) == 0x8DC, "Character::m_fAirTime: Incorrect offset");
static_assert(offsetof(Character, Character::m_groundNormal) == 0x8E0, "Character::m_groundNormal: Incorrect offset");
static_assert(offsetof(Character, Character::m_selectedToolUuid) == 0x8F8, "Character::m_selectedToolUuid: Incorrect offset");
static_assert(offsetof(Character, Character::m_iSelectedToolId) == 0x908, "Character::m_selectedToolId: Incorrect offset");
static_assert(offsetof(Character, Character::m_prevSelectedToolUuid) == 0x90C, "Character::m_prevSelectedToolUuid: Incorrect offset");
static_assert(offsetof(Character, Character::m_iPrevSelectedToolId) == 0x91C, "Character::m_iPrevSelectedToolId: Incorrect offset");
static_assert(offsetof(Character, Character::m_charMovementState) == 0x922, "Character::m_charMovementState: Incorrect offset");
static_assert(offsetof(Character, Character::m_pController) == 0xB48, "Character::m_pController: Incorrect offset");
static_assert(offsetof(Character, Character::m_pPhysicsProxy) == 0xB58, "Character::m_pPhysicsProxy: Incorrect offset");
static_assert(offsetof(Character, Character::m_pRagdollPhysicsProxy) == 0xB68, "Character::m_pRagdollPhysicsProxy: Incorrect offset");
static_assert(offsetof(Character, Character::m_controllerData) == 0xC24, "Character::m_controllerData: Incorrect offset");
static_assert(offsetof(Character, Character::m_scriptData) == 0xC58, "Character::m_scriptData: Incorrect offset");
static_assert(offsetof(Character, Character::m_bCanSwim) == 0xC60, "Character::m_bCanSwim: Incorrect offset");
static_assert(offsetof(Character, Character::m_scriptPath) == 0xC70, "Character::m_scriptPath: Incorrect offset");
static_assert(offsetof(Character, Character::m_scriptClass) == 0xC90, "Character::m_scriptClass: Incorrect offset");
static_assert(offsetof(Character, Character::m_iScriptRef) == 0xCB0, "Character::m_iScriptRef: Incorrect offset");
static_assert(offsetof(Character, Character::m_iPublicDataScriptRef) == 0xCB4, "Character::m_iPublicDataScriptRef: Incorrect offset");
static_assert(offsetof(Character, Character::m_color) == 0xD40, "Character::m_color: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingExtent) == 0xD50, "Character::m_tumblingExtent: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingWorldPosition) == 0xD5C, "Character::m_tumblingWorldPosition: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingWorldRotation) == 0xD68, "Character::m_tumblingWorldRotation: Incorrect offset");
static_assert(offsetof(Character, Character::m_tumblingLinearVelocity) == 0xD78, "Character::m_tumblingLinearVelocity: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTag) == 0xDA0, "Character::m_nameTag: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTagRequiresLineOfSight) == 0xDC0, "Character::m_nameTagRequiresLineOfSight: Incorrect offset");
static_assert(offsetof(Character, Character::m_nameTagColor) == 0xDC4, "Character::m_nameTagColor: Incorrect offset");
static_assert(offsetof(Character, Character::m_fNameTagFadeDistance) == 0xDD4, "Character::m_nameTagFadeDistance: Incorrect offset");
static_assert(offsetof(Character, Character::m_fNameTagRenderDistance) == 0xDD8, "Character::m_nameTagRenderDistance: Incorrect offset");
static_assert(offsetof(Character, Character::m_iNameTagUpdateCounter) == 0xDDC, "Character::m_iNameTagUpdateCounter: Incorrect offset");

static_assert(sizeof(Character) == 0xDE0, "Character: Incorrect Size");
#else
class Character : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
	/* 0x0030 */ SDK_PUB std::int16_t m_iWorldId;
	/* 0x0032 */ SDK_PRI char pad_0x32[0x6];
	/* 0x0038 */ SDK_PUB std::int64_t m_iOwnerSteamId;
	/* 0x0040 */ SDK_PUB bool m_bIsPlayer;
	/* 0x0041 */ SDK_PRI char pad_0x41[0x3];
	/* 0x0044 */ SDK_PUB std::int32_t m_iUnitId;
	/* 0x0048 */ SDK_PUB boost::uuids::uuid m_uuid;
	/* 0x0058 */ SDK_PUB bool m_bIsDowned;
	/* 0x0059 */ SDK_PUB bool m_bIsSwimming;
	/* 0x005A */ SDK_PUB bool m_bIsDiving;
	/* 0x005B */ SDK_PRI char pad_0x5B[0x1];
	/* 0x005C */ SDK_PUB bool m_bIsClimbing;
	/* 0x005D */ SDK_PUB bool m_bIsTumbling;
	/* 0x005E */ SDK_PRI char pad_0x5E[0x2];
	/* 0x0060 */ SDK_PUB float m_fMovementSpeedFraction;
	/* 0x0064 */ SDK_PRI char pad_0x64[0x4];
	/* 0x0068 */ SDK_PUB std::vector<std::string> m_vecAnimations;
	/* 0x0080 */ SDK_PUB DirectX::XMFLOAT3 m_spawnPosition;
	/* 0x008C */ SDK_PRI char pad_0x8C[0x1C];
	/* 0x00A8 */ SDK_PUB DirectX::XMFLOAT3 m_velocity;
	/* 0x00B4 */ SDK_PUB DirectX::XMFLOAT3 m_acceleration;
	/* 0x00C0 */ SDK_PRI char pad_0xC0[0x14];
	/* 0x00D4 */ SDK_PUB std::int32_t m_iControlKeySum;
	/* 0x00D8 */ SDK_PUB float m_fWalkDirectionRadians;
	/* 0x00DC */ SDK_PUB float m_fYaw;
	/* 0x00E0 */ SDK_PUB float m_fPitch;
	/* 0x00E4 */ SDK_PUB float m_fYaw2;
	/* 0x00E8 */ SDK_PUB float m_fPitch2;
	/* 0x00EC */ SDK_PUB DirectX::XMFLOAT3 m_upDirectionCpy;
	/* 0x00F8 */ SDK_PUB DirectX::XMFLOAT3 m_upDirection;
	/* 0x0104 */ SDK_PUB float m_fYaw3;
	/* 0x0108 */ SDK_PUB float m_fPitch3;
	/* 0x010C */ SDK_PRI char pad_0x10C[0x4];
	/* 0x0110 */ SDK_PUB std::int32_t m_iLockingInteractableId;
	/* 0x0114 */ SDK_PRI char pad_0x114[0x1C];
	/* 0x0130 */ SDK_PUB bool m_bIsOnGround;
	/* 0x0131 */ SDK_PRI char pad_0x131[0x3];
	/* 0x0134 */ SDK_PUB float m_fAirTime;
	/* 0x0138 */ SDK_PUB DirectX::XMFLOAT3 m_groundNormal;
	/* 0x0144 */ SDK_PRI char pad_0x144[0xC];
	/* 0x0150 */ SDK_PUB boost::uuids::uuid m_selectedToolUuid;
	/* 0x0160 */ SDK_PUB std::int32_t m_iSelectedToolId;
	/* 0x0164 */ SDK_PUB boost::uuids::uuid m_prevSelectedToolUuid;
	/* 0x0174 */ SDK_PUB std::int32_t m_iPrevSelectedToolId;
	/* 0x0178 */ SDK_PRI char pad_0x178[0x2];
	/* 0x017A */ SDK_PUB std::int8_t m_iCrouchState;
	/* 0x017B */ SDK_PRI char pad_0x17B[0x1D];
	/* 0x0198 */ SDK_PUB std::shared_ptr<CharacterController> m_pController;
	/* 0x01A8 */ SDK_PUB std::shared_ptr<struct CharacterPhysicsProxy> m_pPhysicsProxy;
	/* 0x01B8 */ SDK_PUB std::shared_ptr<struct RagdollPhysicsProxy> m_pRagdollPhysicsProxy;
	/* 0x01C8 */ SDK_PRI char pad_0x1C8[0xB8];
	/* 0x0280 */ SDK_PUB float m_fWalkSpeed;
	/* 0x0284 */ SDK_PUB float m_fAimSpeed;
	/* 0x0288 */ SDK_PUB float m_fCrouchSpeed;
	/* 0x028C */ SDK_PUB float m_fSprintSpeed;
	/* 0x0290 */ SDK_PUB float m_fJumpStrength;
	/* 0x0294 */ SDK_PUB float m_fRadius;
	/* 0x0298 */ SDK_PUB float m_fHeight;
	/* 0x029C */ SDK_PUB float m_fHeightCrouch;
	/* 0x02A0 */ SDK_PUB float m_fMass;
	/* 0x02A4 */ SDK_PRI char pad_0x2A4[0xC];
	/* 0x02B0 */ SDK_PUB bool m_bCanSwim;
	/* 0x02B1 */ SDK_PRI char pad_0x2B1[0x3];
	/* 0x02B4 */ SDK_PUB CharacterScriptData m_scriptData;
	/* 0x02BC */ SDK_PRI char pad_0x2BC[0x4];
	/* 0x02C0 */ SDK_PUB std::string m_scriptPath;
	/* 0x02E0 */ SDK_PUB std::string m_scriptClass;
	/* 0x0300 */ SDK_PUB std::int32_t m_iScriptRef;
	/* 0x0304 */ SDK_PRI char pad_0x304[0x8];
	/* 0x030C */ SDK_PUB DirectX::XMFLOAT4 m_color;
	/* 0x031C */ SDK_PUB DirectX::XMFLOAT3 m_tumblingExtent;
	/* 0x0328 */ SDK_PUB DirectX::XMFLOAT3 m_tumblingWorldPosition;
	/* 0x0334 */ SDK_PUB DirectX::XMFLOAT4 m_tumblingWorldRotation;
	/* 0x0344 */ SDK_PUB DirectX::XMFLOAT3 m_tumblingLinearVelocity;
	/* 0x0350 */ SDK_PRI char pad_0x350[0x20];
	/* 0x0370 */ SDK_PUB std::string m_nameTag;
	/* 0x0390 */ SDK_PUB bool m_nameTagRequiresLineOfSight;
	/* 0x0391 */ SDK_PRI char pad_0x391[0x3];
	/* 0x0394 */ SDK_PUB DirectX::XMFLOAT4 m_nameTagColor;
	/* 0x03A4 */ SDK_PUB float m_fNameTagFadeDistance;
	/* 0x03A8 */ SDK_PUB float m_fNameTagRenderDistance;
	/* 0x03AC */ SDK_PUB std::int32_t m_iNameTagUpdateCounter;
}; // Size: 0x3B0

static_assert(sizeof(Character) == 0x3B0, "Character: Incorrect Size");
#endif

SMSDK_END_NAMESPACE