#include "Engine.h"

void Loop(SDL_Window *window, SDL_Renderer *renderer, struct Game game) {
	struct Colors colors = Init_Colors();
	
	struct Field field;
	field.res = game.opt.resolution;
	field.w = game.w / field.res;
	field.h = game.h / field.res;
	for (int x = 0; x < field.w; x++) {
		for	(int y = 0; y < field.h; y++) {
			// Fill Render Cell
			field.cell[x][y].x = x * field.res;
			field.cell[x][y].y = y * field.res;
			field.cell[x][y].active = 0;
			field.cell[x][y].hover = false;
			// Fill Buffer Cell
			field.bell[x][y].x = x * field.res;
			field.bell[x][y].y = y * field.res;
			field.bell[x][y].active = 0;
			field.bell[x][y].hover = false;
			field.bell[x][y].neighbours = 0;
			field.bell[x][y].neighbours = 0;
		}
	}

	// Main Loop
	while (game.running) {
		colors.RAINBOW = Cycle_Colors(colors.RAINBOW.r, colors.RAINBOW.g, colors.RAINBOW.b, 255, 1);
		Handle_Event(&game, &field);
		Update(&game, &field);
		Render(renderer, game, field, colors);
	}
}

void Clear_Field(struct Field *field) {
	for (int x = 0; x < field->w; x++) {
		for (int y = 0; y < field->h; y++) {
			field->cell[x][y].active = false;
		}
	}
}

void Create_Frame(struct Field *field) {
	for (int x = 0; x < field->w; x++) {
		for (int y = 0; y < field->h; y++) {
			if ((x == 0) || (x == field->w-1) || (y == 0) || (y == field->h-1)) {
				field->cell[x][y].active = true;
			}
		}
	} 
}

void Happening(struct Field *field) {
	for (int x = 0; x < field->w; x++) {
		for (int y = 0; y < field->h; y++) {
			field->cell[x][y].active = (y % 10 == 0 || x % 10 > 5);
		}
	}
}

void Randomize(struct Field *field) {
	for (int x = 0; x < field->w; x++) {
		for (int y = 0; y < field->h; y++) {
			field->cell[x][y].active = rand()%2;
		}
	}
}

void Handle_Event(struct Game *game, struct Field *field) {
	// Reset Mouse State
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			// Make game quitable
			case SDL_QUIT:
				game->running = false;
				break;

			// Mouse Input
			// Get Mouse Position
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&game->x, &game->y);
				break;
			// Get Mousedown (activate/deactivate)
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					game->l_mouse = true;
				} else if (event.button.button == SDL_BUTTON_RIGHT) {
					game->r_mouse = true;
				}
				break;
			// Get Mouseup (so holding of mouse buttons works)
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT) {
					game->l_mouse = false;
				} else if (event.button.button == SDL_BUTTON_RIGHT) {
					game->r_mouse = false;
				}
				break;
			
			// Keyboard Input	
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					// Quit game
					case SDLK_q:
						game->running = false;
						break;
					// Pause game
					case SDLK_SPACE:
						game->paused = !game->paused;
						break;
					// Enable Debug Mode
					case SDLK_d:
						game->debug = !game->debug;
						break;
					// Clear Field
					case SDLK_c:
						Clear_Field(field);
						break;
					// Create Frame
					case SDLK_m:
						Create_Frame(field);
						break;
					// Randomize
					case SDLK_r:
						Randomize(field);
						break;
					case SDLK_e:
						Happening(field);
						break;
				}
				break;
		}
	}
}

double Get_Distance(int x1, int y1, int x2, int y2) {
	double xdst = x1-x2;
	double ydst = y1-y2;
	return sqrt(xdst*xdst+ydst*ydst);
}

int Random_Int(int min, int max) {
	return min + rand() % (max + 1 - min);
}
