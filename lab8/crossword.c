#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *word;
    int len;
} word;

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
void placeWord(char word[20], int len, char board[15][15], letterPlacement letters[300], int numLettersPlaced);
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
    /*
    int numWords = interactiveInput(words);
    printf("Original list:\n");
    printWords(words, numWords);

    int i;
    for (i = 0; i < numWords; i+=1) {
        toUpperCase(words[i], strlen(words[i]));
    }
    printf("Uppercase list:\n");
    printWords(words, numWords);
    printf("Sorted:\n");
    sortWords(words, numWords);
    printWords(words, numWords);
    */
    printf("\n\n-----------\n\n");
    char fileWords[20][15];
    
    FILE *f;
    printf("bang\n");
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
    printf("Sorted and Capitalized:\n");
    sortWords(fileWords, fLen);
    int i;
    for (i = 0; i < fLen; i+=1) {
        toUpperCase(fileWords[i], strlen(fileWords[i]));
    }
    printWords(fileWords, fLen);
    
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
int readFile(FILE *f, char board[20][15]) {
    int numWords = 0;
    char  currentWord[15];
    fgets(currentWord, 15, f);
    while (currentWord != NULL) {
        // remove the newline character
        char *clean = strtok(currentWord, "\n");
        //printf("clean: %s\n", clean);
        strcpy(currentWord, clean);
        int lenWord = strlen(currentWord);
        // get all the words

        //printf("strcmp %s : '.' = %d\n", currentWord, strcmp(currentWord, ".")); // for some reason it is missing the last two words
        
        if (feof(f) || strcmp(currentWord, ".") == 0) {
            return numWords;
        }
        if (strlen(currentWord) < 15) {
            strcpy(board[numWords], currentWord);
            //printf("copying %s to place %d\n", currentWord, numWords);
            numWords +=1;
        } else {
            // debugging
            //printf("%s is too long\n", currentWord);
        } 
        fgets(currentWord, 30, f);
    }
    return numWords;
}
int interactiveInput(char board[20][15]) {
    int c = 0;
    char currentWord[15];
    scanf("%s", &currentWord);
    while(c < 20) {
        if (strcmp(currentWord, ".") == 0) {
            //printf("hit . \n");
            return c;
        }
        //printf("current word: %s, length: %d\n", currentWord, strlen(currentWord));
        // board[c] = currentWord;// this should work right? Or should I use strcpy
        if (strlen(currentWord) > 14) {
            printf("The word is too long\n");
        } else {
            strcpy(board[c], currentWord);
            c+=1;
        }
        
        
        scanf("%s", &currentWord);
    }
    return c;
}
void toUpperCase(char word[20], int len) { // hooray, an easy function
    int i;
    for (i = 0; i < len; i+=1) {
        word[i] = toupper(word[i]);
    }
    
}
void cleanTxt(char word[20]) { // I dont know if I will need this, but I made it just in case
    int i;
    for (i = 0; i < 20; i+=1) {
        word[i] = '\0';
    }
}
void sortWords(char words[20][15], int numWords) {
    int i, j;
    for (i = 0; i < numWords-1; i+=1) {
        for (j = i+1; j < numWords; j+=1) {
            //printf("Strcmp: %d", strcmp(words[i], words[j]));
            int c = strcmp(words[i], words[j]);
            if (c > 0) {
                char temp[15];
                strcpy(temp, words[i]);
                //cleanTxt(words[i]);
                strcpy(words[i], words[j]);
                //cleanTxt(words[j]);
                strcpy(words[j], temp);


            }
        }
    }

}

void placeWord(char word[20], int len, char board[15][15], letterPlacement letters[300], int numLettersPlaced) {
    // place the first word:
    int i, j, x, y, dir;
    for (i = 0; i < numLettersPlaced; i+=1) {
        char searchChar = letters[i].letter;
        for (j = 0; j < len; j+=1) {
            if (word[j] == searchChar) {
                x = letters[i].x;
                y = letters[i].y;
                dir = letters[i].dir;
                // check the coordinate and perpendicular directions
                if (dir == 0) { // up/down
                    int pos;
                    for (pos = 0; pos < len; pos+=1) { // down
                        
                    }
                    for (pos = 0; pos > -len; pos-=1) { // up

                    }
                } else { // right/left
                    int pos;
                    for (pos = 0; pos < len; pos+=1) { // right
                        
                    }
                    for (pos = 0; pos > -len; pos-=1) { // left

                    }
                }




                break;
            }
        }
    }
    if (x == NULL) {
        printf("The word cannot be placed because no letters matched\n");
        return;
    }


    

}