#pragma once

#include "SmSdk/mygui_include.hpp"

SMSDK_BEGIN_NAMESPACE

class OptionsItemBase
{
	SDK_PUB virtual ~OptionsItemBase() = default;
	SDK_PUB OptionsItemBase() : m_pBaseWidget(nullptr) {}

	SDK_PUB virtual void update() = 0;

	/* 0x0008 */ SDK_PUB MyGUI::Widget* m_pBaseWidget;
}; // Size: 0x10

static_assert(offsetof(OptionsItemBase, OptionsItemBase::m_pBaseWidget) == 0x8, "OptionsItemBase::m_pBaseWidget: Incorrect offset");

static_assert(sizeof(OptionsItemBase) == 0x10, "OptionsItemBase: Incorrect Size");

SMSDK_END_NAMESPACE