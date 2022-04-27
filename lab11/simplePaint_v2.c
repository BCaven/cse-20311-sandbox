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

int main(void) {
    /*
    FILE *f = fopen("image.txt", "r+");
    if (f == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    */
    int width = 500;
    int height = 500;
    char *name = "Paint";
    gfx_open(width, height, name);
    int numPoints = width * height;
    color paint[numPoints]; // these are defined later...
    int i;
    for (i = 0; i < numPoints; i += 1) {
        paint[i] = Color(255, 255, 255);
    }
    color currentColor;
    
    char c = 1;
    int clicked = -1;
    int x1, y1, x2, y2 = 0;
    while (1 == 1) {
        writeScreen(paint, numPoints, width);
        gfx_color(100, 100, 100);
        gfx_text(20, 10, "press 1-9 to change colors, press c to clear the screen, press q to quit");
        if (clicked == 1) {
            gfx_text(20, 20, "please press another point to draw the line");
        } else {
            gfx_text(20, 20, "press anywhere to begin drawing a line");
        }
        
        c = gfx_wait();  
        
        if (c == 1) {
            clicked *= -1;
            printf("clicked: %d\n", clicked);
            if (clicked == 1) {
                x1 = gfx_xpos();
                y1 = gfx_ypos();
                draw(x1, y1, x1+1, y1+1, 5, currentColor, paint, width);
                
            } else {
                x2 = gfx_xpos();
                y2 =gfx_ypos();
                draw(x1, y1, x2, y2, 5, currentColor, paint, width);
            }
        } else if (c == '1') {
            currentColor = Color(0, 0, 0);
        } else if (c == '2') {
            currentColor = Color(255, 0, 0);
        } else if (c == '3') {
            currentColor = Color(0, 255, 0);
        } else if (c == '4') {
            currentColor = Color(0, 0, 255);
        } else if (c == '5') {
            currentColor = Color(255, 255, 255);
        } else if (c == '6') {
            currentColor = Color(255, 0, 255);
        } else if (c == '7') {
            currentColor = Color(255, 255, 0);
        } else if (c == '8') {
            currentColor = Color(0, 255, 255);
        } else if (c == '9') {
            currentColor = Color(200, 200, 200);
        } else if (c == 'q') {
            return 0;
        } else if (c == 'c') {
            for (i = 0; i < numPoints; i += 1) {
                paint[i] = Color(255, 255, 255);
            }
        }
          
        //gfx_clear();
        
    }

}

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
    printf("x step: %lf y step: %lf\n", xstep, ystep);
    for (c = 0; c < d; c += 1) {
        x += xstep;
        y += ystep;
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