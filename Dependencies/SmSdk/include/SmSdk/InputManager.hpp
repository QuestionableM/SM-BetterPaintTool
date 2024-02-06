#pragma once

#include "SmSdk/config.hpp"

enum EKeyState : std::uint32_t
{
	None = 0,
	Press = 1,
	Hold = 2
};

enum EMouseButton : std::uint32_t
{
	EMouseButton_Left = 0,
	EMouseButton_Right = 1,
	EMouseButton_Middle = 2,
	EMouseButton_Button1 = 3,
	EMouseButton_Button2 = 4
};

struct MouseData
{
	/* 0x0000 */ __int32 x;
	/* 0x0004 */ __int32 y;
	/* 0x0008 */ __int32 scroll;
}; // Size: 0xC

static_assert(sizeof(MouseData) == 0xC, "MouseData: Incorrect Size");

class InputManager
{
	REMOVE_COPY_CONSTRUCTORS(InputManager);

public:
	static InputManager* GetInstance();

	inline bool _isKeyPressed(char key) const
	{
		return m_eKeyStates[key] == EKeyState::Press;
	}

	inline bool _isKeyHeld(char key) const
	{
		return m_eKeyStates[key] == EKeyState::Hold;
	}

	inline bool _isMouseButtonPressed(EMouseButton btn) const
	{
		return m_eMouseBtnStates[btn] == EKeyState::Press;
	}

	inline bool _isMouseButtonHeld(EMouseButton btn) const
	{
		return m_eMouseBtnStates[btn] == EKeyState::Hold;
	}

	inline static bool IsKeyPressed(char key)
	{
		InputManager* v_pInputMgr = InputManager::GetInstance();
		if (!v_pInputMgr) return false;

		return v_pInputMgr->_isKeyPressed(key);
	}

	inline static bool IsKeyHeld(char key)
	{
		InputManager* v_pInputMgr = InputManager::GetInstance();
		if (!v_pInputMgr) return false;

		return v_pInputMgr->_isKeyHeld(key);
	}

	inline static bool IsMouseButtonPressed(EMouseButton btn)
	{
		InputManager* v_pInputMgr = InputManager::GetInstance();
		if (!v_pInputMgr) return false;

		return v_pInputMgr->_isMouseButtonPressed(btn);
	}

	inline static bool IsMouseButtonHeld(EMouseButton btn)
	{
		InputManager* v_pInputMgr = InputManager::GetInstance();
		if (!v_pInputMgr) return false;

		return v_pInputMgr->_isMouseButtonHeld(btn);
	}

	/* 0x0000 */ char pad_0x0[0xC];
	/* 0x000C */ __int32 character_code;
	/* 0x0010 */ char pad_0x10[0x18];
	/* 0x0028 */ struct Contraption* contraption;
	/* 0x0030 */ MouseData m_currentMouseData;
	/* 0x003C */ MouseData m_prevMouseData;
	/* 0x0048 */ MouseData m_deltaMouseData;
	/* 0x0054 */ bool m_bKeyPressStates[256];
	/* 0x0154 */ bool m_bPrevKeyPressStates[256];
	/* 0x0254 */ EKeyState m_eKeyStates[256];
	/* 0x0654 */ bool m_bMouseBtnPressStates[5];
	/* 0x0659 */ bool m_bMousePrevBtnPressStates[5];
	/* 0x065E */ char pad_0x65E[0x2];
	/* 0x0660 */ EKeyState m_eMouseBtnStates[5];
	/* 0x0674 */ char pad_0x674[0x3C];

}; // Size: 0x6B0

static_assert(sizeof(InputManager) == 0x6B0, "InputManager: Incorrect Size");