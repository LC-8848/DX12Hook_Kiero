#pragma once
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <type_traits>
#include <cstring>
#include <TlHelp32.h>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_4.h>
#include <psapi.h>
#include <string_view>
using namespace std;

#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx12.h"

#define _DEBUG true // 是否为调试模式
#if _DEBUG
#define Printf(fmt, ...) printf(fmt, __VA_ARGS__)  // 仅在调试模式下使用的printf
#else
#define Printf(fmt, ...)  // 仅在调试模式下使用的printf
#endif

#define u8(text) reinterpret_cast<const char*>(u8##text) // 将UTF-8字符串转换为const char*类型

typedef HRESULT(__stdcall* Present) (IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags);
typedef HRESULT(__stdcall* ResizeBuffers)(IDXGISwapChain3* This, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
typedef void(__stdcall* ExecuteCommandLists)(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;