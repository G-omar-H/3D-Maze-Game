#ifndef RAYCASTING_H_INCLUDED
#define RAYCASTING_H_INCLUDED

#include "main.h"
#include <stdio.h>
#include <math.h>  // for trigonometric functions
#include "map.h"  // Include map definition from map.c (adjust path if needed)
#include "wall_types.h"  // Include wall type definitions (adjust path if needed)


typedef struct {
    double perpWallDist;  // Perpendicular distance from camera to wall
    WallType wallHitContent;  // Type of wall hit (e.g., STONE, BRICK)
} RaycastHit;

// Function prototype for casting a ray in a specific direction and returning hit information
RaycastHit cast_ray(double cosRayAngle, double sinRayAngle);

// Function prototype for performing raycasting across all screen columns and storing results in buffers
void raycast_walls(double* distanceBuffer, double* wallHeights);

#endif /* RAYCASTING_H_INCLUDED */
