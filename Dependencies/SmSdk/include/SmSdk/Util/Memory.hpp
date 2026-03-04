#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include <cstddef>
#include <cstdint>
#include <memory>

#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

namespace Memory
{
inline static std::uintptr_t ToLocalAddress(const void* pPtr)
{
	return std::uintptr_t(pPtr) - std::uintptr_t(GetModuleHandle(NULL));
}

template <typename T>
inline static T& ReadRef(std::uintptr_t uOffset)
{
	return *reinterpret_cast<T*>(std::uintptr_t(GetModuleHandle(NULL)) + uOffset);
}

template <typename T>
inline static T* ReadPtr(std::uintptr_t uOffset)
{
	return reinterpret_cast<T*>(std::uintptr_t(GetModuleHandle(NULL)) + uOffset);
}

template <typename T>
inline static T Read(std::uintptr_t uOffset)
{
	return reinterpret_cast<T>(std::uintptr_t(GetModuleHandle(NULL)) + uOffset);
}

template <typename T>
void WriteGlobal(void* pAddr, const T& data)
{
	DWORD oldProtect;
	VirtualProtect(pAddr, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);
	std::memcpy(pAddr, &data, sizeof(T));
	VirtualProtect(pAddr, sizeof(T), oldProtect, &oldProtect);
}

template <typename T>
void WriteMemory(std::uintptr_t uOffset, const T& data)
{
	//void* v_global_ptr = ReadPtr<void>(uOffset);
	WriteGlobal<T>(ReadPtr<void>(uOffset), data);
	//DWORD oldProtect;
	//VirtualProtect(v_global_ptr, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);
	//std::memcpy(v_global_ptr, &data, sizeof(T));
	//VirtualProtect(v_global_ptr, sizeof(T), oldProtect, &oldProtect);
}

inline static void OverwriteVftable(void* pObj, std::uintptr_t uVtblOffset)
{
	*reinterpret_cast<void**>(pObj) = Memory::ReadPtr<void>(uVtblOffset);
}
}

SMSDK_END_NAMESPACE