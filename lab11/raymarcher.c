#include <stdio.h>
#include "gfx.h"

typedef struct {
    int r;
    int g;
    int b;
} color;
typedef struct {
    double x;
    double y;
    double z;
} vec3;


color Color(int r, int g, int b);
//void setScreenColor(color colors[], int l);
//void writeScreen(point p[], int l);

int main(void) {
    // dumb graphics setup
    int width = 500;
    int height = 500;
    char *name = "Raymarcher";
    gfx_open(width, height, name);
    // 
    int numPoints = width * height;
    color c[numPoints];
    int i;
    for (i = 0; i < numPoints; i += 1) {
        c[i] = Color(0, 255, 0);
    }
    
    writeScreen(c, numPoints, width);

    return 0;
}
color Color(int r, int g, int b) {
    color t;
    t.r = r;
    t.g = g;
    t.b = b;
    return t;
}
vec3 Vec3(double x, double y, double z) {
    vec3 t;
    t.x = x;
    t.y = y;
    t.z = z;
    return t;
}
void writeScreen(color c[], int l, int width) {
    int i;
    for (i = 0; i < l; i += 1) {
        gfx_color(c[i].r, c[i].g, c[i].b);
        int x = i % width;
        int y = i / width;
        gfx_point(x, y);
    }
}