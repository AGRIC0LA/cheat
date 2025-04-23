#pragma once
#include "cFeature.h"

class c_Movement : public c_Feature {
public:
	bool noclip;
	c_Bind noclip_bind;
	bool bunny_hop;
	c_Bind bunny_hop_bind;
	bool big_step;
	c_Bind big_step_bind;
	float jmp_multiplier;

	c_Movement();
	static void detour(uintptr_t rcx);
	static update_t original_function;
	void set_hooks() override;
};

extern c_Movement* movement;