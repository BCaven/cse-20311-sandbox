/*
    @author: John Blake Caven
    @name: statesfunc.c
    @date 3-20-22

    Lab 7: Part 2
*/

#include <stdio.h>
#include "statesfunc.h"


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
           // printf("Current State: %s, %s, %s, %d\n", tS[cS].abbr, tS[cS].name, tS[cS].capital, tS[cS].yearJoined);
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
   // printf("Number of States: %d\n", cS);
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
    int j;
    for (j = 0; j < strlen(n); j+=1) {
        n[j] = toupper(n[j]);
    }
    int i;
    int c = 0;
    for (i = 0; i < s; i+=1) {
        if (strcmp(n, tS[i].abbr) == 0) {
            printf("Name: %s\nCapital: %s\nYear that %s joined the union: %d\n", tS[i].name, tS[i].capital, tS[i].name, tS[i].yearJoined);
            c+=1;
        }
        //printf("strcmp value: %d\n", strcmp(n, tS[i].abbr)); // just some debugging :D
    }
    if (c == 0) {
        printf("No states were found with that abbreviation\n");
    }
}
void findCapital(State tS[100], int s) {
    char n[30];
    printf("What is the state's abbreviation or name?\n");
    scanf("%s", &n);
    int j;
    for (j = 0; j < strlen(n); j+=1) {
        n[j] = toupper(n[j]);
    }
    // search for it, yes I am reusing code. Fight me.
    int i;
    int c = 0;
    for (i = 0; i < s; i+=1) {
        char tN[30];
        int z;
        for (z = 0; z < 30; z+=1) {
            tN[z] = '\0';
        }
        int nc;
        for (nc = 0; nc < strlen(tS[i].name); nc+=1) { // make it all uppercase! :D
            tN[nc] = toupper(tS[i].name[nc]);
            //printf("%c", tN[nc]);
            
        }
        if (strcmp(n, tS[i].abbr) == 0 || strcmp(n, tN) == 0) {
            printf("Name: %s\nCapital: %s\n", tS[i].name, tS[i].capital);
            c+=1;
        }
        //printf("strcmp value: %d\n", strcmp(n, tS[i].abbr)); // just some debugging :D
    }
    if (c == 0) {
        printf("No states were found with that abbreviation\n");
    }

}
void sortStatesByYear(State tS[100], int s) {
    printf("The states, sorted by year: earliest year at the top, latest year at the bottom\n");
    State sorted[100];
    int c;
    for (c = 0; c < s; c+=1) {
        strcpy(sorted[c].abbr, tS[c].abbr);
        strcpy(sorted[c].name, tS[c].name);
        strcpy(sorted[c].capital, tS[c].capital);
        sorted[c].yearJoined = tS[c].yearJoined;
    }
    int i; int j;
    for (i = 0 ; i < s-1; i+=1) {
        for (j = i+1; j < s; j+=1) {
            if (sorted[i].yearJoined > sorted[j].yearJoined) {
                State t = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = t;
            }
        }
    }
    listAll(sorted, s);
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