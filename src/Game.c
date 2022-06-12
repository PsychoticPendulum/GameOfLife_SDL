#include "Game.h"

void Clean(SDL_Window *window, SDL_Renderer *renderer, struct Game game) {
	Log(INFO, "Cleaning Renderer", NULL);
	SDL_DestroyRenderer(renderer);
	Log(INFO, "Cleaning Window", NULL);
	SDL_DestroyWindow(window);
	Log(INFO, "Cleaning Fontcache", NULL);
	TTF_CloseFont(game.font);
	TTF_Quit();
	Log(INFO, "Cleaning SDL", NULL);
	SDL_Quit();
}

bool Init(struct Options opt) {
	struct Game game = {
		"GameOfLife", malloc(sizeof(char)*0xff), true, false, false, 1920, 1080, 0, 0, false, false, NULL, opt
	};

	// Initialize SDL
	Log(INFO, "Initializing SDL ...", NULL);
	if (SDL_Init(SDL_INIT_VIDEO) || TTF_Init()) {
		Log(ERROR, "Failed initializing SDL ...", SDL_GetError());
		return EXIT_FAILURE;
	}

	// Initialize SDL_TTF
	game.font = TTF_OpenFont("/usr/share/fonts/TTF/Roboto-Medium.ttf", 24);
	if (!game.font) {
		Log(ERROR, "Error initializing font ...", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}

	// Get SDL Version
	SDL_version compiled;
	SDL_version linked;
	SDL_VERSION(&compiled);
	sprintf(game.msg, "SDL Compiled:\t%d.%d.%d", compiled.major, compiled.minor, compiled.patch);
	Log(INFO, game.msg, NULL);
	SDL_GetVersion(&linked);
	sprintf(game.msg, "SDL Linked:\t%d.%d.%d", linked.major, linked.minor, linked.patch);
	Log(INFO, game.msg, NULL);
	if (linked.patch >= 0xa) {
		Log(WARNING, "Unsupported version of SDL", NULL);
		Log(INFO, "Supported SDL Version: 2.0.9 or older", NULL);
	} 

	// Create Window
	Log(INFO, "Creating Window ...", NULL);
	Uint32 window_flags = 0;
	SDL_Window *window = SDL_CreateWindow(game.title, CENTERED, CENTERED, game.w, game.h, window_flags);
	if (!window) {
		Log(ERROR, "Error creating window ...", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
	
	// Create renderer
	Log(INFO, "Creating Renderer ...", NULL);
	Uint32 render_flags = 0; //SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, render_flags);
	if (!renderer) {
		Log(ERROR, "Error creating renderer ...", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;
	}

	Loop(window, renderer, game);	

	// Clean up and exit
	Clean(window, renderer, game);
	return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
	int option;
	struct Options opt = {
		8		
	};
	while ((option = getopt(argc, argv, "r:")) != -1) {
		switch (option) {
			case 'r':
				opt.resolution = atoi(optarg);
				break;
			default:
				Log(WARNING, "Invalid Option",NULL);
				break;
		}
	}

	return Init(opt);
}
