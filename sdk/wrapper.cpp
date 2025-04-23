#include "wrapper.h"

Vector3 c_Transform::get_position() {
	return UnityEngine::Transform::get_position(reinterpret_cast<uintptr_t>(this));
}

void c_Transform::set_position(Vector3& position) {
	return UnityEngine::Transform::set_position(reinterpret_cast<uintptr_t>(this), position);
}

Quaternion c_Transform::get_rotation() {
	return UnityEngine::Transform::get_rotation(reinterpret_cast<uintptr_t>(this));
}

c_Transform* c_GameObject::get_transform() {
	return reinterpret_cast<c_Transform*>(UnityEngine::GameObject::get_transform(reinterpret_cast<uintptr_t>(this)));
}

Vector3 c_GameObject::get_position() {
	return this->get_transform()->get_position();
}

Quaternion c_GameObject::get_rotation() {
	return this->get_transform()->get_rotation();
}

void c_GameObject::set_position(Vector3& position) {
}

void c_GameObject::set_rotation(Quaternion& set_rotation) {
}

std::string c_ReferenceHub::get_name() {
	uintptr_t nickname_sync = ReferenceHub::nicknameSync_get(reinterpret_cast<uintptr_t>(this));
	if (!nickname_sync) return "";
	return reinterpret_cast<il2cpp_string*>(NicknameSync::get_MyNick(nickname_sync))->to_string();
}

Color c_ReferenceHub::get_role_color() {
	uintptr_t role_manager = ReferenceHub::roleManager_get(reinterpret_cast<uintptr_t>(this));
	if (!role_manager) return Color();
	uintptr_t role_base = PlayerRoles::PlayerRoleManager::_curRole_get(role_manager);
	if (!role_base) return Color();
	uintptr_t method_address = resolve_virtual_method(reinterpret_cast<Il2CppObject*>(role_base), "get_RoleColor", 0);
	if (!method_address) return Color();
	return memory::call_method<Color>(method_address, role_base);
}

std::string c_ReferenceHub::get_role_name() {
	uintptr_t role_manager = ReferenceHub::roleManager_get(reinterpret_cast<uintptr_t>(this));
	if (!role_manager) return "";
	uintptr_t role_base = PlayerRoles::PlayerRoleManager::_curRole_get(role_manager);
	if (!role_base) return "";
	return reinterpret_cast<il2cpp_string*>(PlayerRoles::PlayerRoleBase::get_RoleName(role_base))->to_string();
}

c_ReferenceHub* c_ReferenceHub::get_local() {
	return reinterpret_cast<c_ReferenceHub*>(ReferenceHub::get_LocalHub());
}

Vector3 c_ReferenceHub::get_hitbox_position(HitboxType hitbox_to_find) {
	//uintptr_t model = PlayerRoles::PlayerRolesUtils::GetModel(reinterpret_cast<uintptr_t>(this));
	//if (!model) return 0;
	//std::cout << "model: " << model << std::endl;
	//il2cpp_array<uintptr_t>* hitbox_array = reinterpret_cast<il2cpp_array<uintptr_t>*>(model + 0x90);
	//if (!hitbox_array) return 0;
	//std::cout << "hitbox_array: " << hitbox_array << std::endl;
	return 0;
	//return 0;
	/*for (int i = 0; i < hitbox_array->get_size(); i++) {
		std::cout << "i: " << i << std::endl;
		uintptr_t* hitbox = hitbox_array->get_value(i);
		if (!hitbox) continue;
		std::cout << "hitbox: " << hitbox << std::endl;
		if (HitboxIdentity::get_HitboxType((uintptr_t)hitbox) == hitbox_to_find)
			return HitboxIdentity::get_CenterOfMass((uintptr_t)hitbox);
	} */
}

Vector3 c_Camera::w2s(Vector3& position) {
	return UnityEngine::Camera::WorldToScreenPoint(reinterpret_cast<uintptr_t>(this), position, 2);
}

c_Camera* c_Camera::get_main() {
	return reinterpret_cast<c_Camera*>(UnityEngine::Camera::get_main());
}

c_Transform* c_Component::get_transform() {
	return reinterpret_cast<c_Transform*>(UnityEngine::Component::get_transform(reinterpret_cast<uintptr_t>(this)));
}

Vector3 c_Component::get_position() {
	return this->get_transform()->get_position();
}

void c_Component::set_position(Vector3& pos) {
	return this->get_transform()->set_position(pos);
}
