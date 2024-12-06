#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include <cstddef>
#include <cstdint>
#include <memory>

namespace Memory
{
	inline static std::uintptr_t ToLocalAddress(const void* ptr)
	{
		return std::uintptr_t(ptr) - std::uintptr_t(GetModuleHandle(NULL));
	}

	template<typename T>
	inline static T& ReadRef(std::uintptr_t offset)
	{
		return *reinterpret_cast<T*>(std::uintptr_t(GetModuleHandle(NULL)) + offset);
	}

	template<typename T>
	inline static T* ReadPtr(std::uintptr_t offset)
	{
		return reinterpret_cast<T*>(std::uintptr_t(GetModuleHandle(NULL)) + offset);
	}

	template<typename T>
	inline static T Read(std::uintptr_t offset)
	{
		return reinterpret_cast<T>(std::uintptr_t(GetModuleHandle(NULL)) + offset);
	}

	template<typename T>
	void WriteGlobal(void* addr, const T& data)
	{
		DWORD v_old_protect;
		VirtualProtect(addr, sizeof(T), PAGE_EXECUTE_READWRITE, &v_old_protect);
		std::memcpy(addr, &data, sizeof(T));
		VirtualProtect(addr, sizeof(T), v_old_protect, &v_old_protect);
	}

	template<typename T>
	void WriteMemory(std::uintptr_t offset, const T& data)
	{
		//void* v_global_ptr = ReadPtr<void>(offset);
		WriteGlobal<T>(ReadPtr<void>(offset), data);
		//DWORD v_old_protect;
		//VirtualProtect(v_global_ptr, sizeof(T), PAGE_EXECUTE_READWRITE, &v_old_protect);
		//std::memcpy(v_global_ptr, &data, sizeof(T));
		//VirtualProtect(v_global_ptr, sizeof(T), v_old_protect, &v_old_protect);
	}

	inline static void OverwriteVftable(void* obj, std::uintptr_t vtbl_offset)
	{
		*reinterpret_cast<void**>(obj) = Memory::ReadPtr<void>(vtbl_offset);
	}
}