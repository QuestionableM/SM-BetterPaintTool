#pragma once

#include "SmSdk/Network/SteamNetworkServer.hpp"
#include "SmSdk/Network/SteamNetworkClient.hpp"
#include "SmSdk/Network/NetworkServer.hpp"
#include "SmSdk/Network/ListenServer.hpp"
#include "SmSdk/Base/InputTarget.hpp"

#include "SmSdk/unreferenced_params.hpp"

#include <memory>

SMSDK_BEGIN_NAMESPACE

enum EGameStateType : uint32_t
{
	GameState_Null = 0,
	GameState_LoadState = 1,
	GameState_PlayState = 2,
	GameState_MenuState = 3,
	GameState_TileEditorState = 4,
	GameState_WorldBuilderState = 5
};

struct GameState : public InputTarget
{
	SDK_PUB virtual ~GameState() = default;
	SDK_PRI virtual void func8() { /* implemented by the game */ }
	SDK_PRI virtual void func9() { /* implemented by the game */ }
	SDK_PUB virtual void update(float delta_time) { SMSDK_UNREF(delta_time); /* implemented by the game */ }
	SDK_PRI virtual void func11() { /* implemented by the game */ }
	SDK_PRI virtual void func12() { /* implemented by the game */ }
	SDK_PRI virtual void func13() { /* implemented by the game */ }
	SDK_PRI virtual void func14() { /* implemented by the game */ }
	SDK_PRI virtual void func15() { /* implemented by the game */ }
	SDK_PRI virtual void func16() { /* implemented by the game */ }
	SDK_PRI virtual void func17() { /* implemented by the game */ }
	SDK_PRI virtual void func18() { /* implemented by the game */ }
	SDK_PRI virtual void func19() { /* implemented by the game */ }
	SDK_PRI virtual void func20() { /* implemented by the game */ }
	SDK_PRI virtual void func21() { /* implemented by the game */ }
	SDK_PRI virtual void func22() { /* implemented by the game */ }
	SDK_PRI virtual void func23() { /* implemented by the game */ }
	SDK_PRI virtual void func24() { /* implemented by the game */ }
	SDK_PRI virtual void func25() { /* implemented by the game */ }
	SDK_PUB virtual EGameStateType getGameStateType() { /* implemented by the game */ }
	SDK_PUB virtual EGameStateType getNextGameStateType() { /* implemented by the game */ }
	SDK_PRI virtual void func28() { /* implemented by the game */ }

	SDK_PUB static GameState* GetCurrentState();
	SDK_PUB static bool IsCurrentGameState(EGameStateType gsType);
	SDK_PUB static bool IsCurrentOrNextGameState(EGameStateType gsType);
	SDK_PUB static SteamNetworkClient* GetSteamNetworkClient();

	/* 0x0008 */ SDK_PRI char pad_0x8[0x110];
}; // Size: 0x118

static_assert(sizeof(GameState) == 0x118, "GameState: Incorrect Size");

struct SimpleTimer
{
	SDK_PRI virtual void func1() { /* implemented by the game */ }
	SDK_PRI virtual void func2() { /* implemented by the game */ }
	SDK_PRI virtual void func3() { /* implemented by the game */ }
	SDK_PRI virtual void func4() { /* implemented by the game */ }

	/* 0x0008 */ SDK_PRI char pad_0x8[0xC];
	/* 0x0014 */ SDK_PUB float m_fElapsedTime;
}; // Size: 0x18

static_assert(sizeof(SimpleTimer) == 0x18, "SimpleTimer: Incorrect Size");

struct PlayState : public GameState
{
	/* 0x0118 */ SDK_PRI char pad_0x118[0x8];
	/* 0x0120 */ SDK_PUB std::shared_ptr<ListenServer> m_pListenServer;
	/* 0x0130 */ SDK_PUB std::shared_ptr<SteamNetworkClient> m_pSteamNetworkClient;
	/* 0x0140 */ SDK_PRI char pad_0x140[0x8];
	/* 0x0148 */ SDK_PUB std::shared_ptr<class GameInstance> m_pGameInstance;
	/* 0x0158 */ SDK_PUB SimpleTimer m_someTimer;
	/* 0x0170 */ SDK_PUB std::int32_t m_iConnectionTimeoutIdx;
	/* 0x0174 */ SDK_PRI char pad_0x174[0x1C];
}; // Size: 0x190

static_assert(sizeof(PlayState) == 0x190, "PlayState: Incorrect Size");

struct LoadState : public GameState
{
	/* 0x0118 */ SDK_PRI char pad_0x118[0x8];
	/* 0x0120 */ SDK_PUB std::shared_ptr<GameState> m_pNextState;
	/* 0x0130 */ SDK_PUB std::shared_ptr<GameState> m_pPrevState;
	/* 0x0140 */ SDK_PUB struct LoadingScreen* m_pLoadingScreen;
	/* 0x0148 */ SDK_PRI char pad_0x148[0x10];
}; // Size: 0x158

static_assert(offsetof(LoadState, LoadState::m_pNextState) == 0x120, "LoadState::m_pNextState: Incorrect offset");
static_assert(offsetof(LoadState, LoadState::m_pPrevState) == 0x130, "LoadState::m_pPrevState: Incorrect offset");
static_assert(offsetof(LoadState, LoadState::m_pLoadingScreen) == 0x140, "LoadState::m_pLoadingScreen: Incorrect offset");

static_assert(sizeof(LoadState) == 0x158, "LoadState: Incorrect Size");

SMSDK_END_NAMESPACE