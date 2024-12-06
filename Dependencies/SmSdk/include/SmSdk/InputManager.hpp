#pragma once

#include "SmSdk/config.hpp"

#include <string>
#include <deque>

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

enum EInputEventType : unsigned __int32
{
	InputEventType_Keyboard = 0x0,
	InputEventType_Mouse = 0x1,
	InputEventType_MouseScroll = 0x2,
	InputEventType_MouseMove = 0x3,
};


struct MouseData
{
	/* 0x0000 */ __int32 x;
	/* 0x0004 */ __int32 y;
	/* 0x0008 */ __int32 scroll;
}; // Size: 0xC

static_assert(sizeof(MouseData) == 0xC, "MouseData: Incorrect Size");

struct InputEvent
{
	/* 0x0000 */ EInputEventType event_type;
private:
	/* 0x0004 */ char pad_0x4[0x4];
public:
	/* 0x0008 */ std::wstring some_name;
private:
	/* 0x0028 */ char pad_0x28[0x18];

}; // Size: 0x40

static_assert(sizeof(InputEvent) == 0x40, "InputEvent: Incorrect Size");

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

	inline static std::int32_t GetMouseScrollDelta()
	{
		InputManager* v_pInputMgr = InputManager::GetInstance();
		if (!v_pInputMgr) return false;

		return v_pInputMgr->m_deltaMouseData.scroll;
	}

private:
	/* 0x0000 */ char pad_0x0[0xC];
public:
	/* 0x000C */ __int32 character_code;
private:
	/* 0x0010 */ char pad_0x10[0x18];
public:
	/* 0x0028 */ struct Contraption* contraption;
	/* 0x0030 */ MouseData m_currentMouseData;
	/* 0x003C */ MouseData m_prevMouseData;
	/* 0x0048 */ MouseData m_deltaMouseData;
	/* 0x0054 */ bool m_bKeyPressStates[256];
	/* 0x0154 */ bool m_bPrevKeyPressStates[256];
	/* 0x0254 */ __int32 m_eKeyStates[256];
	/* 0x0654 */ bool m_bMouseBtnPressStates[5];
	/* 0x0659 */ bool m_bMousePrevBtnPressStates[5];
private:
	/* 0x065E */ char pad_0x65E[0x2];
public:
	/* 0x0660 */ __int32 m_eMouseBtnStates[5];
private:
	/* 0x0674 */ char pad_0x674[0x4];
public:
	/* 0x0678 */ std::deque<InputEvent> m_inputQueue;
private:
	/* 0x06A0 */ char pad_0x6A0[0x4];
public:
	/* 0x06A4 */ float m_fCrashTimer;
private:
	/* 0x06A8 */ char pad_0x6A8[0x8];

}; // Size: 0x6B0

static_assert(sizeof(InputManager) == 0x6B0, "InputManager: Incorrect Size");