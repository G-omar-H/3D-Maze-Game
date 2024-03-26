#ifndef MAP_H
#define MAP_H
#include <stdlib.h> 
#include <stdio.h>


#define ROWS 80
#define COLUMNS 80

// Declare `map` as a fixed-size 2D array
extern const char map[ROWS][COLUMNS];
void print_map();

#endif

