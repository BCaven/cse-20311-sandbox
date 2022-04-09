/*
    @author: John Blake Caven
    @date: 4-8-22
    @name: symfunc.c

    Lab 9 : Part 1
*/
#include "symfunc.h"
#include "gfx.h"

void drawSquare(int x, int y, int SIZE) {
    gfx_line(x - (SIZE/2), y - (SIZE/2), x + (SIZE/2), y - (SIZE/2)); // top edge
    gfx_line(x - (SIZE/2), y - (SIZE/2), x - (SIZE/2), y + (SIZE/2)); // left edge
    gfx_line(x + (SIZE/2), y - (SIZE/2), x + (SIZE/2), y + (SIZE/2));
    gfx_line(x + (SIZE/2), y + (SIZE/2), x - (SIZE/2), y + (SIZE/2));
}
void drawTriangle(int x, int y, int SIZE) {
    gfx_line(x, y - (SIZE/3), x + (SIZE/3), y + (SIZE/3));
    gfx_line(x + (SIZE/3), y + (SIZE/3), x - (SIZE/3), y + (SIZE/3));
    gfx_line(x - (SIZE/3), y + (SIZE/3), x, y - (SIZE/3));
}
void drawPolygon(int x, int y, int SIZE, int sides) {
    double i;
    for (i = 0; i < 2*PI; i += (2*(PI))/sides) {
        double oldI = i - (2*PI)/sides;
        gfx_line(x + SIZE*(cos(i)/2), y + SIZE*(sin(i)/2), x + SIZE*(cos(oldI)/2), y + SIZE * (sin(oldI))/2);

    }
}

point getMouse() {
    point x;
    x.x = gfx_xpos();
    x.y = gfx_ypos();
    //printf("x: %d y: %d\n", x.x, x.y);
    return x;
}