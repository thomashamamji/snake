#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

typedef struct {
	int x;
	int y;
	SDL_Texture *texture;
} Entity;

typedef struct {
    int value;
    Entity location;
} Points;

#endif