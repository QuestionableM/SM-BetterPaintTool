#pragma once

#include "SmSdk/config.hpp"

#include <string>
#include <deque>

SMSDK_BEGIN_NAMESPACE

enum EKeyState : uint32_t
{
	EKeyState_None = 0,
	EKeyState_Press = 1,
	EKeyState_Hold = 2
};

enum EMouseButton : uint32_t
{
	EMouseButton_Left = 0,
	EMouseButton_Right = 1,
	EMouseButton_Middle = 2,
	EMouseButton_Button1 = 3,
	EMouseButton_Button2 = 4
};

enum EInputEventType : uint32_t
{
	InputEventType_Keyboard = 0x0,
	InputEventType_Mouse = 0x1,
	InputEventType_MouseScroll = 0x2,
	InputEventType_MouseMove = 0x3,
};


struct MouseData
{
	/* 0x0000 */ SDK_PUB std::int32_t m_x;
	/* 0x0004 */ SDK_PUB std::int32_t m_y;
	/* 0x0008 */ SDK_PUB std::int32_t m_scroll;
}; // Size: 0xC

static_assert(sizeof(MouseData) == 0xC, "MouseData: Incorrect Size");

struct InputEvent
{
	/* 0x0000 */ SDK_PUB EInputEventType m_eventType;
	/* 0x0004 */ SDK_PRI char pad_0x4[0x4];
	/* 0x0008 */ SDK_PUB std::wstring m_someName;
	/* 0x0028 */ SDK_PRI char pad_0x28[0x18];
}; // Size: 0x40

static_assert(sizeof(InputEvent) == 0x40, "InputEvent: Incorrect Size");

class InputManager
{
	REMOVE_COPY_CONSTRUCTORS(InputManager);

	SDK_PUB static InputManager* GetInstance();

	SDK_PUB inline bool _isKeyPressed(char cKey) const
	{
		return m_eKeyStates[cKey] == EKeyState_Press;
	}

	SDK_PUB inline bool _isKeyHeld(char cKey) const
	{
		return m_eKeyStates[cKey] == EKeyState_Hold;
	}

	SDK_PUB inline bool _isMouseButtonPressed(EMouseButton eBtn) const
	{
		return m_eMouseBtnStates[eBtn] == EKeyState_Press;
	}

	SDK_PUB inline bool _isMouseButtonHeld(EMouseButton eBtn) const
	{
		return m_eMouseBtnStates[eBtn] == EKeyState_Hold;
	}

	SDK_PUB inline static bool IsKeyPressed(char cKey)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isKeyPressed(cKey);
	}

	SDK_PUB inline static bool IsKeyHeld(char cKey)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isKeyHeld(cKey);
	}

	SDK_PUB inline static bool IsMouseButtonPressed(EMouseButton eBtn)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isMouseButtonPressed(eBtn);
	}

	SDK_PUB inline static bool IsMouseButtonHeld(EMouseButton eBtn)
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->_isMouseButtonHeld(eBtn);
	}

	SDK_PUB inline static std::int32_t GetMouseScrollDelta()
	{
		InputManager* pInputManager = InputManager::GetInstance();
		if (!pInputManager)
			return false;

		return pInputManager->m_deltaMouseData.m_scroll;
	}

	/* 0x0000 */ SDK_PRI char pad_0x0[0xC];
	/* 0x000C */ SDK_PUB std::int32_t m_iCharacterCode;
	/* 0x0010 */ SDK_PRI char pad_0x10[0x18];
	/* 0x0028 */ SDK_PUB struct Contraption* m_pContraption;
	/* 0x0030 */ SDK_PUB MouseData m_currentMouseData;
	/* 0x003C */ SDK_PUB MouseData m_prevMouseData;
	/* 0x0048 */ SDK_PUB MouseData m_deltaMouseData;
	/* 0x0054 */ SDK_PUB bool m_bKeyPressStates[256];
	/* 0x0154 */ SDK_PUB bool m_bPrevKeyPressStates[256];
	/* 0x0254 */ SDK_PUB EKeyState m_eKeyStates[256];
	/* 0x0654 */ SDK_PUB bool m_bMouseBtnPressStates[5];
	/* 0x0659 */ SDK_PUB bool m_bMousePrevBtnPressStates[5];
	/* 0x065E */ SDK_PRI char pad_0x65E[0x2];
	/* 0x0660 */ SDK_PUB EMouseButton m_eMouseBtnStates[5];
	/* 0x0674 */ SDK_PRI char pad_0x674[0x4];
	/* 0x0678 */ SDK_PUB std::deque<InputEvent> m_deqInputQueue;
	/* 0x06A0 */ SDK_PRI char pad_0x6A0[0x4];
	/* 0x06A4 */ SDK_PUB float m_fCrashTimer;
	/* 0x06A8 */ SDK_PRI char pad_0x6A8[0x8];
}; // Size: 0x6B0

static_assert(sizeof(InputManager) == 0x6B0, "InputManager: Incorrect Size");

SMSDK_END_NAMESPACE