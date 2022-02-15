#include "Draw.h"

void Draw_Glow(SDL_Renderer *renderer, int x, int y, int s, struct Color c) {
	for (int i = 0; i < s; i++) {
		c.r -= i;
		c.g -= i;
		c.b -= i;
		c.a /= 1.41421;
		Draw_Box(renderer, x - i, y - i, s + 2 * i, s + 2 * i, c, false);
	} 
}

void Draw_Box(SDL_Renderer *renderer, int x, int y, int w, int h, struct Color c, bool o) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	// TODO: Write with ternary operation
	if (c.a != 0xff) {
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	} else {
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
	}
	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
	SDL_RenderFillRect(renderer, &rect);
	if (o) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
		SDL_RenderDrawRect(renderer, &rect);
	}
}

void Draw_Texture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h) {
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	SDL_Rect rect = {
		x, y, w, h
	};

	SDL_RenderCopy(renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}

void Draw_Text(SDL_Renderer *renderer, int x, int y, TTF_Font *font, const char *str, ...) {
	SDL_Color color = {
		0xff,0xff,0xff,0xff
	};
	SDL_Surface *surface = TTF_RenderText_Blended(font, str, color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	Draw_Texture(renderer, texture, x, y, 0, 0); 

	SDL_FreeSurface(surface);
}

