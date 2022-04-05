/*
@author: John Blake Caven
@name: crossfunc.c
*/
#include "crossfunc.h"
void writePuzzle(char board[15][15], char puzzle[15][15]){
    int i, j;
    char blank = ' ';
    for (i = 0; i < 15; i+=1) {
        for (j = 0; j < 15; j+=1) {
            if (board[i][j] != '.') {
                //printf("removing\n");
                puzzle[i][j] = blank;
            }
        }
    }
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
    for (i = 0; i < 16; i+=1) {
        printf("--");
    }
    printf("\n|");
    for (i = 0; i < 15; i+=1) {
        for (j = 0; j < 15; j+=1) {
            printf("%c ", board[j][i]);
        }
        printf("|\n|");
    }
    for (i = 0; i < 16; i+=1) {
        printf("--");
    }
    printf("\n");
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
        int i;
        int isNum = 0;
        for (i = 0; i < lenWord; i+=1) {
            if (currentWord[i] - '0' >= 0 && currentWord[i] -'0' < 10) {
                isNum = 1;
            }
        }
        if (strlen(currentWord) < 15 && isNum == 0) {
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
            int c = strlen(words[i]) - strlen(words[j]);
            if (c < 0) {
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
int placeWord(char word[20], int len, char board[15][15], letterPlacement letters[300], int numLettersPlaced, char up[20][15], char across[20][15], int numUpP, int numAcrossP) {
    int numUp = numUpP;
    int numAcross = numAcrossP;
    //printf("Number of characters: %d\n", numLettersPlaced);
    //printf("Trying to place %s\n", word);
    int i, j, x, y, dir;
    for (i = 0; i < numLettersPlaced; i+=1) {
        char searchChar = letters[i].letter;
        //printf("Character we are searching for %c\nIn direction %d\n", searchChar, letters[i].dir);
        for (j = 0; j < len; j+=1) {
            if (word[j] == searchChar) {
                x = letters[i].x;
                y = letters[i].y;
                dir = letters[i].dir;
                // check the coordinate and perpendicular directions
                int finalDir[4] = {1, -1, 1, -1}; // down, up, right, left
                if (dir == 0) { // up/down
                    //printf("scanning up and down\n");
                    finalDir[2] = -1;
                    finalDir[3] = -1;
                    int pos;
                    if (y+(len-j) < 15 && y-(j) > 0) {
                        for (pos = 0-j; pos < len-j; pos+=1) { // down
                            if (board[x][y+pos] == '.' || board[x][y+pos] == word[pos+j]) {
                                // good
                                //printf("Passed check one (down)\n");
                                //printf("%c current board edge\n", board[x][y+pos]);
                                //printf("%c current board edge\n", board[x][y+pos]);
                                if (board[x+1][y+pos] == '.' && board[x-1][y+pos] == '.') {

                                } else {
                                    if (board[x][y+pos] == word[pos+j] || pos == 0 || pos == -j) {
                                        //printf("its ok\n");
                                    } else {
                                        //printf("too close\n");
                                        finalDir[0] = -1;
                                    }
                                }
                                /*
                                if (board[x+1][y+pos] == '.' && board[x-1][y+pos] == "." && board[x][y-j-1] == "." && board[x][y+len-j] == "." || pos == 0){
                                    printf("Passed check two\n");
                                    // good
                                } else if (pos == 0 || pos == -j) {
                                    printf("Passed check two on technical\n");
                                } else {
                                    // bad
                                    printf("Fail.\n");
                                    printf("Could not place %s\n", word);
                                    printf("Character %c failed\n", word[pos+j]);
                                    finalDir[0] = -1;
                                }
                                */
                            } else {
                                // bad
                                //printf("Fail.\n");
                                //printf("Could not place %s\n", word);
                                finalDir[0] = -1;
                            }
                        }
                    } else {
                        //printf("Out of bounds.\n");
                        finalDir[0] = -1;
                    }
                    if (y - (len-j) > 0 && y+j < 15) {
                        for (pos = 0+j; pos > -(len-j); pos-=1) { // up
                            if (board[x][y+pos] == '.' || board[x][y+pos] == word[pos+j]) {
                                // good
                                //printf("Passed check one (up)\n");
                                if (board[x+1][y+pos] == '.' && board[x-1][y+pos] == '.' && board[x][y+j+1] == '.' && board[x][y-len+j] == '.' || pos == 0){
                                    //printf("Passed check two\n");
                                    // good
                                } else if (pos == 0 || pos == j) {
                                    //printf("Passed check two on technical\n");
                                } else {
                                    // bad
                                    //printf("Fail.\n");
                                   // printf("Could not place %s\n", word);
                                    //printf("Character %c failed\n", word[pos-j]);
                                    finalDir[1] = -1;
                                }
                            } else {
                                // bad
                                //printf("Fail.\n");
                                //printf("Could not place %s\n", word);
                                finalDir[1] = -1;
                            }
                        }
                    } else {
                       // printf("Out of bounds.\n");
                        finalDir[1] = -1;
                    }
                } else { // right/left
                   // printf("Scanning left to right\n");
                    finalDir[0] = -1;
                    finalDir[1] = -1;
                    int pos;
                    if (x+(len-j) < 15 && x-(j) > 0) {
                        for (pos = 0-j; pos < len-j; pos+=1) { // right
                            if (board[x+pos][y] == '.' || board[x+pos][y] == word[pos+j]) {
                                // good
                                //printf("Passed check one (right)\n");
                               // printf("Current board edge: %c\n", board[x+pos+1][y]);
                               // printf("Current board edge: %c\n", board[x+pos-1][y]);
                                
                                if (board[x+pos][y+1] == '.' && board[x+pos][y-1] == '.') {

                                } else {
                                    if (board[x+pos][y] == word[pos+j] || pos == 0 || pos == -j) {
                                        //printf("its ok\n");

                                    } else {
                                        finalDir[2] = -1;
                                    }
                                }
                                /*
                                if (board[x+pos][y+1] == '.' && board[x+pos][y-1] == "." && board[x-j-1][y] == "." && board[x+len-j][y] == "."){
                                printf("Passed check two\n");
                                // good
                                } else if (pos == 0 || pos == -j) {
                                    printf("Passed check two on technical\n");
                                } else {
                                    // bad
                                    printf("Fail.\n");
                                    printf("Could not place %s\n", word);
                                    printf("Character %c failed\n", word[pos+j]);
                                    finalDir[2] = -1;
                                } 
                                */
                            } else {
                                // bad
                               // printf("Fail.\n");
                               // printf("Could not place %s\n", word);
                                finalDir[2] = -1;
                            }
                        }
                    } else {
                        //printf("Out of bounds.\n");
                        finalDir[2] = -1;
                    }
                    if (x - (len-j) > 0 && x+j < 15) {
                        for (pos = 0+j; pos > -(len-j); pos-=1) { // left
                            if (board[x+pos][y] == '.' || board[x+pos][y] == word[pos+j]) {
                               // printf("Passed check one (left)\n");
                                // good
                                if (board[x+pos][y+1] == '.' && board[x+pos][y-1] == '.' && board[x+j+1][y] == '.' && board[x-len+j][y] == '.'){
                                   // printf("Passed check two\n");
                                    // good
                                } else if (pos == 0 || pos == j) {
                                    //printf("Passed check two on technical\n");
                                } else {
                                    // bad
                                   // printf("Fail.\n");
                                  //  printf("Could not place %s\n", word);
                                  //  printf("Character %c failed\n", word[pos-j]);
                                    finalDir[3] = -1;
                                }
                            } else {
                                // bad
                               // printf("Fail.\n");
                               // printf("Could not place %s\n", word);
                                finalDir[3] = -1;
                            }
                        }
                    } else {
                        //printf("Out of Bounds.\n");
                        finalDir[3] = -1;
                    }
                }
                // check to see what path worked
                if (finalDir[0] == 1) { // add the word down
                   // printf("Adding %s down at x:%d y:%d\n", word, x, y);
                    int cL;
                    for (cL = 0; cL < len; cL+=1) {
                        board[x][y-j+cL] = word[cL];
                        // add character to char array
                        letters[numLettersPlaced].letter = word[cL];
                        letters[numLettersPlaced].x = x;
                        letters[numLettersPlaced].y = y-j+cL;
                        letters[numLettersPlaced].dir = 1;
                        numLettersPlaced+=1;

                    }
                    //strcpy(up[numUp], word);
                    //numUp +=1;
                    return numLettersPlaced;
                } else if (finalDir[1] == 1) { // add the word up
                    int cL;
                   // printf("Adding %s up at x:%d y:%d\n", word, x, y);
                    for (cL = 0; cL < len; cL+=1) {
                        board[x][y+j-cL] = word[cL];
                        letters[numLettersPlaced].letter = word[cL];
                        letters[numLettersPlaced].x = x;
                        letters[numLettersPlaced].y = y+j-cL;
                        letters[numLettersPlaced].dir = 1;
                        numLettersPlaced+=1;
                    }
                    //strcpy(up[numUp], word);
                    //numUp +=1;
                    return numLettersPlaced;
                } else if (finalDir[2] == 1) { // add the word to the right
                    int cL;
                   // printf("Adding %s right at x:%d y:%d\n", word, x, y);
                    for (cL = 0; cL < len; cL+=1) {
                        board[x-j+cL][y] = word[cL];
                        letters[numLettersPlaced].letter = word[cL];
                        letters[numLettersPlaced].x = x-j+cL;
                        letters[numLettersPlaced].y = y;
                        letters[numLettersPlaced].dir = 0;
                        numLettersPlaced+=1;
                    }
                    //strcpy(across[numAcross], word);
                    //numAcross +=1;
                    return numLettersPlaced;
                } else if (finalDir[3] == 1) { // add the word to the left
                    int cL;
                   // printf("Adding %s left at x:%d y:%d\n", word, x, y);
                    for (cL = 0; cL < len; cL+=1) {
                        board[x+j-cL][y] = word[cL];
                        letters[numLettersPlaced].letter = word[cL];
                        letters[numLettersPlaced].x = x+j-cL;
                        letters[numLettersPlaced].y = y;
                        letters[numLettersPlaced].dir = 0;
                        numLettersPlaced+=1;
                    }
                    //strcpy(across[numAcross], word);
                    //numAcross +=1;
                    return numLettersPlaced;
                } else {
                    //printf("Word was unable to be placed: %s\n", word);
                    //return -1;
                }



                
                //break;
            }
        }
    }
    if (x == NULL) {
       // printf("The word cannot be placed because no letters matched\n");
        return -1;
    }


    

}
void generateBoard(char words[20][15], int numWords, char board[15][15], letterPlacement letters[300], int numLettersPlaced) {
    int i;
    char up[20][15];
    char across[20][15];
    int numUp = sizeof(up) / (sizeof(char) * 15);
    int numAcross = sizeof(across) / (sizeof(char) * 15);
    // place first word
    
    char tempWord[15];
    strcpy(tempWord, words[0]);
    int startY = (15-strlen(tempWord))/2;
    for (i = 0; i < strlen(tempWord); i+=1) {
        board[15/2][startY+i] = tempWord[i];
        letters[i].letter = tempWord[i];
        letters[i].x = 15/2;
        letters[i].y = startY+i;
        letters[i].dir = 1;
        numLettersPlaced+=1;
    }
    //printBoard(board);
    // start adding new words:
    //while (numWords > 0) {
        int originalNumber = numWords;
        for (i = 0; i < originalNumber; i+=1) {
            int check = placeWord(words[i], strlen(words[i]), board, letters, numLettersPlaced, up, across, numUp, numAcross);
            
            if (check > 0) {
                numLettersPlaced = check;
               // printf("It worked\n");
                //cleanTxt(words[i]);
                numWords -=1;
                //printBoard(board);
            } else {
               // printf("It did not work\n");
                printf("%s could not be placed\n", words[i]);
                //printBoard(board);
            }
        }
    //}
}