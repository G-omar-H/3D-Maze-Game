#include "../inc/init.h"

SDL_Window* init_SDL(const char* title, int width, int height) {
    // Initialize SDL subsystems
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL could not initialize: %s\n", SDL_GetError());
        return NULL;
    }

    // Set window hints for multisampling anti-aliasing (optional)
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLE SAMPLES, 4);  // Adjust sample count as needed

    // Create window
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED, width, height,
                                           SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    return window;
}
