#pragma once

#ifndef _WIN64
#error The dll has to be compiled in 64 bit mode
#endif

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <WinUser.h>
#include <winuser.inl>

#define _XM_NO_INTRINSICS_
#include <DirectXMath.h>

#include <d3d11.h>
#include <cstdint>
#include <ctype.h>
#include <cstdio>
#include <cmath>