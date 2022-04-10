#include <stdio.h>


int blakeIsDumb(int a, int b);

int main(void) {
    printf("%d * %d = %d\n", 3, 4, blakeIsDumb(3, 4));
    printf("5! = %d\n", fact(5));
    printf("%d * %d = %d\n", 5, 4, dumber(5, 4));

    // other stuff
    int *i = (int *) malloc(sizeof(int));
    pointerWalk(i, 100);



    return 0;
}

// linked list?





// funny
void pointerWalk(int *p, int n) {
    if (n > 1) {
        //printf("address: %d contents as char: %c contents as int: %d\n", p, *p, *p);
        if (*p != 0) {
            printf("address: %d contents as char: %c contents as int: %d\n", p, *p, *p);
            return pointerWalk(p+1, n-1);
        } else {
            return pointerWalk(p+1, n);
        }
    }
    return;
}



int blakeIsDumb(int a, int b) { // only positive int multiplication :C
    return b > 1 ? blakeIsDumb(a, b-1) + a : a;
}
int fact(int a) {
    return a > 1 ? fact(a-1) * a : 1;
}
int dumber(int a, int b) {
    return blakeIsDumb(fact(a)/fact(a-1), fact(b)/fact(b-1));
}