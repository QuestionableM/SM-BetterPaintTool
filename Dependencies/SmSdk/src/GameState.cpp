#include "SmSdk/GameState.hpp"

bool GameState::IsCurrentGameState(EGameStateType gs_type)
{
	GameState* v_cur_state = GameState::GetCurrentState();
	if (!v_cur_state) return false;

	return v_cur_state->getGameStateType() == gs_type;
}

bool GameState::IsCurrentOrNextGameState(EGameStateType gs_type)
{
	GameState* v_cur_state = GameState::GetCurrentState();
	if (!v_cur_state) return false;

	if (v_cur_state->getGameStateType() == gs_type)
		return true;

	if (v_cur_state->getGameStateType() == GameState_LoadState)
	{
		LoadState* v_load_state = reinterpret_cast<LoadState*>(v_cur_state);
		if (v_load_state->m_pNextState
			&& v_load_state->m_pNextState->getGameStateType() == gs_type)
		{
			return true;
		}
	}

	return false;
}

SteamNetworkClient* GameState::GetSteamNetworkClient()
{
	GameState* v_cur_state = GameState::GetCurrentState();
	if (!v_cur_state) return nullptr;

	if (v_cur_state->getGameStateType() == GameState_PlayState)
		return reinterpret_cast<PlayState*>(v_cur_state)->steam_network_client.get();

	return nullptr;
}