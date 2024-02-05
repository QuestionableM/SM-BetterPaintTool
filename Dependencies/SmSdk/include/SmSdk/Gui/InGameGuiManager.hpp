#pragma once

#include "SmSdk/config.hpp"
#include "InventoryGui.hpp"
#include "HudGui2.hpp"

class InGameGuiManager
{
	REMOVE_COPY_CONSTRUCTORS(InGameGuiManager);

public:
	virtual ~InGameGuiManager() = default;

	static InGameGuiManager* GetInstance();

	void _displayAlertText(const std::string& text, float duration = 4.0f)
	{
		if (!m_pHudGui) return;

		m_pHudGui->m_alertText = text;
		m_pHudGui->m_alertTextTimer = duration;
	}

	static void DisplayAlertText(const std::string& text, float duration = 4.0f)
	{
		InGameGuiManager* v_pGuiMgr = InGameGuiManager::GetInstance();
		if (!v_pGuiMgr) return;

		v_pGuiMgr->_displayAlertText(text, duration);
	}

private:
	/* 0x0008 */ char pad_0x8[0x18];
public:
	/* 0x0020 */ std::shared_ptr<HudGui2> m_pHudGui;
	/* 0x0030 */ std::shared_ptr<InventoryGui> m_pInventory;
private:
	/* 0x0040 */ char pad_0x40[0x18];
	/* 0x0058 */ char pad_0x58[0x198];
}; // Size: 0x1F0

static_assert(sizeof(InGameGuiManager) == 0x1F0, "InGameGuiManager: Incorrect Size");