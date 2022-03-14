#include <stdio.h>

int findN(int num, int n);

int main(void) {
    printf("%d\n", findN(234786, 4));    
    return 0;
}
int findN(int num, int n) {
    int count = 1;
    int temp = num;
    while (temp / count != 0) {
        count *= 10;
    }
    count = count / 10;
    int i;
    for (i = count; i > 0; i = i/10) {
        int t = (temp - ((temp/(i*10))*(i*10))) / i;
        printf("%d\n", t);
        if (t == n) {
            return 1;
        }
    }
    return 0;

}