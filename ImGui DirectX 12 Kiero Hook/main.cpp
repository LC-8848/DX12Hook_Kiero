#include "UI.h"
#include "Function.h"

bool exit_hook = false;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam); // ImGui Win32实现

namespace Process {
	DWORD ID;
	HANDLE Handle;
	HMODULE Module;
	LPCSTR Title;
	LPCSTR ClassName;
	LPCSTR Path;
}

namespace DirectX12Interface {
	ID3D12Device* Device = nullptr;
	ID3D12DescriptorHeap* DescriptorHeapBackBuffers;
	ID3D12DescriptorHeap* DescriptorHeapImGuiRender;
	ID3D12GraphicsCommandList* CommandList;
	ID3D12CommandQueue* CommandQueue;

	struct _FrameContext {
		ID3D12CommandAllocator* CommandAllocator;
		ID3D12Resource* Resource;
		D3D12_CPU_DESCRIPTOR_HANDLE DescriptorHandle;
	};

	uint64_t BuffersCounts = -1;
	_FrameContext* FrameContext;
}

Present oPresent; // 原Present函数
ResizeBuffers oResizeBuffers; // 原ResizeBuffers函数
ExecuteCommandLists oExecuteCommandLists; // 原ExecuteCommandLists函数
HWND window = NULL; // 窗口句柄
WNDPROC oWndProc; // 原WndProc函数

// wndProc函数的hook函数，用于处理ImGui的消息
LRESULT WINAPI hkWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// 处理特定的消息
	switch (msg)
	{
	case WM_LBUTTONDOWN:  // 处理左键按下消息
	case WM_MOUSEMOVE:    // 处理鼠标移动消息
	case WM_LBUTTONUP:    // 处理左键释放消息
	case WM_RBUTTONDOWN:  // 处理右键按下消息
	case WM_RBUTTONUP:    // 处理右键释放消息
	case WM_KEYDOWN:      // 处理键盘按下消息
	case WM_KEYUP:        // 处理键盘释放消息
	case WM_CHAR:         // 处理字符输入消息
		if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam)) // 处理ImGui消息
			return true;
		break;
	default:
		break;
	}

	return CallWindowProcA(oWndProc, hWnd, msg, wParam, lParam); // 调用原来的WndProc函数
}

// Present函数的hook函数，用于渲染ImGui
static bool init = false;
static bool resize_init = false;
HRESULT __stdcall hkPresent(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (exit_hook) return oPresent(pSwapChain, SyncInterval, Flags); // 调用原Present函数
	if (!resize_init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D12Device), (void**)&DirectX12Interface::Device))) // 获取设备指针
		{
			if (!init)
			{
				ImGui::CreateContext(); // 创建ImGui上下文
				SetModernDarkThemeWithLucency(); // 自定义主题
				ImGuiIO& io = ImGui::GetIO(); // 获取ImGui IO
				io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange; // 禁止鼠标光标切换
				io.IniFilename = nullptr; // 不让 ImGui 保存配置文件
				io.LogFilename = nullptr; // 不让 ImGui 保存日志文件
				ImGui_ImplWin32_Init(window); // 初始化ImGui Win32实现
				ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\msyh.ttc", 20.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull()); // 设置中文字体
				UI::Init(); // 初始化菜单
				Function::Init(); // 初始化功能
				init = true;
			}

			DXGI_SWAP_CHAIN_DESC sd; // 定义SwapChain描述
			pSwapChain->GetDesc(&sd); // 获取SwapChain描述
			sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
			sd.OutputWindow = window; // 获取窗口句柄
			sd.Windowed = ((GetWindowLongPtr(window, GWL_STYLE) & WS_POPUP) != 0) ? false : true;

			DirectX12Interface::BuffersCounts = sd.BufferCount;
			DirectX12Interface::FrameContext = new DirectX12Interface::_FrameContext[DirectX12Interface::BuffersCounts];

			D3D12_DESCRIPTOR_HEAP_DESC DescriptorImGuiRender = {};
			DescriptorImGuiRender.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
			DescriptorImGuiRender.NumDescriptors = DirectX12Interface::BuffersCounts;
			DescriptorImGuiRender.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

			if (DirectX12Interface::Device->CreateDescriptorHeap(&DescriptorImGuiRender, IID_PPV_ARGS(&DirectX12Interface::DescriptorHeapImGuiRender)) != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			ID3D12CommandAllocator* Allocator;
			if (DirectX12Interface::Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&Allocator)) != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			for (size_t i = 0; i < DirectX12Interface::BuffersCounts; i++) {
				DirectX12Interface::FrameContext[i].CommandAllocator = Allocator;
			}

			if (DirectX12Interface::Device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, Allocator, NULL, IID_PPV_ARGS(&DirectX12Interface::CommandList)) != S_OK ||
				DirectX12Interface::CommandList->Close() != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			D3D12_DESCRIPTOR_HEAP_DESC DescriptorBackBuffers;
			DescriptorBackBuffers.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
			DescriptorBackBuffers.NumDescriptors = DirectX12Interface::BuffersCounts;
			DescriptorBackBuffers.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
			DescriptorBackBuffers.NodeMask = 1;

			if (DirectX12Interface::Device->CreateDescriptorHeap(&DescriptorBackBuffers, IID_PPV_ARGS(&DirectX12Interface::DescriptorHeapBackBuffers)) != S_OK)
				return oPresent(pSwapChain, SyncInterval, Flags);

			const auto RTVDescriptorSize = DirectX12Interface::Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
			D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle = DirectX12Interface::DescriptorHeapBackBuffers->GetCPUDescriptorHandleForHeapStart();

			for (size_t i = 0; i < DirectX12Interface::BuffersCounts; i++) {
				ID3D12Resource* pBackBuffer = nullptr;
				DirectX12Interface::FrameContext[i].DescriptorHandle = RTVHandle;
				pSwapChain->GetBuffer(i, IID_PPV_ARGS(&pBackBuffer));
				DirectX12Interface::Device->CreateRenderTargetView(pBackBuffer, nullptr, RTVHandle);
				DirectX12Interface::FrameContext[i].Resource = pBackBuffer;
				RTVHandle.ptr += RTVDescriptorSize;
			}

			ImGui_ImplDX12_Init(DirectX12Interface::Device,
				DirectX12Interface::BuffersCounts,
				DXGI_FORMAT_R8G8B8A8_UNORM,
				DirectX12Interface::DescriptorHeapImGuiRender,
				DirectX12Interface::DescriptorHeapImGuiRender->GetCPUDescriptorHandleForHeapStart(),
				DirectX12Interface::DescriptorHeapImGuiRender->GetGPUDescriptorHandleForHeapStart()); // 初始化ImGui DX12实现
			ImGui_ImplDX12_CreateDeviceObjects();
			ImGui::GetIO().ImeWindowHandle = window;
			oWndProc = (WNDPROC)SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)hkWndProc); // 重置WndProc函数

			resize_init = true;
		} else return oPresent(pSwapChain, SyncInterval, Flags); // 设备创建失败，调用原Present函数
	}

	if (DirectX12Interface::CommandQueue == nullptr)
		return oPresent(pSwapChain, SyncInterval, Flags); // 调用原Present函数

	ImGui_ImplDX12_NewFrame(); // ImGui DX12实现新帧
	ImGui_ImplWin32_NewFrame(); // ImGui Win32实现新帧
	ImGui::NewFrame(); // ImGui新帧

	// 完全禁用 ImGui 的鼠标和键盘捕获，防止游戏内鼠标闪烁
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDrawCursor = false;
	io.WantCaptureMouse = false;
	io.WantCaptureKeyboard = false;

	UI::Tick(); // 菜单绘制

	ImGui::EndFrame(); // ImGui结束帧

	// D3D12 渲染提交
	DirectX12Interface::_FrameContext& CurrentFrameContext = DirectX12Interface::FrameContext[pSwapChain->GetCurrentBackBufferIndex()];
	CurrentFrameContext.CommandAllocator->Reset();

	D3D12_RESOURCE_BARRIER Barrier;
	Barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
	Barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
	Barrier.Transition.pResource = CurrentFrameContext.Resource;
	Barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
	Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
	Barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;

	DirectX12Interface::CommandList->Reset(CurrentFrameContext.CommandAllocator, nullptr);
	DirectX12Interface::CommandList->ResourceBarrier(1, &Barrier);
	DirectX12Interface::CommandList->OMSetRenderTargets(1, &CurrentFrameContext.DescriptorHandle, FALSE, nullptr);
	DirectX12Interface::CommandList->SetDescriptorHeaps(1, &DirectX12Interface::DescriptorHeapImGuiRender);

	ImGui::Render(); // ImGui渲染

	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), DirectX12Interface::CommandList);
	Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
	Barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
	DirectX12Interface::CommandList->ResourceBarrier(1, &Barrier);
	DirectX12Interface::CommandList->Close();
	DirectX12Interface::CommandQueue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList* const*>(&DirectX12Interface::CommandList));

	return oPresent(pSwapChain, SyncInterval, Flags); // 调用原Present函数
}

// resizeBuffers函数的hook函数，用于重置ImGui的渲染目标
HRESULT WINAPI hkResizeBuffers(IDXGISwapChain3* This, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) {
	g_width = Width;
	g_height = Height;

	// 释放 ImGui 相关的资源
	ImGui_ImplDX12_Shutdown();
	// 释放你自定义创建的 DX12 资源
	if (DirectX12Interface::FrameContext) {
		for (uint64_t i = 0; i < DirectX12Interface::BuffersCounts; ++i) {
			// 释放每一帧的命令分配器
			if (DirectX12Interface::FrameContext[i].CommandAllocator) {
				DirectX12Interface::FrameContext[i].CommandAllocator->Release();
				DirectX12Interface::FrameContext[i].CommandAllocator = nullptr;
			}
			// 注意：Resource 是交换链的后备缓冲区，不要释放！（放屁！）
			if (DirectX12Interface::FrameContext[i].Resource)
			{
				DirectX12Interface::FrameContext[i].Resource->Release();
				DirectX12Interface::FrameContext[i].Resource = nullptr;
			}
		}
		delete[] DirectX12Interface::FrameContext;
		DirectX12Interface::FrameContext = nullptr;
	}
	// 释放你自己创建的描述符堆
	if (DirectX12Interface::DescriptorHeapImGuiRender) {
		DirectX12Interface::DescriptorHeapImGuiRender->Release();
		DirectX12Interface::DescriptorHeapImGuiRender = nullptr;
	}
	// 释放后备缓冲区的描述符堆
	if (DirectX12Interface::DescriptorHeapBackBuffers) {
		DirectX12Interface::DescriptorHeapBackBuffers->Release();
		DirectX12Interface::DescriptorHeapBackBuffers = nullptr;
	}
	// 还原 WndProc
	if (oWndProc) {
		SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)oWndProc);
		oWndProc = nullptr; // 清空原来备份的WndProc指针
	}
	DirectX12Interface::Device = nullptr;
	DirectX12Interface::CommandQueue = nullptr;
	DirectX12Interface::CommandList = nullptr;

	resize_init = false;
	//exit_hook = true; // 退出消息循环

	return oResizeBuffers(This, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

void WINAPI hkExecuteCommandLists(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists)
{
	if (!DirectX12Interface::CommandQueue)
		DirectX12Interface::CommandQueue = queue;
	oExecuteCommandLists(queue, NumCommandLists, ppCommandLists);
}

static void UnloadDX12Hook()
{
	kiero::unbind(50); // 解绑ExecuteCommandLists函数
	kiero::unbind(140); // 解绑Present函数
	kiero::unbind(145); // 解绑ResizeBuffers函数
	kiero::shutdown(); // 关闭Kiero
	// 等待 GPU 完成所有命令（防止释放正在使用的资源）
	if (DirectX12Interface::CommandQueue)
	{
		// 获取设备（用于创建 Fence）
		ID3D12Device* pDevice = DirectX12Interface::Device;
		if (!pDevice)
		{
			// 如果设备指针无效，尝试从命令队列获取
			if (FAILED(DirectX12Interface::CommandQueue->GetDevice(IID_PPV_ARGS(&pDevice))))
			{
				pDevice = nullptr;
			}
		}
		if (pDevice)
		{
			ID3D12Fence* pFence = nullptr;
			HANDLE hEvent = nullptr;
			UINT64 fenceValue = 1;
			if (SUCCEEDED(pDevice->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&pFence)))) // 创建 Fence
			{
				if (SUCCEEDED(DirectX12Interface::CommandQueue->Signal(pFence, fenceValue))) // 向命令队列发出 Signal，让 GPU 完成当前所有工作后触发 Fence
				{
					if (pFence->GetCompletedValue() < fenceValue) // 如果 Fence 尚未达到该值，创建事件等待
					{
						hEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
						if (hEvent)
						{
							if (SUCCEEDED(pFence->SetEventOnCompletion(fenceValue, hEvent))) // 设置 Fence 完成时触发事件
							{
								WaitForSingleObject(hEvent, INFINITE); // 无限等待，直到 GPU 完成
							}
							CloseHandle(hEvent);
						}
					}
				}
				pFence->Release();
			}
			if (pDevice != DirectX12Interface::Device) // 因 pDevice 是从 GetDevice 处获取的临时指针，需要进行释放
				pDevice->Release();
		}
		else // 无法获取设备，无法创建 Fence，此时只能冒风险继续，或者用 Sleep 简单延迟
			for (int i = 0; i < 5; ++i) Sleep(100); // 共等待500ms
	}
	// 释放 ImGui 相关的资源
	ImGui_ImplDX12_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	// 释放你自定义创建的 DX12 资源
	if (DirectX12Interface::FrameContext) {
		for (uint64_t i = 0; i < DirectX12Interface::BuffersCounts; ++i) {
			// 释放每一帧的命令分配器
			if (DirectX12Interface::FrameContext[i].CommandAllocator) {
				DirectX12Interface::FrameContext[i].CommandAllocator->Release();
				DirectX12Interface::FrameContext[i].CommandAllocator = nullptr;
			}
			// 注意：Resource 是交换链的后备缓冲区，不要释放！（放屁！）
			if (DirectX12Interface::FrameContext[i].Resource)
			{
				DirectX12Interface::FrameContext[i].Resource->Release();
				DirectX12Interface::FrameContext[i].Resource = nullptr;
			}
		}
		delete[] DirectX12Interface::FrameContext;
		DirectX12Interface::FrameContext = nullptr;
	}
	// 释放你自己创建的描述符堆
	if (DirectX12Interface::DescriptorHeapImGuiRender) {
		DirectX12Interface::DescriptorHeapImGuiRender->Release();
		DirectX12Interface::DescriptorHeapImGuiRender = nullptr;
	}
	// 释放后备缓冲区的描述符堆
	if (DirectX12Interface::DescriptorHeapBackBuffers) {
		DirectX12Interface::DescriptorHeapBackBuffers->Release();
		DirectX12Interface::DescriptorHeapBackBuffers = nullptr;
	}
	// 还原 WndProc
	if (oWndProc) {
		SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)oWndProc);
		oWndProc = nullptr; // 清空原来备份的WndProc指针
	}
	// 清空其他变量
	DirectX12Interface::Device = nullptr;
	DirectX12Interface::CommandQueue = nullptr;
	DirectX12Interface::CommandList = nullptr;
	oPresent = nullptr;
	oResizeBuffers = nullptr;
	oExecuteCommandLists = nullptr;
}

static void EnableConsole() // 打开控制台
{
	AllocConsole();
	FILE* pCout;
	FILE* pCerr;
	freopen_s(&pCout, "CONOUT$", "w", stdout);
	freopen_s(&pCerr, "CONOUT$", "w", stderr);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

static void DisableConsole() // 关闭控制台
{
	fclose(stdout);
	fclose(stderr);
	FreeConsole();
}

DWORD WINAPI MainThread(LPVOID lpReserved) // 主线程
{
	bool WindowFocus = false;
	do
	{
		Process::ID = GetCurrentProcessId();
		Process::Handle = GetCurrentProcess();
		window = FindWindowA("UnrealWindow", NULL); // 获取窗口句柄
		if (window)
		{
			RECT TempRect;
			GetWindowRect(window, &TempRect);
			g_width = TempRect.right - TempRect.left; // 记录窗口宽度
			g_height = TempRect.bottom - TempRect.top; // 记录窗口高度

			char TempTitle[MAX_PATH];
			GetWindowTextA(window, TempTitle, sizeof(TempTitle));
			Process::Title = TempTitle;

			char TempClassName[MAX_PATH];
			GetClassNameA(window, TempClassName, sizeof(TempClassName));
			Process::ClassName = TempClassName;

			char TempPath[MAX_PATH];
			GetModuleFileNameExA(Process::Handle, NULL, TempPath, sizeof(TempPath));
			Process::Path = TempPath;

			if (g_width > 0 && g_height > 0) // 窗口大小有效
				WindowFocus = true; // 窗口已找到
		}
		else Sleep(100); // 窗口未找到，等待100ms
	} while (WindowFocus == false);
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D12) == kiero::Status::Success) // 初始化Kiero
		{
			kiero::bind(54, (void**)&oExecuteCommandLists, hkExecuteCommandLists); // 绑定ExecuteCommandLists函数
			kiero::bind(140, (void**)&oPresent, hkPresent); // 绑定Present函数
			kiero::bind(145, (void**)&oResizeBuffers, hkResizeBuffers); // 绑定ResizeBuffers函数
			init_hook = true;
		}
		else Sleep(10); // 等待Kiero初始化
	} while (!init_hook);
	while (!exit_hook) // 循环等待退出消息
	{
		Sleep(100); // 等待消息
	}
	Sleep(100); // 等待资源处理
	if (_DEBUG) DisableConsole(); // 关闭控制台
	UnloadDX12Hook(); // 卸载DX12 Hook
	UI::Release();
	Function::Release();
	HMODULE hModule = static_cast<HMODULE>(lpReserved); // 获取DLL模块句柄
	FreeLibraryAndExitThread(hModule, 0); // 释放DLL并退出线程
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved) // 入口函数
{
	if (dwReason == DLL_PROCESS_ATTACH) // 进程加载
	{
		DisableThreadLibraryCalls(hMod); // 禁止DLL线程调用
		if (_DEBUG) EnableConsole(); // 打开控制台
		HANDLE hThread = CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr); // 创建主线程
		if (hThread) // 线程创建成功
			CloseHandle(hThread); // 关闭线程句柄
	}
	return TRUE;
}