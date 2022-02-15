#pragma once
#include "Game.h"

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct Colors {
	struct Color RED;
	struct Color YELLOW;
	struct Color GREEN;
	struct Color CYAN;
	struct Color BLUE;
	struct Color MAGENTA;
	struct Color WHITE;
	struct Color LIGHT_GREY;
	struct Color DARK_GREY;
	struct Color BLACK;
	struct Color RAINBOW;
};

struct Colors Init_Colors();
