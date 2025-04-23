#pragma once
#include <iostream>
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

namespace menu {
    bool is_open = true;
    c_Bind* bind;

    enum tab_names : int
    {
        Player = 1,
        Aimbot,
        Map,
        Movement,
        Misc,
        Dev
    };

    ImGuiWindow* window;
    ImDrawList* draw_list;
    bool tab_list_is_open = false;
    int tab_list_offset = 30;
    int current_tab;

    bool checkbox(const char* name, bool* value) {
        if (!value) return false;
        window->DC.CursorPos.x += tab_list_offset;
        return ImGui::Checkbox(name, value);
    }

    bool slider_float(const char* name, float* value, float min, float max, const char* format = "%.3f") {
        if (!value) return false;
        window->DC.CursorPos.x += tab_list_offset;
        return ImGui::SliderFloat(name, value, min, max, format);
    }

    void menu_init() {
        bind = new c_Bind(Insert, Toggle, &is_open);
    }

    void player_tab() {
        if (current_tab == Player) {
            checkbox("esp", &player_esp->is_enabled);
            checkbox("list", &player_list_->is_enabled);
        }
    }

    void aimbot_tab() {
        if (current_tab == Aimbot) {
            checkbox("silent", &aimbot->is_enabled);
            checkbox("friendly fire", &aimbot->friendly_fire);
            checkbox("out of screen", &aimbot->shot_out_screen);
            slider_float("fov", &aimbot->fov, 0, 2000, "%.0f");
        }
    }

    void map_tab() {
        if (current_tab == Map) {
            checkbox("room esp", &room_esp->is_enabled);
            checkbox("item esp", &item_esp->is_enabled);
            slider_float("item esp distance", &item_esp->distance, 0, 1000, "%.0f");
        }
    }

    void misc_tab() {
        if (current_tab == Misc) {
            checkbox("anti-tesla", &anti_tesla->is_enabled);
        }
    }

    void draw_tab() {
        switch (current_tab) {
        case Player:
            player_tab();
        case Aimbot:
            aimbot_tab();
        case Map:
            map_tab();
        case Movement:

        case Misc:
            misc_tab();
        case Dev:

        default:
            break;
        }
    }

    void draw_menu() {
        if (!is_open) return;
        ImGui::Begin("zajedna", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
        ImGui::SetWindowSize(ImVec2(500, 300));
        window = ImGui::GetCurrentWindow();
        draw_list = ImGui::GetWindowDrawList();
        ImVec2 window_position = ImGui::GetWindowPos();
        ImVec2 window_size = ImGui::GetWindowSize();
        ImGui::tab_vidvigaemyi(window_position, &tab_list_is_open, &tab_list_offset, &current_tab);

        draw_tab();

        ImGui::End();
    }
}
