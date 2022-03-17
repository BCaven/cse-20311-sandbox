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