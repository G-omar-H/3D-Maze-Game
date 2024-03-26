#include "raycasting.h"
#include "main.h"


double cameraX = 2.0;  // Player's X position in the map
double cameraY = 2.0;  // Player's Y position in the map
double cameraDir = M_PI / 3;  // Player's camera direction (initially facing right)

RaycastHit cast_ray(double cosRayAngle, double sinRayAngle) {
    RaycastHit hit;
    int hitX, hitY;
    double deltaX = 0.0, deltaY = 0.0;

    int mapWidth = COLUMNS;
    int mapHeight = ROWS;

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
            hit.wallHitContent = map[hitY][hitX] == 'S' ? WALL_STONE : WALL_BRICK;  //'S' for stone, 'B' for brick
            return hit;
        }
        x += deltaX;
        y += deltaY;

        hitX = (int)x;
        hitY = (int)y;
        if (hitX < 0 || hitX >= mapWidth || hitY < 0 || hitY >= mapHeight) {
            // Handle boundary exceeded (e.g., log error message)
            break; // Exit the loop
        }
    }
    // No wall hit, set distance to far plane
    hit.perpWallDist = FAR_PLANE;
    hit.wallHitContent = EMPTY;
    printf("Raycast: perpWallDist = %f, wallHitContent = %d\n", hit.perpWallDist, hit.wallHitContent);
    return hit;
}

void raycast_walls(double* distanceBuffer, double* wallHeights) {
    // Loop through all columns on the screen
    for (int x = 0; x < COLUMNS; ++x) {
        
        // Calculate ray angle based on camera direction and field of view (FOV)
        double rayAngle = (cameraDir - FOV / 2.0) + ((double)x / (double)COLUMNS) * FOV;
        double cosRayAngle = cos(rayAngle);
        double sinRayAngle = sin(rayAngle);
        
        // Cast a ray for this column and store the results
        RaycastHit hit = cast_ray(cosRayAngle, sinRayAngle);
        distanceBuffer[x] = hit.perpWallDist;
        
        // Calculate wall height based on distance and field of view
        if (hit.perpWallDist > NEAR_PLANE) {
            double wallHeight = (double)ROWS / hit.perpWallDist * (ROWS / (2.0 * tan(FOV / 2)));
            
            // Check if wall height exceeds screen height
            if (wallHeight > HEIGHT) {
                wallHeight = HEIGHT; // Adjust to screen height
            }
            wallHeights[x] = wallHeight;
        } else {
            wallHeights[x] = 0.0;  // No wall visible for very close distances
        }
    }
}
