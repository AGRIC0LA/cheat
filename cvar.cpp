#include "cvar.h"

void cvar::initialize() {
	player_iterate = new c_PlayerIterate;
	player_esp = new c_PlayerEsp;
	aimbot = new c_Aimbot;
	anti_tesla = new c_AntiTesla;
	room_esp = new c_RoomEsp;
	item_esp = new c_ItemEsp;
	player_list_ = new c_PlayerList;
	movement = new c_Movement;
}

void cvar::draw_esp() {
	ImGui::Begin("overlay", nullptr, 
				 ImGuiWindowFlags_NoTitleBar | 
				 ImGuiWindowFlags_NoInputs | 
				 ImGuiWindowFlags_NoBackground | 
				 ImGuiWindowFlags_NoMove | 
				 ImGuiWindowFlags_NoScrollbar | 
				 ImGuiWindowFlags_NoCollapse);
	screen::update();
	ImGui::SetWindowSize(ImVec2(screen::width, screen::height));
	draw::update(ImGui::GetWindowDrawList());
	c_Bind::update();
	for (auto feature : c_Feature::feature_list)
		feature->update();
	player_list.clear();
	
	ImGui::End();
}
