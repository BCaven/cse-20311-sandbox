#include <stdio.h>
#include "gfx.h"

typedef struct {
    int r;
    int g;
    int b;
    int t;
} color;
color Color(int r, int g, int b);
void draw(int x, int y, int brush, int currentColor, color canvas[], int width);
void writeScreen(color paint[], int l, int width);

int main(void) {
    int width = 500;
    int height = 500;
    char *name = "Paint";
    gfx_open(width, height, name);
    int numPoints = width * height;
    color paint[numPoints]; // 0 = black, 1 = red, 2 = green, 3 = blue, 4 = eraser
    int i;
    for (i = 0; i < numPoints; i += 1) {~
        paint[i] = Color(255, 255, 255);
    }
    color currentColor;
    
    char c = 1;
    while (1 == 1) {
        writeScreen(paint, numPoints, width);

        
        
        c = gfx_wait();
        if (c == 1) {
            int x = gfx_xpos();
            int y = gfx_ypos();
            draw(x, y, 5, currentColor, paint, width);
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
        } else if (c == 'q') {
            return 0;
        }
                
        gfx_clear();
        
    }

}

color Color(int r, int g, int b) {
    color c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.t = 1;
    return c;
}
void draw(int x, int y, int brush, color currentColor, color canvas[], int width) {
    canvas[x + (y * width)] = currentColor;
    int i, j, nX, nY;
    nX = x;
    nY = y;
    for (i = 0; i < brush; i += 1) {
        for (j = 0; j < brush; j += 1) {
            nX = x + i - (brush / 2);
            nY = y + j - (brush / 2);
            canvas[nX + (nY * width)] = currentColor;
        }
    }


}

void writeScreen(int paint[], int l, int width) {
    int i;
    for (i = 0; i < l; i += 1) {
        int x = i % width;
        int y = i / width;
        gfx_color(paint[i].r, paint[i].g, paint[i].b);
        gfx_point(x, y);
    }
}