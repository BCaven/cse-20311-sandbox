/*
    @author: John Blake Caven
    @name: pathfunc.h
    @date: 3-16-22

    Lab 7: Part 1

*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
/*
Functions I need:
getDistance(point1, point2);
displayTable(*arrayOfPoints, int lenOfArray); -> ended up merging this with the collect data
*/

typedef struct {
        float x;
        float y;
} point; // having fun
float getDistance(point a, point b);
void getFileData(FILE *f);