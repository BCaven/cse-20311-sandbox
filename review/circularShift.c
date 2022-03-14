/*
	@author: John Blake Caven
	@date: 2-22-22
	@name: circularShift.c
*/
#include <stdio.h>

void shiftLeft(int a[], int l);
void shiftRight(int a[], int l);
void print(int a[], int l);
int main(void) {
	int a[5] = {1, 2, 3, 4, 5};
	int l = sizeof(a)/sizeof(a[0]);
	printf("Original Array: ");
	print(a, l);
	shiftLeft(a, l);
	printf("Shifted Left: ");
	print(a, l);
	shiftRight(a, l);
	printf("Shifted Right: ");
	print(a, l);
	return 0;
}
void shiftLeft(int a[], int l) {
	int temp = a[0];
	int i;
	for (i = 0; i < l-1; i+=1) {
		a[i] = a[i+1];
	}
	a[l-1] = temp;
}
/*

1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
1 2 3 4 5

For some reason my brain is dying:

1 2 3 4 5
int temp = 1;
2 3 4 5 null
a[lastIndex] = temp
5 1 2 3 4
4 5 1 2 3
3 4 5 1 2
2 3 4 5 1
1 2 3 4 5


1 1 2 3 4
5 1 2 3 4
int temp = a[i+1]
a[i+1] = a[i]

temp = a[lastIndex]
1 2 3 4 5
start at the end
	null 1 2 3 4
a[0] = temp


*/
void shiftRight(int a[], int l, int times) {
	int j;
	for (j = 0; j < times; j+=1) {}
		int temp = a[l-1]; // last value will be overwritten
		int i;
		for (i = l-1; i > 0; i-=1) {
			a[i] = a[i-1];
		}
		a[0] = temp;
	}
	/*
	j = 0;
	while (j < times) {
		int temp = a[l-1]; // last value will be overwritten
		int i;
		for (i = l-1; i > 0; i-=1) {
			a[i] = a[i-1];
		}
		a[0] = temp;
		j+=1;
	}
	*/
}
void print(int a[], int l) {
	int i;
	for (i = 0; i < l; i+=1) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
