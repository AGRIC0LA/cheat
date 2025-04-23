#include "includes.h"
#include "kiero/kiero.h"
#include "il2cpp/include_il2cpp.h"
#include "offsets.h"
#include "sdk/init.h"
using namespace il2cpp_sdk_gen;
#include "cvar.h"
#include "menu.h"
#include "hooks.h"
#include "dx_hook.hpp"
//#define zajedna_dbg 1

void create_console() {
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	SetConsoleTitleA("ZAJEDNA");
}

void initialize_cheat() {
	kiero::init(kiero::RenderType::D3D11);
#ifdef zajedna_dbg
	create_console();
#endif // zajedna_dbg
	il2cpp_api::initialize();
	il2cpp_sdk_gen::init();
	offsets::initialize();
	cvar::initialize();
	menu::menu_init();
	hooks::initialize();
	kiero::bind(8, reinterpret_cast<void**>(&dx_hook::present_o), dx_hook::present_hk);
	kiero::bind(13, reinterpret_cast<void**>(&dx_hook::resize_buffer_o), dx_hook::resize_buffer_hk);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		std::thread potok(initialize_cheat);
		potok.detach();
	}
	return false;
}