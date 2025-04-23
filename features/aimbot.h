#pragma once
#include "cFeature.h"

class c_Aimbot : public c_Feature {
public:
	struct target : public c_Player {
		Quaternion rotation_to_target;

		void clear() {
			this->rotation_to_target = Quaternion(0, 0, 0);
			this->position = Vector3(0, 0, 0);
			this->hub = 0;
		}
	};

	bool has_target;
	float fov;
	bool friendly_fire;
	bool shot_out_screen;
	target aimbot_target;
	
	using original_function_t = void(*)(uintptr_t, uintptr_t);
	static original_function_t original_function;

	static void detour(uintptr_t rcx, uintptr_t rdx);
	void update() override;
	void set_hooks() override;
};

extern c_Aimbot* aimbot;