#include "Render.h"

struct Color Cycle_Colors(int r, int g, int b, int m, int v) {
	if (r == m && b == 0) {
		g += v;
	}
	if (g == m && r > 0) {
		r -= v;
	}
	if (g == m && r == 0) {
		b += v;
	}
	if (b == m && g > 0) {
		g -= v;
	}
	if (b == m && g == 0) {
		r += v;
	}
	if (r == m && b > 0) {
		b -= v;
	}
	struct Color color = {
		r, g, b, 255
	};
	return color;
}

struct Color RAINBOW = {
	240, 0, 0, 240
};
int rainbow_count = 8;

struct Color Get_Gradient(int y) {
	struct Color color = {
		RAINBOW.r, RAINBOW.g, RAINBOW.b, RAINBOW.a
	};
	for (int i = 0; i < y; i++) {
		color = Cycle_Colors(color.r, color.g, color.b, 240, 6);
	}
	return color;
}

struct Color Get_Cell_Color(struct Game game, struct Cell cell, int y, struct Colors colors) {
	struct Color color = cell.active ? Get_Gradient(y) : colors.DARK_GREY;
	if (game.paused && cell.hover) {
		color = colors.WHITE;
	}
	return color;
}

void Render(SDL_Renderer *renderer, struct Game game, struct Field field, struct Colors colors) {
	// Flush buffer
	SDL_RenderClear(renderer);
	
	char *buffer = malloc(sizeof(char)*8);
	
	if (rainbow_count-- == 0) {
		RAINBOW = Cycle_Colors(RAINBOW.r, RAINBOW.g, RAINBOW.b, 240, 12);
		rainbow_count = 8;
	}

	for (int x = 0; x < field.w; x++) {
		for (int y = 0; y < field.h; y++) {
			Draw_Box(renderer,
					field.cell[x][y].x,
					field.cell[x][y].y,
					field.res, field.res,
					Get_Cell_Color(game, field.cell[x][y], y, colors),
					false);		

			// Draw Cell Neighbours
			if (game.debug) {
				sprintf(buffer, "%d", field.cell[x][y].neighbours);
				Draw_Text(renderer,
							field.cell[x][y].x,
							field.cell[x][y].y,
							game.font, buffer);
			}
		}
	}	

	free(buffer);
	
	// Draw paused
	if (game.paused) {
		Draw_Box(renderer, game.w / 2 - 20, game.h / 2 - 25, 15, 50, colors.WHITE, true); 
		Draw_Box(renderer, game.w / 2 + 5, game.h / 2 - 25, 15, 50, colors.WHITE, true); 
	}

	// Draw background
	SDL_SetRenderDrawColor(renderer, 0xf, 0xf, 0xf, 0xff);
	SDL_RenderPresent(renderer);
}
