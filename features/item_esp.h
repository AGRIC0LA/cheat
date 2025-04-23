#pragma once
#include "cFeature.h"

enum ItemType {
    Noaweafsdne = -1,
    KeycardJanitor,
    KeycardScientist,
    KeycardResearchCoordinator,
    KeycardZoneManager,
    KeycardGuard,
    KeycardMTFPrivate,
    KeycardContainmentEngineer,
    KeycardMTFOperative,
    KeycardMTFCaptain,
    KeycardFacilityManager,
    KeycardChaosInsurgency,
    KeycardO5,
    Radio,
    GunCOM15,
    Medkit,
    Flashlight,
    MicroHID,
    SCP500,
    SCP207,
    Ammo12gauge,
    GunE11SR,
    GunCrossvec,
    Ammo556x45,
    GunFSP9,
    GunLogicer,
    GrenadeHE,
    GrenadeFlash,
    Ammo44cal,
    Ammo762x39,
    Ammo9x19,
    GunCOM18,
    SCP018,
    SCP268,
    Adrenaline,
    Painkillers,
    Coin,
    ArmorLight,
    ArmorCombat,
    ArmorHeavy,
    GunRevolver,
    GunAK,
    GunShotgun,
    SCP330,
    SCP2176,
    SCP244a,
    SCP244b,
    SCP1853,
    ParticleDisruptor,
    GunCom45,
    SCP1576,
    Jailbird,
    Anti
};

class c_ItemEsp : public c_Feature {
public:
    struct item {
        Vector3 position;
        ItemType type;

        std::string get_name() {
            switch (this->type) {
                case None:
                    return "None";
                case KeycardJanitor:
                    return "Keycard Janitor";
                case KeycardScientist:
                    return "Keycard Scientist";
                case KeycardResearchCoordinator:
                    return "Keycard Research Coordinator";
                case KeycardZoneManager:
                    return "Keycard Zone Manager";
                case KeycardGuard:
                    return "Keycard Guard";
                case KeycardMTFPrivate:
                    return "Keycard MTF Private";
                case KeycardContainmentEngineer:
                    return "Keycard Containment Engineer";
                case KeycardMTFOperative:
                    return "Keycard MTF Operative";
                case KeycardMTFCaptain:
                    return "Keycard MTF Captain";
                case KeycardFacilityManager:
                    return "Keycard Facility Manager";
                case KeycardChaosInsurgency:
                    return "Keycard Chaos Insurgency";
                case KeycardO5:
                    return "Keycard O5";
                case Radio:
                    return "Radio";
                case GunCOM15:
                    return "COM-15";
                case Medkit:
                    return "Medkit";
                case Flashlight:
                    return "Flashlight";
                case MicroHID:
                    return "Micro HID";
                case SCP500:
                    return "SCP-500";
                case SCP207:
                    return "SCP-207";
                case Ammo12gauge:
                    return "12 Gauge Ammo";
                case GunE11SR:
                    return "E-11 SR";
                case GunCrossvec:
                    return "Crossvec";
                case Ammo556x45:
                    return "5.56x45 Ammo";
                case GunFSP9:
                    return "FSP-9";
                case GunLogicer:
                    return "Logicer";
                case GrenadeHE:
                    return "HE Grenade";
                case GrenadeFlash:
                    return "Flash Grenade";
                case Ammo44cal:
                    return ".44 Caliber Ammo";
                case Ammo762x39:
                    return "7.62x39 Ammo";
                case Ammo9x19:
                    return "9x19 Ammo";
                case GunCOM18:
                    return "COM-18";
                case SCP018:
                    return "SCP-018";
                case SCP268:
                    return "SCP-268";
                case Adrenaline:
                    return "Adrenaline";
                case Painkillers:
                    return "Painkillers";
                case Coin:
                    return "Coin";
                case ArmorLight:
                    return "Light Armor";
                case ArmorCombat:
                    return "Combat Armor";
                case ArmorHeavy:
                    return "Heavy Armor";
                case GunRevolver:
                    return "Revolver";
                case GunAK:
                    return "AK";
                case GunShotgun:
                    return "Shotgun";
                case SCP330:
                    return "SCP-330";
                case SCP2176:
                    return "SCP-2176";
                case SCP244a:
                    return "SCP-244a";
                case SCP244b:
                    return "SCP-244b";
                case SCP1853:
                    return "SCP-1853";
                case ParticleDisruptor:
                    return "Particle Disruptor";
                case GunCom45:
                    return "COM-45";
                case SCP1576:
                    return "SCP-1576";
                case Jailbird:
                    return "Jailbird";
                case Anti:
                    return "Anti";
                default:
                    return "Unknown Item";
            }
        }
    };
    float distance;
	static std::vector<item> item_list;
	static update_t original_function;
	static void detour(uintptr_t rcx);
	void update() override;
	void set_hooks() override;
};

extern c_ItemEsp* item_esp;