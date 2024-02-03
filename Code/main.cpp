#include "Utils/Console.hpp"

#include "PaintToolGui.hpp"
#include "PaintTool.hpp"

#include <Windows.h>
#include <MinHook.h>

static bool ms_mhInitialized = false;
static bool ms_mhHooksAttached = false;

void process_attach()
{
	AttachDebugConsole();

	if (MH_Initialize() != MH_OK)
	{
		DebugErrorL("Couldn't initialize minHook");
		return;
	}

	ms_mhInitialized = true;

	//Do the hooking here
	const std::uintptr_t v_mod_base = std::uintptr_t(GetModuleHandle(NULL));

	if (MH_CreateHook((LPVOID)(v_mod_base + 0x3CE3F0),
		(LPVOID)PaintToolGui::h_initialize,
		(LPVOID*)&PaintToolGui::o_initialize) != MH_OK)
		return;

	if (MH_CreateHook((LPVOID)(v_mod_base + 0x3EF190),
		(LPVOID)PaintTool::h_initialize,
		(LPVOID*)&PaintTool::o_initialize) != MH_OK)
		return;

	ms_mhHooksAttached = MH_EnableHook(MH_ALL_HOOKS) == MH_OK;
}

void process_detach(HMODULE hmod)
{
	if (ms_mhInitialized)
	{
		if (ms_mhHooksAttached)
			MH_DisableHook(MH_ALL_HOOKS);

		MH_Uninitialize();
	}

	FreeLibrary(hmod);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		process_attach();
		break;
	case DLL_PROCESS_DETACH:
		process_detach(hModule);
		break;
	}

	return TRUE;
}