#pragma once

#include "SmSdk/win_include.hpp"

#define _SM_TIMESTAMP_070_771 1733399248
#define _SM_TIMESTAMP_071_772 1733491522
#define _SM_TIMESTAMP_072_775 1733754961
#define _SM_TIMESTAMP_073_776 1733837301
#define _SM_TIMESTAMP_074_778 1772468471

namespace SmSdk
{
// Checks the versions of the loaded module by its timestamp
bool CheckTimestamp(uint32_t timeStamp)
{
	const std::uintptr_t pBase = (std::uintptr_t) GetModuleHandle(NULL);

	const IMAGE_DOS_HEADER* pDosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(pBase);
	const IMAGE_NT_HEADERS64* pNtHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(pBase + pDosHeader->e_lfanew);

	return pNtHeader->FileHeader.TimeDateStamp == timeStamp;
}
}