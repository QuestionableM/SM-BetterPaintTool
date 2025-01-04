#include "SmSdk/StaticValues.hpp"
#include "Utils/Console.hpp"

#include <SmSdk/TimestampCheck.hpp>
#include <SmSdk/offsets.hpp>

#include "BetterPaintToolGui.hpp"
#include "CustomPaintToolGui.hpp"
#include "BetterPaintTool.hpp"

#include <Windows.h>
#include <MinHook.h>

static bool ms_mhInitialized = false;
static bool ms_mhHooksAttached = false;

#define DEFINE_HOOK(address, detour, original) \
	MH_CreateHook((LPVOID)(v_mod_base + address), (LPVOID)detour, (LPVOID*)&original)

#if _SM_VERSION_NUM == 073776
#	define BPT_PROCESS_INPUTS_FUNC 0x53BD00
#	define BPT_GUI_INITIALIZE_FUNC 0x3C0780
#	define BPT_INITIALIZE_FUNC 0x3DF8D0
#	define BPT_UPDATE_FUNC 0x3DEE00
#elif _SM_VERSION_NUM == 072775
#	define BPT_PROCESS_INPUTS_FUNC 0x53BD80
#	define BPT_GUI_INITIALIZE_FUNC 0x3C0800
#	define BPT_INITIALIZE_FUNC 0x3DF950
#	define BPT_UPDATE_FUNC 0x3DEE80
#elif _SM_VERSION_NUM == 071772
#	define BPT_PROCESS_INPUTS_FUNC 0x53BD60
#	define BPT_GUI_INITIALIZE_FUNC 0x3C07E0
#	define BPT_INITIALIZE_FUNC 0x3DF930
#	define BPT_UPDATE_FUNC 0x3DEE60
#elif _SM_VERSION_NUM == 070771
#	define BPT_PROCESS_INPUTS_FUNC 0x53BD60
#	define BPT_GUI_INITIALIZE_FUNC 0x3C07E0
#	define BPT_INITIALIZE_FUNC 0x3DF930
#	define BPT_UPDATE_FUNC 0x3DEE60
#else
#	define BPT_PROCESS_INPUTS_FUNC 0x54B8F0
#	define BPT_GUI_INITIALIZE_FUNC 0x3CE3F0
#	define BPT_INITIALIZE_FUNC 0x3EF190
#	define BPT_UPDATE_FUNC 0x3EE6D0
#endif

void process_attach(HMODULE hmod)
{
	AttachDebugConsole();

	if (!SmSdk::CheckTimestamp(_SM_TIMESTAMP_073_776))
	{
		MessageBoxA(
			NULL,
			"Your game version is not supported by Better Paint Tool. The current version of the mod has been built for Scrap Mechanic 0.7.3.776\n\nPress OK to continue loading without the mod.",
			"Unsupported Version",
			MB_ICONWARNING);
		return;
	}

	if (MH_Initialize() != MH_OK)
	{
		DebugErrorL("Couldn't initialize minHook");
		return;
	}

	CustomPaintToolGui::SelfDll = hmod;
	ms_mhInitialized = true;

	//Do the hooking here
	const std::uintptr_t v_mod_base = std::uintptr_t(GetModuleHandle(NULL));
	if (DEFINE_HOOK(BPT_PROCESS_INPUTS_FUNC, BetterPaintTool::h_processInputs, BetterPaintTool::o_processInputs) != MH_OK) return;
	if (DEFINE_HOOK(BPT_GUI_INITIALIZE_FUNC, BetterPaintToolGui::h_initialize, BetterPaintToolGui::o_initialize) != MH_OK) return;
	if (DEFINE_HOOK(BPT_INITIALIZE_FUNC, BetterPaintTool::h_initialize, BetterPaintTool::o_initialize) != MH_OK) return;
	if (DEFINE_HOOK(BPT_UPDATE_FUNC, BetterPaintTool::h_update, BetterPaintTool::o_update) != MH_OK) return;

	StaticValues::sm_paintToolPaintLimiter = 63;
	StaticValues::sm_paintToolEraseLimiter = 63;
	StaticValues::sm_blockBuildLimiter = 63;

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
}

BOOL APIENTRY DllMain(
	HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		process_attach(hModule);
		break;
	case DLL_PROCESS_DETACH:
		process_detach(hModule);
		break;
	}

	return TRUE;
}