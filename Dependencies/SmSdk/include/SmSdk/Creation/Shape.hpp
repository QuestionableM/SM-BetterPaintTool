#pragma once

#include "SmSdk/Util/Color.hpp"

#include <boost/uuid/uuid.hpp>
#include <DirectXMath.h>

class Shape
{
public:
	virtual void func1() {}
	virtual void func2() {}
	virtual unsigned int getCollisionShapeType() { return 0; }

	char pad_0x0008[0x8]; //0x0008
	boost::uuids::uuid shape_uuid; //0x0010 
	__int32 shape_type; //0x0020 
	Color shape_color; //0x0024
	char pad_0x0028[0x4]; //0x0028
	DirectX::XMFLOAT3 size; //0x002C 
	char pad_0x0038[0x24]; //0x0038

}; //Size=0x0060

static_assert(sizeof(Shape) == 0x60, "Shape: Incorrect Size");