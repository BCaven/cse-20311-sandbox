#include <stdio.h>
#include <math.h>
#include "gfx.h"
#define PI 3.1415926535
void shrinkingSquares(int x, int y, int size, int n);
void square(int x, int y, int size);
void spiralSquares(int x, int y, int size, double n);
void circularLace(int x, int y, int size, int petals, int n);
void snowFlake(int x, int y, int oldX, int oldY, int size, int petals, int n);
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int n);
void triangle(int x1, int y1, int x2, int y2, int x3, int y3);
int main(void) {
    int width = 1000;
    int height = 1000;
    char *name = "Fractals";
    gfx_open(width, height, name);
    char c = '0';
    while (1) {
        gfx_clear();
        if (c == '1') {

        } else if (c == '2') {
            shrinkingSquares(width/2, height/2, 500, 6);
        } else if (c == '3') {
            spiralSquares(width/2, height/2, 1, 0);
        } else if (c == '4') {
            circularLace(width/2, height/2, 200, 6, 6);
        } else if (c == '5') {
            snowFlake(width/2, height/2, width/2, height/2, 300, 5, 6);
        } else if (c == '6') {

        } else if (c == '7') {

        } else if (c == 'q') {
            return 0;
        } else {
            
        }
        c = gfx_wait();
    }
}
void triangle(int x1, int y1, int x2, int y2, int x3, int y3) {

}
void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int n) {
    if( n < 0 ) {
        return;
    }

    // Draw the triangle
    triangle(x1, y1, x2, y2, x3, y3);
    // Recursive calls
    sierpinskiClass(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2, n-1);
    sierpinskiClass((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2, n-1);
    sierpinskiClass((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3, n-1);
    
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
    spiralSquares(x + (cos(n) * (size*2)), y + (sin(n) * (size*2)), size + (n/4), n+.5);
    
}
void circularLace(int x, int y, int size, int petals, int n) {
    if (n < 0) {
        return;
    }
    gfx_circle(x, y, size);
    double i;
    for (i = 0; i < 2*PI; i+= (2*PI)/petals) {
        int newX = x + (cos(i)*size);
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
        int newX = x + (sin(i)*size);
        int newY = y + (cos(i)*size);
        snowFlake(newX, newY, x, y, (1.5*size)/petals, petals, n-1);
    }
}