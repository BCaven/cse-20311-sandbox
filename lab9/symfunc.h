/*
    @author: John Blake Caven
    @date: 4-8-22
    @name: symfunc.h

    Lab 9 : Part 1
*/
#define PI 3.14159
#include <stdio.h>
#include <math.h>
#include "gfx.h"

typedef struct {
    int x;
    int y;
} point;
point getMouse();
void drawSquare(int x, int y, int SIZE);
void drawTriangle(int x, int y, int SIZE);
void drawPolygon(int x, int y, int SIZE, int sides);
