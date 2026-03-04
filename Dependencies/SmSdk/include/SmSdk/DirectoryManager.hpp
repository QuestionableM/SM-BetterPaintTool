#pragma once

#include "SmSdk/config.hpp"

#include <unordered_map>
#include <string>

SMSDK_BEGIN_NAMESPACE

class DirectoryManager
{
	SINGLETON_CLASS(DirectoryManager);

	SDK_PUB static DirectoryManager* GetInstance();

	SDK_PUB bool getReplacement(const std::string& key, std::string& replacement);
	SDK_PUB bool replacePathR(std::string& path);

	SDK_PUB static bool ReplacePathR(std::string& path);
	SDK_PUB static bool GetReplacement(const std::string& key, std::string& replacement);

	/* 0x0000 */ SDK_PRI char pad_0x0[8];
	/* 0x0008 */ SDK_PUB std::unordered_map<std::string, std::string> m_mapContentKeyToPathList;
}; // Size: 0x48

static_assert(offsetof(DirectoryManager, DirectoryManager::m_mapContentKeyToPathList) == 0x8, "DirectoryManager::m_pathReplacements: Incorrect offset");

static_assert(sizeof(DirectoryManager) == 0x48, "DirectoryManager: Incorrect Size");

SMSDK_END_NAMESPACE