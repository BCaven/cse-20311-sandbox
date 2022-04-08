/*
    @author: John Blake Caven
    @date: 4-8-22
    @name: symbol.c

    Lab 9 : Part 1
*/
#include <stdio.h>
#include "gfx.h"

typedef struct {
    int x;
    int y;
} point;
point getMouse();

int main(void) {
    int width, height;
    char *name = "symbol";
    gfx_open(width, height, name);
    gfx_clear_color(200, 100, 100);
    gfx_clear();
    point mouse;
    mouse.x = width/2;
    mouse.y = height/2;
    while (1) {
        int in = gfx_event_waiting();
        if (in) {
            mouse = getMouse();
        }

        gfx_color((1.0 * mouse.x/width) * 250, (1.0 * mouse.y/height) * 250, ((1.0 * mouse.x + mouse.y) / (width + height)) * 250);
        gfx_circle(mouse.x, mouse.y, 10);
        
    }

    return 0;
}

point getMouse() {
    point x;
    x.x = gfx_xpos();
    x.y = gfx_ypos();
    printf("x: %d y: %d\n", x.x, x.y);
    return x;
}