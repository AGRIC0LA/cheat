#include "cFeature.h"

std::vector<c_Feature*> c_Feature::feature_list;

c_Feature::c_Feature() {
	feature_list.push_back(this);
}

void c_Feature::update() {}

void c_Feature::set_hooks() {}

bool create_hook(uintptr_t address, void* detour, void** original) {
	if (MH_CreateHook(reinterpret_cast<void*>(address), detour, original) == MH_OK) {
		if (MH_EnableHook(reinterpret_cast<void*>(address)) == MH_OK)
			return true;
	}
	return false;
}