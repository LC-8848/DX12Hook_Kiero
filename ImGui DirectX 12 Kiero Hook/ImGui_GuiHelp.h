#pragma once
#ifndef IMGUI_GUIHELP_H_
#define IMGUI_GUIHELP_H_

#include "ImGui/imgui.h"

/* ImGui 函数定义区域 */
// GetBackgroundDrawList 中的函数绘制在ImGui窗口的下面
// GetForegroundDrawList 中的函数绘制在ImGui窗口的上面
extern ImU32 White30;
extern ImU32 White210;
extern ImU32 White255;
extern ImU32 Black30;
extern ImU32 Black210;
extern ImU32 Black255;
extern ImU32 Red30;
extern ImU32 Red210;
extern ImU32 Red255;
extern ImU32 Green30;
extern ImU32 Green210;
extern ImU32 Green255;
extern ImU32 Blue30;
extern ImU32 Blue210;
extern ImU32 Blue255;
extern ImU32 Yellow30;
extern ImU32 Yellow210;
extern ImU32 Yellow255;
extern ImU32 Purple30;
extern ImU32 Purple210;
extern ImU32 Purple255;
extern ImU32 Gray30;
extern ImU32 Gray210;
extern ImU32 Gray255;

void SetModernDarkTheme();
void SetModernDarkThemeWithLucency();
void SetKawaiiPinkTheme();
void SetKawaiiPinkThemeWithLucency();

// 白绿渐变函数（环形追逐 + 透明过渡）
ImColor GetWhiteGreenColor_Transparent(float t);
// 白绿渐变函数（环形追逐 + 黑色过渡）
ImColor GetWhiteGreenColor(float t);
// 暖色系渐变函数（基于HSL色相逆时针过渡）
ImColor GetWarmColor(float t);
// 冷色系渐变函数（基于HSL色彩模型）
ImColor GetCoolColor(float t);
// 彩色渐变函数（基于RGB色彩模型）
ImU32 GetRainbowColorFromRGB(float t);
// 彩色渐变函数（基于HSL色彩模型）
ImColor GetRainbowColorFromHSL(float t);

namespace ImGui_Draw_Force
{
	// 绘制文本
	void DrawTexts(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawTexts(float Pos_X, float Pos_Y, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawTextsOutlined(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawTextsOutlined(float Pos_X, float Pos_Y, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	// 绘制居中文本
	void DrawCenterTextsOutlined(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawCenterTextsOutlinedA(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	// 支持中文的动态彩色文本绘制函数
	void DrawSuperEffectText(ImFont* font, float size, ImVec2 pos, const char* text, float time, float spacing = 0.0f);
	// 支持中文 + 缩放 + 彩虹渐变颜色
	void DrawSuperEffectTextPlus(ImFont* font, float base_size, ImVec2 pos, const char* text, float time, float spacing = 0.0f);
}

namespace ImGui_Draw_Back
{
	// 绘制文本
	void DrawTexts(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawTexts(float Pos_X, float Pos_Y, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawTextsOutlined(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawTextsOutlined(float Pos_X, float Pos_Y, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	// 绘制居中文本
	void DrawCenterTexts(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawCenterTextsOutlined(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawCenterTextsA(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	void DrawCenterTextsOutlinedA(ImVec2 Pos, const char* text, ImU32 color = Green210, float size = 20.0f, ImFont* font = nullptr);
	// 绘制矩形
	void DrawRectangle(ImVec2 Pos, ImVec2 Size, ImU32 color = Green210, float thickness = 1.0f, float rounding = 0.0f, ImDrawCornerFlags flags = ImDrawCornerFlags_None);
	// 绘制填充矩形
	void DrawFilledRectangle(ImVec2 Pos, ImVec2 Size, ImU32 color = ImColor(0, 255, 0, 30), float rounding = 0.0f, ImDrawCornerFlags flags = ImDrawCornerFlags_None);
	// 绘制线段
	void DrawLine(ImVec2 Pos_Start, ImVec2 Pos_End, ImU32 color = Green210, float thickness = 1.0f);
	void DrawLine(float Pos_Start_X, float Pos_Start_Y, float Pos_End_X, float Pos_End_Y, ImU32 color = Green210, float thickness = 1.0f);
	// 绘制圆形
	void DrawCircle(ImVec2 Pos, float radius, ImU32 color = White210, int num_segments = 0, float thickness = 1.0f);
	// 绘制填充圆形
	void DrawFilledCircle(ImVec2 center, float radius, ImU32 color, int num_segments = 0);
	// 更自然的彩色渐变 + 发光模拟矩形
	void DrawGlowingRect(ImVec2 min, ImVec2 max, float time, float base_thickness = 1.5f, float rounding = 5.0f);
	// 绘制动态矩形
	void DrawRunningRect(ImVec2 min, ImVec2 size, float time, bool is_bot, float thickness = 1.0f, float rounding = 0.0f);
	// 绘制跑马灯线条
	void DrawRunningLine(ImVec2 start, ImVec2 end, float time, bool is_bot, float thickness, int segments, float Alpha);
	// 绘制跑马灯箭头线条
	void DrawRunningArrow(ImVec2 start, ImVec2 end, float time, bool is_bot, float thickness, float arrow_size, int segments);
	// 绘制跑马灯虚线线条
	void DrawRunningDashedLine(ImVec2 start, ImVec2 end, float time, bool is_bot, float thickness, float dash_length, int segments);
	// 绘制动态圆环
	void DrawRunningCircle(ImVec2 center, float radius, float time, bool is_bot, float thickness, int segments, float Alpha);
	// 绘制血条
	void DrawHpBar(ImVec2 pos, ImVec2 size, float currentHp, float maxHp, ImU32 HpColor);

}

/* ImGui 结束定义区域 */

#endif // IMGUI_GUIHELP_H_