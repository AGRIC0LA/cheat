#pragma once
#include "cFeature.h"

enum RoomName {
	Unnamed,
	LczClassDSpawn,
	LczComputerRoom,
	LczCheckpointA,
	LczCheckpointB,
	LczToilets,
	LczArmory,
	Lcz173,
	LczGlassroom,
	Lcz330,
	Lcz914,
	LczGreenhouse,
	LczAirlock,
	HczCheckpointToEntranceZone,
	HczCheckpointA,
	HczCheckpointB,
	HczWarhead,
	Hcz049,
	Hcz079,
	Hcz096,
	Hcz106,
	Hcz939,
	HczMicroHID,
	HczArmory,
	HczServers,
	HczTesla,
	EzCollapsedTunnel,
	EzGateA,
	EzGateB,
	EzRedroom,
	EzEvacShelter,
	EzIntercom,
	EzOfficeStoried,
	EzOfficeLarge,
	EzOfficeSmall,
	Outside,
	Pocket,
	HczTestroom
};

class c_RoomEsp : public c_Feature {
	struct room {
		Vector3 position;
		RoomName name;
        std::string get_name() {
            switch (this->name) {
                case Unnamed:
                    return "Unnamed";
                case LczClassDSpawn:
                    return "Class D";
                case LczComputerRoom:
                    return "Computer Room";
                case LczCheckpointA:
                    return "Checkpoint A";
                case LczCheckpointB:
                    return "Checkpoint B";
                case LczToilets:
                    return "Toilets";
                case LczArmory:
                    return "Armory";
                case Lcz173:
                    return "SCP 173";
                case LczGlassroom:
                    return "Glassroom";
                case Lcz330:
                    return "SCP 330";
                case Lcz914:
                    return "SCP 914";
                case LczGreenhouse:
                    return "Greenhouse";
                case LczAirlock:
                    return "Airlock";
                case HczCheckpointToEntranceZone:
                    return "Checkpoint";
                case HczCheckpointA:
                    return "Checkpoint A";
                case HczCheckpointB:
                    return "Checkpoint B";
                case HczWarhead:
                    return "Warhead";
                case Hcz049:
                    return "SCP 049";
                case Hcz079:
                    return "SCP 079";
                case Hcz096:
                    return "SCP 096";
                case Hcz106:
                    return "SCP 106";
                case Hcz939:
                    return "SCP 939";
                case HczMicroHID:
                    return "Micro HID";
                case HczArmory:
                    return "Armory";
                case HczServers:
                    return "Servers";
                case HczTesla:
                    return "Tesla";
                case EzCollapsedTunnel:
                    return "Collapsed Tunnel";
                case EzGateA:
                    return "Gate A";
                case EzGateB:
                    return "Gate B";
                case EzRedroom:
                    return "Red Room";
                case EzEvacShelter:
                    return "Evac Shelter";
                case EzIntercom:
                    return "Intercom";
                case EzOfficeStoried:
                    return "Office Storied";
                case EzOfficeLarge:
                    return "Office Large";
                case EzOfficeSmall:
                    return "Office Small";
                case Outside:
                    return "Outside";
                case Pocket:
                    return "Pocket";
                case HczTestroom:
                    return "Test Room";
            }
            return "Unknown";
        }

        bool get_is_valid() {
            switch (this->name) {
                case Unnamed:
                    return false;
                case LczClassDSpawn:
                    return true;
                case LczComputerRoom:
                    return true;
                case LczCheckpointA:
                    return true;
                case LczCheckpointB:
                    return true;
                case LczToilets:
                    return true;
                case LczArmory:
                    return true;
                case Lcz173:
                    return true;
                case LczGlassroom:
                    return true;
                case Lcz330:
                    return true;
                case Lcz914:
                    return true;
                case LczGreenhouse:
                    return true;
                case LczAirlock:
                    return false;
                case HczCheckpointToEntranceZone:
                    return true;
                case HczCheckpointA:
                    return true;
                case HczCheckpointB:
                    return true;
                case HczWarhead:
                    return true;
                case Hcz049:
                    return true;
                case Hcz079:
                    return true;
                case Hcz096:
                    return true;
                case Hcz106:
                    return true;
                case Hcz939:
                    return true;
                case HczMicroHID:
                    return true;
                case HczArmory:
                    return true;
                case HczServers:
                    return true;
                case HczTesla:
                    return true;
                case EzCollapsedTunnel:
                    return true;
                case EzGateA:
                    return true;
                case EzGateB:
                    return true;
                case EzRedroom:
                    return false;
                case EzEvacShelter:
                    return false;
                case EzIntercom:
                    return true;
                case EzOfficeStoried:
                    return false;
                case EzOfficeLarge:
                    return false;
                case EzOfficeSmall:
                    return false;
                case Outside:
                    return false;
                case Pocket:
                    return true;
                case HczTestroom:
                    return false;
            }
            return false;
        }
	};
	static std::vector<room> room_list;
	static update_t original_function;
	static void detour(uintptr_t rcx);
	void update() override;
	void set_hooks() override;
};

extern c_RoomEsp* room_esp;