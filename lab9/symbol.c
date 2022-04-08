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
    int SIZE = 50;
    while (1) {
        int in = gfx_event_waiting();
        char pressed;
        if (in) {
            pressed = gfx_wait();
            mouse = getMouse();
        }
        if (pressed == 1) { // mouse1 pressed, blue square outline of SIZE
            gfx_line(mouse.x - (SIZE/2), mouse.y - (SIZE/2), mouse.x + (SIZE/2), mouse.y - (SIZE/2)); // top edge
            gfx_line(mouse.x - (SIZE/2), mouse.y - (SIZE/2), mouse.x - (SIZE/2), mouse.y + (SIZE/2)); // left edge
            gfx_line(mouse.x + (SIZE/2), mouse.y - (SIZE/2), mouse.x + (SIZE/2), mouse.y + (SIZE/2));
            gfx_line(mouse.x + (SIZE/2), mouse.y + (SIZE/2), mouse.x - (SIZE/2), mouse.y + (SIZE/2));
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