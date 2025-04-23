#pragma once
#include <cstdint>
#include "kiero/minhook/include/MinHook.h"
#include "features/cFeature.h"

namespace hooks {
	bool create_hook(uintptr_t address, uintptr_t detour, void* original);
	void initialize();
}