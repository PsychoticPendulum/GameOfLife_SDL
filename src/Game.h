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

#define ANSI_RED    	"\x1b[31m"
#define ANSI_YELLOW  	"\x1b[33m"
#define ANSI_GREEN   	"\x1b[32m"
#define ANSI_CYAN    	"\x1b[36m"
#define ANSI_BLUE    	"\x1b[34m"
#define ANSI_MAGENTA 	"\x1b[35m"
#define ANSI_WHITE	 	"\x1b[39m"
#define ANSI_LIGHT_GREY	"\x1b[38m"
#define ANSI_DARK_GREY	"\x1b[39m"
#define ANSI_BLACK		"\x1b[30m"
#define ANSI_RESET   	"\x1b[0m"

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

#include "Color.h"
#include "Draw.h"
#include "Update.h"
#include "Render.h"
#include "Engine.h"

bool Init(struct Options opt);
void Clean(SDL_Window *window, SDL_Renderer *renderer, struct Game game);
void Save_Highscore(int score);
