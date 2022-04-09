/*
    @author: John Blake Caven
    @date: 4-8-22
    @name: symbol.c

    Lab 9 : Part 1
*/
//#include "symfunc.h" // ignore this...
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

int main(void) {
    int width, height;
    width = 400;
    height = 400;
    char *name = "symbol";
    gfx_open(width, height, name);
    //gfx_clear_color(200, 100, 100);
    gfx_clear();
    point mouse;
    mouse.x = width/2;
    mouse.y = height/2;
    int SIZE = 50;
    while (1) {
        int in = gfx_event_waiting();
        char pressed = 0;
        if (in) {
            pressed = gfx_wait();
            mouse = getMouse();
        }
        if (pressed == 1) { // mouse1 pressed, blue square outline of SIZE
            gfx_color(0, 0, 255);
            drawSquare(mouse.x, mouse.y, SIZE);
        } else if (pressed == 'c') { // 'c' pressed, white circle
            gfx_color(255, 255, 255);
            gfx_circle(mouse.x, mouse.y, SIZE/2);
        } else if (pressed == 't') { // green triangle around cursor
            gfx_color(0, 255, 0);
            drawTriangle(mouse.x, mouse.y, SIZE);
        } else if (pressed >= '3' && pressed <= '9') { // regular sided polygons
            // ugh these are annoying
            //gfx_color(200, 200, 200);
            //gfx_circle(mouse.x, mouse.y, SIZE/2); // drawing the circle for reference
            gfx_color(128, 0, 128);
            drawPolygon(mouse.x, mouse.y, SIZE, pressed - '0');


        } else if (pressed == 27) {
            gfx_clear();
        } else if (pressed == 'q') {
            return 0;
        }
        //gfx_color((1.0 * mouse.x/width) * 250, (1.0 * mouse.y/height) * 250, ((1.0 * mouse.x + mouse.y) / (width + height)) * 250);
        //gfx_circle(mouse.x, mouse.y, 10);
        
    }
    return 0;
}
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