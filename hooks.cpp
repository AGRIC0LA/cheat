#include "hooks.h"

void hooks::initialize() {
	for (auto& feature : c_Feature::feature_list)
		feature->set_hooks();
}
