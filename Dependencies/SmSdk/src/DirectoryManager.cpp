#include "SmSdk/DirectoryManager.hpp"

bool DirectoryManager::get_replacement(const std::string& key, std::string& replacement)
{
	auto v_iter = content_key_to_path_list.find(key);
	if (v_iter == content_key_to_path_list.end())
		return false;

	replacement = v_iter->second;
	return true;
}

bool DirectoryManager::replace_path_r(std::string& path)
{
	if (path.empty() || path[0] != L'$')
		return false;

	const char* v_key_beg = path.data();
	const char* v_key_ptr = std::strchr(v_key_beg, L'/');
	if (v_key_ptr == nullptr)
		return false;

	const std::size_t v_key_idx = v_key_ptr - v_key_beg;

	const std::string v_key_chunk = path.substr(0, v_key_idx);
	const auto v_iter = content_key_to_path_list.find(v_key_chunk);
	if (v_iter == content_key_to_path_list.end())
		return false;

	path = (v_iter->second + path.substr(v_key_idx));
	return true;
}

bool DirectoryManager::ReplacePathR(std::string& path)
{
	DirectoryManager* v_dir_mgr = DirectoryManager::GetInstance();
	if (!v_dir_mgr) return false;

	return v_dir_mgr->replace_path_r(path);
}

bool DirectoryManager::GetReplacement(const std::string& key, std::string& replacement)
{
	DirectoryManager* v_dir_mgr = DirectoryManager::GetInstance();
	if (!v_dir_mgr) return false;

	return v_dir_mgr->get_replacement(key, replacement);
}