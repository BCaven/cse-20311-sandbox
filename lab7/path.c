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

/*
I hate C files. I hate them so much.

*/

#include "pathfunc.h"
#include <stdio.h>

int main(void) {
    char fname[30];
    printf("what is the name of the file? ");
    scanf("%s", &fname);
    // get the file
    FILE *f = fopen(fname, "r");
    getFileData(f);
    
    /*
    int i;
    for (i = 0; i < 30; i+=1) {
        printf("%lf %lf\n", p[i].x, p[i].y);
    }
    */

    return 0;
}
