/*
    @author: John Blake Caven
    @name: statesfunc.h
    @date 3-20-22

    Lab 7: Part 2


CSV file: statesinfo.csv
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <ctype.h>
// struct
typedef struct {
    char abbr[5];
    char name[30];
    char capital[30];
    int yearJoined;
} State;
// function headers
int fileScrape(FILE *f, State tS[100]);
int printMenu();
void listAll(State tS[100], int s);
void listSpecific(State tS[100], int s);
void findCapital(State tS[100], int s);
void sortStatesByYear(State tS[100], int s);
void findStatesByYear(State tS[100], int s);

