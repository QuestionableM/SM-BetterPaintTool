#include "InGameGuiManager.hpp"

#include "win_include.hpp"

InGameGuiManager* InGameGuiManager::GetInstance()
{
	return *reinterpret_cast<InGameGuiManager**>(std::uintptr_t(GetModuleHandle(NULL)) + 0x128D670);
}