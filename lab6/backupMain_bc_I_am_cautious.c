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
                updateBoard();
            } else if (choice == 'p') {
                while (0 == 0) { // im tired
                    system("clear");
                    printBoard();
                    updateBoard();
                    usleep(100);
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
        
    } else {
        printf("Sorry, you entered too many arguments!\n");
    }
    
    printf("\n");
    return 0;
}