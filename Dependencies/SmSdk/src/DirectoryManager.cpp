#include "SmSdk/DirectoryManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

bool DirectoryManager::getReplacement(const std::string& key, std::string& replacement)
{
	auto iter = m_mapContentKeyToPathList.find(key);
	if (iter == m_mapContentKeyToPathList.end())
		return false;

	replacement = iter->second;
	return true;
}

bool DirectoryManager::replacePathR(std::string& path)
{
	if (path.empty() || path[0] != L'$')
		return false;

	const char* pBegin = path.data();
	const char* pKey = std::strchr(pBegin, L'/');
	if (pKey == nullptr)
		return false;

	const size_t iKeyIdx = pKey - pBegin;

	const std::string keyChunk = path.substr(0, iKeyIdx);
	const auto iter = m_mapContentKeyToPathList.find(keyChunk);
	if (iter == m_mapContentKeyToPathList.end())
		return false;

	path = (iter->second + path.substr(iKeyIdx));
	return true;
}

bool DirectoryManager::ReplacePathR(std::string& path)
{
	DirectoryManager* pDirectoryManager = DirectoryManager::GetInstance();
	if (!pDirectoryManager)
		return false;

	return pDirectoryManager->replacePathR(path);
}

bool DirectoryManager::GetReplacement(const std::string& key, std::string& replacement)
{
	DirectoryManager* pDirectoryManager = DirectoryManager::GetInstance();
	if (!pDirectoryManager)
		return false;

	return pDirectoryManager->getReplacement(key, replacement);
}