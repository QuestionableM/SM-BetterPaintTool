#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/Util/Color.hpp"

#include <DirectXMath.h>

SMSDK_BEGIN_NAMESPACE

class Shape
{
	SDK_PRI virtual void func1() {}
	SDK_PRI virtual void func2() {}
	SDK_PUB virtual std::uint32_t getCollisionShapeType() { return 0; }

	/* 0x0008 */ SDK_PRI char pad_0x8[0x8];
	/* 0x0010 */ SDK_PUB boost::uuids::uuid m_shapeUuid;
	/* 0x0020 */ SDK_PUB std::int32_t m_iShapeType;
	/* 0x0024 */ SDK_PUB Color m_shapeColor;
	/* 0x0028 */ SDK_PRI char pad_0x28[0x4];
	/* 0x002C */ SDK_PUB DirectX::XMFLOAT3 m_shapeSize;
	/* 0x0038 */ SDK_PRI char pad_0x38[0x28];
}; // Size: 0x60

static_assert(sizeof(Shape) == 0x60, "Shape: Incorrect Size");

SMSDK_END_NAMESPACE