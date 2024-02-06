#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include <cstddef>
#include <cstdint>
#include <memory>

namespace Memory
{
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
	void WriteMemory(std::uintptr_t offset, const T& data)
	{
		void* v_global_ptr = ReadPtr<void>(offset);

		DWORD v_old_protect;
		VirtualProtect(v_global_ptr, sizeof(T), PAGE_EXECUTE_READWRITE, &v_old_protect);
		std::memcpy(v_global_ptr, &data, sizeof(T));
		VirtualProtect(v_global_ptr, sizeof(T), v_old_protect, &v_old_protect);
	}
}