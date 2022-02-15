#pragma once
#include "Game.h"

void Draw_Box(SDL_Renderer *renderer, int x, int y, int w, int h, struct Color c, bool o);
void Draw_Texture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);
void Draw_Text(SDL_Renderer *renderer, int x, int y, TTF_Font *font, const char *str, ...);
void Draw_Glow(SDL_Renderer *rendere, int x, int y, int s, struct Color c);
