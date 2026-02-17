#include "UI.h"
#include "main.h"

uint64_t is_crash_count = 0; // 崩溃计数器

void UI::Init() // 注入时初始化一次
{
}

void UI::Tick() // 每帧调用一次
{
	ImGuiIO& io = ImGui::GetIO(); &io; // 获取ImGui输入输出对象
	static bool show_menu = true;
	if (ImGui::IsKeyPressed(VK_INSERT, false)) show_menu = !show_menu; // 按下INSERT键显隐菜单
	if (io.KeysDown[VK_END]) exit_hook = true; // 按下END键退出
	ImGui::SetNextWindowPos(ImVec2(g_width / 20 * 11, 0), ImGuiCond_FirstUseEver); // 设置初始窗口位置
	ImGui::SetNextWindowSize(ImVec2(450, 390), ImGuiCond_FirstUseEver); // 设置初始窗口大小
	ImGui::SetNextWindowSizeConstraints(ImVec2(100, 0), ImVec2(g_width, g_height)); // 设置窗口大小限制
	if (show_menu) // 显示菜单
	{
		ImGui::Begin(u8("这是一个ImGui菜单 --INSERT键显隐菜单")); // 开始一个ImGui窗口
		ImGui::Text(u8("我想，你Hook成功了！"));
		if (ImGui::BeginTabBar("TabBar"))
		{
			if (ImGui::BeginTabItem(u8("声明")))
			{
				ImGui::Text(u8("开源项目，请勿用于商业用途！"));
				ImGui::Text(u8("仅供学习交流使用，请勿用于非法用途！"));
				ImGui::Text(u8("作者：冷辰"));
				ImGui::Text(u8("QQ交流群：636674384"));
				ImGui::Text(u8("Github：https://github.com/LC-8848/DX12Hook_Kiero"));
				ImGui::Text(u8("新增：按下 INSERT 键显示/隐藏菜单，按下 END 键退出程序。"));
				ImGui::Text(u8("改进：被注入窗口支持调整大小不会导致崩溃。"));
				ImGui::Text(u8("修复：解决因反复注入导致的崩溃问题。"));
				ImGui::Text(u8("修复：修复退出 ImGui 时的崩溃问题。"));
				ImGui::Text(u8("其他：修复其他若干稳定性问题。"));
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(u8("调试")))
			{
				ImGui::Text(u8("运行中崩溃次数：%lld"), is_crash_count);
				ImGui::Text(u8("游戏分辨率：%d x %d"), g_width, g_height);
				ImGui::Text(u8("光标位置：(%.1f, %.1f)"), clamp(io.MousePos.x, 0.0f, (float)g_width), clamp(io.MousePos.y, 0.0f, (float)g_height));
				ImGui::Text(u8("ImGui菜单大小：(%.1f, %.1f)"), ImGui::GetWindowSize().x, ImGui::GetWindowSize().y);
				ImGui::Text(u8("菜单位置：(%.1f, %.1f)"), ImGui::GetWindowPos().x, ImGui::GetWindowPos().y);
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
		if (ImGui::Button(u8("退出"))) exit_hook = true; // 退出按钮
		ImGui::Separator(); // 分割线
		ImGui::Text(u8("当前FPS：%.1f"), io.Framerate); // 显示当前FPS
		ImGui::End(); // 结束ImGui窗口
	}

	__try { if (!exit_hook) Function::Tick(); } // 调用功能模块的Tick函数
	__except (EXCEPTION_EXECUTE_HANDLER) { is_crash_count++; } // 帧级异常处理
}

void UI::Release() // 注销时释放一次
{
}