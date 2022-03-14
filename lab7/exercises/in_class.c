#include <stdio.h>

int main() {
    /*
    %x <- address of the variable (in memory)
    %p <- full address
    */

    /*
    Pointers:
        - takes on address of another variable
        - its value is the address of another variable

        Declaring pointers: *
        int *p; <- variable "p" is a pointer
        
        & => address of a variable

        so 
        p = &n; => p is n's address


        Dumb thing about pointers:
            data type does not matter
            int* p => p is a pointer
            int * p => p is a pointer
            int *p => p is a pointer
            int *p, j => p is a pointer, j is an int
            same with int* p, j;
        
        *p = 17
        changes value which p is pointing to

        (*p)++; <- now value of thing that p points to is 18

    pointers in arrays (wooooo)
    */

    int arr[5] = {1, 2, 3, 4, 5};
    int *p;
    p = &arr[0];
    // name of the array is also the address of the beginning of the array
    p = arr; // whoa, lol
    // so, p rn is equal to the memory position of arr[0]
    p+=1; // ok so in theory, this should now equal arr[1] (it does)
    // pointers to arrays of memory are subsequential spots in memory
    p++;
    // the pointer knows how many bytes to jump (because you declare its type :D)

    // bringing pointers back to the beginning...
    p = arr; // and now it is back to the beginning of the array

    /*
    you can use a pointer in this way to iterate through the array
    can also use p[i] but it defeats the point
    
    */
    int a = 100;
    p = &a;
    int i;
    for (i = 0; i < 100; i+=1) {
        
        printf("pointer: %p | value: %d\n", p, *p);
        p++;
        
    }

    /*
    pass by reference:
    void func(int *p) {
        *p = n;
    }
    
    */
    return 0;
}