#pragma once

#if defined(SMSDK_ENABLE_D3D11)
#include <d3d11.h>
#else
typedef unsigned int DXGI_FORMAT;
// This is a stub, please define `SMSDK_ENABLE_D3D11` to use Direct3D 11
struct ID3D11InputLayout;
// This is a stub, please define `SMSDK_ENABLE_D3D11` to use Direct3D 11
struct ID3D11PixelShader;
// This is a stub, please define `SMSDK_ENABLE_D3D11` to use Direct3D 11
struct ID3D11VertexShader;
// This is a stub, please define `SMSDK_ENABLE_D3D11` to use Direct3D 11
struct ID3DBlob;
#endif