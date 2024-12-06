#pragma once

#include "Network/SteamNetworkServer.hpp"
#include "Network/SteamNetworkClient.hpp"
#include "Network/NetworkServer.hpp"
#include "Network/ListenServer.hpp"
#include "Base/InputTarget.hpp"

#include "SmSdk/unreferenced_params.hpp"

#include <memory>

enum EGameStateType : std::uint32_t
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
public:
	virtual ~GameState() = default;

	virtual void func8() { /* implemented by the game */ }
	virtual void func9() { /* implemented by the game */ }
	virtual void update(float delta_time) { SMSDK_UNREF(delta_time); /* implemented by the game */ }
	virtual void func11() { /* implemented by the game */ }
	virtual void func12() { /* implemented by the game */ }
	virtual void func13() { /* implemented by the game */ }
	virtual void func14() { /* implemented by the game */ }
	virtual void func15() { /* implemented by the game */ }
	virtual void func16() { /* implemented by the game */ }
	virtual void func17() { /* implemented by the game */ }
	virtual void func18() { /* implemented by the game */ }
	virtual void func19() { /* implemented by the game */ }
	virtual void func20() { /* implemented by the game */ }
	virtual void func21() { /* implemented by the game */ }
	virtual void func22() { /* implemented by the game */ }
	virtual void func23() { /* implemented by the game */ }
	virtual void func24() { /* implemented by the game */ }
	virtual void func25() { /* implemented by the game */ }
	virtual EGameStateType getGameStateType() { /* implemented by the game */ }
	virtual EGameStateType getNextGameStateType() { /* implemented by the game */ }
	virtual void func28() { /* implemented by the game */ }

	static GameState* GetCurrentState();
	static bool IsCurrentGameState(EGameStateType gs_type);
	static bool IsCurrentOrNextGameState(EGameStateType gs_type);
	static SteamNetworkClient* GetSteamNetworkClient();

private:
	/* 0x0008 */ char pad_0x8[0x110];

}; // Size: 0x118
static_assert(sizeof(GameState) == 0x118, "GameState: Incorrect Size");

struct SimpleTimer
{
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();

	/* 0x0008 */ char pad_0x8[0xC];
	/* 0x0014 */ float timer_value;
}; // Size: 0x18
static_assert(sizeof(SimpleTimer) == 0x18, "SimpleTimer: Incorrect Size");

struct PlayState : public GameState
{
	/* 0x0118 */ char pad_0x118[0x8];
	/* 0x0120 */ std::shared_ptr<ListenServer> listen_server;
	/* 0x0130 */ std::shared_ptr<SteamNetworkClient> steam_network_client;
	/* 0x0140 */ char pad_0x140[0x8];
	/* 0x0148 */ std::shared_ptr<class GameInstance> game_instance;
	/* 0x0158 */ SimpleTimer some_timer;
	/* 0x0170 */ __int32 m_connectionTimeoutIndex;
	/* 0x0174 */ char pad_0x174[0x1C];
}; // Size: 0x190
static_assert(sizeof(PlayState) == 0x190, "PlayState: Incorrect Size");

struct LoadState : public GameState
{
private:
	/* 0x0118 */ char pad_0x118[0x8];
public:
	/* 0x0120 */ std::shared_ptr<GameState> m_pNextState;
	/* 0x0130 */ std::shared_ptr<GameState> m_pPrevState;
	/* 0x0140 */ struct LoadingScreen* m_pLoadingScreen;
private:
	/* 0x0148 */ char pad_0x148[0x10];
}; // Size: 0x158

static_assert(offsetof(LoadState, LoadState::m_pNextState) == 0x120, "LoadState::m_pNextState: Incorrect offset");
static_assert(offsetof(LoadState, LoadState::m_pPrevState) == 0x130, "LoadState::m_pPrevState: Incorrect offset");
static_assert(offsetof(LoadState, LoadState::m_pLoadingScreen) == 0x140, "LoadState::m_pLoadingScreen: Incorrect offset");

static_assert(sizeof(LoadState) == 0x158, "LoadState: Incorrect Size");