#pragma once

#include "includes.h"
#include "main.h"
#include "UI.h"
#include "ImGui_GuiHelp.h"
using namespace ImGui_Draw_Back;

extern UINT g_width;
extern UINT g_height;

class Function
{
public:
	static void Init();
	static void Tick();
	static void Release();
};