/*
    @author: John Blake Caven
    @name: usastates.c
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
// main
int main(void) {
    State a;
    strcpy(a.abbr, "FL");
    strcpy(a.name, "Florida");
    strcpy(a.capital, "Talli");
    // printf("%s %s %s\n", a.abbrev, a.name, a.capital);
    char fname[30];
    //printf("Please enter the name of the file: \n");
    //scanf("%s", &fname);
    strcpy(fname, "statesinfo.csv");
    printf("%s\n", fname);
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
            }
        }
    } else {
        printf("File does not exist.\n");
    }
    
    return 0;
}
// functions
int fileScrape(FILE *f, State tS[100]) {
    // the old way that goes char by char... its a pain.
    char c = fgetc(f);
    
    //Variables we need

    //Tricks:
    //the numbers are always four digits...
    
    char temp[30];
    int cL = 0; // current location in the State
    int cS = 0; // current State which is being filled
    int cT = 0;
    while (c != EOF) {
        
        if (c == ',' || c=='\n') { // I dont care that this code is not great.
           // printf("\nHit ','!\n");
            if (cL == 0) { // abbreviation
                strcpy(tS[cS].abbr, temp);
            } else if (cL == 1) { // name
                strcpy(tS[cS].name, temp);
            } else if (cL == 2) { // capital
                strcpy(tS[cS].capital, temp);
            } else { // year founded
                // this is going to be a dumb conversion
                int y = 0;
                int i;
                //printf("Inputing the year, this is temp: %s\n", temp);
                for (i = 0 ; i < cL ; i +=1) {
                    int p = (int) pow(10, (cL)-i); // the place of the current number
                    y += (p * (temp[i] - '0'));
                }
                y += (temp[3]-'0'); // for some reason, the final digit is not working in the for loop, so instead I am just going to hard code it. I will fix it if I come back to it.
               // printf("%d\n", y);
                tS[cS].yearJoined = y;
            }
            printf("Current State: %s, %s, %s, %d\n", tS[cS].abbr, tS[cS].name, tS[cS].capital, tS[cS].yearJoined);
            cL+=1;
            cT = 0;
            int i_d;
            for (i_d = 0; i_d < sizeof(temp)/sizeof(temp[0]); i_d+=1) {
                temp[i_d] = '\0';
            }
            if (c == '\n') {
                cS += 1;
                cL = 0;
                cT = 0;
            }
           // printf("\nHit '\\n'!\n");
        } else { // I hate that I split these up but I am tired and it works, so who cares.
            temp[cT] = c;   
            cT += 1; 
        }
        c = fgetc(f);

    }
    printf("Number of States: %d\n", cS);
    return cS;
}
int printMenu() {
    printf("Menu:\n");
    printf("1) list all of the states\n");
    printf("2) list the description of a specific state\n");
    printf("3) find the capital based on the name of the state or the abbreviation\n");
    printf("4) sort the states based on the year they joined the union\n");
    printf("5) find every state that joined in a specific year\n");
    printf("6) exit\n");
    int o;
    printf("Choose one of the options\n");
    scanf("%d", &o);
    return o;
}
void listAll(State tS[100], int s) {
    int i;
    for (i = 0; i < s; i+=1) {
        printf("%s, %s, %s, %d\n", tS[i].abbr, tS[i].name, tS[i].capital, tS[i].yearJoined);
    }
}
void listSpecific(State tS[100], int s) {
    char n[30];
    printf("What is the state's abbreviation?\n");
    scanf("%s", &n);
    int i;
    for (i = 0; i < s; i+=1) {
        if (strcmp(n, tS[i].abbr) == 0) {
            printf("Name: %s\nCapital: %s\nYear that %s joined the union: %d\n", tS[i].name, tS[i].capital, tS[i].name, tS[i].yearJoined);
        }
        //printf("strcmp value: %d\n", strcmp(n, tS[i].abbr)); // just some debugging :D
    }
}
void findCapital(State tS[100], int s) {

}
void sortStatesByYear(State tS[100], int s) {

}
void findStatesByYear(State tS[100], int s) {
    int y;
    printf("What year would you like to search for?\n");
    scanf("%d", &y);
    int i = 0;
    int c = 0;
    for (i = 0; i < s; i+= 1) {
        if (tS[i].yearJoined == y) {
            printf("%s joined in %d\n", tS[i].name, tS[i].yearJoined);
            c += 1;
        }
    }
    if (c == 0) {
        printf("No states joined that year.\n");
    }
}