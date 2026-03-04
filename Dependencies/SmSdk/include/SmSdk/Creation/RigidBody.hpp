#pragma once

#include "SmSdk/bullet_include.hpp"
#include "SmSdk/Base/NetObj.hpp"

#include "SmSdk/Creation/ChildShape.hpp"
#include "SmSdk/Creation/Joint.hpp"

#include <unordered_set>
#include <vector>

SMSDK_BEGIN_NAMESPACE

class RigidBody : public NetObj
{
	SDK_PUB inline ChildShape* getChildShape(const std::size_t uChildId)
	{
		if (uChildId >= m_vecChildShapes.size())
			return nullptr;

		return m_vecChildShapes[uChildId].get();
	}

	/* 0x0028 */ SDK_PRI char pad_0x28[0xC];
	/* 0x0034 */ SDK_PUB std::int16_t m_iWorldId;
	/* 0x0036 */ SDK_PRI char pad_0x36[0xA];
	/* 0x0040 */ SDK_PUB DirectX::XMMATRIX m_transform;
	/* 0x0080 */ SDK_PRI char pad_0x80[0x8];
	/* 0x0088 */ SDK_PUB std::shared_ptr<struct ShapeGridData> m_pShapeGridData;
	/* 0x0098 */ SDK_PUB DirectX::XMFLOAT3 m_localAabbMin;
	/* 0x00A4 */ SDK_PUB DirectX::XMFLOAT3 m_localAabbMax;
	/* 0x00B0 */ SDK_PRI char pad_0xB0[0x20];
	/* 0x00D0 */ SDK_PUB btCompoundShape m_compoundShape;
	/* 0x0150 */ SDK_PUB std::vector<std::shared_ptr<ChildShape>> m_vecChildShapes;
	/* 0x0168 */ SDK_PRI char pad_0x168[0x18];
	/* 0x0180 */ SDK_PUB std::unordered_set<std::shared_ptr<Joint>> m_setJointStorage;
	/* 0x01C0 */ SDK_PRI char pad_0x1C0[0x10];
}; // Size: 0x1D0

static_assert(sizeof(RigidBody) == 0x1D0, "RigidBody: Incorrect Size");

SMSDK_END_NAMESPACE