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
        


    */
    return 0;
}