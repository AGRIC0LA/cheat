#include "anti_tesla.h"

c_AntiTesla* anti_tesla;
c_AntiTesla::original_function_t c_AntiTesla::original_function;

bool c_AntiTesla::detour(uintptr_t rcx) {
	if (anti_tesla->is_enabled)
		return false;
	return c_AntiTesla::original_function(rcx);
}

void c_AntiTesla::set_hooks() {
	create_hook(TeslaGate::PlayerInHurtRange_va(), c_AntiTesla::detour, reinterpret_cast<void**>(&c_AntiTesla::original_function));
}
