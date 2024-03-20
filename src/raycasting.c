#include "../inc/raycasting.h"

double cameraX = 2.0;  // Player's X position in the map
double cameraY = 2.0;  // Player's Y position in the map
double cameraDir = M_PI / 3;  // Player's camera direction (initially facing right)
const double FAR_PLANE = 100.0;

RaycastHit cast_ray(double rayAngle, double cosRayAngle, double sinRayAngle) {
    RaycastHit hit;
    int hitX, hitY;
    double deltaX = 0.0, deltaY = 0.0;

    int mapWidth = WIDTH;
    int mapHeight = HEIGHT;

    double x = cameraX;
    double y = cameraY;

    // Calculate initial step distances based on ray angle
    if (cosRayAngle >= 0.0) {
        deltaX = 1.0;
        hitX = (int)x + 1;
    } else {
        deltaX = -1.0;
        hitX = (int)x;
    }
    if (sinRayAngle >= 0.0) {
        deltaY = 1.0;
        hitY = (int)y + 1;
    } else {
        deltaY = -1.0;
        hitY = (int)y;
    }

    // DDA loop for ray casting
    while (hitX >= 0 && hitX < mapWidth && hitY >= 0 && hitY < mapHeight) {
        // Check if ray hit a wall (avoiding issue at player position)
        if (map[hitY][hitX] != '.' && (x - cameraX) * (x - cameraX) + (y - cameraY) * (y - cameraY) > NEAR_PLANE * NEAR_PLANE) {
            hit.perpWallDist = sqrt(pow(x - cameraX, 2) + pow(y - cameraY, 2));
            hit.wallHitContent = map[hitY][hitX] == 'S' ? WALL_STONE : WALL_BRICK;  // Example: 'S' for stone, 'B' for brick
            return hit;
        }

        x += deltaX;
        y += deltaY;

        hitX = (int)x;
        hitY = (int)y;
    }

    // No wall hit, set distance to far plane
    hit.perpWallDist = FAR_PLANE;
    hit.wallHitContent = EMPTY;
    return hit;
}

void raycast_walls(double* distanceBuffer, double* wallHeights) {
    // Loop through all columns on the screen
    for (int x = 0; x < WIDTH; ++x) {
        // Calculate ray angle based on camera direction and field of view (FOV)
        double rayAngle = (cameraDir - FOV / 2.0) + ((double)x / (double)WIDTH) * FOV;
        double cosRayAngle = cos(rayAngle);
        double sinRayAngle = sin(rayAngle);

        // Cast a ray for this column and store the results
        RaycastHit hit = cast_ray(rayAngle, cosRayAngle, sinRayAngle);
        distanceBuffer[x] = hit.perpWallDist;

        // Calculate wall height based on distance and field of view (adjust as needed)
        if (hit.perpWallDist > NEAR_PLANE) {
            double wallHeight = (double)HEIGHT / hit.perpWallDist * (HEIGHT / (2.0 * tan(FOV / 2)));
            wallHeights[x] = wallHeight;
        } else {
            wallHeights[x] = 0.0;  // No wall visible for very close distances
        }
    }
}