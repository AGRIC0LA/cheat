#pragma once
#include "cFeature.h"

class c_AntiTesla : public c_Feature {
public:
	using original_function_t = bool(*)(uintptr_t);
	static original_function_t original_function;
	static bool detour(uintptr_t);
	void set_hooks() override;
};

extern c_AntiTesla* anti_tesla;