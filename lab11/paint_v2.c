#include <stdio.h>
#include <math.h>
#include "gfx.h"

typedef struct {
    int r;
    int g;
    int b;
    int t;
} color;
color Color(int r, int g, int b, int t);
void paintScreen(char paint[], int l, int width, color colors[]);
void drawDot(int x, int y, int brush, int currentColor, char canvas[], int width);
double distance(int x1, int y1, int x2, int y2);
void drawLine(int x1, int y1, int x2, int y2, int currentColor, int brush, char canvas[], int width);
void writeColors(color colors[]);

int main(void) {
    int width = 500;
    int height = 500;
    char *name = "Paint 2V";
    gfx_open(width, height, name);
    int numPoints = width * height;
    char paint[numPoints]; // 0 = black, 1 = red, 2 = green, 3 = blue, 4 = eraser
    int i;
    for (i = 0; i < numPoints; i += 1) {
        paint[i] = '-';
    }
    int mode = 0;
    color colors[10];
    writeColors(colors);
    int currentColor = 0;
    int clicked = 1;
    int fx = 0;
    int fy = 0;
    while (1) {
        
        if (gfx_event_waiting()) {
            char c = gfx_wait();
            if (mode == 0) { // view
                if (c == '1') { // dots
                    mode = 1;
                } else if (c == '2') { // lines
                    mode = 2;
                } else if (c == '3') { // save
                    mode = 3;
                } else if (c == 'q') {
                    printf("\n");
                    return 0;
                }
            } else if (mode == 1) { // draw dots
                if (c == 1) { // mouse press
                    drawDot(gfx_xpos(), gfx_ypos(), 10, currentColor, paint, width);
                } else if (c >= '0' && c <= '9') { // all characters 1-9
                    currentColor = c - 1;
                    if (currentColor < '0') {
                        currentColor = '9';
                    }


                } else if (c == 'q') {
                    mode = 0;
                }
            } else if (mode == 2) { // draw lines
                if (c == 1) { // mouse press
                    clicked *= -1; // binary switch: -1 or 1 -> -1 is depressed, 1 is not pressed
                    if (clicked == -1) {
                        fx = gfx_xpos();
                        fy = gfx_ypos();
                    } else if (clicked == 1) {
                        drawLine(fx, fy, gfx_xpos(), gfx_ypos(), currentColor, 10, paint, width);
                    }

                } else if (c >= '0' && c <= '9') { // all characters 1-9
                    currentColor = c - 1;
                    if (currentColor < '0') {
                        currentColor = '9';
                    }

                } else if (c == 'q') {
                    mode = 0;
                }
            } else if (mode == 3) { // erase
                if (c == 'q') {
                    mode = 0;
                }

            }
            gfx_clear();
        }
        // what to print for each mode:
        if (mode == 0) {
            gfx_color(100, 100, 100);
            gfx_text(10, 10, "paint program - select a mode by pressing [1] [2] or [3]");
        
        } else if (mode == 1) {
            gfx_color(100, 100, 100);
            gfx_text(10, 10, "paint program - dot drawing mode - select a color by pressing 1-9, press the mouse to draw");

        } else if (mode == 2) {
            gfx_color(100, 100, 100);
            gfx_text(10, 10, "paint program - line drawing mode - select a color by pressing 1-9, press the mouse to draw");

        } else if (mode == 3) {
            gfx_color(100, 100, 100);
            gfx_text(10, 10, "paint program - file mode - not implemented yet");

        }
        paintScreen(paint, numPoints, width, colors);
    }

    
    
    return 0;
}

// constructors
color Color(int r, int g, int b, int t) {
    color c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.t = t;
    return c;
}

void writeColors(color colors[10]) { // hard-coding each color for now because this is a pain
    colors[0] = Color(0, 0, 0, 1); // r, g, b, transparency
    colors[1] = Color(100, 100, 100, 1);
    colors[2] = Color(200, 200, 200, 1);
    colors[3] = Color(255, 255, 255, 1);
    colors[4] = Color(255, 000, 000, 1);
    colors[5] = Color(000, 255, 000, 1);
    colors[6] = Color(000, 000, 255, 1);
    colors[7] = Color(255, 255, 000, 1);
    colors[8] = Color(000, 255, 255, 1);
    colors[9] = Color(255, 000, 255, 1);
}

// displaying the screen

void paintScreen(char paint[], int l, int width, color colors[]) {
    int i;
    for (i = 0; i < l; i += 1) {
        int x = i % width;
        int y = i / width;
        if (paint[i] != '-') {
            color c = colors[paint[i] - '0'];
            gfx_color(c.r, c.g, c.b);
            gfx_point(x, y);
        }
    }
}

//void writeFile(char *name, ) // doing this if I have time

// system 1: dot painting

void drawDot(int x, int y, int brush, int currentColor, char canvas[], int width) {
    int i, j, nX, nY;
    nX = x;
    nY = y;
    for (i = 0; i < brush; i += 1) {
        for (j = 0; j < brush; j += 1) {
            nX = x + i - (brush / 2);
            nY = y + j - (brush / 2);
            canvas[nX + (nY * width)] = currentColor + '0';
            printf("%c", currentColor);
        }
    }
}

// system 2: line painting

double distance(int x1, int y1, int x2, int y2) {
    return sqrt( ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) );
}
void drawLine(int x1, int y1, int x2, int y2, int currentColor, int brush, char canvas[], int width) {
    double i, j;
    int nX, nY;
    nX = x1;
    nY = y1;
    
    double d = distance(x1, y1, x2, y2);
    double stepx = (x2 - x1 * 1) / d;
    double stepy = (y2 - y1 * 1) / d;
    for (i = x1; i < x2; i += stepx) {
        for (j = y1; j < y2; j += stepy) {
            drawDot(i, j, brush/2, currentColor, canvas, width);
        }
    }
    
}
