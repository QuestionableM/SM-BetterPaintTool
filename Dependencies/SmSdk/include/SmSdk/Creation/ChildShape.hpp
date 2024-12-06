#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "Shape.hpp"

#include <memory>

class RigidBody;

class ChildShape : public NetObj
{
public:
	inline Color getColor() const
	{
		return shape->m_shapeColor;
	}

	//SERVER ONLY
	inline void setColor(Color new_color)
	{
		if (shape->m_shapeColor == new_color)
			return;

		shape->m_shapeColor = new_color;
		this->update_object();
	}

	char pad_0x0028[0x30]; //0x0028
	std::shared_ptr<Shape> shape; //0x0058 
	char pad_0x0068[0x8]; //0x0068
	__int32 m_currentIdx; //0x0070 
	char pad_0x0074[0xC]; //0x0074
	std::shared_ptr<RigidBody> parent_body; //0x0080 
	std::shared_ptr<class ControllerBase> controller; //0x0090 
	char pad_0x00A0[0x30]; //0x00A0

}; //Size=0x00D0

static_assert(sizeof(ChildShape) == 0xD0, "ChildShape: Incorrect Size");