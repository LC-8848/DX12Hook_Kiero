#pragma once

#include "includes.h"
#include "Function.h"

extern uint64_t is_crash_count; // ±ÀÀ£¼ÆÊýÆ÷

class UI
{
public:
	static void Init();
	static void Tick();
	static void Release();
};