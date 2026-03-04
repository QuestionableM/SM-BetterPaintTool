#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/mygui_include.hpp"

#include "SmSdk/Gui/GuiInterface.hpp"

SMSDK_BEGIN_NAMESPACE

class GuiBase
{
	SDK_PUB virtual ~GuiBase() = default;

	SDK_PUB virtual void initialize() { /* implemented by the game */ }
	SDK_PUB virtual void destroyWidgets() { /* implemented by the game */ }
	SDK_PUB virtual void open() { /* implemented by the game */ }
	SDK_PUB virtual void close() { /* implemented by the game */ }
	SDK_PUB virtual bool isActive()
#if defined(SMSDK_ENABLE_MYGUI)
	{
		return m_pMainPanel && m_pMainPanel->getVisible();
	}
#else
	{
		return false;
	}
#endif

	SDK_PUB virtual void setFocus(const std::string& widget) { SMSDK_UNREF(widget); /* implemented by the game */ }

	/* 0x0008 */ SDK_PUB MyGUI::Widget* m_pMainPanel;
	/* 0x0010 */ SDK_PUB GuiInterface* m_pGuiInterface;
}; // Size: 0x18

static_assert(sizeof(GuiBase) == 0x18, "GuiBase: Incorrect Size");

SMSDK_END_NAMESPACE