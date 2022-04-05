/*
@author: John Blake Caven
@name: crossword.c
*/
#include "crossfunc.h"
int main(int argc, char *argv[]) {
    char fName[30];
    
    if (argc == 1) {
        printf("Get the file name: (enter '0' to use the interactive input)\n");
        scanf("%s", &fName);
    } else {
        strcpy(fName, argv[1]);
    }
    // make and initialize the arrays
    letterPlacement letters[300];
    int numLetters = 0;
    char words[20][15];
    char dotBoard[15][15];
    char hashBoard[15][15];
    initBoard(dotBoard, 0);
    initBoard(hashBoard, 1);

    // print the board
    printf("Solution board:\n");
    printBoard(dotBoard);
    printf("Crossword:\n");
    printBoard(hashBoard);
    if (strcmp("0", fName) == 0) {
        
        int numWords = interactiveInput(words);
       // printf("Original list:\n");
       // printWords(words, numWords);

        int i;
        for (i = 0; i < numWords; i+=1) {
            toUpperCase(words[i], strlen(words[i]));
        }
       // printf("Uppercase list:\n");
       // printWords(words, numWords);
       // printf("Sorted:\n");
        sortWords(words, numWords);
       // printWords(words, numWords);
        generateBoard(words, numWords, dotBoard, letters, numLetters);
       // printf("Puzzle board before removing\n");
       // printBoard(hashBoard);
        writePuzzle(dotBoard, hashBoard);
        printf("Solution:\n");
        printBoard(dotBoard);
        printf("Crossword Puzzle:\n");
        printBoard(hashBoard);
    } else {
        printf("\n\n-----------\n\n");
        char fileWords[20][15];
        
        FILE *f;
        //printf("bang\n");
        if (fopen(fName, "r") == NULL) {
            printf("File not found\n");
            return 0;
        }

        f = fopen(fName, "r");
        //printf("File opened\n");
        int fLen = readFile(f, fileWords);
        fclose(f);
        printf("List from file:\n");
        printWords(fileWords, fLen);
       // printf("Sorted and Capitalized:\n");
       // sortWords(fileWords, fLen);
        int i;
        for (i = 0; i < fLen; i+=1) {
            toUpperCase(fileWords[i], strlen(fileWords[i]));
        }
     //   printWords(fileWords, fLen);
        generateBoard(fileWords, fLen, dotBoard, letters, numLetters);
       // printf("Puzzle board before removing\n");
     //   printBoard(hashBoard);
        writePuzzle(dotBoard, hashBoard);
        printf("Solution:\n");
        printBoard(dotBoard);
        printf("Crossword Puzzle:\n");
        printBoard(hashBoard);
    }
    return 0;
}
