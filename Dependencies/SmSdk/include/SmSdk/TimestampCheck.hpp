#pragma once

#include "SmSdk/win_include.hpp"

#define _SM_TIMESTAMP_070_771 1733399248
#define _SM_TIMESTAMP_071_772 1733491522
#define _SM_TIMESTAMP_072_775 1733754961
#define _SM_TIMESTAMP_073_776 1733837301

namespace SmSdk
{
	bool CheckTimestamp(std::uint32_t timeStamp)
	{
		const std::uintptr_t v_basePtr = (std::uintptr_t)GetModuleHandle(NULL);

		const IMAGE_DOS_HEADER* v_dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(v_basePtr);
		const IMAGE_NT_HEADERS64* v_ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(v_basePtr + v_dosHeader->e_lfanew);

		return v_ntHeader->FileHeader.TimeDateStamp == timeStamp;
	}
}