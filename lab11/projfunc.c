/*
    @author: John Blake Caven
    @name: projfunc.c
*/
#include "projfunc.h"
#include "gfx.h"
#include <math.h>

color Color(int r, int g, int b) {
    color c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.t = .9;
    return c;
}
color merge(color a, color b) {
    color t;
    t.r = ((a.r*a.t) + (b.r*b.t)) / 2.0;
    t.g = ((a.g*a.t) + (b.g*b.t)) / 2.0;
    t.b = ((a.b*a.t) + (b.b*b.t)) / 2.0;
    t.t = (a.t + b.t) / 2.0;
    return t;
}
double dist(int x1, int y1, int x2, int y2) {
    return sqrt( ((x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1)) );
}
void draw(int x1, int y1, int x2, int y2, int brush, color currentColor, color canvas[], int width) {
    //canvas[x + (y * width)] = currentColor;
    int i, j, nX, nY;
    double c;
    double x = x1;
    double y = y1;
    nX = x;
    nY = y;
    double d = dist(x1, y1, x2, y2);
    double xstep = (x2 - x1) / d;
    double ystep = (y2 - y1) / d;
    //printf("x step: %lf y step: %lf\n", xstep, ystep);
    int s = 1;
    for (c = 0; c < d; c += s) { // only hit some spots
        x += xstep*s;
        y += ystep*s;
        for (i = 0; i < brush; i += 1) {
            for (j = 0; j < brush; j += 1) {
                nX = x + i - (brush / 2);
                nY = y + j - (brush / 2);
                color oldColor = canvas[nX + (nY * width)];
                canvas[nX + (nY * width)] = merge(oldColor, currentColor);
            }
        }
    }

}

void writeScreen(color paint[], int l, int width) {
    int i;
    for (i = 0; i < l; i += 1) {
        int x = i % width;
        int y = i / width;
        gfx_color(paint[i].r, paint[i].g, paint[i].b);
        gfx_point(x, y);
    }
}

void saveScreen(color paint[], int l, int width, FILE *f) {

}