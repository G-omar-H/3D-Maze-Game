#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#include "main.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include "map.h"
#include "raycasting.h"

// Function prototypes for texture loading and rendering (implementation in render.c)
SDL_Texture* load_texture(const char* filePath);
void render_texture(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer, double textureYOffset);

// Function prototype for rendering a wall (implementation in render.c)
void render_wall(int x, double distance, const char(*)[COLUMNS], double wallHeight, SDL_Renderer* renderer, double cameraY);

// Optional function prototype for rendering ceiling and floor (implementation in main.c)
void render_ceiling_and_floor(SDL_Renderer* renderer, int height, int width);

#endif /* RENDER_H_INCLUDED */
