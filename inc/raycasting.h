#ifndef RAYCASTING_H_INCLUDED
#define RAYCASTING_H_INCLUDED

#include <stdio.h>
#include <math.h>  // for trigonometric functions
#include "../inc/map.h"  // Include map definition from map.c (adjust path if needed)
#include "../inc/wall_types.h"  // Include wall type definitions (adjust path if needed)


#define M_PI 3.14159265358979323846  // Define pi for raycasting calculations
#define FOV (M_PI / 3)  // Field of view angle
#define WIDTH 640  // Adjust screen width as needed
#define HEIGHT 480  // Adjust screen height as needed
#define NEAR_PLANE 0.1  // Distance of the nearest plane (prevents issues with walls at player position)

typedef struct {
    double perpWallDist;  // Perpendicular distance from camera to wall
    WallType wallHitContent;  // Type of wall hit (e.g., STONE, BRICK)
} RaycastHit;

// Function prototype for casting a ray in a specific direction and returning hit information
RaycastHit cast_ray(double rayAngle, double cosRayAngle, double sinRayAngle);

// Function prototype for performing raycasting across all screen columns and storing results in buffers
void raycast_walls(double* distanceBuffer, double* wallHeights);

#endif /* RAYCASTING_H_INCLUDED */
