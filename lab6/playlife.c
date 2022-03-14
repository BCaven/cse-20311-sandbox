/*
    @author: John Blake Caven
    @name: playlife.c
    @date: 3-6-22

    Lab 6
        The main file

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
Rules:
    a)  a dead cell with exactly 3 neighbors becomes live
    b)  only a live cell with 2 or 3 neighbors survives, all others die

Board is 40x40
alive cells 'x'
dead cells ' '

*/

char tempBoard[40][40];
char printBoard[40][40];


int main(int argc, int *argv[]) {
    if (argc < 2) { // no arguments given
        while (0 == 0) {
            // menu! I LOVE menus (just kidding they are awful)
            char choice;
            system("clear");
            printf("---- Board ----\n");
            PrintBoard(40, 40);
            printf("----       ----\n");
            printMenu();
            printf("Please choose an option:\n");
            scanf("%c", &choice);
            if (choice == 'a') {
                int x, y;
                printf("Enter the x coordinate:\n");
                scanf("%d", &x);
                printf("Enter the y coordinate:\n");
                scanf("%d", &y);
                printBoard[x][y] = 'x';
            } else if (choice == 'r') {
                int x, y;
                printf("Enter the x coordinate:\n");
                scanf("%d", &x);
                printf("Enter the y coordinate:\n");
                scanf("%d", &y);
                printBoard[x][y] = ' ';
            } else if (choice == 'n') {
                updateBoard(40, 40);
            } else if (choice == 'p') {
                while (0 == 0) { // im tired
                    system("clear");
                    PrintBoard(40, 40);
                    updateBoard(40, 40);
                    usleep(1000);
                }
            } else if (choice == 'q') {
                printf("Bye!\n");
                return 0;
            } else {
                printf("Sorry, that was not understood\n");
            }
        }
    } else if (argc == 2) { // one given (file name?)
        // ugh, scan throgh each line, why is c such a pain
        FILE *f;
        f = fopen(argv[1], "r");
        char inC = fgetc(f);
        while (inC != 'q') {
            if (inC == 'a') {
                inC = fgetc(f); // skip the first space
                printf("current character: %c\n", inC);
                inC = fgetc(f);
                printf("current character: %c\n", inC);
                
                int x, y;

                /*
                // first number
                int a = inC - '0'; 
                int b;
                int x, y;
                inC = fgetc(f);
                if (inC != 'n' && inC != '\\' && inC != '\n' && inC != ' ') { // another number
                    b = inC - '0';
                    x = (a*10) + b;
                } else {
                    x = a;
                }
                // second number
                inC = fgetc(f);
                a = inC - '0'; 
                if (inC != 'n' && inC != '\\' && inC != '\n' && inC != ' ') { // another number
                    b = inC - '0';
                    y = (a*10) + b;
                } else {
                    y = a;
                }
                printf("x: %d y: %d\n", x, y);
                */
                printBoard[x][y] = 'x';
            } else if (inC == 'r') {
                inC = fgetc(f); // skip the first space
                inC = fgetc(f);
                // first number
                int a = inC - '0'; 
                int b;
                int x, y;
                inC = fgetc(f);
                if (inC != 'n' && inC != '\\' && inC != '\n' && inC != ' ') { // another number
                    b = inC - '0';
                    x = (a*10) + b;
                } else {
                    x = a;
                }
                // second number
                inC = fgetc(f);
                a = inC - '0'; 
                if (inC != 'n' && inC != '\\' && inC != '\n' && inC != ' ') { // another number
                    b = inC - '0';
                    y = (a*10) + b;
                } else {
                    y = a;
                }
                printf("x: %d y: %d\n", x, y);
                printf("Current character: %c\n", inC);
                printBoard[x][y] = ' ';
            } else if (inC == 'n') {
                updateBoard(40, 40);
            } else if (inC == 'q') {
                fclose(f);
                return 0;
            } else if (inC == 'p') {
                fclose(f);
                while(1==1) {
                    //system("clear");
                    PrintBoard(40, 40);
                    updateBoard(40, 40);
                    usleep(100000);
                    int i, j;
                    int hit = 0;
                    for (i =0; i < 40; i+=1) {
                        for (j = 0; j < 40; j+=1) {
                            if (printBoard[i][j] == 'x') {
                                hit+=1;
                            }
                        }
                    }
                    if (hit == 0) {
                        printf("No more cells\n");
                        return 0;
                    }
                }
            } else {
                printf("current input: %c \n", inC);
                printf("not understood\n");
                usleep(10000);
                
            }
            if (inC == EOF) {
                printf("Reached the end of the file\n");
                return 0;
            }
            inC = fgetc(f);
        }


        /*
        char fIn[10];
        getLine(f, fIn, ' ');
        while (strcmp(fIn, "q") != 0 || strcmp(fIn, "q\n") != 0) {
            printf("current line: %s\n", fIn);
            if (fIn[0] == 'a') {
                getLine(f, fIn, ' '); // first int
                int x = fIn - '0';
                getLine(f, fIn, ' '); // second int
                char temp[10];
                strncpy(temp, fIn, strlen(fIn)-1);
                int y = fIn - '0';
                printBoard[x][y] = 'x';
            } else if (fIn[0] == 'r') {
                getLine(f, fIn, ' '); // first int
                int x = fIn - '0';
                getLine(f, fIn, ' '); // second int
                char temp[10];
                strncpy(temp, fIn, strlen(fIn)-1);
                int y = fIn - '0';
                printBoard[x][y] = ' ';
            } else if (fIn[0] == 'n') {
                updateBoard(40, 40);
            } else if (fIn[0] == 'p') {
                fclose(f);
                while(1==1) {
                    system("clear");
                    PrintBoard(40, 40);
                    updateBoard(40, 40);
                    usleep(1000);
                }
            } else if (fIn[0] == 'q') {
                fclose(f);
                return 0;
            } else {
                printf("Sorry that was not understood");
            }
            getLine(f, fIn, ' ');
        }
        */
        fclose(f);

    } else {
        printf("Sorry, you entered too many arguments!\n");
    }
    
    printf("\n");
    return 0;
}