#include <stdio.h>
#include "gfx.h"

typedef struct {
    int data;
    node *next;
} node;

int blakeIsDumb(int a, int b);

int main(void) {
    printf("%d * %d = %d\n", 3, 4, blakeIsDumb(3, 4));
    printf("5! = %d\n", fact(5));
    printf("%d * %d = %d\n", 5, 4, dumber(5, 4));

    // other stuff



    return 0;
}

// linked list?





// funny




int blakeIsDumb(int a, int b) { // only positive int multiplication :C
    return b > 1 ? blakeIsDumb(a, b-1) + a : a;
}
int fact(int a) {
    return a > 1 ? fact(a-1) * a : 1;
}
int dumber(int a, int b) {
    return blakeIsDumb(fact(a)/fact(a-1), fact(b)/fact(b-1));
}