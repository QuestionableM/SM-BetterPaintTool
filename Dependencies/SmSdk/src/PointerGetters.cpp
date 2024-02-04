#include "SmSdk/Harvestable/HarvestableManager.hpp"
#include "SmSdk/Creation/CreationManager.hpp"
#include "SmSdk/Gui/GuiSystemManager.hpp"
#include "SmSdk/Gui/InGameGuiManager.hpp"
#include "SmSdk/DirectoryManager.hpp"
#include "SmSdk/CharacterManager.hpp"
#include "SmSdk/PlayerManager.hpp"
#include "SmSdk/MyPlayer.hpp"

#include "SmSdk/config.hpp"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#if defined(SMSDK_ENABLE_PHYSICS)
#include "SmSdk/Physics/Physics.hpp"
#endif

#define GET_GLOBAL_PTR(type, val) *reinterpret_cast<type**>(std::uintptr_t(GetModuleHandle(NULL)) + val)

#define GET_INSTANCE_DEFINE(type, val) \
type* type::GetInstance() \
{ \
	return GET_GLOBAL_PTR(type, val); \
}

GET_INSTANCE_DEFINE(HarvestableManager, 0x128D8A0);
GET_INSTANCE_DEFINE(DirectoryManager, 0x128D8F0);
GET_INSTANCE_DEFINE(InGameGuiManager, 0x128D670);
GET_INSTANCE_DEFINE(GuiSystemManager, 0x128D7B0);
GET_INSTANCE_DEFINE(CharacterManager, 0x128D8C0);
GET_INSTANCE_DEFINE(CreationManager, 0x128D8C8);
GET_INSTANCE_DEFINE(PlayerManager, 0x128D8B8);
GET_INSTANCE_DEFINE(MyPlayer, 0x128D658);

#if defined(SMSDK_ENABLE_PHYSICS)
GET_INSTANCE_DEFINE(Physics, 0x128D628);
#endif