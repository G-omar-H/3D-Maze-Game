#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <stdio.h>

// Function prototypes for window and renderer initialization (implementation in init.c)
SDL_Window* init_window(int width, int height);
SDL_Renderer* init_renderer(SDL_Window* window);

// Function prototype for cleanup (if applicable, implementation in init.c)
void cleanup_resources(SDL_Window* window, SDL_Renderer* renderer);

#endif /* INIT_H_INCLUDED */
