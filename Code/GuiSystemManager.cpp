#include "GuiSystemManager.hpp"

#include "win_include.hpp"

GuiSystemManager* GuiSystemManager::GetInstance()
{
	return *reinterpret_cast<GuiSystemManager**>(std::uintptr_t(GetModuleHandle(NULL)) + 0x128D7B0);
}