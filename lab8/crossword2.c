// no, this scares me

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *word;
    int len;
} word;

void initBoard(char board[15][15], int type);
void printBoard(char board[15][15]);
void printWords(word words[20], int len);
int readFile(FILE *f, word words[20]);
int interactiveInput(word words[20]);
void toUpperCase(word w[20], int len);


int main(void) {
    char fName[30];
    printf("Get the file name:\n");
    scanf("%s", &fName);
    
    // make and initialize the arrays
    word words[20];
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
    printf("Original list:\n");
    printWords(words, numWords);

    int i;
    toUpperCase(words, numWords);
    
    printf("Uppercase list:\n");
    printWords(words, numWords);
    printf("Sorted:\n");
    sortWords(words, numWords);
    printWords(words, numWords);
    printf("\n\n-----------\n\n");
    word fileWords[20];
    FILE *f;
    printf("bang\n");
    if (fopen(fName, "r") == NULL) {
        printf("File not found\n");
        return 0;
    }
    f = fopen(fName, "r");
    printf("File opened\n");
    int fLen = readFile(f, fileWords);
    printf("List from file:\n");
    printWords(fileWords, fLen);
    printf("List from file, capitalized and sorted:\n");
    toUpperCase(fileWords, fLen);
    sortWords(fileWords, fLen);
    printWords(fileWords, fLen);
    fclose(f);
    
    return 0;
}


/* ------------------------ Board functions -------------------------- */
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
/* ----------------------------- Word Functions  ----------------------------- */
void printWords (word words[20], int len) {
    int i;
    for (i = 0; i < len; i+=1) {
        printf("%s\n", words[i].word);
    }
}
void toUpperCase(word w[20], int len) { // hooray, an easy function
    int i, j;
    for (j = 0; j < len; j+=1) {
    for (i = 0; i < w[j].len; i+=1) {
        w[j].word[i] = toupper(w[j].word[i]);
    }
    }
    
}
void cleanTxt(word w) { // I dont know if I will need this, but I made it just in case
    int i;
    for (i = 0; i < 20; i+=1) {
        w.word[i] = '\0';
    }
}
void sortWords(word words[20], int numWords) {
    int i, j;
    for (i = 0; i < numWords-1; i+=1) {
        for (j = i+1; j < numWords; j+=1) {
            //printf("Strcmp: %d", strcmp(words[i], words[j]));
            int c = strcmp(words[i].word, words[j].word);
            if (c > 0) {
                char temp[15];
                strcpy(temp, words[i].word);
                //cleanTxt(words[i]);
                strcpy(words[i].word, words[j].word);
                //cleanTxt(words[j]);
                strcpy(words[j].word, temp);


            }
        }
    }

}
/* ----------------------------- Input Functions ----------------------------- */
int readFile(FILE *f, word words[20]) {
    int numWords = 0;
    char  currentWord[15];
    fgets(currentWord, 15, f);
    while (currentWord != NULL) {
        int lenWord = strlen(currentWord);
        // get all the words
        printf("strcmp %s : '.' = %d\n", currentWord, strcmp(currentWord, ".")); // for some reason it is missing the last two words
        if (feof(f) || strcmp(currentWord, ".") == 0) {
            return lenWord;
        }
        currentWord[lenWord-1] = '\0';
        //currentWord[lenWord-2] = '\0';
        //printf("word: %s\n", currentWord);
        if (strlen(currentWord) < 15) {

            words[numWords].word = &currentWord;
            words[numWords].len = strlen(currentWord);
        } else {
            printf("%s is too long\n", currentWord);
        }
        numWords +=1;
        fgets(currentWord, 30, f);
    }
    return numWords;
}
int interactiveInput(word words[20]) {
    int c = 0;
    char currentWord[15];
    scanf("%s", &currentWord);
    while(c < 20) {
        if (strcmp(currentWord, ".") == 0) {
            //printf("hit . \n");
            return c;
        }
        if (strlen(currentWord) > 14) {
            printf("The word is too long\n");
        } else {
            words[c].word = &currentWord;
            words[c].len = strlen(currentWord);
            c+=1;
        }
        
        
        scanf("%s", &currentWord);
    }
    return c;
}
/* ---------------------------- misc functions ---------------------------- */
