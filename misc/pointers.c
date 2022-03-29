#include <stdio.h>
#include <string.h>

typedef struct {
    char *str;
    int len;
} word;
word returnStruct(char *s, int len);
void pointToStruct(word *w, char *c, int l);

int main(void) {
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