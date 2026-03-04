#pragma once

#include <memory>
#include <string>

#include "SmSdk/boost_include.hpp"
#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

struct PlayerGarments
{
	/* 0x0000 */ SDK_PUB bool m_bIsFemale;
	/* 0x0001 */ SDK_PUB boost::uuids::uuid m_headUuid;
	/* 0x0011 */ SDK_PUB boost::uuids::uuid m_hairUuid;
	/* 0x0021 */ SDK_PUB boost::uuids::uuid m_facialHairUuid;
	/* 0x0031 */ SDK_PUB boost::uuids::uuid m_torsoUuid;
	/* 0x0041 */ SDK_PUB boost::uuids::uuid m_glovesUuid;
	/* 0x0051 */ SDK_PUB boost::uuids::uuid m_shoesUuid;
	/* 0x0061 */ SDK_PUB boost::uuids::uuid m_legsUuid;
	/* 0x0071 */ SDK_PUB boost::uuids::uuid m_hatUuid;
	/* 0x0081 */ SDK_PUB boost::uuids::uuid m_backpackUuid;
	/* 0x0091 */ SDK_PUB char pad_0x91[0x3];
	/* 0x0094 */ SDK_PUB std::int32_t m_headColor;
	/* 0x0098 */ SDK_PUB std::int32_t m_hairColor;
	/* 0x009C */ SDK_PUB std::int32_t m_facialHairColor;
	/* 0x00A0 */ SDK_PUB std::int32_t m_torsoColor;
	/* 0x00A4 */ SDK_PUB std::int32_t m_glovesColor;
	/* 0x00A8 */ SDK_PUB std::int32_t m_shoesColor;
	/* 0x00AC */ SDK_PUB std::int32_t m_legsColor;
	/* 0x00B0 */ SDK_PUB std::int32_t m_hatColor;
	/* 0x00B4 */ SDK_PUB std::int32_t m_backpackColor;
}; // Size: 0xB8

static_assert(sizeof(PlayerGarments) == 0xB8, "PlayerGarments: Incorrect Size");

struct PlayerScriptData
{
	/* 0x0000 */ SDK_PUB bool m_bHasServerOnRefresh;
	/* 0x0001 */ SDK_PUB bool m_bHasServerOnProjectile;
	/* 0x0002 */ SDK_PUB bool m_bHasServerOnExplosion;
	/* 0x0003 */ SDK_PUB bool m_bHasServerOnMelee;
	/* 0x0004 */ SDK_PUB bool m_bHasServerOnCollision;
	/* 0x0005 */ SDK_PUB bool m_bHasServerOnCollisionCrush;
	/* 0x0006 */ SDK_PUB bool m_bHasServerOnShapeRemoved;
	/* 0x0007 */ SDK_PUB bool m_bHasServerOnInventoryChanges;
}; // Size: 0x8

static_assert(sizeof(PlayerScriptData) == 0x8, "PlayerScriptData: Incorrect Size");

class Character;

class Player
{
	SDK_PUB Character* getCharacter() const;
	SDK_PUB bool characterExists() const;

	/* 0x0000 */ SDK_PUB std::shared_ptr<Player> m_pSelf;
	/* 0x0010 */ SDK_PUB std::int32_t m_iId;
	/* 0x0014 */ SDK_PUB std::int32_t m_iCharacterId;
	/* 0x0018 */ SDK_PUB std::int16_t m_worldId;
	/* 0x001A */ SDK_PRI char pad_0x1A[0x2];
	/* 0x001C */ SDK_PUB DirectX::XMFLOAT3 m_characterPosition;
	/* 0x0028 */ SDK_PUB DirectX::XMFLOAT3 m_characterVelocity;
	/* 0x0034 */ SDK_PUB float m_fCharacterYaw;
	/* 0x0038 */ SDK_PUB float m_fCharacterPitch;
	/* 0x003C */ SDK_PRI char pad_0x3C[0x4];
	/* 0x0040 */ SDK_PUB std::int64_t m_steamId;
	/* 0x0048 */ SDK_PUB std::string m_name;
	/* 0x0068 */ SDK_PRI char pad_0x68[0x4];
	/* 0x006C */ SDK_PUB PlayerGarments m_garments;
	/* 0x0124 */ SDK_PUB std::int32_t m_iGarmentChangeCounter;
	/* 0x0128 */ SDK_PRI char pad_0x128[0x10];
	/* 0x0138 */ SDK_PUB std::int32_t m_scriptRef;
	/* 0x013C */ SDK_PUB PlayerScriptData m_scriptData;
	/* 0x0144 */ SDK_PRI char pad_0x144[0xC];
}; // Size: 0x150

static_assert(sizeof(Player) == 0x150, "Player: Incorrect Size");

SMSDK_END_NAMESPACE