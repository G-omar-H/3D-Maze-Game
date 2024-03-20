#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for random seed
#include <SDL2/SDL.h>

#include "../inc/init.h"
#include "../inc/input.h"
#include "../inc/render.h"
#include "../inc/map.h"
#include "../inc/raycasting.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window and renderer
    SDL_Window* window = init_window(WIDTH, HEIGHT);
    SDL_Renderer* renderer = init_renderer(window);
    if (!window || !renderer) {
        cleanup_resources(window, renderer);  // Call cleanup function from init.c (if applicable)
        SDL_Quit();
        return 1;
    }

    // Seed the random number generator for map generation (if applicable)
    srand(time(NULL));

    // Initialize raycasting data structures (map data)
    double distanceBuffer[WIDTH];  // Buffer to store distances for each column
    double wallHeights[WIDTH];      // Buffer to store wall heights for each column

    // Main loop for rendering and handling events
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                default:
                    // Call input handling function to process events
                    handle_input(&running, &cameraDir, &cameraX, &cameraY, event);
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
        SDL_RenderClear(renderer);

        // Perform raycasting for each column on the screen
        raycast_walls(distanceBuffer, wallHeights);

        // Render ceiling and floor
        render_ceiling_and_floor(renderer, HEIGHT, WIDTH);

        // Render walls using information from raycasting
        for (int x = 0; x < WIDTH; x++) {
            // Access distance and wall height from raycasting results
            double distance = distanceBuffer[x];
            double wallHeight = wallHeights[x];

            // Call function from render.c to render the wall based on distance and height
            if (distance > 0.1) {  // Avoid rendering for very close distances
                render_wall(x, distance, map, wallHeight, renderer);
            }
        }

        // Render other elements (sprites, UI) here (if applicable)

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up resources
    cleanup_resources(window, renderer);  // Call cleanup function from init.c (if applicable)
    SDL_Quit();

    return 0;
}

// Function to render ceiling and floor (moved outside main loop for readability)
void render_ceiling_and_floor(SDL_Renderer* renderer, int height, int width) {
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Dark gray for ceiling/floor

    int halfHeight = height / 2;
    SDL_Rect ceilingRect = {0, 0, width, halfHeight};
    SDL_Rect floorRect = {0, halfHeight, width, height - halfHeight};
    SDL_RenderFillRect(renderer, &ceilingRect);
    SDL_RenderFillRect(renderer, &floorRect);
}