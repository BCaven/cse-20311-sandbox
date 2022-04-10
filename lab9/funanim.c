/*
    @author: John Blake Caven
    @date: 4-9-22
    @name: funanim.c

    Lab 9 : Part 3

    This is good enough for now
*/

#include <stdio.h>
#include "gfx.h"
#include <math.h>
#define PI 3.14159

void rotatingCircle(int t, int rC, int rR,  int width, int height);
double fun_lines(double t, int x, int y, int r, int n, int d);
double drawPolygon(int x, int y, int SIZE, int sides, double t, int d); // yes, I am reusing this from part 1 - with some modifications

int main(void) {
    int t = 0;
    int dt = 1;
    int d = 1;
    double rt = 0; // rotation of the lines
    double rp = 0; // rotation of the polygon
    int width = 500;
    int height = 500;

    // graphics setup
    char *name = "Fun Animation";
    gfx_open(width, height, name);
    gfx_clear();
    

    while (1) {
        gfx_clear();
        t+=dt;
        int in = gfx_event_waiting(); // yes, I DID reuse my code from symbol.c (again)
        char pressed = 0;
        if (in) {
            pressed = gfx_wait();
        }
        if (pressed == 'a') {// LEFT ARROW KEY
            dt = -1;
        } else if (pressed == 'd') { // RIGHT ARROW KEY
            dt = 1;
        } else if (pressed == 's') {
            dt = 0;
        } else if (pressed == 'q') {
            return 0;
        }
        gfx_color(100, 100, 100);
        gfx_text(10, 10, "use 'a' and 'd' to change the direction of the animation");
        gfx_color(255, 0, 0);
        rotatingCircle(t, 50, 100, width, height);
        gfx_color(0, 255, 0);
        rotatingCircle(-t/2, 20, 30, width, height);
        gfx_color(100, 100, 255);
        
        rt = fun_lines(rt, 200, 200, 100, 8, d * dt);
        gfx_color(255, 0, 255);
        rp = drawPolygon(width/2, height/2, 100, 5, rp, d * dt);
        //rp = drawPolygon(width/2, height/2, 20, ((int) (rp * 1000)) % 6 + 3, rp, d * dt);
        //drawPolygon(300, 300, 40, ((int) (rp * 1000)) % 6 + 3, 1, 1);
        //printf("%d\n", ((int) (rp * 1000)) % 6 + 3);
        //printf("%lf\n", rp * 1000);
        //printf("%d\n", (int) (rp * 1000));
        if (rt < 0.5) {
            d *= -1;
            rt = .5;
        } else if (rt > 1) {
            d *= -1;
            rt = 1;
        }
        gfx_flush();
        usleep(100000);
    }
    return 0;
}

void rotatingCircle(int t, int rC, int rR,  int width, int height) {
    //gfx_color(255, 100, 100);
    gfx_circle((width/2) + rR*cos(t/(2*PI)), (height/2) + rR*sin(t/(2*PI)), rC);
}
double fun_lines(double t, int x, int y, int r, int n, int d) {
    double i;
    for (i = 0; i < 2*PI; i+= (2.0*PI) / n) {
        gfx_line(x, y, x + r*(cos(i + (2*PI)/t)), y + r*(sin(i + (2*PI)/t)));
        gfx_circle(x + r*(cos(i + (2*PI)/t)), y + r*(sin(i + (2*PI)/t)), 10);
    }
    if (d == 1) {
        return t+.01;
    } else {
        return t-=.01;
    }
}
double drawPolygon(int x, int y, int SIZE, int sides, double t, int d) {
    double i;
    for (i = 0; i < 2*PI; i += (2*(PI))/sides) {
        double oldI = i - (2*PI)/sides;
        gfx_line(x + SIZE*(cos(i+ (2*PI)/t)/2), y + SIZE*(sin(i+ (2*PI)/t)/2), x + SIZE*(cos(oldI+ (2*PI)/t)/2), y + SIZE * (sin(oldI+ (2*PI)/t))/2);

    }
    if (d == 1) {
        return t+.001;
    } else {
        return t-=.001;
    }
}