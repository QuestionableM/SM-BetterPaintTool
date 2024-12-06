#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/mygui_include.hpp"

#include "GuiInterface.hpp"

class GuiBase
{
public:
	virtual ~GuiBase() = default;

	virtual void initialize() { /* implemented by the game */ }
	virtual void destroyWidgets() { /* implemented by the game */ }
	virtual void open() { /* implemented by the game */ }
	virtual void close() { /* implemented by the game */ }
	virtual bool isActive()
#if defined(SMSDK_ENABLE_MYGUI)
	{ return m_pMainPanel && m_pMainPanel->getVisible(); }
#else
	{ return false; }
#endif

	virtual void setFocus(const std::string& widget) { SMSDK_UNREF(widget); /* implemented by the game */ }

	/* 0x0008 */ MyGUI::Widget* m_pMainPanel;
	/* 0x0010 */ GuiInterface* m_pGuiInterface;

}; // Size: 0x18