#pragma once

#include "SmSdk/config.hpp"

#include <unordered_map>
#include <string>

class DirectoryManager
{
	SINGLETON_CLASS(DirectoryManager);

public:
	static DirectoryManager* GetInstance();

	bool get_replacement(const std::string& key, std::string& replacement);
	bool replace_path_r(std::string& path);

	static bool ReplacePathR(std::string& path);
	static bool GetReplacement(const std::string& key, std::string& replacement);

private:
	char unk_data1[8];
public:
	std::unordered_map<std::string, std::string> content_key_to_path_list;
};