#include "movement.h"

c_Movement* movement;
update_t c_Movement::original_function;

c_Movement::c_Movement() : c_Feature() {
	this->bind();
}

void c_Movement::detour(uintptr_t rcx) {
	c_Movement::original_function(rcx);


}

void c_Movement::set_hooks() {
	create_hook(PlayerRoles_FirstPersonControl::FirstPersonMovementModule::UpdateMovement_va(), detour, reinterpret_cast<void**>(&c_Movement::original_function));
}
