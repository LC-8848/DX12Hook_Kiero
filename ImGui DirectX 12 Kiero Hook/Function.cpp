#include "Function.h"

UINT g_width = 0;
UINT g_height = 0;

void Function::Init() // 注入时初始化一次
{
}

void Function::Tick() // 每帧调用一次
{
	ImGuiIO& io = ImGui::GetIO(); &io; // 获取ImGui输入输出对象
	ImFont* font = io.Fonts->Fonts[0]; // 获取默认字体
	float t = ImGui::GetTime(); // 获取当前时间

	if (ImGui::IsKeyPressed(VK_F1)) is_crash_count = 0; // 按F1重置崩溃计数器
	if (is_crash_count > 50)
	{
		std::string text = u8("游戏出现>50次崩溃，请检查代码是否有误！");
		ImVec2 text_size = font->CalcTextSizeA(52.0f, FLT_MAX, 0.0f, text.c_str(), nullptr, nullptr);
		ImVec2 pos = ImVec2(g_width / 2 - text_size.x * 0.5f, g_height / 2 - text_size.y * 0.5f);
		ImGui_Draw_Force::DrawSuperEffectTextPlus(font, 52.0f, pos, text.c_str(), t, 0.0f);
	}
	else if (is_crash_count > 10)
	{
		std::string text = u8("游戏出现<50次崩溃，请检查代码！");
		ImVec2 text_size = font->CalcTextSizeA(24.0f, FLT_MAX, 0.0f, text.c_str(), nullptr, nullptr);
		ImVec2 pos = ImVec2(g_width / 2 - text_size.x * 0.5f, 24.0f - text_size.y * 0.5f);
		ImGui_Draw_Force::DrawSuperEffectTextPlus(font, 24.0f, pos, text.c_str(), t, 0.0f);
	}
	else if (is_crash_count > 0)
	{
		std::string text = u8("游戏出现<10次崩溃，请注意！");
		ImVec2 text_size = font->CalcTextSizeA(20.0f, FLT_MAX, 0.0f, text.c_str(), nullptr, nullptr);
		ImVec2 pos = ImVec2(g_width / 2 - text_size.x * 0.5f, 20.0f - text_size.y * 0.5f);
		ImGui_Draw_Force::DrawSuperEffectTextPlus(font, 20.0f, pos, text.c_str(), t, 0.0f);
	}

	// 绘制FPS
	char fps_str[64];
	snprintf(fps_str, sizeof(fps_str), u8("帧率: %.0f"), io.Framerate);
	ImGui_Draw_Force::DrawSuperEffectText(font, 20.0f, ImVec2(0, 0), fps_str, t, 0.0f);
}

void Function::Release() // 注销时释放一次
{
}