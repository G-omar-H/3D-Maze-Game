#include "../inc/input.h"  // Include input handling definitions

void handle_input(SDL_Event* event, double* cameraX, double* cameraY, double* cameraDir) {
    // Handle keyboard events
    switch (event->type) {
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym) {
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
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
