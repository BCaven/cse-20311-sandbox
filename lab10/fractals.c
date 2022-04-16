#include <stdio.h>
#include <math.h>
#include "gfx.h"
#define PI 3.1415926535
typedef struct {
    int x;
    int y;
} point;
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int n);
void triangle(int x1, int y1, int x2, int y2, int x3, int y3);
void shrinkingSquares(int x, int y, int size, int n);
void square(int x, int y, int size);
void spiralSquares(int x, int y, int size, double n);
void circularLace(int x, int y, int size, int petals, int n);
void snowFlake(int x, int y, int oldX, int oldY, int size, int petals, int n);
void treeFractal(int x, int y, int branches, int size, double theta, int n);
void fernFractal(int x, int y, int branches, int size, double theta, int n, int tn);
void spiralFractal(int x, int y, int size, double n, double max);
point spiralHelper(int x, int y, int size, double theta);
void drawSpiral(int x, int y, double size, double maxTheta, int maxSize);
void drawConstrainedSpiral(int xc, int yc, double maxR, double maxTheta, double theta, double startTheta);
int main(void) {
    int width = 500;
    int height = 500;
    char *name = "Fractals";
    gfx_open(width, height, name);
    char c = '0';
    while (1) {
        gfx_clear();
        gfx_text(10, 10, "Fractals 1-7 work. I am still working on Fractal 8.");
        if (c == '1') {
            sierpinski(width/10, height/10, (.9)*width, height/10, width/2, height * (.9), 7);
        } else if (c == '2') {
            shrinkingSquares(width/2, height/2, width/2, 6);
        } else if (c == '3') {
            spiralSquares(width/2, height/2, 1, 0);
        } else if (c == '4') {
            circularLace(width/2, height/2, width/4, 6, 6);
        } else if (c == '5') {
            snowFlake(width/2, height/2, width/2, height/2, width/4, 5, 6);
        } else if (c == '6') {
            treeFractal(width/2, height * (.9), 2, width/6, 0, 10);
        } else if (c == '7') {
            int n = 2;
            fernFractal(width/2, height * (.9), 2, width/6, 0, n, n);
        } else if (c == '8') {
            int size = 400;
            drawConstrainedSpiral(width/2, height/2, size, 6*PI, 0, 1);
            gfx_circle(width/2, height/2, size);
            //drawSpiral(width/2, height/2, size, 4*PI, size);
            //spiralFractal(width/2, height/2, 1, 0, 2*PI);
            //spiralFractal(width/2, height/2, 10, 0, 2*PI);
        } else if (c == 'q') {
            return 0;
        } else {
            
        }
        c = gfx_wait();
    }
}
void triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    gfx_line(x1, y1, x2, y2);
    gfx_line(x2, y2, x3, y3);
    gfx_line(x3, y3, x1, y1);
}
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int n) {
    if( n < 0 ) {
        return;
    }

    // draw the current
    triangle(x1, y1, x2, y2, x3, y3);
    // draw the inner triangles
    sierpinski(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2, n-1);
    sierpinski((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2, n-1);
    sierpinski((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3, n-1);
    
}
void square(int x, int y, int size) {
    gfx_line(x-(size/2), y-(size/2), x+(size/2), y-(size/2));
    gfx_line(x+(size/2), y-(size/2), x+(size/2), y+(size/2));
    gfx_line(x+(size/2), y+(size/2), x-(size/2), y+(size/2));
    gfx_line(x-(size/2), y+(size/2), x-(size/2), y-(size/2));
}
void shrinkingSquares(int x, int y, int size, int n) {
    int sep = (size/2) - (size/20);
    square(x, y, size);
    if (n > 0) { // could have done this with sin/cos and a for loop but this is so brain-dead and I dont feel like changing it because it works.
        shrinkingSquares(x-(size/2), y-(size/2), sep, n-1);
        shrinkingSquares(x-(size/2), y+(size/2), sep, n-1);
        shrinkingSquares(x+(size/2), y-(size/2), sep, n-1);
        shrinkingSquares(x+(size/2), y+(size/2), sep, n-1);
    }
}
void spiralSquares(int x, int y, int size, double n) {
    square(x, y, size);
    if (n > 40) {
        return;
    }
    spiralSquares(x + (cos(n) * (size*2)), y + (sin(n) * (size*2)), size + (n/4), n+.5); // Mmmmmmmm
}
void circularLace(int x, int y, int size, int petals, int n) {
    if (n < 0) {
        return;
    }
    gfx_circle(x, y, size);
    double i;
    for (i = 0; i < 2*PI; i+= (2*PI)/petals) {
        int newX = x + (cos(i)*size); // split these up so they were easier to edit
        int newY = y + (sin(i)*size);
        circularLace(newX, newY, (2*size)/petals, petals, n-1);
    }
}
void snowFlake(int x, int y, int oldX, int oldY, int size, int petals, int n) {
    if (n < 0) {
        return;
    }
    gfx_line(x, y, oldX, oldY);
    double i;
    for (i = 0; i < 2*PI; i+= (2*PI)/petals) {
        int newX = x + (sin(i)*size); // this was totally not copied from circularLace()
        int newY = y + (cos(i)*size);
        snowFlake(newX, newY, x, y, (1.5*size)/petals, petals, n-1);
    }
}
void treeFractal(int x, int y, int branches, int size, double theta, int n) {
    if (n < 0) {
        return;
    }
    int newX = x + (size*sin(theta)); // once again split out to be easier to edit
    int newY = y - (size*cos(theta));
    gfx_line(x, y, newX, newY);
    double i;
    for (i = -PI/4; i <= PI/4; i += PI/branches) {
        treeFractal(newX, newY, branches, size * (.75), theta + i, n-1);
    }
}
void fernFractal(int x, int y, int branches, int size, double theta, int n, int tn) {
    if (size < 1 || n < 0) {
        return;
    }    
    int newX = x + (size*sin(theta));
    int newY = y - (size*cos(theta));
    gfx_line(x, y, newX, newY);
    double i;
    for (i = -PI/4.0; i <= PI/4.0; i+= PI/4.0) {
        if (i == 0) {
            fernFractal(newX, newY, branches, size, theta, n-1, tn); // main stalks
        } else {
            fernFractal(newX, newY, branches, size/3, theta + i, tn, tn); // smaller leaflets
        }
    }

}
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
void drawConstrainedSpiral(int xc, int yc, double maxR, double maxTheta, double theta, double innerTheta) {
    double rCutoff = 0.01;
    double s = (maxR/maxTheta);
    if (theta > maxTheta || maxR < rCutoff) {
        printf("cutoff 1\n");
        return;
    }
    if (innerTheta > maxTheta) {
        printf("Cutoff 3\n");
        printf("inner theta: %lf max theta: %lf\n", innerTheta, maxTheta);
        return;
    }
    if ((s*theta) > maxR) {
        printf("cutoff 2\n");
        return;
    }
    int nextX = xc + ((int) ((s*innerTheta) * (cos(innerTheta))));
    int nextY = yc + ((int) ((s*innerTheta) * (sin(innerTheta))));
    double r = distance(nextX, nextY, xc + ((s*(innerTheta-(PI/12))) * (cos((innerTheta-(PI/12))))), yc + ((s*(innerTheta-(PI/12))) * (sin((innerTheta-(PI/12))))))/2;
    gfx_point(nextX, nextY);
    printf("x: %d, y: %d\n", nextX, nextY);
    //drawConstrainedSpiral(nextX, nextY, r, maxTheta, theta + (PI/12), theta); // inner spirals
    drawConstrainedSpiral(nextX, nextY, r, maxTheta, theta, innerTheta + (PI/12)); // inner spirals
    nextX = xc + ((int) ((s*theta) * (cos(theta))));
    nextY = yc + ((int) ((s*theta) * (sin(theta))));
    gfx_point(nextX, nextY);
    drawConstrainedSpiral(xc, yc, maxR, maxTheta, theta + (PI/12), 0); // main spiral
    //drawConstrainedSpiral(nextX, nextY, r, maxTheta, startTheta + (PI/12), theta);
    //drawConstrainedSpiral(nextX, nextY, r, maxTheta, theta + (PI/12) - startTheta, 0);   
     
}
