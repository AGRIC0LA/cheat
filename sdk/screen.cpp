#include "screen.h"

int screen::height;
int screen::width;

void screen::update() {
	screen::height = UnityEngine::Screen::get_height();
	screen::width = UnityEngine::Screen::get_width();
}

bool screen::w2s(Vector3& position, Vector3* on_screen, c_Camera* camera) {
	if (!camera) return false;
	*on_screen = camera->w2s(position);

	if (!on_screen->x > width || on_screen->y > width || on_screen->x < 0 || on_screen->y < 0 || on_screen->z < 0)
		return false;
	if (on_screen->z > 0.f)
		return true;
	return false;
}
