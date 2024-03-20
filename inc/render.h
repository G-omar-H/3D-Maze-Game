#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include <stdio.h>
#include <SDL2/SDL.h>

#define FOV M_PI / 3  // Field of view angle

// Function prototypes for texture loading and rendering (implementation in render.c)
SDL_Texture* load_texture(const char* filePath);
void render_texture(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer, double textureYOffset = 0.0);

// Function prototype for rendering a wall (implementation in render.c)
void render_wall(int x, double distance, char** map, double wallHeight, SDL_Renderer* renderer);

// Optional function prototype for rendering ceiling and floor (implementation in main.c)
void render_ceiling_and_floor(SDL_Renderer* renderer, int height, int width);

#endif /* RENDER_H_INCLUDED */
