#include "room_esp.h"

c_RoomEsp* room_esp;
update_t c_RoomEsp::original_function;
std::vector<c_RoomEsp::room> c_RoomEsp::room_list;

void c_RoomEsp::update() {
	if (this->is_enabled) {
		for (auto& room : room_list) {
			if (!room.get_is_valid()) continue;
			Vector3 on_screen;
			if (screen::w2s(room.position, &on_screen, local->camera)) {
				on_screen.y = screen::height - on_screen.y;
				draw::centered_text(on_screen, ImColor(168, 50, 119), room.get_name());
				on_screen.y += 15;
				draw::centered_text(on_screen, ImColor(255, 255, 255), std::format("{}m", (int)local->distance(room.position)));
			}
		}
	}
	room_list.clear();
}

void c_RoomEsp::detour(uintptr_t rcx) {
	c_RoomEsp::original_function(rcx);

	uintptr_t room_identifier = RoomLightController::get_Room(rcx);
	if (!room_identifier) return;
	room* room_ = new room;

	Vector3 pos = reinterpret_cast<c_Component*>(room_identifier)->get_position();
	room_->position = pos;
	room_->name = (RoomName)MapGeneration::RoomIdentifier::Name_get(room_identifier);
	c_RoomEsp::room_list.push_back(*room_);

	delete room_;
}

void c_RoomEsp::set_hooks() {
	create_hook(RoomLightController::Update_va(), c_RoomEsp::detour, reinterpret_cast<void**>(&c_RoomEsp::original_function));
}
