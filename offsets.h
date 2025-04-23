#pragma once
#include "mem.h"

namespace offsets {
	extern LDR_DATA_TABLE_ENTRY* dll;
	extern uintptr_t shot_request_ctor;

	void initialize();
}