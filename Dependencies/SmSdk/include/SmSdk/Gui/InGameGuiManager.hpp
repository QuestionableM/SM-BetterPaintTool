#pragma once

#include "SmSdk/config.hpp"

#include "InGameGuiManagerInterface.hpp"
#include "InventoryGui.hpp"
#include "HudGui2.hpp"

class InGameGuiManager : public InGameGuiManagerInterface
{
	REMOVE_COPY_CONSTRUCTORS(InGameGuiManager);

public:
	virtual ~InGameGuiManager() = default;

	static InGameGuiManager* GetInstance();

	inline void _displayAlertText(const std::string& text, float duration = 4.0f)
	{
		if (!m_pHudGui) return;

		m_pHudGui->m_alertText = text;
		m_pHudGui->m_alertTextTimer = duration;
	}

	inline void _setInteractionText(const std::vector<std::string>& vec)
	{
		if (!m_pHudGui) return;

		const std::size_t v_last_entry = m_pHudGui->m_vecInteractionTexts.size();

		m_pHudGui->m_vecInteractionTexts.push_back(vec);
		m_pHudGui->m_vecInteractionTexts[v_last_entry].push_back("\n");
	}

	inline static void DisplayAlertText(const std::string& text, float duration = 4.0f)
	{
		InGameGuiManager* v_pGuiMgr = InGameGuiManager::GetInstance();
		if (!v_pGuiMgr) return;

		v_pGuiMgr->_displayAlertText(text, duration);
	}

	inline static void SetInteractionText(const std::vector<std::string>& vec)
	{
		InGameGuiManager* v_pGuiMgr = InGameGuiManager::GetInstance();
		if (!v_pGuiMgr) return;

		v_pGuiMgr->_setInteractionText(vec);
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