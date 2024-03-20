#include "../inc/render.h"

SDL_Renderer* renderer;  // Replace with actual renderer declaration

// Function prototypes for texture loading and rendering (implementation included)
SDL_Texture* load_texture(const char* filePath);
void render_texture(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer);

void render_wall(int x, double distance, char** map, double wallHeight, SDL_Renderer* renderer) {
    // Calculate wall height based on distance and field of view (adjust as needed)
    double wallHeightRatio = (double)HEIGHT / distance * (HEIGHT / (2.0 * tan(FOV / 2)));

    // Calculate starting and ending Y coordinates for the wall on the screen
    int startY = (int)(HEIGHT / 2 - wallHeightRatio / 2);
    if (startY < 0) {
        startY = 0;
    }
    int endY = (int)(HEIGHT / 2 + wallHeightRatio / 2);
    if (endy > HEIGHT) {
        endy = HEIGHT;
    }

    // Determine wall type based on map data
    int mapY = (int)cameraY;  // Assuming cameraY represents player Y position (adjust if needed)
    char wallType = map[mapY][x];

    // Set wall texture based on wall type
    SDL_Texture* wallTexture;
    switch (wallType) {
        case 'S':
            wallTexture = load_texture("stone_wall.bmp");  // Replace with your texture path
            break;
        case 'B':
            wallTexture = load_texture("brick_wall.bmp");  // Replace with your texture path
            break;
        // Add cases for other wall types and textures
        default:
            wallTexture = NULL;  // Indicate no texture for empty space
            break;
    }

    // Draw ceiling and floor
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Dark gray for ceiling/floor

    // Adjust ceiling and floor rectangles based on wall height
    SDL_Rect ceilingRect = {0, 0, WIDTH, startY};
    SDL_Rect floorRect = {0, endY, WIDTH, HEIGHT - endY};
    SDL_RenderFillRect(renderer, &ceilingRect);
    SDL_RenderFillRect(renderer, &floorRect);

    // Draw the wall using texture (if available) or color
    if (wallTexture) {
        // Calculate texture Y offset based on wall hit position (optional for scrolling textures)
        double textureYOffset = /* Calculate offset based on hit position */;
        render_texture(wallTexture, x, startY, renderer, textureYOffset);  // Pass texture offset (if applicable)
    } else {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);  // Light gray for empty space
        SDL_Rect wallRect = {x, startY, 1, endY - startY};
        SDL_RenderFillRect(renderer, &wallRect);
    }
}

SDL_Texture* load_texture(const char* filePath) {
    // Initialize SDL_image if not already done
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("SDL_image initialization error: %s\n", IMG_GetError());
        return NULL;
    }

    // Load the image from the specified file path
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        printf("Error loading texture: %s\n", IMG_GetError());
        return NULL;
    }

    // Convert the surface to a texture for hardware rendering
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("Error creating texture from surface: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return NULL;
    }

    // Free the loaded surface as we don't need it anymore
    SDL_FreeSurface(surface);

    return texture;
}

void render_texture(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer, double textureYOffset) {
    // Get the texture width and height
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);

    // Calculate the source rectangle within the texture based on Y offset
    SDL_Rect srcRect = {0, (int)(textureYOffset * textureHeight), textureWidth, textureHeight / 2};  // Adjust for half-height

    // Define the destination rectangle for rendering the texture
    SDL_Rect dstRect = {x, y, textureWidth, textureHeight / 2};  // Adjust for half-height

    // Render the portion of the texture specified by the source rectangle
    SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}
