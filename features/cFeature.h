#pragma once
#include <format>
#include "../offsets.h"
#include "../includes.h"
#include "../kiero/minhook/include/MinHook.h"
#include "../sdk/player.h"
#include "../sdk/wrapper.h"
#include "../sdk/screen.h"
#include "../sdk/draw.h"
#include "../sdk/cBind.h"

class c_Feature {
public:
	static std::vector<c_Feature*> feature_list;
	c_Bind* bind;
	bool is_enabled;
	c_Feature();
	virtual void update();
	virtual void set_hooks();
};

bool create_hook(uintptr_t address, void* detour, void** original);