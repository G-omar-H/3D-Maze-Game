#include "input.h"  // Include input handling definitions

void handle_input(int* running, double* cameraDir, double* cameraX, double* cameraY, SDL_Event event)
{
    // Handle keyboard events
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    *cameraX += MOVE_SPEED * cos(*cameraDir);
                    *cameraY += MOVE_SPEED * sin(*cameraDir);
                    break;
                case SDLK_s:
                    *cameraX -= MOVE_SPEED * cos(*cameraDir);
                    *cameraY -= MOVE_SPEED * sin(*cameraDir);
                    break;
                case SDLK_a:
                    *cameraDir -= TURN_SPEED;  // Rotate camera left
                    break;
                case SDLK_d:
                    *cameraDir += TURN_SPEED;  // Rotate camera right
                    break;
                case SDLK_ESCAPE:
                    *running = 0;  // Quit the game
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
