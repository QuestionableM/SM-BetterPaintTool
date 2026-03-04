#pragma once

#include "SmSdk/config.hpp"

#include <unordered_map>
#include <string>

SMSDK_BEGIN_NAMESPACE

class GameSettings
{
	SDK_PUB static GameSettings* GetInstance();

	SDK_PUB inline float _getFloatSetting(const std::string& name, float fDefaultValue = 1.0f) const
	{
		auto iter = m_mapFloatSettings.find(name);
		if (iter != m_mapFloatSettings.end())
			return iter->second;

		return fDefaultValue;
	}

	SDK_PUB inline float _getMasterVolume() const
	{
		return this->_getFloatSetting("MasterVolume", 1.0f);
	}

	SDK_PUB inline static float GetEffectsVolume()
	{
		GameSettings* pGameSettings = GameSettings::GetInstance();
		if (!pGameSettings)
			return 1.0f;

		const float fMasterVolume = pGameSettings->_getMasterVolume();
		const float fEffectVolume = pGameSettings->_getFloatSetting("EffectVolume");

		return fEffectVolume * fMasterVolume;
	}

	SDK_PUB inline static float GetMasterVolume()
	{
		GameSettings* pGameSettings = GameSettings::GetInstance();
		if (!pGameSettings)
			return 1.0f;

		return pGameSettings->_getFloatSetting("MasterVolume", 1.0f);
	}

	/* 0x0000 */ SDK_PUB std::unordered_map<std::string, int> m_mapIntSettings;
	/* 0x0040 */ SDK_PUB std::unordered_map<std::string, float> m_mapFloatSettings;
	/* 0x0080 */ SDK_PUB std::unordered_map<std::string, std::string> m_mapStringSettings;
	/* 0x00C0 */ SDK_PUB std::int32_t m_appliedSettings;
	/* 0x00C4 */ SDK_PRI char pad_0xC4[0x4];
}; // Size: 0xC8

static_assert(offsetof(GameSettings, GameSettings::m_mapIntSettings) == 0x0, "GameSettings::m_mapIntSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_mapFloatSettings) == 0x40, "GameSettings::m_mapFloatSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_mapStringSettings) == 0x80, "GameSettings::m_mapStringSettings: Incorrect offset");
static_assert(offsetof(GameSettings, GameSettings::m_appliedSettings) == 0xC0, "GameSettings::m_appliedSettings: Incorrect offset");

static_assert(sizeof(GameSettings) == 0xC8, "GameSettings: Incorrect Size");

SMSDK_END_NAMESPACE