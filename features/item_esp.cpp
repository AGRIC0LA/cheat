#include "item_esp.h"

c_ItemEsp* item_esp;
std::vector<c_ItemEsp::item> c_ItemEsp::item_list;
update_t c_ItemEsp::original_function;

void c_ItemEsp::update() {
	if (this->is_enabled) {
		for (auto& item : c_ItemEsp::item_list) {
			float distance = local->distance(item.position);
			if (distance > this->distance) continue;
			Vector3 on_screen;
			if (screen::w2s(item.position, &on_screen, local->camera)) {
				on_screen.y = screen::height - on_screen.y;
				draw::centered_text(on_screen, ImColor(34, 186, 186), std::format("{}-{:.0f}m", item.get_name(), distance));
			}
		}
	}
	c_ItemEsp::item_list.clear();
}

void c_ItemEsp::detour(uintptr_t rcx) {
	c_ItemEsp::original_function(rcx);

	uintptr_t pickup_base = InventorySystem_Items_Pickups::PickupStandardPhysics::get_Pickup(rcx);
	if (!pickup_base) return;
	uintptr_t item_info = pickup_base + 0x78;
	if (!item_info) return;
	item* item_ = new item;

	item_->type = *reinterpret_cast<ItemType*>(item_info);
	item_->position = reinterpret_cast<c_Component*>(pickup_base)->get_position();
	c_ItemEsp::item_list.push_back(*item_);

	delete item_;
}

void c_ItemEsp::set_hooks() {
	create_hook(InventorySystem_Items_Pickups::PickupStandardPhysics::UpdateClient_va(), c_ItemEsp::detour, reinterpret_cast<void**>(&c_ItemEsp::original_function));
}