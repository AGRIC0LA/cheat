#pragma once
#include "../imgui/imgui.h"
#include <string>
#include "../sdk/vectorAndEtc.hpp"
#include "screen.h"

namespace draw {
	extern ImDrawList* draw_list;
	void update(ImDrawList* draw_list_);

	void text(ImVec2 pos, ImColor color, std::string text);
	void text(Vector3 pos, ImColor color, std::string text);
	void centered_text(Vector3 pos, ImColor color, std::string text);
	void centered_text(ImVec2 pos, ImColor color, std::string text);
	void text(ImVec2 pos, Color colorr, std::string text);
	void text(Vector3 pos, Color colorr, std::string text);
	void centered_text(Vector3 pos, Color colorr, std::string text);
	void centered_text(ImVec2 pos, Color colorr, std::string text);
	void circle(ImVec2 pos, ImColor color, float radius);
}