# DX12Hook_Kiero

[![License](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)

**DX12Hook_Kiero** 是一个专为 **Unreal Engine 5.0 及以上版本** 设计的 **DirectX 12 渲染钩子**，基于 **Kiero** 与 **MinHook** 构建。它能够在运行时将自定义 DLL 注入目标进程，无缝集成 [Dear ImGui](https://github.com/ocornut/imgui) 界面，为开发者、模组作者及逆向工程师提供一个实时调试和可视化图形管道的强大平台。

---

## 📖 简介

虚幻引擎 5 引入了全新的 Nanite、Lumen 等图形技术，底层渲染完全基于 DirectX 12。传统注入工具在 DX12 环境下常常面临不稳定、崩溃或兼容性问题。DX12Hook_Kiero 通过底层 API 无痕挂钩，完美适配 UE5 的 DX12 渲染管线，解决了窗口缩放、重复注入及安全退出等常见崩溃问题，让开发者能够专注于功能实现而非稳定性调试。

无论是用于开发游戏内调试工具、创建自定义模组，还是深入理解 DX12 渲染机制，本工具都能提供一个稳定、灵活且易于使用的起点。

---

## ✨ 特性

- **🎯 精准适配 UE5 (DX12)**  
  基于 [Kiero](https://github.com/Rini-Studio/Kiero) 的 DX12 挂钩实现，利用 [MinHook](https://github.com/TsudaKageyu/minhook) 进行高效、稳定的 API 拦截，专为虚幻引擎 5 的渲染流程优化，确保注入后渲染无延迟、无闪退。

- **🛡️ 坚如磐石的稳定性**  
  完全解决了以下常见崩溃场景：
  - 调整 ImGui 窗口大小时导致程序崩溃
  - 多次注入/卸载 DLL 造成的死锁或崩溃
  - 退出 ImGui 或卸载 Hook 时引发的内存访问违规  
  现在您可以自由调整窗口大小、多次注入或随时退出，无需担心游戏或工具本身崩溃。

- **🎮 便捷的全局控制**  
  - 按下 **`INSERT`** 键：实时显示或隐藏 ImGui 菜单界面
  - 按下 **`END`** 键：安全、干净地退出整个 Hook 程序（释放资源、恢复挂钩）

- **🚀 即插即用**  
  编译生成 DLL 后，使用任意常规注入工具（如 Extreme Injector、Xenos 等）加载到目标 UE5 进程即可生效。无需修改游戏源文件，对游戏性能影响极小（仅在 ImGui 渲染时占用少量 CPU/GPU 资源）。

- **🔧 高度可定制**  
  项目源码完全开放，您可以根据需求自由修改 ImGui 界面布局、添加自定义控件或扩展功能。所有 ImGui 绘制逻辑均与挂钩代码分离，易于维护。

---

## 📋 快速开始

### 前置要求
- Windows 10/11 操作系统（需支持 DirectX 12）
- Visual Studio 2022 或更高版本（用于编译）
- 一个基于 Unreal Engine 5.0+ 的 64 位应用程序（目标进程）

### 依赖库
本项目依赖于以下第三方库（均已包含或可通过子模块获取）：
- [Dear ImGui](https://github.com/ocutorn/imgui) v1.90+（用于界面渲染）
- [Kiero](https://github.com/Rini-Studio/Kiero)（提供 DirectX 12 挂钩点）
- [MinHook](https://github.com/TsudaKageyu/minhook)（提供高效 API 挂钩）

### 构建步骤
1. **克隆仓库**（包含子模块）：
   ```bash
   git clone --recursive https://github.com/yourname/DX12Hook_Kiero.git
   cd DX12Hook_Kiero
   ```
2. 使用 Visual Studio 打开解决方案文件 `DX12Hook_Kiero.sln`。
3. 选择配置为 `Release` 和平台 `x64`。
4. 生成解决方案，编译后将得到 `DX12Hook_Kiero.dll`。

### 注入方法
1. 启动目标 UE5 应用程序。
2. 以管理员身份运行您常用的 DLL 注入工具。
3. 选择目标进程（例如 `YourGame.exe`），并将 `DX12Hook_Kiero.dll` 注入。
4. 注入成功后，ImGui 界面将自动出现，您可以使用 `INSERT` 键切换显示/隐藏。

> **注意**：部分 UE5 游戏可能启用了反作弊系统，注入前请确认您的行为符合相关法律法规及用户协议。

---

## 🎮 使用方法

- **显示/隐藏菜单**：按下 `INSERT` 键。当菜单隐藏时，所有 ImGui 窗口均不可见，游戏操作不受任何影响。
- **退出 Hook**：按下 `END` 键。工具将自动恢复所有 API 挂钩，释放分配的资源，然后安全退出 DLL。卸载后游戏可继续正常运行（若需重新显示，再次注入即可）。

您可以在 `imgui_demo.cpp` 或 `main.cpp` 中修改 ImGui 的初始化及绘制代码，添加自定义窗口、控件或调试信息。

---

## 🔧 兼容性

- **目标引擎**：Unreal Engine 5.0、5.1、5.2、5.3 及以上版本（理论上兼容所有使用 DX12 渲染的 UE5 游戏）。
- **图形 API**：仅支持 DirectX 12（不支持 Vulkan 或 DX11，如有需要可自行修改 Kiero 初始化部分）。
- **系统**：Windows 10 版本 1809+ 或 Windows 11。

已知在以下游戏中测试通过：
- 《The Matrix Awakens》（UE5 示例）
- 《Fortnite》（UE5 版本，需注意反作弊）
- 其他基于 UE5 的自研项目

---

## ⚠️ 注意事项

1. **反作弊系统**  
   如果目标游戏采用了 EAC、BattlEye 等内核级反作弊，注入 DLL 可能导致封号。请仅在单人游戏或您拥有合法修改权限的环境中使用。

2. **多线程渲染**  
   UE5 可能使用多线程渲染，本工具在 Present 挂钩点同步执行 ImGui 绘制，确保线程安全。若遇渲染卡顿，可尝试在 `D3D12Hook.cpp` 中调整挂钩点位置。

3. **调试符号**  
   如需调试，建议使用 Visual Studio 的“附加到进程”功能，并确保编译为 Debug 版本以获取完整符号信息。

4. **许可证合规**  
   本工具采用 **GPLv3** 许可证，任何基于本工具的二次开发或分发都必须遵循 GPLv3 协议（即必须开源且采用相同许可证）。详情请参阅 [LICENSE](LICENSE) 文件。

---

## 📁 项目结构

```
DX12Hook_Kiero/
├── src/                    # 源码目录
│   ├── dllmain.cpp         # DLL 入口点
│   ├── D3D12Hook.cpp       # DX12 挂钩实现
│   ├── ImGuiRenderer.cpp   # ImGui 渲染与消息处理
│   └── ...
├── vendor/                 # 第三方依赖（子模块）
│   ├── imgui/
│   ├── kiero/
│   └── minhook/
├── DX12Hook_Kiero.sln      # Visual Studio 解决方案
├── README.md               # 本文档
└── LICENSE                 # GPLv3 许可证
```

---

## 🤝 贡献

欢迎提交 Issue 和 Pull Request 来改进本项目。在提交代码前，请确保：
- 代码风格与现有项目保持一致
- 新增功能不影响现有稳定性
- 更新相关文档

---

## 📄 许可证

Copyright © [年份] [作者/组织]

本项目采用 **GNU General Public License v3.0** 进行许可。  
这意味着您可以自由使用、修改和分发本代码，但任何基于本项目的衍生作品也必须以 GPLv3 协议开源，且不得闭源商业化。完整的许可证条款请参见 [LICENSE](LICENSE) 文件。

---

**DX12Hook_Kiero** — 为 UE5 开发者打开一扇通往内部渲染世界的窗口。
