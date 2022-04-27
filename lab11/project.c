/*
    @author: John Blake Caven
    @name: project.c

*/

#include "projfunc.h"
#include "gfx.h"

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
            //printf("clicked: %d\n", clicked);
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
