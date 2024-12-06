#pragma once

#include <unordered_map>
#include <string>

class GameSettings
{
public:
	static GameSettings* GetInstance();

	inline float _getFloatSetting(const std::string& name, float default_value = 1.0f) const
	{
		auto v_iter = m_mapFloatSettings.find(name);
		if (v_iter != m_mapFloatSettings.end())
			return v_iter->second;

		return default_value;
	}

	inline float _getMasterVolume() const
	{
		return this->_getFloatSetting("MasterVolume", 1.0f);
	}

	inline static float GetEffectsVolume()
	{
		GameSettings* v_game_set = GameSettings::GetInstance();
		if (!v_game_set) return 1.0f;

		const float v_master_volume = v_game_set->_getMasterVolume();
		const float v_eff_volume = v_game_set->_getFloatSetting("EffectVolume");

		return v_eff_volume * v_master_volume;
	}

	inline static float GetMasterVolume()
	{
		GameSettings* v_game_set = GameSettings::GetInstance();
		if (!v_game_set) return 1.0f;

		return v_game_set->_getFloatSetting("MasterVolume", 1.0f);
	}

public:
	/* 0x0000 */ std::unordered_map<std::string, int> m_mapIntSettings;
	/* 0x0040 */ std::unordered_map<std::string, float> m_mapFloatSettings;
	/* 0x0080 */ std::unordered_map<std::string, std::string> m_mapStringSettings;
	/* 0x00C0 */ __int32 m_appliedSettings;
private:
	/* 0x00C4 */ char pad_0xC4[0x4];
}; // Size: 0xC8

static_assert(offsetof(GameSettings, GameSettings::m_mapIntSettings) == 0x0, "GameSettings::m_mapIntSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_mapFloatSettings) == 0x40, "GameSettings::m_mapFloatSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_mapStringSettings) == 0x80, "GameSettings::m_mapStringSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_appliedSettings) == 0xC0, "GameSettings::m_appliedSettings: Incorrect offset");

static_assert(sizeof(GameSettings) == 0xC8, "GameSettings: Incorrect Size");