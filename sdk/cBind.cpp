#include "cBind.h"

std::vector<c_Bind*> c_Bind::bind_list;

c_Bind::c_Bind(KeyCode key_code = Escappe, BindMode bind_mode = Toggle, bool* value_ = nullptr) {
	if (!value_) return;
	key = key_code;
	mode = bind_mode;
	value = value_;
	bind_list.push_back(this);
}

void c_Bind::change_bind(KeyCode key_code, BindMode bind_mode) {
	key = key_code;
	mode = bind_mode;
}

void c_Bind::update() {
	for (auto bind : bind_list) {
		if (UnityEngine::Input::GetKey(bind->key)) {
			if (!bind->key_pressed) {
				*bind->value = !*bind->value;
				bind->key_pressed = true;
			}
		}
		else
			bind->key_pressed = false;
	}
}
