#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/Base/NetObj.hpp"

#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

struct Harvestable : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
	/* 0x0030 */ SDK_PUB bool m_bPoseWeightUpdateFlag;
	/* 0x0031 */ SDK_PUB bool m_bColorUpdateFlag;
	/* 0x0032 */ SDK_PUB bool m_bUVUpdateFlag;
	/* 0x0033 */ SDK_PUB bool m_bTransformUpdateFlag;
	/* 0x0034 */ SDK_PRI char pad_0x34[0x4];
	/* 0x0038 */ SDK_PUB std::shared_ptr<struct HarvestableData> m_pHarvestableData;
	/* 0x0048 */ SDK_PUB std::int16_t m_iWorldId;
	/* 0x004A */ SDK_PUB boost::uuids::uuid m_uuid;
	/* 0x005A */ SDK_PRI char pad_0x5A[0x1E];
	/* 0x0078 */ SDK_PUB DirectX::XMFLOAT3 m_position;
	/* 0x0084 */ SDK_PUB DirectX::XMFLOAT4 m_rotation;
	/* 0x0094 */ SDK_PUB DirectX::XMFLOAT3 m_scale;
	/* 0x00A0 */ SDK_PRI char pad_0xA0[0x4];
	/* 0x00A4 */ SDK_PUB bool m_bKinematic;
	/* 0x00A5 */ SDK_PRI char pad_0xA5[0x12B];
	/* 0x01D0 */ SDK_PUB float m_fPoseWeights[3];
	/* 0x01DC */ SDK_PRI char pad_0x1DC[0xC];
	/* 0x01E8 */ SDK_PUB DirectX::XMFLOAT4 m_color;
	/* 0x01F8 */ SDK_PUB std::int8_t m_iUVFrameIndex;
	/* 0x01F9 */ SDK_PRI char pad_0x1F9[0x37];
}; // Size: 0x230

static_assert(sizeof(Harvestable) == 0x230, "Harvestable: Incorrect Size");

SMSDK_END_NAMESPACE