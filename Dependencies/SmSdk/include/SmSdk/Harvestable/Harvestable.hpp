#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/Base/NetObj.hpp"

#include <DirectXMath.h>

struct Harvestable : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ bool pose_weight_update_flag;
	/* 0x0031 */ bool color_update_flag;
	/* 0x0032 */ bool uv_update_flag;
	/* 0x0033 */ bool transform_update_flag;
private:
	/* 0x0034 */ char pad_0x34[0x4];
public:
	/* 0x0038 */ std::shared_ptr<struct HarvestableData> hvs_data;
	/* 0x0048 */ __int16 world_id;
	/* 0x004A */ boost::uuids::uuid uuid;
private:
	/* 0x005A */ char pad_0x5A[0x1E];
public:
	/* 0x0078 */ DirectX::XMFLOAT3 position;
	/* 0x0084 */ DirectX::XMFLOAT4 rotation;
	/* 0x0094 */ DirectX::XMFLOAT3 scale;
private:
	/* 0x00A0 */ char pad_0xA0[0x4];
public:
	/* 0x00A4 */ bool m_bKinematic;
private:
	/* 0x00A5 */ char pad_0xA5[0x12B];
public:
	/* 0x01D0 */ float pose_weights[3];
private:
	/* 0x01DC */ char pad_0x1DC[0xC];
public:
	/* 0x01E8 */ DirectX::XMFLOAT4 color;
	/* 0x01F8 */ __int8 uv_frame_index;
private:
	/* 0x01F9 */ char pad_0x1F9[0x37];

}; // Size: 0x230

static_assert(sizeof(Harvestable) == 0x230, "Harvestable: Incorrect Size");