#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "SmSdk/Util/Color.hpp"

struct Joint : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x20];
public:
	/* 0x0048 */ Color m_color;
private:
	/* 0x004C */ char pad_0x4C[0x4];
public:
	/* 0x0050 */ std::shared_ptr<ChildShape> m_pParentChild;
private:
	/* 0x0060 */ char pad_0x60[0x68];
public:
	/* 0x00C8 */ std::shared_ptr<class ControllerBase> controller;
private:
	/* 0x00D8 */ char pad_0xD8[0x8];
}; // Size: 0xE0

static_assert(sizeof(Joint) == 0xE0, "Joint: Incorrect Size");