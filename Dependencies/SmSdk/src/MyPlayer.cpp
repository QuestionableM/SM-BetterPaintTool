#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/MyPlayer.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

Character* MyPlayer::getCharacter() const
{
	if (!this->m_player)
		return nullptr;

	return CharacterManager::GetCharacter(this->m_player->m_iCharacterId);
}