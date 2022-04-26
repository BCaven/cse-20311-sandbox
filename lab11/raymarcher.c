#include <stdio.h>
#include <math.h>
#include "gfx.h"

/*
Things I need to do

store the geometry in a struct
pass that geometry to the lighting function
find the closest lighting point using the normal to the ray
then find the normal to the geometry using the geometry struct (and the point you found in the previous step)
use the dot product between the light and the normal you just found


what does a geometry struct look like?


option 1:
    series of faces <- this is gross and boring

option 2:
    math equations <- fuck this, also only gives things you can graph

option 3:
    combination of planes? (basically a piecewise function)

option 4:
    a bunch of simple shapes (circles/squares)
    merged together

    ^ this could work pretty easily for a struct
    and can use the fractal function to make a geometry.... ooooh

    lets do it with spheres because cubes are boring.
    each sphere: x center, y center, radius

    making it is going to be a pain.

    ugh I hate this.

*/
typedef struct {
    int x;
    int y;
    double r;
} sphere;

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
vec3 getNormal(vec3 v);
double dot(vec3 a, vec3 b);
vec3 calcPixelRay(int x, int y, int width, int height);
void writeScreen(color c[], int l, int width);
color getRayColor(ray r);
double length(vec3 v);
double getSceneDist(vec3 v, double r, sphere geometry[]);
void addScl(vec3 *a, vec3 b, double k);
color simpleLighting(vec3 normal, vec3 light);


int main(void) {
    // dumb graphics setup
    int width = 500;
    int height = 500;
    char *name = "Raymarcher";
    gfx_open(width, height, name);
    // 
    int numPoints = width * height;
    color c[numPoints];
    sphere geometry[2]; // Idk make this later
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
    double rot = 0;
    vec3 samplePoint;
    samplePoint = r.origin;
    int i;
    for (i = 0; i < MAXSTEPS; i += 1) {
        double d = getSceneDist(samplePoint, rot);
        if (EPS > d) {
            // but we want shading
            // use the tutorial online :D
            //vec3 normal;
            //normal = getNormal(samplePoint);
            //return Color(255/i, 255/i, 255/i);
            //return simpleLighting(samplePoint, Vec3(1, 1, 1)); // using a light that points directly out (or whatever)
            //return Color(255-(i*5), 255-(i*5), 255-(i*5));
            return Color(255, 255, 255); // no shading
        }
        addScl(&samplePoint, r.dir, d);   
        rot += 1;     
    }
    return Color(0, 0, 0);
}
void addScl(vec3 *a, vec3 b, double k) {
    a->x += b.x * k;
    a->y += b.y * k;
    a->z += b.z * k;
}
double getSceneDist(vec3 v, double r, sphere geometry[]) {
    // all of the shape gets drawn here...
    double dC = length(v); // distance to the center
    //printf("%lf %lf %lf\n", v.x, v.y, v.z);
    /*
    if (v.z < 1) {

        return length(v); // a ring? (a set of rings... why?)
    }
    

    return dC - 2;
    */
    double closest;
    int i;
    for (i = 0; i < )
    return length(v) - 3; // a circle of radius 1
}
double length(vec3 v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}
vec3 getNormal(vec3 v) {

}
double dot(vec3 a, vec3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
color simpleLighting(vec3 v, vec3 light) {
    // easiest would be seeing how closely the normal aligns with the light vector
    return Color(255, 255, 255); // temporary because how tf do normals work
    
    vec3 normal;
    normal = getNormal(v);
    double d = dot(normal, light) * -1.0;
    if (d > 0) {
        return Color(d * 10, d * 10, d * 10);
    } else {
        return Color(0, 0, 0);
    }
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
