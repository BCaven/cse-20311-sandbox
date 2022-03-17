/*
    @author: John Blake Caven
    @name: pathfunc.c
    @date: 3-16-22

    Lab 7: Part 1

*/

#include "pathfunc.h"
#include <stdio.h>

float getDistance(point a, point b) {
    float sq = sqrtf(((b.x-a.x)*(b.x-a.x)) + ((b.y-a.y)*(b.y-a.y))); // whooo - standard distance formula
    return sq;
}
void getFileData(FILE *f) { // alright, we can iterate through the entire file
    char c = fgetc(f); // assuming the file has already been assigned
    /*
    so, we are going through the individual characters, which means we have to harvest numbers
    we know that the maximum number of characters is 3: i.e. for -99
    so we can create a temp catch that waits until it hits a space
    */
    char temp[4] = {'0', '0', '0', '0'}; // temp[3] is reserved for decimal places
    char current = 'x'; // what value in that point we are writing to
    int p = 0; // what point we are currently writing to
    float num; // just gonna throw it out here to see if it makes a difference... probably not
    point tempPoints[30];
    while (c != EOF) {
        if (c != ' ' && c != '\n') {
            //printf("%c\n", c);
            if (c == '.') {
                c = fgetc(f);
                //printf("\nCurrent C: %c\n", c);
                temp[3] = c;
            } else if (c == '-') {
                temp[0] = c;

            } else if (temp[2] != '0') { // we already filled a number, but now we have to add the second digit -> we are going to filp them so they are in the right order
                temp[1] = temp[2];
                temp[2] = c;
            } else {
                temp[2] = c;
            }
        } else {
            
            // so, we wrote the char array so it will look something like
            /*
            {'0', '0', '1', '0'}
            up to
            {'-', '9', '9', '9'}
            */
            //printf("Temp[1] %d Temp[2] %d Temp[3] %d\n", temp[1]-'0', temp[2]-'0', temp[3]-'0');
            num = ((10 * (temp[1]-'0')) + (temp[2]-'0')) + ((temp[3]-'0') / (10.0));
            // then check for the negative
            if (temp[0] == '-') {
                //printf("making the number negative\n");
                num = num * -1.0;
            }
            if (current == 'x') {
                //printf("adding %lf to x\n", num);
                tempPoints[p].x = num;
                current = 'y';
            } else {
                //printf("adding %lf to y\n", num);
                tempPoints[p].y = num;
                p+=1;
                current = 'x';
            }
            // reset temp!
            int j;
            for (j = 0; j < 4; j+=1) {
                temp[j] = '0';
            }
            //printf("\nreset temp: %s\n", temp);
        }
        c = fgetc(f);
    }
    printf("There are %d points\n", p);
    printf("\n  x    |    y  \n");
    printf("---------------\n");
    
    int i;
    for (i = 0; i < p; i += 1) {
        printf(" %4.1lf  |  %4.1lf\n", tempPoints[i].x, tempPoints[i].y);
    }
    float dist = 0;
    for (i = 0; i < p-1; i+=1) {
        dist += getDistance(tempPoints[i], tempPoints[i+1]);
    }
    printf("\nThe path distance through them is %4.2lf\n", dist);
}