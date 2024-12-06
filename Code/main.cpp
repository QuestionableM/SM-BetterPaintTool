#include "SmSdk/StaticValues.hpp"
#include "Utils/Console.hpp"

#include "SmSdk/TimestampCheck.hpp"

#include "BetterPaintToolGui.hpp"
#include "BetterPaintTool.hpp"

#include <Windows.h>
#include <MinHook.h>

static bool ms_mhInitialized = false;
static bool ms_mhHooksAttached = false;

#define DEFINE_HOOK(address, detour, original) \
	MH_CreateHook((LPVOID)(v_mod_base + address), (LPVOID)detour, (LPVOID*)&original)

void process_attach()
{
	AttachDebugConsole();

	if (!SmSdk::CheckTimestamp(_SM_TIMESTAMP_070_771))
	{
		MessageBoxA(
			NULL,
			"Your game version is unsupposed by Better Paint Tool. The current version of the mod has been built for Scrap Mechanic 0.7.0.771",
			"Unsupported Version",
			MB_ICONWARNING);
		return;
	}

	if (MH_Initialize() != MH_OK)
	{
		DebugErrorL("Couldn't initialize minHook");
		return;
	}

	ms_mhInitialized = true;

	//Do the hooking here
	const std::uintptr_t v_mod_base = std::uintptr_t(GetModuleHandle(NULL));

#if defined(_SM_VERSION_070_771)
	if (DEFINE_HOOK(0x53BD60, BetterPaintTool::h_processInputs, BetterPaintTool::o_processInputs) != MH_OK) return;
	if (DEFINE_HOOK(0x3C07E0, BetterPaintToolGui::h_initialize, BetterPaintToolGui::o_initialize) != MH_OK) return;
	if (DEFINE_HOOK(0x3DF930, BetterPaintTool::h_initialize, BetterPaintTool::o_initialize) != MH_OK) return;
	if (DEFINE_HOOK(0x3DEE60, BetterPaintTool::h_update, BetterPaintTool::o_update) != MH_OK) return;
#else
	if (DEFINE_HOOK(0x54B8F0, BetterPaintTool::h_processInputs, BetterPaintTool::o_processInputs) != MH_OK) return;
	if (DEFINE_HOOK(0x3CE3F0, BetterPaintToolGui::h_initialize, BetterPaintToolGui::o_initialize) != MH_OK) return;
	if (DEFINE_HOOK(0x3EF190, BetterPaintTool::h_initialize, BetterPaintTool::o_initialize) != MH_OK) return;
	if (DEFINE_HOOK(0x3EE6D0, BetterPaintTool::h_update, BetterPaintTool::o_update) != MH_OK) return;
#endif

	StaticValues::sm_paintToolPaintLimiter = 63;
	StaticValues::sm_paintToolEraseLimiter = 63;

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