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
char findCharAtCoord(int x, int y, letterPlacement letters[300]) {
    return 0; // might not need this after all
}
void placeWord(char word[20], int len, char board[15][15], letterPlacement letters[300], int numLettersPlaced) {
    
    int i, j, x, y, dir;
    for (i = 0; i < numLettersPlaced; i+=1) {
        char searchChar = letters[i].letter;
        for (j = 0; j < len; j+=1) {
            if (word[j] == searchChar) {
                x = letters[i].x;
                y = letters[i].y;
                dir = letters[i].dir;
                // check the coordinate and perpendicular directions
                int finalDir[4] = {1, 1, 1, 1}; // down, up, right, left
                if (dir == 0) { // up/down
                    finalDir[2] = -1;
                    finalDir[3] = -1;
                    int pos;
                    if (y+(len-j) < 15 && y-(j) > 0) {
                        for (pos = 0-j; pos < len-j; pos+=1) { // down
                            if (board[x][y+pos] == '.' || board[x][y+pos] == word[pos+j]) {
                                // good
                            } else {
                                // bad
                                printf("Fail.\n");
                                finalDir[0] = -1;
                            }
                        }
                    } else {
                        printf("Out of bounds.\n");
                        finalDir[0] = -1;
                    }
                    if (y - (len-j) > 0 && y+j < 15) {
                        for (pos = 0+j; pos > -(len-j); pos-=1) { // up
                            if (board[x][y+pos] == '.' || board[x][y+pos] == word[pos+j]) {
                                // good
                            } else {
                                // bad
                                printf("Fail.\n");
                                finalDir[1] = -1;
                            }
                        }
                    } else {
                        printf("Out of bounds.\n");
                        finalDir[1] = -1;
                    }
                } else { // right/left
                    finalDir[0] = -1;
                    finalDir[1] = -1;
                    int pos;
                    if (x+(len-j) < 15 && x-(j) > 0) {
                        for (pos = 0-j; pos < len-j; pos+=1) { // right
                            if (board[x+pos][y] == '.' || board[x+pos][y] == word[pos+j]) {
                                // good
                            } else {
                                // bad
                                printf("Fail.\n");
                                finalDir[2] = -1;
                            }
                        }
                    } else {
                        printf("Out of bounds.\n");
                        finalDir[2] = -1;
                    }
                    if (x - (len-j) > 0 && x+j < 15) {
                        for (pos = 0+j; pos > -(len-j); pos-=1) { // left
                            if (board[x+pos][y] == '.' || board[x+pos][y] == word[pos+j]) {
                                // good
                            } else {
                                // bad
                                printf("Fail.\n");
                                finalDir[3] = -1;
                            }
                        }
                    } else {
                        printf("Out of Bounds.\n");
                        finalDir[3] = -1;
                    }
                }
                // check to see what path worked
                if (finalDir[0] == 1) { // add the word down
                    int cL;
                    for (cL = 0; cL < len; cL+=1) {
                        board[x][y-j+cL] = word[cL];
                        // add character to char array
                    }
                } else if (finalDir[1] == 1) { // add the word up
                    int cL;
                    for (cL = 0; cL < len; cL+=1) {
                        board[x][y+j-cL] = word[cL];
                    }
                } else if (finalDir[2] == 1) { // add the word to the right
                    int cL;
                    for (cL = 0; cL < len; cL+=1) {
                        board[x-j+cL][y] = word[cL];
                    }
                } else if (finalDir[3] == 1) { // add the word to the left
                    int cL;
                    for (cL = 0; cL < len; cL+=1) {
                        board[x+j-cL][y] = word[cL];
                    }
                }



                return;
                //break;
            }
        }
    }
    if (x == NULL) {
        printf("The word cannot be placed because no letters matched\n");
        return;
    }


    

}