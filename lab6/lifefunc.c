/*
    @author: John Blake Caven
    @name: lifefunc.c
    @date: 3-6-22

    Lab 6
        The funtions file

*/

/*
Rules:
    a)  a dead cell with exactly 3 neighbors becomes live
    b)  only a live cell with 2 or 3 neighbors survives, all others die
*/


#include <stdio.h>
#include "lifefunc.h"
//#include "playlife.c"

void updateBoard(int w, int h) {
    int i, j;
    for (i = 1; i < h-1; i+=1) { // scanning the inside, will check the walls later
        //printf("i: %d\n", i);
        for (j = 1; j < w-1; j+=1) {
           // printf("j: %d\n", j);
            int liveCells = 0;
            int c;
            for (c = -1; c < 2; c+=2) {
               // printf("c: %d\n", c);
                /*
                Patterns to search

                - ` ~
                ' o '
                ~ ` -
                
                
                */
                if (printBoard[i+c][j] == 'x') {
                    liveCells+=1;
                    //printf("Hit live cell");
                }
                if (printBoard[i][j+c] == 'x') {
                    liveCells += 1;
                    //printf("Hit live cell");
                }
                // do diagonal neighbors count? If not, remove these next two if statements.
                if (printBoard[i+c][j+c] == 'x') {
                    liveCells += 1;
                    //printf("Hit live cell");
                }
                if (printBoard[i+c][j-c] == 'x') {
                    liveCells += 1;
                   // printf("Hit live cell");
                }

            }
            if (liveCells < 2) {
                tempBoard[i][j] = ' ';
            } else if (liveCells >=2 && liveCells <= 3  && printBoard[i][j] == 'x') {
                tempBoard[i][j] = 'x';
            } else if (liveCells ==3 && printBoard[i][j] == ' ') {
                tempBoard[i][j] = 'x';
            }
        }
    }
    for (i = 0; i < h; i += 1) { // side walls
        int liveCellsR = 0;
        int liveCellsL = 0;
        if (i-1 >= 0) {
            if (printBoard[i-1][0] == 'x') {
                liveCellsR += 1;
            }
            if (printBoard[i-1][h-1] == 'x') {
                liveCellsL += 1;
            }
            if (printBoard[i-1][1] == 'x') {
                liveCellsR += 1;
            }
            if (printBoard[i][1] == 'x') {
                liveCellsR += 1;
            }
            if (printBoard[i-1][h-2] == 'x') {
                liveCellsL += 1;
            }
            if (printBoard[i][h-2] == 'x') {
                liveCellsL += 1;
            }
        }
        if (i+1 < h) {
            if (printBoard[i+1][0] == 'x') {
                liveCellsR += 1;
            }
            if (printBoard[i+1][h-1] == 'x') {
                liveCellsL += 1;
            }
            if (printBoard[i+1][1] == 'x') {
                liveCellsR += 1;
            }
            if (printBoard[i+1][h-2] == 'x') {
                liveCellsL += 1;
            }
        }
        if (liveCellsR < 2) {
                tempBoard[i][0] = ' ';
            } else if (liveCellsR >=2 && liveCellsR <= 3  && printBoard[i][0] == 'x') {
                tempBoard[i][0] = 'x';
            } else if (liveCellsR ==3 && printBoard[i][0] == ' ') {
                tempBoard[i][0] = 'x';
        }
        if (liveCellsL < 2) {
                tempBoard[i][h-1] = ' ';
            } else if (liveCellsL >=2 && liveCellsL <= 3 && printBoard[i][h-1] == 'x') {
                tempBoard[i][h-1] = 'x';
            } else if (liveCellsL ==3 && printBoard[i][h-1] == ' ') {
                tempBoard[i][h-1] = 'x';
        }

    }
    // fill printBoard
    for (i = 0; i < h; i+=1) {
        for (j = 0; j < w; j+=1) {
            printBoard[i][j] = tempBoard[i][j]; // replace
            tempBoard[i][j] = ' '; // clear temp board
        }
    }

}
void PrintBoard(int h, int w) {
    int i;
    int j;
    for (i = 0; i < h; i+=1) {
        for (j = 0; j < w; j+=1) {
            printf("%c  ", printBoard[j][i]);
        }
        printf("\n");
    }
}
void printMenu() {
    printf("---------\n");
    printf("a) add a new live cell to the scene\n");
    printf("r) remove a cell from the scene\n");
    printf("n) advance the game by one step\n");
    printf("p) play the program forever\n");
    printf("q) quit the program\n");
}