#include "player.h"

std::vector<c_Player> player_list;
Local* local = new Local;

std::string c_Player::get_name() {
    return this->hub->get_name();
}

std::string c_Player::get_role_name() {
    return this->hub->get_role_name();
}

Color c_Player::get_role_color() {
    return this->hub->get_role_color();
}

float c_Player::distance(Vector3& position) {
    return this->position.Distance(position);
}

Vector3 c_Player::get_hitbox_position(HitboxType hitbox_to_find) {
    return this->hub->get_hitbox_position(hitbox_to_find);
}

bool Local::is_friend(c_Player* player) {
    return !HitboxIdentity::IsEnemy(reinterpret_cast<uintptr_t>(this->hub), reinterpret_cast<uintptr_t>(player->hub));
}
