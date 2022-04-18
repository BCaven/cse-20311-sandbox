#include <stdio.h>
#include <math.h>
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
typedef struct {
    vec3 origin;
    vec3 dir;
} ray;


color Color(int r, int g, int b);
ray Ray(vec3 origin, vec3 dir);
vec3 Vec3(double x, double y, double z);
vec3 calcPixelRay(int x, int y, int width, int height);
void writeScreen(color c[], int l, int width);
color getRayColor(ray r);
double length(vec3 v);
double getSceneDist(vec3 v);
void addScl(vec3 *a, vec3 b, double k);


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
        int x = i % width;
        int y = i / width;
        vec3 dir, cam;
        ray r; 
        color rc;
        dir = calcPixelRay(x, y, width, height);
        cam = Vec3(0, 0, -5.0);
        r = Ray(cam, dir);
        rc = getRayColor(r);
        c[i] = rc;
    }
    
    writeScreen(c, numPoints, width);




    gfx_wait(); // dumb gfx stupidity
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
ray Ray(vec3 origin, vec3 dir) {
    ray t;
    t.origin = origin;
    t.dir = dir;
    return t;
}

color getRayColor(ray r) {
    int MAXSTEPS = 100;
    double EPS = 0.001;
    vec3 samplePoint;
    samplePoint = r.origin;
    int i;
    for (i = 0; i < MAXSTEPS; i += 1) {
        double d = getSceneDist(samplePoint);
        if (EPS > d) {
            return Color(255, 255, 255);
        }
        addScl(&samplePoint, r.dir, d);        
    }
    return Color(0, 0, 0);
}
void addScl(vec3 *a, vec3 b, double k) {
    a->x += b.x * k;
    a->y += b.y * k;
    a->z += b.z * k;
}
double getSceneDist(vec3 v) {
    return length(v) - 1;
}
double length(vec3 v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}
vec3 calcPixelRay(int x, int y, int width, int height) {
    vec3 t;
    t.x = ((double) x - (width / 2)) / (width / 2);
    t.y = ((double) y - (height / 2)) / (height / 2);
    t.z = 1;
    double l = length(t);
    t.x /= l;
    t.y /= l;
    t.z /= l;
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
