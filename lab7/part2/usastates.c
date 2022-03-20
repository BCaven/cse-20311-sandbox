/*
    @author: John Blake Caven
    @name: usastates.c
    @date 3-20-22

    Lab 7: Part 2

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char abbrev[5];
    char name[30];
    char capital[30];
    int year_joined;
} State;

int main(void) {
    State a;
    strcpy(a.abbrev, "FL");
    strcpy(a.name, "Floridda");
    strcpy(a.capital, "Talli");
    printf("%s %s %s\n", a.abbrev, a.name, a.capital);
    
    return 0;
}