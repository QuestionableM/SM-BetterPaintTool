#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/MyPlayer.hpp"

Character* MyPlayer::getCharacter() const
{
	if (!this->player)
		return nullptr;

	return CharacterManager::GetCharacter(this->player->character_id);
}