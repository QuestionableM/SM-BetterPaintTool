#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "Shape.hpp"

#include <memory>

SMSDK_BEGIN_NAMESPACE

class RigidBody;

class ChildShape : public NetObj
{
	SDK_PUB inline Color getColor() const
	{
		return m_pShape->m_shapeColor;
	}

	// SERVER ONLY
	SDK_PUB inline void setColor(Color newColor)
	{
		if (m_pShape->m_shapeColor == newColor)
			return;

		m_pShape->m_shapeColor = newColor;
		this->updateObject();
	}

	/* 0x0028 */ SDK_PRI char pad_0x0028[0x30];
	/* 0x0058 */ SDK_PUB std::shared_ptr<Shape> m_pShape;
	/* 0x0068 */ SDK_PRI char pad_0x0068[0x8];
	/* 0x0070 */ SDK_PUB std::int32_t m_iCurrentIdx;
	/* 0x0074 */ SDK_PRI char pad_0x0074[0xC];
	/* 0x0080 */ SDK_PUB std::shared_ptr<RigidBody> m_pParentBody;
	/* 0x0090 */ SDK_PUB std::shared_ptr<class ControllerBase> m_pController;
	/* 0x00A0 */ SDK_PRI char pad_0x00A0[0x30];
}; // Size: 0x00D0

static_assert(sizeof(ChildShape) == 0xD0, "ChildShape: Incorrect Size");

SMSDK_END_NAMESPACE