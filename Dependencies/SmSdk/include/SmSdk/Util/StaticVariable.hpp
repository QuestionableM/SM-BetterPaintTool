#pragma once

#include "SmSdk/Util/Memory.hpp"

#include <cstddef>
#include <cstdint>

template<typename T, std::uintptr_t t_static_offset>
class StaticVariable
{
public:
	StaticVariable() = default;

	StaticVariable(const T& val)
	{
		Memory::WriteMemory<T>(t_static_offset, val);
	}

	inline void operator=(const T& val) noexcept
	{
		Memory::WriteMemory<T>(t_static_offset, val);
	}

	//Be careful when writing data to the pointer, the data might be protected
	inline const T* operator&() noexcept
	{
		return Memory::ReadPtr<T>(t_static_offset);
	}

	inline operator T()
	{
		return *Memory::ReadPtr<T>(t_static_offset);
	}
};