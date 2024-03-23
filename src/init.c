#include "init.h"

// Function to create and initialize the SDL window
SDL_Window* init_window(int width, int height) {
    SDL_Window* window = NULL;

    // Create a window with the specified title, position, and size
    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Failed to create window: %s\n", SDL_GetError());
        return NULL;
    }

    return window;
}

// Function to create a renderer associated with the window
SDL_Renderer* init_renderer(SDL_Window* window) {
    SDL_Renderer* renderer = NULL;

    // Create a renderer for the window with hardware acceleration (if available)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        return NULL;
    }

    // Set the color format of the renderer (usually matches the window format)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set default background color to black

    return renderer;
}

// Function to clean up resources before exiting
void cleanup_resources(SDL_Window* window, SDL_Renderer* renderer) {
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }

    if (window != NULL) {
        SDL_DestroyWindow(window);
    }
}

