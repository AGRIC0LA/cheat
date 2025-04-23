#pragma once
#include "cFeature.h"

class c_PlayerIterate : c_Feature {
public:
	c_PlayerIterate() : c_Feature() {}
	void update() override;
};

extern c_PlayerIterate* player_iterate;