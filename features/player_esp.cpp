#include "player_esp.h"

c_PlayerEsp* player_esp;

void c_PlayerEsp::update() {
	if (!this->is_enabled) return;
	for (auto& player : player_list) {
		if (player.hub == local->hub) continue;
		Vector3 on_screen;
		if (screen::w2s(player.position, &on_screen, local->camera)) {
			ImVec2 to_draw = ImVec2(on_screen.x, screen::height - on_screen.y);

			if (player.hub == aimbot->aimbot_target.hub) {
				Vector3 target_on_screen;
				if (screen::w2s(aimbot->aimbot_target.position, &target_on_screen, local->camera))
					draw::draw_list->AddCircleFilled(ImVec2(target_on_screen.x, screen::height - target_on_screen.y), ImColor(199.f, 16.f, 43.f), 3.f, 300);
			}
			draw::centered_text(to_draw, ImColor(255, 255, 255), std::format("{}m", (int)local->distance(player.position)));		
			to_draw.y -= 15;
			draw::centered_text(to_draw, player.get_role_color(), player.get_role_name());
			to_draw.y -= 15;
			draw::centered_text(to_draw, ImColor(255, 255, 255), player.get_name());
			if (aimbot->aimbot_target.hub == player.hub) {
				to_draw.y -= 15;
				draw::centered_text(to_draw, ImColor(41, 191, 21), "TARGET");
			}
		}
	} 
}
