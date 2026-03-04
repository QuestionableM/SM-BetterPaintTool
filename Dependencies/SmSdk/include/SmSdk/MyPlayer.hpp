#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/config.hpp"

#include "SmSdk/Base/Aligned16Base.hpp"
#include "SmSdk/Base/InputTarget.hpp"
#include "SmSdk/Player.hpp"

#include <DirectXMath.h>

#include <memory>

SMSDK_BEGIN_NAMESPACE

struct PlayerCamera
{
	/* 0x0000 */ SDK_PUB DirectX::XMFLOAT3 cam_character_pos;
	/* 0x000C */ SDK_PUB DirectX::XMFLOAT3 some_vector;
	/* 0x0018 */ SDK_PUB DirectX::XMFLOAT3 position;
	/* 0x0024 */ SDK_PUB DirectX::XMFLOAT3 direction;
	/* 0x0030 */ SDK_PUB DirectX::XMFLOAT3 up;
	/* 0x003C */ SDK_PUB DirectX::XMFLOAT3 some_vector2;
	/* 0x0048 */ SDK_PUB DirectX::XMFLOAT4 some_quat;
	/* 0x0058 */ SDK_PUB float up_offset;
	/* 0x005C */ SDK_PUB float pullback;
	/* 0x0060 */ SDK_PUB float fov;
	/* 0x0064 */ SDK_PUB float shake;
}; // Size: 0x68

static_assert(sizeof(PlayerCamera) == 0x68, "PlayerCamera: Incorrect Size");

class Viewer : public Aligned16Base
{
	SDK_PUB virtual ~Viewer() = default;

	/* 0x0010 */ SDK_PUB bool going_forwards;
	/* 0x0011 */ SDK_PUB bool going_backwards;
	/* 0x0012 */ SDK_PUB bool going_left;
	/* 0x0013 */ SDK_PUB bool going_right;
	/* 0x0014 */ SDK_PRI char pad_0x14[0x4];
	/* 0x0018 */ SDK_PUB double yaw;
	/* 0x0020 */ SDK_PUB double pitch;
	/* 0x0028 */ SDK_PUB double delta_yaw;
	/* 0x0030 */ SDK_PUB double delta_pitch;
	/* 0x0038 */ SDK_PUB double yaw_no_clamp;
	/* 0x0040 */ SDK_PUB double pitch_no_clamp;
	/* 0x0048 */ SDK_PUB double delta_yaw2;
	/* 0x0050 */ SDK_PUB double delta_pitch2;
	/* 0x0058 */ SDK_PRI char pad_0x58[0x8];
}; // Size: 0x60

static_assert(sizeof(Viewer) == 0x60, "Viewer: Incorrect Size");

class Character;

class MyPlayer : public InputTarget, public Viewer
{
	REMOVE_COPY_CONSTRUCTORS(MyPlayer);

	SDK_PUB static MyPlayer* GetInstance();

	SDK_PUB Character* getCharacter() const;

	/* 0x0070 */ SDK_PUB std::shared_ptr<Player> m_player;
	/* 0x0080 */ SDK_PUB std::int8_t m_controlCharacterSum;
	/* 0x0081 */ SDK_PRI char pad_0x81[0x3];
	/* 0x0084 */ SDK_PUB float m_walkDirectionRadians;
	/* 0x0088 */ SDK_PUB float m_fYawFloat;
	/* 0x008C */ SDK_PUB float m_fPitchFloat;
	/* 0x0090 */ SDK_PUB PlayerCamera camera;
	/* 0x00F8 */ SDK_PRI std::shared_ptr<struct Effect> m_someEffect;
	/* 0x0108 */ SDK_PRI char pad_0x108[0x28];
	/* 0x0130 */ SDK_PUB DirectX::XMMATRIX m_cameraMatrix;
	/* 0x0170 */ SDK_PUB float m_fCameraFov2;
	/* 0x0174 */ SDK_PRI char pad_0x174[0x4];
	/* 0x0178 */ SDK_PUB std::shared_ptr<struct FirstPersonHands> m_pFirstPersonHands;
	/* 0x0188 */ SDK_PRI char pad_0x188[0x38];
	/* 0x01C0 */ SDK_PUB std::shared_ptr<struct Inventory> m_pInventory;
	/* 0x01D0 */ SDK_PUB std::shared_ptr<struct ToolBox> m_pToolBox;
	/* 0x01E0 */ SDK_PUB std::shared_ptr<struct Construction> m_pConstruction;
	/* 0x01F0 */ SDK_PUB std::shared_ptr<struct Destruction> m_pDestruction;
	/* 0x0200 */ SDK_PRI char pad_0x200[0x10];
	/* 0x0210 */ SDK_PUB bool m_bIsRaycastValid;
	/* 0x0211 */ SDK_PRI char pad_0x211[0xD7];
	/* 0x02E8 */ SDK_PUB std::int32_t m_iOwnedLiftId;
	/* 0x02EC */ SDK_PRI char pad_0x2EC[0x34];
	/* 0x0320 */ SDK_PUB std::int32_t m_iCameraPullbackIdx;
	/* 0x0324 */ SDK_PRI char pad_0x324[0x4];
	/* 0x0328 */ SDK_PUB std::shared_ptr<struct AudioEvent> m_pAudioEvent;
	/* 0x0338 */ SDK_PRI char pad_0x338[0x1];
	/* 0x0339 */ SDK_PUB bool m_bIsDowned;
	/* 0x033A */ SDK_PRI char pad_0x33A[0x6];
	/* 0x0340 */ SDK_PUB boost::uuids::uuid m_selectedToolUuid;
	/* 0x0350 */ SDK_PUB std::int32_t m_iSelectedToolId;
	/* 0x0354 */ SDK_PUB boost::uuids::uuid m_prevSelectedToolUuid;
	/* 0x0364 */ SDK_PUB std::int32_t m_iPrevSelectedToolId;
	/* 0x0368 */ SDK_PRI char pad_0x368[0x8];
}; // Size: 0x370

static_assert(sizeof(MyPlayer) == 0x370, "MyPlayer: Incorrect Size");

SMSDK_END_NAMESPACE