/*
@author: John Blake Caven
@name: crossfunc.h
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
typedef struct {
    char *word;
    int len;
} word;
*/
typedef struct {
    char letter;
    int x;
    int y;
    int dir;
} letterPlacement;


void initBoard(char board[15][15], int type);
void printWords(char words[20][15], int len);
void printBoard(char board[15][15]);
int readFile(FILE *f, char board[15][15]);
int interactiveInput(char board[15][15]);
void toUpperCase(char word[20], int len);
void sortWords(char words[20][15], int numWords);
int placeWord(char word[20], int len, char board[15][15], letterPlacement letters[300], int numLettersPlaced, char up[20][15], char across[20][15], int numUpP, int numAcrossP);
void generateBoard(char words[20][15], int numWords, char board[15][15], letterPlacement letters[300], int numLettersPlaced);
void writePuzzle(char board[15][15], char puzzle[15][15]);
