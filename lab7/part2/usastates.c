/*
    @author: John Blake Caven
    @name: usastates.c
    @date 3-20-22

    Lab 7: Part 2


CSV file: statesinfo.csv
*/
#include <stdio.h>
#include "statesfunc.h"
// main
int main(void) {
    char fname[30];
    printf("Please enter the name of the file: \n");
    scanf("%s", &fname);
    //strcpy(fname, "statesinfo.csv"); // I was hard coding it to test it easily
    //printf("%s\n", fname);
    FILE *fn = fopen(fname, "r");
    if (fn != NULL) {
        State s[100];
        int size = fileScrape(fn, s);
        while (1) {
            int option = printMenu();
            if (option == 1) {
                listAll(s, size);
            } else if (option == 2) {
                listSpecific(s, size);
            } else if (option == 3) {
                findCapital(s, size);
            } else if (option == 4) {
                sortStatesByYear(s, size);
            } else if (option == 5) {
                findStatesByYear(s, size);
            } else if (option == 6) {
                printf("Bye!\n");
                return 0;
            } else {
                printf("Sorry, that option is not available\n");
                option = 0;
            }
        }
    } else {
        printf("File does not exist.\n");
    }
    
    return 0;
}
