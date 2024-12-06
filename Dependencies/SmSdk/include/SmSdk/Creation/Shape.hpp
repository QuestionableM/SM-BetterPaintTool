#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/Util/Color.hpp"

#include <DirectXMath.h>

class Shape
{
public:
	virtual void func1() {}
	virtual void func2() {}
	virtual unsigned int getCollisionShapeType() { return 0; }

private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ boost::uuids::uuid m_shapeUuid;
	/* 0x0020 */ __int32 m_shapeType;
	/* 0x0024 */ Color m_shapeColor;
private:
	/* 0x0028 */ char pad_0x28[0x4];
public:
	/* 0x002C */ DirectX::XMFLOAT3 m_shapeSize;
private:
	/* 0x0038 */ char pad_0x38[0x28];

}; //Size=0x0060

static_assert(sizeof(Shape) == 0x60, "Shape: Incorrect Size");