#pragma once

#include "SmSdk/d3d11_include.hpp"
#include "SmSdk/config.hpp"

#include <unordered_map>
#include <string>

SMSDK_BEGIN_NAMESPACE

namespace rend
{
class D3D11Resource
{
	SDK_PRI virtual void func1() { /* implemented by the game */ }
	SDK_PRI virtual void func2() { /* implemented by the game */ }
	SDK_PRI virtual void func3() { /* implemented by the game */ }
	SDK_PRI virtual void func4() { /* implemented by the game */ }

	/* 0x0008 */ SDK_PUB std::string m_debugName;
}; // Size: 0x28

static_assert(offsetof(rend::D3D11Resource, rend::D3D11Resource::m_debugName) == 0x8, "rend::D3D11Resource::m_debugName: Incorrect offset");
static_assert(sizeof(rend::D3D11Resource) == 0x28, "rend::D3D11Resource: Incorrect Size");

class D3D11ShaderProgram : public rend::D3D11Resource
{
	/* 0x0028 */ SDK_PUB ID3DBlob* m_pVertexShaderBlob;
	/* 0x0030 */ SDK_PUB ID3DBlob* m_pPixelShaderBlob;
	/* 0x0038 */ SDK_PUB std::uint32_t m_uVertexShaderBlobSize;
	/* 0x003C */ SDK_PUB std::uint32_t m_uPixelShaderBlobSize;
	/* 0x0040 */ SDK_PUB ID3D11PixelShader* m_pPixelShader;
	/* 0x0048 */ SDK_PUB ID3D11VertexShader* m_pVertexShader;
	/* 0x0050 */ SDK_PUB std::string m_shaderPath;
	/* 0x0070 */ SDK_PUB std::string m_vsEntry;
	/* 0x0090 */ SDK_PUB std::string m_psEntry;
	/* 0x00B0 */ SDK_PUB std::unordered_map<XXHStringHash, std::uint32_t> m_mapPixelShaderBindings;
	/* 0x00F0 */ SDK_PUB std::unordered_map<XXHStringHash, std::uint32_t> m_mapVertexShaderBindings;
	/* 0x0130 */ SDK_PUB std::uint64_t m_uInputDescHash;
	/* 0x0138 */ SDK_PUB std::vector<std::string> m_vecDefines;
}; // Size: 0x150

static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_pVertexShaderBlob) == 0x28, "rend::D3D11ShaderProgram::m_pVertexShaderBlob: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_pPixelShaderBlob) == 0x30, "rend::D3D11ShaderProgram::m_pPixelShaderBlob: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_uVertexShaderBlobSize) == 0x38, "rend::D3D11ShaderProgram::m_uVertexShaderBlobSize: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_uPixelShaderBlobSize) == 0x3C, "rend::D3D11ShaderProgram::m_uPixelShaderBlobSize: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_pPixelShader) == 0x40, "rend::D3D11ShaderProgram::m_pPixelShader: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_pVertexShader) == 0x48, "rend::D3D11ShaderProgram::m_pVertexShader: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_shaderPath) == 0x50, "rend::D3D11ShaderProgram::m_shaderPath: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_vsEntry) == 0x70, "rend::D3D11ShaderProgram::m_vsEntry: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_psEntry) == 0x90, "rend::D3D11ShaderProgram::m_psEntry: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_mapPixelShaderBindings) == 0xB0, "rend::D3D11ShaderProgram::m_mapPixelShaderBindings: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_mapVertexShaderBindings) == 0xF0, "rend::D3D11ShaderProgram::m_mapVertexShaderBindings: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_uInputDescHash) == 0x130, "rend::D3D11ShaderProgram::m_uInputDescHash: Incorrect offset");
static_assert(offsetof(rend::D3D11ShaderProgram, rend::D3D11ShaderProgram::m_vecDefines) == 0x138, "rend::D3D11ShaderProgram::m_vecDefines: Incorrect offset");
static_assert(sizeof(rend::D3D11ShaderProgram) == 0x150, "rend::D3D11ShaderProgram: Incorrect Size");

class D3D11Layout : public rend::D3D11Resource
{
	/* 0x0028 */ SDK_PUB ID3D11InputLayout* m_pDxLayout;
}; // Size: 0x30

static_assert(offsetof(rend::D3D11Layout, rend::D3D11Layout::m_pDxLayout) == 0x28, "rend::D3D11Layout::m_pDxLayout: Incorrect offset");
static_assert(sizeof(rend::D3D11Layout) == 0x30, "rend::D3D11Layout: Incorrect Size");
}

SMSDK_END_NAMESPACE