#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <math.h>  // For sin and cos functions
#include <SDL2/SDL.h>
#include <stdbool.h>  // for boolean type


#define MOVE_SPEED 0.1  // Adjust as needed for desired movement speed
#define TURN_SPEED 0.05  // Adjust as needed for desired turn speed

// Function prototype for handling user input (implementation in input.c)
void handle_input(int* running, double* cameraDir, double* cameraX, double* cameraY, SDL_Event event);

#endif /* INPUT_H_INCLUDED */
