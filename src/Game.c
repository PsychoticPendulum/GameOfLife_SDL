#include "Game.h"

#define INFO	0
#define WARNING	1
#define ERROR	2

void dprintf(int type, const char *str) {
	switch (type) {
		case WARNING:
			printf(ANSI_YELLOW "[WARNING]\t\t%s\n" ANSI_RESET, str);
			break;
		case ERROR:
			printf(ANSI_RED "[ERROR]\t\t\t%s\n" ANSI_RESET, str);
			break;
		default:
			printf("[INFO]\t\t\t%s\n", str);
			break;			
	}		
}

void Clean(SDL_Window *window, SDL_Renderer *renderer, struct Game game) {
	printf("\n  -> Renderer ...\t");
	SDL_DestroyRenderer(renderer);
	printf("Done!\n  -> Window ...\t\t");
	SDL_DestroyWindow(window);
	printf("Done!\n  -> Fontcache ...\t");
	TTF_CloseFont(game.font);
	TTF_Quit();
	printf("Done!\n  -> SDL ...\t\t");
	SDL_Quit();
	printf("Done!\n");
}

bool Init(struct Options opt) {
	struct Game game = {
		"GameOfLife", malloc(sizeof(char)*0xff), true, false, false, 1920, 1080, 0, 0, false, false, NULL, opt
	};

	// Initialize SDL
	printf("Initializing SDL ...\t");
	if (SDL_Init(SDL_INIT_VIDEO) || TTF_Init()) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	// Initialize SDL_TTF
	game.font = TTF_OpenFont("/usr/share/fonts/TTF/Roboto-Medium.ttf", 24);
	if (!game.font) {
		printf("Error initializing font: %s\n", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
	printf("Done!\n");

	// Get SDL Version
	SDL_version compiled;
	SDL_version linked;
	SDL_VERSION(&compiled);
	sprintf(game.msg, "SDL Compiled:\t%d.%d.%d", compiled.major, compiled.minor, compiled.patch);
	dprintf(INFO, game.msg);
	SDL_GetVersion(&linked);
	sprintf(game.msg, "SDL Linked:\t%d.%d.%d", linked.major, linked.minor, linked.patch);
	dprintf(INFO, game.msg);
	if (linked.patch >= 0xa) {
		dprintf(WARNING, "Unsupported version of SDL");
		dprintf(INFO, "Supported SDL Version: 2.0.9 or older");
	} 

	// Create Window
	printf("Creating Window ...\t");
	Uint32 window_flags = 0;
	SDL_Window *window = SDL_CreateWindow(game.title, CENTERED, CENTERED, game.w, game.h, window_flags);
	if (!window) {
		printf("Error creating window: %s\n", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}
	printf("Done!\n");
	
	// Create renderer
	printf("Creating Renderer ...\t");
	Uint32 render_flags = 0; //SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, render_flags);
	if (!renderer) {
		printf("Error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;
	}
	printf("Done!\n");

	Loop(window, renderer, game);	

	// Clean up and exit
	printf("Cleaning up:");
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
				dprintf(WARNING, "Invalid Option");
				break;
		}
	}

	return Init(opt);
}
