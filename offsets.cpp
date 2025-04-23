#include "offsets.h"

LDR_DATA_TABLE_ENTRY* offsets::dll;
uintptr_t offsets::shot_request_ctor;

void offsets::initialize() {
	offsets::dll = windows_functions::GetLDREntryInternal(L"GameAssembly.dll");
	offsets::shot_request_ctor = memory::PatternScan("48 89 5C 24 ? 57 48 83 EC ? 80 3D ? ? ? ? ? 48 8B DA 48 8B F9 75 ? 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 48 85 DB 0F 84 ? ? ? ? 48 8B 4B ? 48 85 C9 0F 84 ? ? ? ? E8", offsets::dll);
}
