#include <stdio.h>
#include "gfx.h"

typedef struct {
    int r;
    int g;
    int b;
    int t;
} color;
// color functions
color Color(int r, int g, int b, int t);
color combineColors(color a, color b);

// layer functions because c is a pain
void makeLayer(color layer[], int l);

// drawing functions
void drawColor(color c, color layer[], int width);

// UI elements
void filledRect(int x, int y, int w, int h);
void colorPicker(int width);

// screen shenanigans
void writeScreen(color c[], color buffer[], int l);
void writeBuffer(color buffer[], int l, int width);


int main(void) {
    int width = 500;
    int height = 500;
    char *name = "Paint";
    gfx_open(width, height, name);
    int numPoints = width * height;
    color layer1[numPoints]; // 5 layers, each layer has a point for every spot on the screen
    color buffer[numPoints];
    color currentColor;
    currentColor = Color(255, 0, 0, 1);
    while (1 == 1) {
        gfx_color(255, 0, 0);
        gfx_circle(10, 10, 10);
        filledRect(10, 10, 10, 10);
        
        if (gfx_event_waiting()) {
            char c = gfx_wait();
            if (c == 1) {
                drawColor(currentColor, layer1, width);
            } else if (c == 'q') {
                return 0;
            }

        } else {
            colorPicker(width);



        }
        writeScreen(layer1, buffer, numPoints);
        writeBuffer(buffer, numPoints, width);
        gfx_wait();
        return 0;
    }

    return 0;
}
// color functions
color Color(int r, int g, int b, int t) {
    color c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.t = t;
    return c;
}

color combineColors(color a, color b) {
    if (b.t == 1) { // if the new color is completely opaque it overwrites the other color
        return b;
    }
    color c;
    c.r = ((a.r * a.t) + (b.r * b.t)) / 2;
    c.g = ((a.g * a.t) + (b.g * b.t)) / 2;
    c.b = ((a.b * a.t) + (b.b * b.t)) / 2;
    return c;

}
// layer functions
void makeLayer(color layer[], int l) {
    int i;
    for (i = 0; i < l; i += 1) {
        layer[i] = Color(255, 255, 255, 1);
    }
}

// drawing functions
void drawColor(color c, color layer[], int width) {
    int x = gfx_xpos();
    int y = gfx_ypos();
    layer[x + (y*width)] = c;
}

// UI elements
void filledRect(int x, int y, int w, int h) {
    int i;
    for (i = 0; i < w; i += 1) {
        gfx_line(x + i, y, x + i, y + h);
    }
}

void colorPicker(int width) {
    int colors[10][3] = {
        {0, 0, 0},          // black
        {100, 100, 100},    // grey
        {200, 200, 200},    // light-grey
        {255, 255, 255},    // white
        {255, 0, 0},        // red
        {0, 255, 0},        // green
        {0, 0, 255},        // blue
        {255, 255, 0},      // red/green
        {255, 0, 255},      // red/blue
        {0, 255, 255},      // green/blue  
    };
    int i;
    for (i = 0; i < width; i += width/10) {
        int c = i / (10 / width);
        gfx_color(colors[c][0], colors[c][1], colors[c][2]);
        filledRect(i, 0, 10/width, 10/width);
    }
}

// screen functions
void writeScreen(color c[], color buffer[], int l) {
    int i;
    for (i = 0; i < l; i += 1) {
        // add the new layer
        color n = combineColors(buffer[i], c[i]);
        buffer[i] = n;
    }
}
void writeBuffer(color buffer[], int l, int width) {
    int i;
    for (i = 0; i < l; i += 1) {
        gfx_color(buffer[i].r, buffer[i].g, buffer[i].b);
        gfx_point(i % width, i / width);
    }
}