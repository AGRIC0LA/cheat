#include "draw.h"

ImDrawList* draw::draw_list;

void draw::update(ImDrawList* draw_list_) {
	draw_list = draw_list_;
}

void draw::text(ImVec2 pos, ImColor color, std::string text) {
	draw_list->AddText(ImVec2(pos.x + 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x - 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y + 1), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y - 1), ImColor(0, 0, 0), text.c_str());

	draw_list->AddText(pos, color, text.c_str());
}

void draw::text(Vector3 pos, ImColor color, std::string text) {
	draw_list->AddText(ImVec2(pos.x + 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x - 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y + 1), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y - 1), ImColor(0, 0, 0), text.c_str());

	draw_list->AddText(ImVec2(pos.x, pos.y), color, text.c_str());
}

void draw::centered_text(Vector3 pos, ImColor color, std::string text) {
	ImVec2 text_size = ImGui::CalcTextSize(text.c_str());
	draw::text(ImVec2(pos.x - text_size.x / 2, pos.y), color, text);
}

void draw::centered_text(ImVec2 pos, ImColor color, std::string text) {
	ImVec2 text_size = ImGui::CalcTextSize(text.c_str());
	draw::text(ImVec2(pos.x - text_size.x / 2, pos.y), color, text);
}

void draw::text(ImVec2 pos, Color colorr, std::string text) {
	draw_list->AddText(ImVec2(pos.x + 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x - 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y + 1), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y - 1), ImColor(0, 0, 0), text.c_str());

	ImColor color = colorr.convert();
	draw_list->AddText(pos, color, text.c_str());
}

void draw::text(Vector3 pos, Color colorr, std::string text) {
	draw_list->AddText(ImVec2(pos.x + 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x - 1, pos.y), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y + 1), ImColor(0, 0, 0), text.c_str());
	draw_list->AddText(ImVec2(pos.x, pos.y - 1), ImColor(0, 0, 0), text.c_str());

	ImColor color = colorr.convert();
	draw_list->AddText(ImVec2(pos.x, pos.y), color, text.c_str());
}

void draw::centered_text(Vector3 pos, Color colorr, std::string text) {
	ImColor color = colorr.convert();
	ImVec2 text_size = ImGui::CalcTextSize(text.c_str());
	draw::text(ImVec2(pos.x - text_size.x / 2, pos.y), color, text);
}

void draw::centered_text(ImVec2 pos, Color colorr, std::string text) {
	ImColor color = colorr.convert();
	ImVec2 text_size = ImGui::CalcTextSize(text.c_str());
	draw::text(ImVec2(pos.x - text_size.x / 2, pos.y), color, text);
}

void draw::circle(ImVec2 pos, ImColor color, float radius) {
	draw_list->AddCircle(pos, radius, color, 360);
}
