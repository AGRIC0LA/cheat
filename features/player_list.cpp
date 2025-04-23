#include "player_list.h"

c_PlayerList* player_list_;
void c_PlayerList::update() {
	if (!this->is_enabled) return;
	for (int i = 0; i < player_list.size(); i++) {
		c_Player& player = player_list[i];
		draw::text(ImVec2(15, 35 + 14 * i), player.get_role_color(), player.get_name());
		draw::text(ImVec2(15 + ImGui::CalcTextSize(player.get_name().c_str()).x, 35 + 14 * i), player.get_role_color(), player.get_role_name());
	}
}
