#pragma once
#include "Game.h"

void Render(SDL_Renderer *renderer, struct Game game, struct Field field, struct Colors colors);
struct Color Cycle_Colors(int r, int g, int b, int m, int v);
void Vignette(SDL_Renderer *renderer, int x, int y);
