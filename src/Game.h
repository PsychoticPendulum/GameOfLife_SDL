#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

#include <getopt.h>
#include <math.h>
#include <limits.h>

#include <sys/stat.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define CENTERED SDL_WINDOWPOS_CENTERED

struct Options {
	int resolution;
};

struct Game {
	char *title;
	char *msg;
	bool running;
	bool paused;
	bool debug;
	int w;
	int h;
	int x;
	int y;
	bool l_mouse;
	bool r_mouse;
	TTF_Font *font;
	struct Options opt;
};

struct Color;
struct Colors;
struct Field;

#include "Log.h"
#include "Color.h"
#include "Draw.h"
#include "Update.h"
#include "Render.h"
#include "Engine.h"

bool Init(struct Options opt);
void Clean(SDL_Window *window, SDL_Renderer *renderer, struct Game game);
void Save_Highscore(int score);
