#include "aimbot.h"

c_Aimbot* aimbot;
c_Aimbot::original_function_t c_Aimbot::original_function;

void c_Aimbot::update() {
	if (!this->is_enabled) return;
	float closest = FLT_MAX;
	draw::circle(ImVec2(screen::width / 2, screen::height / 2), ImColor(255, 255, 255), this->fov);
	this->aimbot_target.clear();
	this->has_target = false;
	for (auto& player : player_list) {
		if (player.hub == local->hub) continue;
		//if (memory::call_method<bool>(module_base + 0x28D8CD0, local->position, player.position, 134479873)) continue;
		if (!this->friendly_fire && local->is_friend(&player)) continue;
		Vector3 position = player.position;
		Vector3 on_screen;
		if (!screen::w2s(position, &on_screen, local->camera) && !this->shot_out_screen) continue;
		float distance_to_player = screen_distance(Vector2(screen::width / 2, screen::height / 2), on_screen);
		if (distance_to_player > this->fov) continue;
		if (distance_to_player < closest) {
			closest = distance_to_player;
			Vector3 direction = position - local->position;
			this->aimbot_target.position = position;
			this->aimbot_target.hub = player.hub;
			this->aimbot_target.rotation_to_target = Quaternion::QuaternionLookRotation(direction, Vector3(0, 1, 0));
			this->has_target = true;
		}
	}
}

void c_Aimbot::detour(uintptr_t rcx, uintptr_t rdx) {
	c_Aimbot::original_function(rcx, rdx);
	if (aimbot->is_enabled) {
		if (aimbot->has_target) {
			uintptr_t quaternion_address = (rcx + 0x8) + 0x8;
			*reinterpret_cast<float*>(quaternion_address) = aimbot->aimbot_target.rotation_to_target.x;
			*reinterpret_cast<float*>(quaternion_address + 0x4) = aimbot->aimbot_target.rotation_to_target.y;
			*reinterpret_cast<float*>(quaternion_address + 0x8) = aimbot->aimbot_target.rotation_to_target.z;
			*reinterpret_cast<float*>(quaternion_address + 0xC) = aimbot->aimbot_target.rotation_to_target.w;
		}
	}
}
void c_Aimbot::set_hooks() {
	create_hook(offsets::shot_request_ctor, c_Aimbot::detour, reinterpret_cast<void**>(&c_Aimbot::original_function));
}
