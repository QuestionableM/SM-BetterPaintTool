#pragma once

#include "SmSdk/win_include.hpp"

#define _SM_TIMESTAMP_070_771 1733399248

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