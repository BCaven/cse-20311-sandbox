/*
    @author: John Blake Caven
    @date: 4-9-22
    @name: bounce.c

    Lab 9 : Part 2

*/

#include <stdio.h>
#include "gfx.h"    // needed for graphics
#include <unistd.h> // needed for sleep function
#include <stdlib.h> // needed for rand function

// structs
typedef struct {
    int x;
    int y;
} point;
typedef struct {
    int r;
    int g;
    int b;
} color;
typedef struct {
    point pos;
    point vel;
    int r;
    color c;
} ball;
// ball functions
void updateBall(ball *a, int width, int height);
void updateBounce(ball *a, int width, int height);
void draw(ball a);
// constructors
color Color(int r, int g, int b);
ball Ball(int x, int y, int xVel, int yVel, int r, color c);
point getMouse();
int main(void) {
    int width = 500;
    int height = 400;
    color black = Color(50, 50, 50);
    color red   = Color(255, 50, 50);
    color green = Color(50, 255, 50);
    color blue  = Color(50, 50, 255);
    // now for the graphics setup
    char *name = "Bounce";
    gfx_open(width, height, name);
    gfx_clear();
    // ok, so we need to seed the random function, and tbh I dont really want to also import the time function because we dont care if it isnt truly random
    // instead I am going to use the memory location of width
    srand((unsigned int) &width); // I dont care that this throwws a warning... it works for this purpose.
    int maxVel = 10;
    ball b = Ball(width/2, height/2, (rand() % maxVel) - (maxVel/2), (rand() % maxVel) - (maxVel/2), 10, blue); // the first ball
    point mouse; // where the mouse is
    // the main draw loop
    while (1) {
        gfx_clear();
        int in = gfx_event_waiting(); // yes, I DID reuse my code from symbol.c
        char pressed = 0;
        if (in) {
            pressed = gfx_wait();
            mouse = getMouse();
        }
        if (pressed == 1) { // mouse1 pressed, blue square outline of SIZE
            b = Ball(mouse.x, mouse.y, (rand() % maxVel) - (maxVel/2), (rand() % maxVel) - (maxVel/2), 10, blue);

        } else if (pressed == 'q') {
            return 0;
        }
        updateBall(&b, width, height);
        draw(b);
        gfx_flush();
        usleep(10000);
    }
    return 0; // this will never get hit, but just in case :D
}
point getMouse() {
    point p;
    p.x = gfx_xpos();
    p.y = gfx_ypos();
    return p;
}
ball Ball(int x, int y, int xVel, int yVel, int r, color c) { // using these as constructors for the structs
    ball t;
    t.pos.x = x;
    t.pos.y = y;
    t.vel.x = xVel;
    t.vel.y = yVel;
    t.r = r;
    t.c = c;
    return t;
}
color Color(int r, int g, int b) { // hehe
    color t;
    t.r = r;
    t.g = g;
    t.b = b;
    return t;
}
void updateBall(ball *a, int width, int height) {
    a->pos.x += a->vel.x;
    a->pos.y += a->vel.y;
    updateBounce(a, width, height);
}
void updateBounce(ball *a, int width, int height) {
    int rW = width - a->r; // the width at which the ball "hits" the edge
    int rH = height -a->r; // making it easier to follow
    // since it is a circle which only collides into a rectangular wall, you can use rectangular collision boxes :D
    if (a->pos.x >= rW || a->pos.x <= a->r) { // hits the left or right wall
        a->vel.x *= -1;
    }
    if (a->pos.y >= rH || a->pos.y <= a->r) { // hits the top or bottom walls
        a->vel.y *= -1;
    }
    // the thing is, you have to catch the ball incase it overshoots so it does not get stuck in the wall
    if (a->pos.x < a->r) {
        a->pos.x = a->r; //+ 1; // making it one pixel away from the wall to ensure it does not stick <- this probably isnt needed
    } else if (a->pos.x > rW) {
        a->pos.x = rW;
    }
    if (a->pos.y < a->r) {
        a->pos.y = a->r;
    } else if (a->pos.y > rH) {
        a->pos.y = rH;
    }
}
void draw(ball a) {
    gfx_color(a.c.r, a.c.g, a.c.b);
    gfx_circle(a.pos.x, a.pos.y, a.r);
}