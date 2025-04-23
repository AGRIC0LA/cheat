#pragma once
#include "sdk/init.h"
#include "sdk/screen.h"
#include "sdk/draw.h"
#include "features/include_features.h"

namespace cvar {
	extern c_Bind* menu_bind;

	void initialize();
	void draw_esp();
}

using namespace cvar;