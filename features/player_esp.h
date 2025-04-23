#pragma once
#include "cFeature.h"
#include "aimbot.h"
#include "../sdk/player.h"
#include <format>

class c_PlayerEsp : public c_Feature {
	void update() override;
};

extern c_PlayerEsp* player_esp;