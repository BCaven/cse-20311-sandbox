#include <stdio.h>
#include <ctype.h>
#include <string.h>

void initBoard(char board[15][15], int type);
void printWords(char words[20][15], int len);
void printBoard(char board[15][15]);
void readFile(FILE *f, char board[15][15]);
int interactiveInput(char board[15][15]);
void toUpperCase(char word[20], int len);

int main(void) {
    char fName[30];
    printf("Get the file name:\n");
    scanf("%s", &fName);
    
    // make and initialize the arrays
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
    
    int numWords = interactiveInput(words);
    printWords(words, numWords);

    int i;
    for (i = 0; i < numWords; i+=1) {
        toUpperCase(words[i], strlen(words[1]));
    }
    printWords(words, numWords);
    /*    
    FILE *file;
    file = fopen(fName, 'r');
    if (file == NULL) {
        printf("File not found\n");
        return 0;
    }

    fclose(file);
    */
    return 0;
}
void printWords(char words[20][15], int len) {
    int i;
    for (i = 0; i < len; i+=1) {
        printf("%s\n", words[i]);
    }
}
void initBoard(char board[15][15], int type) {
    int i, j;
    char block = '#';
    for (i = 0; i < 15; i+=1) {
        for (j = 0; j < 15; j+=1) {
            if (type == 0) {
                board[i][j] = '.';
            } else {
                board[i][j] = block;
            }
        }
    }
}
void printBoard(char board[15][15]) {
    int i, j;
    for (i = 0; i < 15; i+=1) {
        for (j = 0; j < 15; j+=1) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void readFile(FILE *f, char board[20][15]) {
    char  currentWord[15];
    while (fgets(currentWord, 15, f) != NULL) {
        // get all the words
    }

}
int interactiveInput(char board[20][15]) {
    int c = 0;
    char currentWord[15];
    scanf("%s", &currentWord);
    while(c < 20) {
        if (strcmp(currentWord, ".") == 0) {
            printf("hit . \n");
            return c;
        }
        printf("current word: %s\n", currentWord);
        // board[c] = currentWord;// this should work right? Or should I use strcpy
        strcpy(board[c], currentWord);
        c+=1;
        
        scanf("%s", &currentWord);
    }
    return c;
}
void toUpperCase(char word[20], int len) {
    int i;
    for (i = 0; i < len; i+=1) {
        word[i] = toupper(word[i]);
    }
    
}