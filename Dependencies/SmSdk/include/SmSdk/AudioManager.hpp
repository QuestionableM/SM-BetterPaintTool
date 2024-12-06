#pragma once

#include "SmSdk/fmod_include.hpp"
#include "SmSdk/Base/Task.hpp"

#include <memory>
#include <string>
#include <mutex>
#include <deque>
#include <map>

struct EventData
{
	/* 0x0000 */ __int16 world_id;
private:
	/* 0x0002 */ char pad_0x2[0x2];
public:
	/* 0x0004 */ __int32 some_val;
private:
	/* 0x0008 */ char pad_0x8[0x18];
public:
	/* 0x0020 */ std::string event_name;
	/* 0x0040 */ std::map<std::string, float> tmp_map;
	/* 0x0050 */ std::shared_ptr<struct AudioEvent> m_pAudioEvent;
}; // Size: 0x60

static_assert(sizeof(EventData) == 0x60, "EventData: Incorrect Size");

class AudioManager : public Task
{
public:
	static AudioManager* GetInstance();

	inline void _playSound(const std::string& sound_name, std::uint16_t world_id = 0xFFFF)
	{
		std::lock_guard<std::mutex> v_lock_g(m_mutex);

		EventData v_new_event;
		v_new_event.world_id = world_id;
		v_new_event.some_val = 1;
		v_new_event.event_name = sound_name;

		event_queue.push_back(v_new_event);
	}

	inline static void PlaySound(const std::string& sound_name, std::uint16_t world_id = 0xFFFF)
	{
		AudioManager* v_pAudioMgr = AudioManager::GetInstance();
		if (!v_pAudioMgr) return;

		v_pAudioMgr->_playSound(sound_name, world_id);
	}

	/* 0x0008 */ std::shared_ptr<struct AudioEventManager> audio_event_mgr;
	/* 0x0018 */ std::mutex m_mutex;
	/* 0x0068 */ FMOD::Studio::System* fmod_studio_system;
	/* 0x0070 */ FMOD::System* fmod_system;
	/* 0x0078 */ FMOD_ADVANCEDSETTINGS fmod_advanced_settings;
	/* 0x00E0 */ float m_masterVolume;
	/* 0x00E4 */ float m_oldMasterVolume;
private:
	/* 0x00E8 */ char pad_0xE8[0x10];
public:
	/* 0x00F8 */ std::deque<EventData> event_queue;
private:
	/* 0x0120 */ char pad_0x120[0x78];
public:
	/* 0x0198 */ std::map<std::string, std::string> name_to_fmod_path;
	/* 0x01A8 */ std::map<std::size_t, std::string> some_hash_to_fmod_path;
	/* 0x01B8 */ std::map<std::string, std::shared_ptr<struct AudioEvent>> name_to_event_ptr;
private:
	/* 0x01C8 */ char pad_0x1C8[0x100];
public:
	/* 0x02C8 */ __int32 fmod_init_flags;
private:
	/* 0x02CC */ char pad_0x2CC[0xC];
}; // Size: 0x2D8

static_assert(sizeof(AudioManager) == 0x2D8, "AudioManager: Incorrect Size");