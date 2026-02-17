#include "ImGui_GuiHelp.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include <algorithm>
#include <cmath>
#include <vector>

// 定义颜色变量
ImU32 White30 = ImColor(255, 255, 255, 30);
ImU32 White210 = ImColor(255, 255, 255, 210);
ImU32 White255 = ImColor(255, 255, 255, 255);
ImU32 Black30 = ImColor(0, 0, 0, 30);
ImU32 Black210 = ImColor(0, 0, 0, 210);
ImU32 Black255 = ImColor(0, 0, 0, 255);
ImU32 Red30 = ImColor(255, 0, 0, 30);
ImU32 Red210 = ImColor(255, 0, 0, 210);
ImU32 Red255 = ImColor(255, 0, 0, 255);
ImU32 Green30 = ImColor(0, 255, 0, 30);
ImU32 Green210 = ImColor(0, 255, 0, 210);
ImU32 Green255 = ImColor(0, 255, 0, 255);
ImU32 Blue30 = ImColor(0, 0, 255, 30);
ImU32 Blue210 = ImColor(0, 0, 255, 210);
ImU32 Blue255 = ImColor(0, 0, 255, 255);
ImU32 Yellow30 = ImColor(255, 255, 0, 30);
ImU32 Yellow210 = ImColor(255, 255, 0, 210);
ImU32 Yellow255 = ImColor(255, 255, 0, 255);
ImU32 Purple30 = ImColor(255, 0, 255, 30);
ImU32 Purple210 = ImColor(255, 0, 255, 210);
ImU32 Purple255 = ImColor(255, 0, 255, 255);
ImU32 Gray30 = ImColor(128, 128, 128, 30);
ImU32 Gray210 = ImColor(128, 128, 128, 210);
ImU32 Gray255 = ImColor(128, 128, 128, 255);

void SetModernDarkTheme() // 现代黑暗主题
{
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;
    style.FrameRounding = 6.0f;
    style.PopupRounding = 6.0f;
    style.GrabRounding = 4.0f;
    style.ScrollbarRounding = 6.0f;
    style.ChildRounding = 6.0f;

    style.FrameBorderSize = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;

    ImVec4* colors = style.Colors;

    colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.14f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.14f, 0.14f, 0.16f, 1.00f);
    colors[ImGuiCol_Border] = ImVec4(0.35f, 0.35f, 0.39f, 0.40f);

    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.30f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.45f, 0.60f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.25f, 0.38f, 0.55f, 1.00f);

    colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.50f, 0.75f, 0.78f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.45f, 0.60f, 0.85f, 1.00f);

    colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.10f, 0.12f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.20f, 0.25f, 1.00f);

    colors[ImGuiCol_Tab] = ImVec4(0.13f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.35f, 0.45f, 0.85f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.28f, 0.38f, 1.00f);

    colors[ImGuiCol_Text] = ImVec4(0.90f, 0.92f, 0.95f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.55f, 0.58f, 0.60f, 1.00f);

    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.18f, 0.20f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.28f, 0.32f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.22f, 0.25f, 0.30f, 1.00f);

    colors[ImGuiCol_Header] = ImVec4(0.25f, 0.35f, 0.45f, 0.70f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.35f, 0.45f, 0.60f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.30f, 0.40f, 0.55f, 1.00f);

    colors[ImGuiCol_CheckMark] = ImVec4(0.55f, 0.75f, 0.95f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.32f, 0.32f, 0.38f, 1.00f);
}

void SetKawaiiPinkTheme() // 可爱粉主题
{
    ImGui::StyleColorsLight();

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;
    style.FrameRounding = 6.0f;
    style.PopupRounding = 6.0f;
    style.GrabRounding = 4.0f;
    style.ScrollbarRounding = 6.0f;
    style.ChildRounding = 6.0f;

    style.FrameBorderSize = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;

    ImVec4* colors = style.Colors;

    // 背景
    colors[ImGuiCol_WindowBg] = ImVec4(0.96f, 0.87f, 0.92f, 1.00f);

    // 标题栏
    colors[ImGuiCol_TitleBg] = ImVec4(0.89f, 0.58f, 0.72f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.94f, 0.67f, 0.82f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.90f, 0.57f, 0.70f, 0.75f);

    // 菜单栏
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.92f, 0.63f, 0.77f, 1.00f);

    // 按钮
    colors[ImGuiCol_Button] = ImVec4(0.93f, 0.67f, 0.82f, 0.85f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.97f, 0.75f, 0.88f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.85f, 0.55f, 0.70f, 1.00f);

    // 复选框、列表头
    colors[ImGuiCol_Header] = ImVec4(0.93f, 0.67f, 0.83f, 0.60f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.97f, 0.74f, 0.89f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.88f, 0.54f, 0.69f, 1.00f);

    // 边框和分割线
    colors[ImGuiCol_Border] = ImVec4(0.85f, 0.50f, 0.66f, 1.00f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0, 0, 0, 0);

    // 文字颜色
    colors[ImGuiCol_Text] = ImVec4(0.40f, 0.10f, 0.30f, 1.00f);

    // 滚动条
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.95f, 0.87f, 0.91f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.93f, 0.67f, 0.82f, 0.75f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.96f, 0.72f, 0.86f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.88f, 0.54f, 0.69f, 1.00f);

    // 输入框
    colors[ImGuiCol_FrameBg] = ImVec4(0.94f, 0.70f, 0.82f, 0.40f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.96f, 0.74f, 0.88f, 0.75f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.88f, 0.54f, 0.69f, 1.00f);

    // 复选框勾选颜色 - 加深，提升对比
    colors[ImGuiCol_CheckMark] = ImVec4(0.65f, 0.15f, 0.40f, 1.00f);

    // 滑块抓取
    colors[ImGuiCol_SliderGrab] = ImVec4(0.93f, 0.67f, 0.82f, 0.85f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.85f, 0.50f, 0.65f, 1.00f);

    // Tab标签页
    colors[ImGuiCol_Tab] = ImVec4(0.90f, 0.60f, 0.75f, 0.86f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.97f, 0.75f, 0.90f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.88f, 0.54f, 0.69f, 1.00f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.91f, 0.65f, 0.79f, 0.60f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.89f, 0.58f, 0.72f, 1.00f);

    // 弹出窗口背景
    colors[ImGuiCol_PopupBg] = ImVec4(0.95f, 0.85f, 0.90f, 1.00f);

    // 新增：Disabled文本色，避免灰色过浅
    colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.40f, 0.50f, 1.00f);

    // 圆角设置
    style.WindowRounding = 10.0f;
    style.FrameRounding = 6.0f;
    style.ScrollbarRounding = 6.0f;
    style.GrabRounding = 6.0f;
    style.TabRounding = 8.0f;
}

void SetModernDarkThemeWithLucency() // 现代黑暗主题（透明效果）
{
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;
    style.FrameRounding = 6.0f;
    style.PopupRounding = 6.0f;
    style.GrabRounding = 4.0f;
    style.ScrollbarRounding = 6.0f;
    style.ChildRounding = 6.0f;

    style.FrameBorderSize = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;

    ImVec4* colors = style.Colors;

    colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.14f, 0.90f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.10f, 0.12f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.14f, 0.14f, 0.16f, 0.90f);
    colors[ImGuiCol_Border] = ImVec4(0.35f, 0.35f, 0.39f, 0.30f);

    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.30f, 0.90f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.45f, 0.60f, 0.85f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.25f, 0.38f, 0.55f, 0.85f);

    colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.50f, 0.75f, 0.65f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.45f, 0.60f, 0.85f, 0.85f);

    colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.10f, 0.12f, 0.95f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.20f, 0.25f, 0.95f);

    colors[ImGuiCol_Tab] = ImVec4(0.13f, 0.15f, 0.18f, 0.90f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.26f, 0.35f, 0.45f, 0.75f);
    colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.28f, 0.38f, 0.90f);

    colors[ImGuiCol_Text] = ImVec4(0.90f, 0.92f, 0.95f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.55f, 0.58f, 0.60f, 0.75f);

    colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.12f, 0.14f, 0.66f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.28f, 0.32f, 0.75f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.22f, 0.25f, 0.30f, 0.85f);

    colors[ImGuiCol_Header] = ImVec4(0.25f, 0.35f, 0.45f, 0.55f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.35f, 0.45f, 0.60f, 0.70f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.30f, 0.40f, 0.55f, 0.85f);

    colors[ImGuiCol_CheckMark] = ImVec4(0.55f, 0.75f, 0.95f, 0.85f);
    colors[ImGuiCol_Separator] = ImVec4(0.32f, 0.32f, 0.38f, 0.75f);
}

void SetKawaiiPinkThemeWithLucency() // 卡哇伊粉主题（透明效果）
{
    ImGui::StyleColorsLight();

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;
    style.FrameRounding = 6.0f;
    style.PopupRounding = 6.0f;
    style.GrabRounding = 4.0f;
    style.ScrollbarRounding = 6.0f;
    style.ChildRounding = 6.0f;

    style.FrameBorderSize = 0.0f;
    style.WindowBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;

    ImVec4* colors = style.Colors;

    // 背景
    colors[ImGuiCol_WindowBg] = ImVec4(0.96f, 0.87f, 0.92f, 0.90f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.96f, 0.87f, 0.92f, 0.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.96f, 0.87f, 0.92f, 0.92f);

    // 标题栏
    colors[ImGuiCol_TitleBg] = ImVec4(0.89f, 0.58f, 0.72f, 0.83f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.94f, 0.67f, 0.82f, 0.87f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.90f, 0.57f, 0.70f, 0.20f);

    // 菜单栏
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.92f, 0.63f, 0.77f, 0.80f);

    // 按钮
    colors[ImGuiCol_Button] = ImVec4(0.93f, 0.67f, 0.82f, 0.62f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.97f, 0.75f, 0.88f, 0.79f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.85f, 0.55f, 0.70f, 1.00f);

    // Header（复选框、列表头等）
    colors[ImGuiCol_Header] = ImVec4(0.93f, 0.67f, 0.83f, 0.45f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.97f, 0.74f, 0.89f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.88f, 0.54f, 0.69f, 0.80f);

    // 边框
    colors[ImGuiCol_Border] = ImVec4(0.85f, 0.50f, 0.66f, 0.50f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);

    // 文字
    colors[ImGuiCol_Text] = ImVec4(0.40f, 0.10f, 0.30f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.40f, 0.50f, 1.00f); // 自定义也可调

    // 滚动条
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.95f, 0.87f, 0.91f, 0.60f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.88f, 0.60f, 0.78f, 0.30f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.88f, 0.60f, 0.78f, 0.40f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.88f, 0.60f, 0.78f, 0.60f);

    // 滑块
    colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 0.80f, 0.90f, 0.30f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.80f, 0.90f, 0.60f);

    // 分隔条
    colors[ImGuiCol_Separator] = ImVec4(0.80f, 0.50f, 0.70f, 0.60f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.80f, 0.50f, 0.70f, 1.00f);
    colors[ImGuiCol_SeparatorActive] = ImVec4(0.80f, 0.50f, 0.70f, 1.00f);

    colors[ImGuiCol_FrameBg] = ImVec4(0.92f, 0.75f, 0.85f, 0.50f);  // 输入框、复选框等背景
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.97f, 0.75f, 0.88f, 0.40f);  // 鼠标悬停
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.97f, 0.75f, 0.88f, 0.60f);  // 点击时

    colors[ImGuiCol_CheckMark] = ImVec4(0.88f, 0.33f, 0.65f, 1.00f);  // 复选框对勾
    colors[ImGuiCol_PlotLines] = ImVec4(0.90f, 0.55f, 0.75f, 1.00f);  // 折线图
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.95f, 0.66f, 0.85f, 1.00f);  // 柱状图

    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 0.80f, 0.90f, 0.90f);  // 拖放目标高亮
    colors[ImGuiCol_NavHighlight] = ImVec4(0.85f, 0.40f, 0.70f, 0.80f);  // 键盘/手柄导航高亮
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.85f, 0.40f, 0.70f, 0.60f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.50f, 0.70f, 0.20f);

    colors[ImGuiCol_Tab] = ImVec4(0.95f, 0.66f, 0.85f, 0.60f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.97f, 0.75f, 0.88f, 0.80f);
    colors[ImGuiCol_TabActive] = ImVec4(0.88f, 0.33f, 0.65f, 0.90f);
    colors[ImGuiCol_TabUnfocused] = ImVec4(0.95f, 0.66f, 0.85f, 0.30f);
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.88f, 0.33f, 0.65f, 0.50f);
}

// 白绿渐变函数（环形追逐 + 透明过渡）
ImColor GetWhiteGreenColor_Transparent(float t)
{
    // t 范围 0~1，循环渐变：绿 → 透明 → 白 → 透明 → 绿
    t = fmodf(t, 1.0f);

    float r = 0, g = 0, b = 0, a = 1.0f;

    if (t < 0.25f)
    {
        // 绿 → 透明（alpha逐渐减小）
        float k = t / 0.25f;        // 0~1
        r = 0.0f;
        g = 1.0f;
        b = 0.0f;
        a = 1.0f - k;              // alpha 从1变0
    }
    else if (t < 0.5f)
    {
        // 透明 → 白（alpha逐渐增大）
        float k = (t - 0.25f) / 0.25f;
        r = 1.0f;
        g = 1.0f;
        b = 1.0f;
        a = k;                    // alpha 从0变1
    }
    else if (t < 0.75f)
    {
        // 白 → 透明（alpha逐渐减小）
        float k = 1.0f - (t - 0.5f) / 0.25f;
        r = 1.0f;
        g = 1.0f;
        b = 1.0f;
        a = k;                    // alpha 从1变0
    }
    else
    {
        // 透明 → 绿（alpha逐渐增大）
        float k = (t - 0.75f) / 0.25f;
        r = 0.0f;
        g = 1.0f;
        b = 0.0f;
        a = k;                    // alpha 从0变1
    }

    return ImColor(r, g, b, a);
}

// 白绿渐变函数（环形追逐 + 黑色过渡）
ImColor GetWhiteGreenColor(float t)
{
    // t 范围 0~1，映射一个圆周，环形渐变：绿 → 黑 → 白 → 黑 → 绿 ...
    t = fmodf(t, 1.0f);

    // 将 t 分为 4 个区间：0~0.25（绿→黑）、0.25~0.5（黑→白）、0.5~0.75（白→黑）、0.75~1.0（黑→绿）
    float r = 0, g = 0, b = 0;

    if (t < 0.25f)
    {
        // 绿 → 黑（逐渐变暗）
        float k = t / 0.25f;        // 0~1
        r = (1.0f - k) * 0.0f;
        g = (1.0f - k) * 1.0f;
        b = (1.0f - k) * 0.0f;
    }
    else if (t < 0.5f)
    {
        // 黑 → 白（逐渐变亮）
        float k = (t - 0.25f) / 0.25f;
        r = g = b = k;
    }
    else if (t < 0.75f)
    {
        // 白 → 黑（逐渐变暗）
        float k = 1.0f - (t - 0.5f) / 0.25f;
        r = g = b = k;
    }
    else
    {
        // 黑 → 绿（逐渐变亮的绿）
        float k = (t - 0.75f) / 0.25f;
        r = 0.0f;
        g = k;
        b = 0.0f;
    }

    return ImColor(r, g, b, 1.0f);
}

// 暖色系渐变函数（基于HSL色相逆时针过渡）
ImColor GetWarmColor(float t)
{
    // t: 0 ~ 1，控制从 300°（紫红）→ 0°（红）→ 60°（黄）渐变
    float hue = fmodf(300.0f + t * 120.0f, 360.0f); // 总跨度为 120°

    float s = 1.0f; // 饱和度
    float v = 1.0f; // 明度

    int hi = (int)(hue / 60.0f) % 6;
    float f = (hue / 60.0f) - hi;
    float p = v * (1.0f - s);
    float q = v * (1.0f - f * s);
    float r = 0, g = 0, b = 0;

    switch (hi)
    {
    case 0: r = v; g = q; b = p; break; // 红
    case 1: r = q; g = v; b = p; break; // 橙
    case 2: r = p; g = v; b = q; break; // 黄
    case 3: r = p; g = q; b = v; break; // 黄绿
    case 4: r = q; g = p; b = v; break; // 品红
    case 5: r = v; g = p; b = q; break; // 紫红
    }

    return ImColor(r, g, b, 1.0f);
}

// 冷色系渐变函数（基于HSL色彩模型）
ImColor GetCoolColor(float t)
{
    // t 范围：0 ~ 1
    // 从青 -> 蓝 -> 紫 循环渐变
    float hue = 180.0f + t * 120.0f; // 色相 H：180°（青）到 300°（紫）
    float s = 1.0f;
    float v = 1.0f;

    int hi = (int)(hue / 60.0f) % 6;
    float f = (hue / 60.0f) - hi;
    float p = v * (1.0f - s);
    float q = v * (1.0f - f * s);
    float r = 0, g = 0, b = 0;

    switch (hi)
    {
    case 3: r = p; g = q; b = v; break; // 青到蓝
    case 4: r = q; g = p; b = v; break; // 蓝到紫
    case 5: r = v; g = p; b = q; break; // 紫过渡
    }

    return ImColor(r, g, b, 1.0f);
}

// 彩色渐变函数（基于RGB色彩模型）
ImU32 GetRainbowColorFromRGB(float t)
{
    float r = 0.5f + 0.5f * sinf(t + 0.0f);
    float g = 0.5f + 0.5f * sinf(t + 2.0f);
    float b = 0.5f + 0.5f * sinf(t + 4.0f);
    return ImColor(r, g, b, 1.0f);
}

// 彩色渐变函数（基于HSL色彩模型）
ImColor GetRainbowColorFromHSL(float t)
{
    // t 0~1，映射到色相360°
    float hue = t * 360.0f;
    float s = 1.0f; // 饱和度
    float v = 1.0f; // 明度

    // 简单HSL->RGB转换
    int hi = (int)(hue / 60.0f) % 6;
    float f = (hue / 60.0f) - hi;
    float p = v * (1.0f - s);
    float q = v * (1.0f - f * s);
    float r = 0, g = 0, b = 0;
    switch (hi)
    {
    case 0: r = v; g = q; b = p; break;
    case 1: r = q; g = v; b = p; break;
    case 2: r = p; g = v; b = q; break;
    case 3: r = p; g = q; b = v; break;
    case 4: r = q; g = p; b = v; break;
    case 5: r = v; g = p; b = q; break;
    }
    return ImColor(r, g, b, 1.0f);
}

// Based on stb_to_utf8() from github.com/nothings/stb/
static inline int ImTextCharToUtf8(char* buf, int buf_size, unsigned int c)
{
    if (c < 0x80)
    {
        buf[0] = (char)c;
        return 1;
    }
    if (c < 0x800)
    {
        if (buf_size < 2) return 0;
        buf[0] = (char)(0xc0 + (c >> 6));
        buf[1] = (char)(0x80 + (c & 0x3f));
        return 2;
    }
    if (c >= 0xdc00 && c < 0xe000)
    {
        return 0;
    }
    if (c >= 0xd800 && c < 0xdc00)
    {
        if (buf_size < 4) return 0;
        buf[0] = (char)(0xf0 + (c >> 18));
        buf[1] = (char)(0x80 + ((c >> 12) & 0x3f));
        buf[2] = (char)(0x80 + ((c >> 6) & 0x3f));
        buf[3] = (char)(0x80 + ((c) & 0x3f));
        return 4;
    }
    //else if (c < 0x10000)
    {
        if (buf_size < 3) return 0;
        buf[0] = (char)(0xe0 + (c >> 12));
        buf[1] = (char)(0x80 + ((c >> 6) & 0x3f));
        buf[2] = (char)(0x80 + ((c) & 0x3f));
        return 3;
    }
}

namespace ImGui_Draw_Force
{
    // 绘制文本
    void DrawTexts(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        ImGui::GetForegroundDrawList()->AddText(font, size, Pos, color, text);
    }
    void DrawTexts(float Pos_X, float Pos_Y, const char* text, ImU32 color, float size, ImFont* font)
    {
        ImGui::GetForegroundDrawList()->AddText(font, size, ImVec2(Pos_X, Pos_Y), color, text);
    }
    void DrawTextsOutlined(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImDrawList* draw_list = ImGui::GetForegroundDrawList();
        ImU32 outline_color = IM_COL32(0, 0, 0, 100); // 黑色描边
        float offset = 1.0f;

        // 八方向描边
        draw_list->AddText(font, size, ImVec2(Pos.x - offset, Pos.y), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x + offset, Pos.y), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x, Pos.y - offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x, Pos.y + offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x - offset, Pos.y - offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x + offset, Pos.y - offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x - offset, Pos.y + offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x + offset, Pos.y + offset), outline_color, text);

        // 中心文字
        draw_list->AddText(font, size, Pos, color, text);
    }
    void DrawTextsOutlined(float Pos_X, float Pos_Y, const char* text, ImU32 color, float size, ImFont* font)
    {
        DrawTextsOutlined(ImVec2(Pos_X, Pos_Y), text, color, size, font);
    }
    // 绘制居中文本
    void DrawCenterTextsOutlined(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImFont* used_font = font ? font : ImGui::GetFont();
        ImDrawList* draw_list = ImGui::GetForegroundDrawList();

        // 计算文本大小
        ImVec2 text_size = ImGui::CalcTextSize(text);
        ImVec2 pos = ImVec2(Pos.x - text_size.x * 0.5f, Pos.y - text_size.y * 0.5f);

        // 描边颜色
        ImU32 outline_color = IM_COL32(0, 0, 0, 210);
        const float offset = 1.0f;  // 建议 1.0 更清晰

        // 八方向描边（相对 pos 偏移）
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0) continue;
                draw_list->AddText(used_font, size, ImVec2(pos.x + dx * offset, pos.y + dy * offset), outline_color, text);
            }
        }

        // 正文字体
        draw_list->AddText(used_font, size, pos, color, text);
    }
    // 绘制居中文本（支持自定义字体、字号，带描边）
    void DrawCenterTextsOutlinedA(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImFont* used_font = font ? font : ImGui::GetFont();
        ImDrawList* draw_list = ImGui::GetForegroundDrawList();

        // 计算文本大小（指定字号）
        ImVec2 text_size = used_font->CalcTextSizeA(size, FLT_MAX, 0.0f, text, nullptr, nullptr);
        ImVec2 pos = ImVec2(Pos.x - text_size.x * 0.5f, Pos.y - text_size.y * 0.5f);

        // 描边颜色和厚度
        ImU32 outline_color = IM_COL32(0, 0, 0, 100);
        const float offset = 1.0f;

        // 八方向描边
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0) continue;
                draw_list->AddText(used_font, size, ImVec2(pos.x + dx * offset, pos.y + dy * offset), outline_color, text);
            }
        }

        // 主文本
        draw_list->AddText(used_font, size, pos, color, text);
    }
    // 支持中文的动态彩色文本绘制函数
    void DrawSuperEffectText(ImFont* font, float size, ImVec2 pos, const char* text, float time, float spacing)
    {
        if (!font || !text)
            return;

        ImDrawList* drawList = ImGui::GetForegroundDrawList();
        const char* s = text;

        float x = pos.x;
        float y = pos.y;
        float offset = 0.0f;

        while (*s)
        {
            unsigned int c = 0;
            int char_len = ImTextCharFromUtf8(&c, s, nullptr);
            if (char_len <= 0)
                break;

            char utf8_char[5] = { 0 };
            ImTextCharToUtf8(utf8_char, sizeof(utf8_char), c);

            float phase = time * 2.0f + offset * 0.3f;
            ImU32 color = GetRainbowColorFromRGB(phase);

            drawList->AddText(font, size, ImVec2(x, y), color, utf8_char);

            // 更新坐标和偏移
            float char_width = font->CalcTextSizeA(size, FLT_MAX, 0.0f, utf8_char).x;
            x += char_width + spacing;
            s += char_len;
            offset += 1.0f;
        }
    }

    // 支持中文 + 缩放 + 彩虹渐变颜色
    void DrawSuperEffectTextPlus(ImFont* font, float base_size, ImVec2 pos, const char* text, float time, float spacing)
    {
        if (!font || !text)
            return;

        ImDrawList* drawList = ImGui::GetForegroundDrawList();
        const char* s = text;
        float x = pos.x;
        float y = pos.y;
        float offset = 0.0f;

        while (*s)
        {
            // 解码 UTF-8 字符
            unsigned int c = 0;
            int char_len = ImTextCharFromUtf8(&c, s, nullptr);
            if (char_len <= 0)
                break;

            char utf8_char[5] = { 0 };
            ImTextCharToUtf8(utf8_char, sizeof(utf8_char), c);

            // 彩虹颜色流动
            float phase = time * 2.0f + offset * 0.3f;
            ImU32 color = GetRainbowColorFromRGB(phase);

            // 缩放动画
            float scale = 1.0f + 0.2f * sinf(time * 5.0f + offset);
            float size = base_size * scale;

            // 获取字符尺寸
            ImVec2 char_size = font->CalcTextSizeA(size, FLT_MAX, 0.0f, utf8_char);

            // 绘制字符
            drawList->AddText(font, size, ImVec2(x, y), color, utf8_char);

            // 移动到下一个字符位置
            x += char_size.x + spacing;
            s += char_len;
            offset += 1.0f;
        }
    }
}

namespace ImGui_Draw_Back
{
    // 绘制文本
    void DrawTexts(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        ImGui::GetBackgroundDrawList()->AddText(font, size, Pos, color, text);
    }
    void DrawTexts(float Pos_X, float Pos_Y, const char* text, ImU32 color, float size, ImFont* font)
    {
        ImGui::GetBackgroundDrawList()->AddText(font, size, ImVec2(Pos_X, Pos_Y), color, text);
    }
    void DrawTextsOutlined(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
        ImU32 outline_color = IM_COL32(0, 0, 0, 100); // 黑色描边
        float offset = 1.0f;

        // 八方向描边
        draw_list->AddText(font, size, ImVec2(Pos.x - offset, Pos.y), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x + offset, Pos.y), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x, Pos.y - offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x, Pos.y + offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x - offset, Pos.y - offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x + offset, Pos.y - offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x - offset, Pos.y + offset), outline_color, text);
        draw_list->AddText(font, size, ImVec2(Pos.x + offset, Pos.y + offset), outline_color, text);

        // 中心文字
        draw_list->AddText(font, size, Pos, color, text);
    }
    void DrawTextsOutlined(float Pos_X, float Pos_Y, const char* text, ImU32 color, float size, ImFont* font)
    {
        DrawTextsOutlined(ImVec2(Pos_X, Pos_Y), text, color, size, font);
    }
    // 绘制居中文本
    void DrawCenterTexts(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImFont* used_font = font ? font : ImGui::GetFont();
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();

        // 计算文本大小
        ImVec2 text_size = ImGui::CalcTextSize(text);
        ImVec2 pos = ImVec2(Pos.x - text_size.x * 0.5f, Pos.y - text_size.y * 0.5f);

        draw_list->AddText(used_font, size, pos, color, text);
    }
    void DrawCenterTextsOutlined(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImFont* used_font = font ? font : ImGui::GetFont();
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();

        // 计算文本大小
        ImVec2 text_size = ImGui::CalcTextSize(text);
        ImVec2 pos = ImVec2(Pos.x - text_size.x * 0.5f, Pos.y - text_size.y * 0.5f);

        // 描边颜色
        ImU32 outline_color = IM_COL32(0, 0, 0, 100);
        const float offset = 1.0f;  // 建议 1.0 更清晰

        // 八方向描边（相对 pos 偏移）
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0) continue;
                draw_list->AddText(used_font, size, ImVec2(pos.x + dx * offset, pos.y + dy * offset), outline_color, text);
            }
        }

        // 正文字体
        draw_list->AddText(used_font, size, pos, color, text);
    }
    // 绘制居中文本（支持自定义字体、字号，带描边）
    void DrawCenterTextsA(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImFont* used_font = font ? font : ImGui::GetFont();
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();

        // 计算文本大小（指定字号）
        ImVec2 text_size = used_font->CalcTextSizeA(size, FLT_MAX, 0.0f, text, nullptr, nullptr);
        ImVec2 pos = ImVec2(Pos.x - text_size.x * 0.5f, Pos.y - text_size.y * 0.5f);

        draw_list->AddText(used_font, size, pos, color, text);
    }
    void DrawCenterTextsOutlinedA(ImVec2 Pos, const char* text, ImU32 color, float size, ImFont* font)
    {
        if (!text) return;

        ImFont* used_font = font ? font : ImGui::GetFont();
        ImDrawList* draw_list = ImGui::GetBackgroundDrawList();

        // 计算文本大小（指定字号）
        ImVec2 text_size = used_font->CalcTextSizeA(size, FLT_MAX, 0.0f, text, nullptr, nullptr);
        ImVec2 pos = ImVec2(Pos.x - text_size.x * 0.5f, Pos.y - text_size.y * 0.5f);

        // 描边颜色和厚度
        ImU32 outline_color = IM_COL32(0, 0, 0, 100);
        const float offset = 1.0f;

        // 八方向描边
        for (int dx = -1; dx <= 1; ++dx)
        {
            for (int dy = -1; dy <= 1; ++dy)
            {
                if (dx == 0 && dy == 0) continue;
                draw_list->AddText(used_font, size, ImVec2(pos.x + dx * offset, pos.y + dy * offset), outline_color, text);
            }
        }

        // 主文本
        draw_list->AddText(used_font, size, pos, color, text);
    }
    // 绘制矩形
    void DrawRectangle(ImVec2 Pos, ImVec2 Size, ImU32 color, float thickness, float rounding, ImDrawCornerFlags flags)
    {
        ImGui::GetBackgroundDrawList()->AddRect(Pos, ImVec2(Pos.x + Size.x, Pos.y + Size.y), color, rounding, flags, thickness);
    }
    // 绘制填充矩形
    void DrawFilledRectangle(ImVec2 Pos, ImVec2 Size, ImU32 color, float rounding, ImDrawCornerFlags flags)
    {
        ImGui::GetBackgroundDrawList()->AddRectFilled(Pos, ImVec2(Pos.x + Size.x, Pos.y + Size.y), color, rounding, flags);
    }
    // 绘制线段
    void DrawLine(ImVec2 Pos_Start, ImVec2 Pos_End, ImU32 color, float thickness)
    {
        ImGui::GetBackgroundDrawList()->AddLine(Pos_Start, Pos_End, color, thickness);
    }
    void DrawLine(float Pos_Start_X, float Pos_Start_Y, float Pos_End_X, float Pos_End_Y, ImU32 color, float thickness)
    {
        ImGui::GetBackgroundDrawList()->AddLine(ImVec2(Pos_Start_X, Pos_Start_Y), ImVec2(Pos_End_X, Pos_End_Y), color, thickness);
    }
    // 绘制圆形
    void DrawCircle(ImVec2 Pos, float radius, ImU32 color, int num_segments, float thickness)
    {
        ImGui::GetBackgroundDrawList()->AddCircle(Pos, radius, color, num_segments, thickness);
    }
    // 绘制填充圆形
    void DrawFilledCircle(ImVec2 center, float radius, ImU32 color, int num_segments)
    {
        ImGui::GetBackgroundDrawList()->AddCircleFilled(center, radius, color, num_segments);
    }
    // 更自然的彩色渐变 + 发光模拟矩形
    void DrawGlowingRect(ImVec2 min, ImVec2 max, float time, float base_thickness, float rounding)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        // 计算矩形宽高
        float width = max.x - min.x;
        float height = max.y - min.y;

        // 根据尺寸动态计算发光半径（例如占较小边的10%，范围限定10~30）
        int glow_radius = (int)(0.10f * (width < height ? width : height)); // 外发光半径
        glow_radius = std::clamp(glow_radius, 10, 30); // 限制范围
        int inner_glow_radius = glow_radius / 3; // 内发光半径更短

        ImColor base_color = GetRainbowColorFromRGB(time);
        ImVec4 base = base_color;
        base.w = 1.0f; // 内层不透明

        // --- 外发光边框（高斯衰减）---
        for (int i = glow_radius; i >= 1; --i)
        {
            float t = (float)i / (float)glow_radius;
            float alpha = powf(expf(-t * t * 6.0f), 1.5f);  // 高斯衰减+指数衰减
            float thickness = 1.0f;

            ImVec4 glow_col = base;
            glow_col.w = alpha * 0.35f;

            draw->AddRect(
                ImVec2(min.x - i, min.y - i),
                ImVec2(max.x + i, max.y + i),
                ImColor(glow_col),
                rounding + i * 0.5f,
                ImDrawCornerFlags_All,
                thickness
            );
        }

        // --- 内发光边框（更透明更快衰减）---
        for (int i = 1; i <= inner_glow_radius; ++i)
        {
            float t = (float)i / inner_glow_radius;      // 0~1
            float alpha = (1.0f - t * t) * 0.4f;         // 内发光透明度二次衰减，更快消失
            float thickness = base_thickness * (1.0f - t) * 0.6f; // 变细

            ImVec4 inner_glow_col = base;
            inner_glow_col.w = alpha;

            draw->AddRect(
                ImVec2(min.x + i, min.y + i),
                ImVec2(max.x - i, max.y - i),
                ImColor(inner_glow_col),
                rounding - i > 0 ? rounding - i : 0.0f,
                ImDrawCornerFlags_All,
                thickness
            );
        }

        // 主体轮廓
        draw->AddRect(min, max, base_color, rounding, ImDrawCornerFlags_All, base_thickness);
    }

    // 绘制动态矩形
    void DrawRunningRect(ImVec2 min, ImVec2 size, float time, bool is_bot, float thickness, float rounding)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        // 计算右下角坐标 max
        ImVec2 max = ImVec2(min.x + size.x, min.y + size.y);

        // 计算边框四边长度
        float width = size.x;
        float height = size.y;
        float perimeter = 2.0f * (width + height);

        // 采样点数，越大越平滑，但开销越大
        const int segments = 100;

        // 边框上采样点数组
        ImVec2 points[segments];

        // 生成四边均匀分布的点（顺时针）
        for (int i = 0; i < segments; i++)
        {
            float pos = (float)i / segments * perimeter; // 在周长上的位置
            if (pos < width) // 上边
                points[i] = ImVec2(min.x + pos, min.y);
            else if (pos < width + height) // 右边
                points[i] = ImVec2(max.x, min.y + (pos - width));
            else if (pos < 2 * width + height) // 下边
                points[i] = ImVec2(max.x - (pos - (width + height)), max.y);
            else // 左边
                points[i] = ImVec2(min.x, max.y - (pos - (2 * width + height)));
        }

        // 绘制多段渐变线
        for (int i = 0; i < segments - 1; i++)
        {
            // 计算颜色参数，跑马灯效果：颜色随时间和位置偏移变化
            float t0 = fmodf(time + (float)i / segments, 1.0f);
            float t1 = fmodf(time + (float)(i + 1) / segments, 1.0f);

            ImColor col0 = is_bot ? GetWhiteGreenColor_Transparent(t0) : GetCoolColor(t0);
            ImColor col1 = is_bot ? GetWhiteGreenColor_Transparent(t1) : GetCoolColor(t1);

            // 简化的线性插值颜色中间值
            ImVec4 col_mid = ImVec4(
                (col0.Value.x + col1.Value.x) * 0.5f,
                (col0.Value.y + col1.Value.y) * 0.5f,
                (col0.Value.z + col1.Value.z) * 0.5f,
                (col0.Value.w + col1.Value.w) * 0.5f
            );

            draw->AddLine(points[i], points[i + 1], ImColor(col_mid), thickness);
        }

        // 闭合边框最后一段线
        float t_last = fmodf(time + (segments - 1) / (float)segments, 1.0f);
        float t_first = fmodf(time, 1.0f);
        ImColor col_last = is_bot ? GetWhiteGreenColor_Transparent(t_last) : GetCoolColor(t_last);
        ImColor col_first = is_bot ? GetWhiteGreenColor_Transparent(t_first) : GetCoolColor(t_first);
        ImVec4 col_close = ImVec4(
            (col_last.Value.x + col_first.Value.x) * 0.5f,
            (col_last.Value.y + col_first.Value.y) * 0.5f,
            (col_last.Value.z + col_first.Value.z) * 0.5f,
            (col_last.Value.w + col_first.Value.w) * 0.5f
        );
        draw->AddLine(points[segments - 1], points[0], ImColor(col_close), thickness);
    }

    // 绘制动态线条
    void DrawRunningLine(ImVec2 start, ImVec2 end, float time, bool is_bot, float thickness, int segments, float Alpha)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        // 计算线条长度和方向
        ImVec2 direction = ImVec2(end.x - start.x, end.y - start.y);
        float length = sqrtf(direction.x * direction.x + direction.y * direction.y);

        // 归一化方向向量
        ImVec2 unit_direction = ImVec2(direction.x / length, direction.y / length);

        // 线条上采样点数组
        std::vector<ImVec2> points(segments + 1);

        // 生成线条上的均匀分布点
        for (int i = 0; i <= segments; i++)
        {
            float t = (float)i / segments;
            points[i] = ImVec2(
                start.x + direction.x * t,
                start.y + direction.y * t
            );
        }

        // 绘制多段渐变线
        for (int i = 0; i < segments; i++)
        {
            // 计算颜色参数，跑马灯效果：颜色随时间和位置偏移变化
            float t0 = fmodf(time * 0.5f + (float)i / (segments * 8), 1.0f);
            float t1 = fmodf(time * 0.5f + (float)(i + 1) / (segments * 8), 1.0f);

            ImColor col0 = is_bot ? GetWhiteGreenColor_Transparent(t0) : GetCoolColor(t0);
            ImColor col1 = is_bot ? GetWhiteGreenColor_Transparent(t1) : GetCoolColor(t1);

            // 颜色插值
            ImVec4 col_mid = ImVec4(
                (col0.Value.x + col1.Value.x) * 0.5f,
                (col0.Value.y + col1.Value.y) * 0.5f,
                (col0.Value.z + col1.Value.z) * 0.5f,
                (col0.Value.w + col1.Value.w) * 0.5f * Alpha
            );

            draw->AddLine(points[i], points[i + 1], ImColor(col_mid), thickness);
        }
    }

    // 绘制带箭头的动态线条（用于指示方向）
    void DrawRunningArrow(ImVec2 start, ImVec2 end, float time, bool is_bot, float thickness, float arrow_size, int segments)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        // 先绘制主线
        DrawRunningLine(start, end, time, is_bot, thickness, segments, 1.0f);

        // 计算箭头方向
        ImVec2 direction = ImVec2(end.x - start.x, end.y - start.y);
        float length = sqrtf(direction.x * direction.x + direction.y * direction.y);
        ImVec2 unit_direction = ImVec2(direction.x / length, direction.y / length);

        // 计算垂直方向（用于箭头两翼）
        ImVec2 perpendicular = ImVec2(-unit_direction.y, unit_direction.x);

        // 计算箭头点
        ImVec2 arrow_tip = end;
        ImVec2 arrow_left = ImVec2(
            end.x - unit_direction.x * arrow_size + perpendicular.x * arrow_size * 0.5f,
            end.y - unit_direction.y * arrow_size + perpendicular.y * arrow_size * 0.5f
        );
        ImVec2 arrow_right = ImVec2(
            end.x - unit_direction.x * arrow_size - perpendicular.x * arrow_size * 0.5f,
            end.y - unit_direction.y * arrow_size - perpendicular.y * arrow_size * 0.5f
        );

        // 绘制箭头（使用当前时间的颜色）
        float t_arrow = fmodf(time, 1.0f);
        ImColor arrow_color = is_bot ? GetWhiteGreenColor_Transparent(t_arrow) : GetCoolColor(t_arrow);

        draw->AddLine(arrow_tip, arrow_left, arrow_color, thickness);
        draw->AddLine(arrow_tip, arrow_right, arrow_color, thickness);
    }

    // 绘制虚线样式的动态线条
    void DrawRunningDashedLine(ImVec2 start, ImVec2 end, float time, bool is_bot, float thickness, float dash_length, int segments)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        ImVec2 direction = ImVec2(end.x - start.x, end.y - start.y);
        float total_length = sqrtf(direction.x * direction.x + direction.y * direction.y);
        ImVec2 unit_direction = ImVec2(direction.x / total_length, direction.y / total_length);

        int dash_count = (int)(total_length / (dash_length * 2));

        for (int i = 0; i < dash_count; i++)
        {
            float segment_start = i * dash_length * 2;
            float segment_end = segment_start + dash_length;

            if (segment_end > total_length)
                segment_end = total_length;

            ImVec2 dash_start = ImVec2(
                start.x + unit_direction.x * segment_start,
                start.y + unit_direction.y * segment_start
            );
            ImVec2 dash_end = ImVec2(
                start.x + unit_direction.x * segment_end,
                start.y + unit_direction.y * segment_end
            );

            // 为每个虚线段计算独立的颜色动画
            float t_dash = fmodf(time + (float)i / dash_count, 1.0f);
            ImColor dash_color = is_bot ? GetWhiteGreenColor_Transparent(t_dash) : GetCoolColor(t_dash);

            draw->AddLine(dash_start, dash_end, dash_color, thickness);
        }
    }

    // 绘制动态圆环
    void DrawRunningCircle(ImVec2 center, float radius, float time, bool is_bot, float thickness, int segments, float Alpha)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList();

        // 计算圆周长
        float circumference = 2.0f * IM_PI * radius;

        // 圆环上采样点数组
        std::vector<ImVec2> points(segments);

        // 生成圆环上均匀分布的点（顺时针）
        for (int i = 0; i < segments; i++)
        {
            float angle = (float)i / segments * 2.0f * IM_PI;
            points[i] = ImVec2(
                center.x + cosf(angle) * radius,
                center.y + sinf(angle) * radius
            );
        }

        // 绘制多段渐变线 - 保持与矩形相同的逻辑
        for (int i = 0; i < segments - 1; i++)
        {
            // 计算颜色参数，跑马灯效果：颜色随时间和位置偏移变化
            float t0 = fmodf(time + (float)i / segments, 1.0f);
            float t1 = fmodf(time + (float)(i + 1) / segments, 1.0f);

            ImColor col0 = is_bot ? GetWhiteGreenColor_Transparent(t0) : GetCoolColor(t0);
            ImColor col1 = is_bot ? GetWhiteGreenColor_Transparent(t1) : GetCoolColor(t1);

            // 简化的线性插值颜色中间值 - 与矩形相同
            ImVec4 col_mid = ImVec4(
                (col0.Value.x + col1.Value.x) * 0.5f,
                (col0.Value.y + col1.Value.y) * 0.5f,
                (col0.Value.z + col1.Value.z) * 0.5f,
                (col0.Value.w + col1.Value.w) * 0.5f * Alpha
            );

            draw->AddLine(points[i], points[i + 1], ImColor(col_mid), thickness);
        }

        // 闭合圆环最后一段线 - 保持与矩形相同的逻辑
        float t_last = fmodf(time + (segments - 1) / (float)segments, 1.0f);
        float t_first = fmodf(time, 1.0f);
        ImColor col_last = is_bot ? GetWhiteGreenColor_Transparent(t_last) : GetCoolColor(t_last);
        ImColor col_first = is_bot ? GetWhiteGreenColor_Transparent(t_first) : GetCoolColor(t_first);
        ImVec4 col_close = ImVec4(
            (col_last.Value.x + col_first.Value.x) * 0.5f,
            (col_last.Value.y + col_first.Value.y) * 0.5f,
            (col_last.Value.z + col_first.Value.z) * 0.5f,
            (col_last.Value.w + col_first.Value.w) * 0.5f * Alpha
        );
        draw->AddLine(points[segments - 1], points[0], ImColor(col_close), thickness);
    }

    void DrawHpBar(ImVec2 pos, ImVec2 size, float currentHp, float maxHp, ImU32 HpColor)
    {
        ImDrawList* draw = ImGui::GetBackgroundDrawList(); // 绘制列表
        float hpRatio = ImClamp(currentHp / maxHp, 0.f, 1.f); // 生命值比例
        float hpWidth = size.x * hpRatio; // 生命值宽度

        float rounding = 8.0f; // 圆角半径

        // 背景底色
        draw->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y), Black30, rounding);

        if (hpWidth > 0) // 绘制生命值
        {
            ImVec2 hpEnd = ImVec2(pos.x + hpWidth, pos.y + size.y); // 生命值终点

            // 底色深红色圆角矩形
            draw->AddRectFilled(pos, hpEnd, HpColor, rounding);
        }

        // 玻璃边框
        draw->AddRect(pos, ImVec2(pos.x + size.x, pos.y + size.y), IM_COL32(50, 50, 50, 150), rounding, 0, 2.0f);
    }

}