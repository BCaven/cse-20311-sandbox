/*
    @author: John Blake Caven
    @name: projfunc.h
*/
#include <stdio.h>
#include <math.h>
#include "gfx.h"

typedef struct {
    int r;
    int g;
    int b;
    double t;
} color;
color Color(int r, int g, int b);
color merge(color a, color b);
void draw(int x1, int y1, int x2, int y2, int brush, color currentColor, color canvas[], int width);
void writeScreen(color paint[], int l, int width);

