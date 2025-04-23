#pragma once
#include "include_sdk.h"
#include "wrapper.h"

class c_Player {
public:
	Vector3 position;
	c_ReferenceHub* hub;

	std::string get_name();
	std::string get_role_name();
	Color get_role_color();
	float distance(Vector3& position);
	Vector3 get_hitbox_position(HitboxType hitbox_to_find);
};

class Local : public c_Player {
public:
	c_Camera* camera;

	bool is_friend(c_Player* player);
	Local operator=(c_Player* player){
		Local tmp;
		tmp.hub = player->hub;
		return tmp;
	}
};

extern Local* local;
extern std::vector<c_Player> player_list;