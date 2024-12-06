#include "SmSdk/Player.hpp"

#include "SmSdk/CharacterManager.hpp"

Character* Player::getCharacter() const
{
	return CharacterManager::GetCharacter(this->character_id);
}

bool Player::characterExists() const
{
	return this->getCharacter() != nullptr;
}