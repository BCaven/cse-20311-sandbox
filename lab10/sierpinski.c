#include <stdio.h>
#include "gfx.h"
#include <math.h>

void triangle(int topX, int topY, int size);
void sierpinski(int x, int y, int n, int size, int oX, int iX, int mN);
void sierpinski2(int x, int y, int size);
void sierpinskiClass( int x1, int y1, int x2, int y2, int x3, int y3 );
int main(void) {
    int width = 500;
    int height = 500;
    char *name = "Sierpinski";
    gfx_open(width, height, name);
    gfx_clear();
    int x = 100;
    int y = 100;
    //sierpinski(x, y, 10, 10, x, x, 10);
    //sierpinski2(200, 200, 100);
    //sierpinskiClass(300, 100, 400, 100, 350, 200);
    //gfx_wait();

    while (1) {
        
        char p = gfx_wait();
        if (p == '1') {
            //gfx_clear();
            gfx_color(255, 255, 255);
            sierpinskiClass(100, 100, 400, 100, 250, 300);        
        } else if (p == '2') {

        } else if (p == '3') {

        } else if (p == '4') {

        }       else if (p == 'q') {
            return 0;
        } else if (p == 'c') {
            gfx_clear();
        }
    }
    return 0;
}

void triangle(int topX, int topY, int size) {
    gfx_line(topX, topY, topX-size, topY+size);
    gfx_line(topX, topY, topX+size, topY+size);
    gfx_line(topX-size, topY+size, topX+size, topY+size);
    
}
void triangle2(int x1, int y1, int x2, int y2, int x3, int y3) {
    gfx_line(x1, y1, x2, y2);
    gfx_line(x2, y2, x3, y3);
    gfx_line(x3, y3, x1, y1);
}
void sierpinski(int x, int y, int n, int size, int oX, int iX, int mN) {
    //gfx_color(255, 255, 255);
    // make it in clumps of three
    // clump of three
/*
    if (n % 2 == 0) {
        if (x > oX) {
            oX = x+size;
        } else {
            oX = x-size;
        }
    }
    if (n == mN) {
        triangle(x, y, size);
        triangle(x-size, y+size, size);
        triangle(x+size, y+size, size);
        sierpinski(x-(size*2), y+(size*2), n-1, size, x-(size), iX, mN);
        sierpinski(x+(size*2), y+(size*2), n-1, size, x+(size), iX, mN);
    } else if (n > 0) {
        if (x == iX) {
            return;
        }
        triangle(x, y, size);
        triangle(x-size, y+size, size);
        triangle(x+size, y+size, size);
        printf("x: %d, iX: %d, oX %d\n", x, iX, oX);
        // check what positions to call
        if (oX == x+size) {
            sierpinski(x-(2*size));
        } else if (oX == x-size) {

        }
        
    }

*/
}

void sierpinski2(int x, int y, int size) {   
    triangle2(x, y, x-size, y+size, x+size, y+size);
    if ((x+size) - (x-size) < 2) {
        return;
    }

}
void sierpinskiClass( int x1, int y1, int x2, int y2, int x3, int y3 )
{
    // Base case. 
    if( abs(x2-x1) < 5 ) return;

    // Draw the triangle
    triangle2( x1, y1, x2, y2, x3, y3 );
    // Recursive calls
    sierpinskiClass( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
    sierpinskiClass( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
    sierpinskiClass( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
    
}
