#pragma once

#include "SmSdk/mygui_include.hpp"

class OptionsItemBase
{
public:
	virtual ~OptionsItemBase() = default;
	OptionsItemBase() : m_pBaseWidget(nullptr) {}

	virtual void update() = 0;

public:
	/* 0x0008 */ MyGUI::Widget* m_pBaseWidget;
}; // Size: 0x10

static_assert(offsetof(OptionsItemBase, OptionsItemBase::m_pBaseWidget) == 0x8, "OptionsItemBase::m_pBaseWidget: Incorrect offset");

static_assert(sizeof(OptionsItemBase) == 0x10, "OptionsItemBase: Incorrect Size");