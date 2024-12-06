#pragma once

#include "SmSdk/boost_include.hpp"
#include "SmSdk/config.hpp"

#include "SmSdk/Character.hpp"

#include <unordered_map>
#include <vector>
#include <memory>
#include <map>

class CharacterManager
{
	REMOVE_COPY_CONSTRUCTORS(CharacterManager);

public:
	virtual ~CharacterManager() = default;

	static CharacterManager* GetInstance();

	inline Character* _getCharacter(int char_id)
	{
		auto v_iter = m_mapCharacterState.find(char_id);
		if (v_iter == m_mapCharacterState.end())
			return nullptr;

		return v_iter->second.get();
	}

	inline static Character* GetCharacter(int char_id)
	{
		CharacterManager* v_pCharMgr = CharacterManager::GetInstance();
		if (!v_pCharMgr) return nullptr;

		return v_pCharMgr->_getCharacter(char_id);
	}

	/* 0x0008 */ std::unordered_map<int, std::shared_ptr<Character>> m_mapCharacterState;
	/* 0x0048 */ std::unordered_map<int, std::shared_ptr<struct Lift>> m_worldLiftMap;
	/* 0x0088 */ __int32 some_id;
	/* 0x008C */ __int32 tick;
	/* 0x0090 */ std::map<boost::uuids::uuid, struct CharacterData> character_data_list;
	/* 0x00A0 */ std::vector<std::shared_ptr<Character>> character_vector;

}; // Size: 0xB8

static_assert(sizeof(CharacterManager) == 0xB8, "CharacterManager: Incorrect Size");