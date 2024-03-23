#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for random seed
#include <SDL2/SDL_image.h>

#define WIDTH 800
#define HEIGHT 600
#define M_PI 3.14159265358979323846  // Define pi for raycasting calculations
#define FOV (M_PI / 3)  // Field of view angle (60 degrees)
#define NEAR_PLANE 0.1  // Distance of the nearest plane (prevents issues with walls at player position)
#define FAR_PLANE 100.0  // Distance of the farthest plane (affects rendering distance)

extern double value;

#endif
