#pragma once
#include "cFeature.h"

class c_PlayerList : public c_Feature {
	void update() override;
};

extern c_PlayerList* player_list_;