#include <stdio.h>
#include <string.h>

typedef struct {
    char *str;
    int len;
} word;
word returnStruct(char *s, int len);
void pointToStruct(word *w, char *c, int l);
void walk(int *intArr, int len);
int* returningPointer(int len);



int main(int argc, char *argv) {
    word test;
    test.str = "hello world";
    test.len = strlen("hello world");

    word returnedWord = returnStruct("this is a test", strlen("this is a test"));

    printf("%s | len: %d\n", test.str, test.len);
    printf("%s | len: %d\n", returnedWord.str, returnedWord.len);

    word testPoint;
    pointToStruct(&testPoint, "wow it worked", strlen("wow it worked"));
    printf("%s | len: %d\n", testPoint.str, testPoint.len);
    char *testString = "hello world pointers are cool!";
    printf("%s\n", testString);

    printf("%d\n", strlen(testString));
    printf("%c\n", testString[0]);

    int intPointer[10];
    int i;
    for (i = 0; i < 10; i+=1) {
        intPointer[i] = i;
    }
    int *pointer = &intPointer;

    for (i = 0; i < 10; i+=1) {
        printf("%d ", (*(pointer+i)));
    }
    printf("\n");

    
    for (i = 0; i < 10; i+=1) {
        printf("%d ", *pointer);
        pointer++;
    }
    
    printf("\n");
    printf("%d\n", pointer);
    
    pointer = intPointer;
    printf("%d\n", *pointer);
    while (pointer < intPointer+10) {
        printf("%d ", *pointer);
        pointer++;
    }
    printf("\n");

    printf("-------\n");
    walk(&intPointer, 10);
    printf("-------\n");
    int *arrPointer = returningPointer(10);
    for (i = 0; i < 10; i+=1) {
        printf("%d ", *arrPointer);
        arrPointer++;
    }
    printf("\n");

    printf("\n\nargc/argv testing\n\n");
    printf("argc: %d\n", argc);
    char * p = argv;
    printf("printing as string:\n");
    printf("%s\n", argv);
    printf("printing as chars:\n");
    for (i = 0; i < argc; i+=1) {
        printf("%c\n", argv[0]);
        argv++;
    }

    printf("\n\nMalloc Testing:\n\n");


    word *mallocTest = (word*) malloc(sizeof(word));
    mallocTest->str = "hello random point in memory";
    mallocTest->len = sizeof("hello random point in memory");
    printf("%s | len: %d\n", mallocTest->str, mallocTest->len);

    free(mallocTest);

    printf("%d\n", fact(5));


    return 0;
}

word returnStruct(char *s, int len) {
    word temp;
    temp.str = s;
    temp.len = len;
    return temp;
}
void pointToStruct(word *w, char *c, int l) {
    w->str = c;
    w->len = l;
}
void walk(int *intArr, int len) {
    int *p = intArr;
    while (p < intArr + len) {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}
int* returningPointer(int len) {
    int a[len];
    int i;
    for (i = 0; i < len; i+=1) {
        a[i] = i;
    }
    return &a;
}

int fact(int x) {return x > 1 ? fact(x-1)*x : 1;}