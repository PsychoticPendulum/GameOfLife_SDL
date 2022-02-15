#pragma once
#include "Game.h"

struct Cell {
	int x;
	int y;
	int neighbours;
	bool hover;
	bool active;
};

struct Field {
	int res;
	int w;
	int h;
	struct Cell cell[0xff][0xff];
	struct Cell bell[0xff][0xff];
};

void Loop(SDL_Window *window, SDL_Renderer *renderer, struct Game game);
void Handle_Event(struct Game *game, struct Field *field);

// Mathematical Functions
double Get_Distance(int x1, int y1, int x2, int y2);
int Random_Int(int min, int max);
