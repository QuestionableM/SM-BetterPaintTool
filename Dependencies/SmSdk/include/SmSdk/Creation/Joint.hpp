#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "SmSdk/Util/Color.hpp"

SMSDK_BEGIN_NAMESPACE

struct Joint : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x10];
	/* 0x0038 */ SDK_PUB boost::uuids::uuid m_uuid;
	/* 0x0048 */ SDK_PUB Color m_color;
	/* 0x004C */ SDK_PRI char pad_0x4C[0x4];
	/* 0x0050 */ SDK_PUB std::shared_ptr<ChildShape> m_pChildShapeA;
	/* 0x0060 */ SDK_PUB std::shared_ptr<ChildShape> m_pChildShapeB;
	/* 0x0070 */ SDK_PUB DirectX::XMINT3 m_positionA;
	/* 0x007C */ SDK_PUB DirectX::XMINT3 m_positionB;
	/* 0x0088 */ SDK_PUB DirectX::XMINT3 m_zAxisA;
	/* 0x0094 */ SDK_PUB DirectX::XMINT3 m_zAxisB;
	/* 0x00A0 */ SDK_PUB DirectX::XMINT3 m_xAxisA;
	/* 0x00AC */ SDK_PUB DirectX::XMINT3 m_xAxisB;
	/* 0x00B8 */ SDK_PUB std::shared_ptr<class ControllerBase> m_pParentController;
	/* 0x00C8 */ SDK_PUB std::shared_ptr<class ControllerBase> m_pController;
	/* 0x00D8 */ SDK_PRI char pad_0xD8[0x8];
}; // Size: 0xE0

static_assert(offsetof(Joint, Joint::m_uuid) == 0x38, "Joint::m_uuid: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_color) == 0x48, "Joint::m_color: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_pChildShapeA) == 0x50, "Joint::m_pChildShapeA: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_pChildShapeB) == 0x60, "Joint::m_pChildShapeB: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_positionA) == 0x70, "Joint::m_positionA: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_positionB) == 0x7C, "Joint::m_positionB: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_zAxisA) == 0x88, "Joint::m_zAxisA: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_zAxisB) == 0x94, "Joint::m_zAxisB: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_xAxisA) == 0xA0, "Joint::m_xAxisA: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_xAxisB) == 0xAC, "Joint::m_xAxisB: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_pParentController) == 0xB8, "Joint::m_pParentController: Incorrect offset");
static_assert(offsetof(Joint, Joint::m_pController) == 0xC8, "Joint::m_pController: Incorrect offset");

static_assert(sizeof(Joint) == 0xE0, "Joint: Incorrect Size");

SMSDK_END_NAMESPACE