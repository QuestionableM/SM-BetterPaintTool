#include "SmSdk/GameState.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

bool GameState::IsCurrentGameState(EGameStateType gsType)
{
	GameState* pCurrentState = GameState::GetCurrentState();
	if (!pCurrentState)
		return false;

	return pCurrentState->getGameStateType() == gsType;
}

bool GameState::IsCurrentOrNextGameState(EGameStateType gsType)
{
	GameState* pCurrentState = GameState::GetCurrentState();
	if (!pCurrentState)
		return false;

	if (pCurrentState->getGameStateType() == gsType)
		return true;

	if (pCurrentState->getGameStateType() == GameState_LoadState)
	{
		LoadState* pLoadState = reinterpret_cast<LoadState*>(pCurrentState);
		if (pLoadState->m_pNextState && pLoadState->m_pNextState->getGameStateType() == gsType)
		{
			return true;
		}
	}

	return false;
}

SteamNetworkClient* GameState::GetSteamNetworkClient()
{
	GameState* pCurrentState = GameState::GetCurrentState();
	if (!pCurrentState)
		return nullptr;

	if (pCurrentState->getGameStateType() == GameState_PlayState)
		return reinterpret_cast<PlayState*>(pCurrentState)->m_pSteamNetworkClient.get();

	return nullptr;
}