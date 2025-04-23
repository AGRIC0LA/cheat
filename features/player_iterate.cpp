#include "player_iterate.h"

c_PlayerIterate* player_iterate;

void c_PlayerIterate::update() {
	c_ReferenceHub* local_hub = c_ReferenceHub::get_local();
	if (!local_hub) return;
	local->camera = c_Camera::get_main();
	local->position = local->camera->get_position();
	local->hub = local_hub;
	il2cpp_dictionary<c_GameObject*, c_ReferenceHub*>* dict =
	reinterpret_cast<il2cpp_dictionary<c_GameObject*, c_ReferenceHub*>*>(ReferenceHub::HubsByGameObjects());
	if (!dict) return;
	size_t size = dict->get_size();
	for (int i = 0; i < size; i++) {
		auto entry = dict->get_entry(i);
		if (!entry) continue;

		c_GameObject* game_object = entry->key;
		if (!game_object) continue;

		c_ReferenceHub* hub = entry->value;
		if (!hub) continue;

		c_Player* player = new c_Player;
		player->hub = hub;
		player->position = game_object->get_position();
		
		player_list.push_back(*player);
		delete player;
	}
}
