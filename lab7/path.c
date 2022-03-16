/*
    @author: John Blake Caven
    @name: path.c
    @date: 3-16-22

    Lab 7: Part 1

*/

/*
structs are fun

need to make file scraper

use pointers! they will make your life easier



*/



#include <stdio.h>

int main(void) {
    typedef struct {
        int x;
        int y;
    } point;

    point a;
    a.x = 1;
    a.y = 2;

    printf("x: %d y: %d\n", a.x, a.y);


    return 0;
}