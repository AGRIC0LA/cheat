#pragma once
#include "vectorAndEtc.hpp"
#include "include_sdk.h"
#include "../mem.h"

enum RoleTypeId {
	None = -1,
	Scp173,
	ClassD,
	Spectator,
	Scp106,
	NtfSpecialist,
	Scp049,
	Scientist,
	Scp079,
	ChaosConscript,
	Scp096,
	Scp0492,
	NtfSergeant,
	NtfCaptain,
	NtfPrivate,
	Tutorial,
	FacilityGuard,
	Scp939,
	CustomRole,
	ChaosRifleman,
	ChaosMarauder,
	ChaosRepressor,
	Overwatch,
	Filmmaker,
	Scp3114,
	Destroyed,
	Flamingo,
	AlphaFlamingo,
	ZombieFlamingo
};

enum HitboxType {
	Body,
	Limb,
	Headshot
};

class c_Transform {
public:
	Vector3 get_position();
	void set_position(Vector3& position);
	Quaternion get_rotation();
};

class c_GameObject {
public:
	c_Transform* get_transform();
	Vector3 get_position();
	Quaternion get_rotation();
	void set_position(Vector3& position);
	void set_rotation(Quaternion& set_rotation);
};

class c_Component {
public:
	c_Transform* get_transform();
	Vector3 get_position();
	void set_position(Vector3& pos);
};

class c_Camera : public c_Component { 
public:
	Vector3 w2s(Vector3& position);
	static c_Camera* get_main();
};

class c_ReferenceHub {
public:
	std::string get_name();
	Color get_role_color();
	std::string get_role_name();
	static c_ReferenceHub* get_local();
	Vector3 get_hitbox_position(HitboxType hitbox_to_find);
};