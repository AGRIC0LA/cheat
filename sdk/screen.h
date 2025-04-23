#pragma once
#include "include_sdk.h"
#include "wrapper.h"

namespace screen {
	extern int height, width;
	void update();
	bool w2s(Vector3& position, Vector3* on_screen, c_Camera* camera);
}