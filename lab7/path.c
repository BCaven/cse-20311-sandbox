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



#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
/*
Functions I need:
getDistance(point1, point2);
displayTable(*arrayOfPoints, int lenOfArray);
*/

typedef struct {
        double x;
        double y;
} point; // having fun
double getDistance(point a, point b);
void displayTable(point p[30]);    
void getFileData(FILE *f, point *arrayOfPoints);

int main(void) {
    char fname[30];
    printf("what is the name of the file? ");
    scanf("%s", &fname);
    // get the file
    FILE *f = fopen(fname, "r");
    point *points;
    getFileData(f, points);
    point a;
    a.x = 10;
    a.y = 5;
    printf("%d %d\n", a.x, a.y);

    return 0;
}

double getDistance(point a, point b) {
    return 0.0;
    //return sqrt(((b.x-a.x)*(b.x-a.x)) + ((b.y-a.y)*(b.y-a.y))); // whooo - standard distance formula
}
void displayTable(point p[30]) {
    int i;
    for (i = 0; i < 30; i+=1) { // print the points

    }
}
void getFileData(FILE *f, point *arrayOfPoints) { // alright, we can iterate through the entire file
    char c = fgetc(f); // assuming the file has already been assigned
    /*
    so, we are going through the individual characters, which means we have to harvest numbers
    we know that the maximum number of characters is 3: i.e. for -99
    so we can create a temp catch that waits until it hits a space
    */
    char temp[4] = {'0', '0', '0', '0'}; // temp[3] is reserved for decimal places
    char current = 'x'; // what value in that point we are writing to
    int p = 0; // what point we are currently writing to
    int pt = 2; // where we are in the temp array
    point tempPoints[30];
    while (c != EOF) {
        if (c != ' ' && c != '\n') {
            printf("%c\n", c);
            if (pt >= 0) {
                if (c == '.') {
                    c = fgetc(f);
                    printf("\nCurrent C: %c\n", c);
                    temp[3] = c;
                } if (c == '-') {
                    temp[0] = c;

                } else {
                    temp[pt] = c;
                    pt-=1; // this should never get below 0, but we will check anyways
            
                }
            }
            printf("Temp: %s\n", temp);
        } else {
            double num;
            // so, we wrote the char array so it will look something like
            /*
            {'0', '0', '1', '0'}
            up to
            {'-', '9', '9', '9'}
            */
            printf("Temp[1] %d Temp[2] %d Temp[3] %d\n", temp[1]-'0', temp[2]-'0', temp[3]-'0');
            num = ((10 * (temp[1]-'0')) + (temp[2]-'0')) + ((temp[3]-'0') / (10.0));
            // then check for the negative
            if (temp[0] == '-') {
                num = num * -1;
            }
            if (current == 'x') {
                printf("\nadding %d to x\n", num);
                tempPoints[p].x = num;
                current = 'y';
            } else {
                printf("\nadding %d to y\n", num);
                tempPoints[p].y = num;
                p+=1;
                current = 'x';
            }
            printf(" Hit a break\n");
            p += 1;
            pt = 2;
            // reset temp!
            int j;
            for (j = 0; j < 4; j+=1) {
                temp[j] = '0';
            }
            printf("\nreset temp: %s\n", temp);
        }
        c = fgetc(f);
    }
    arrayOfPoints = &tempPoints;
}