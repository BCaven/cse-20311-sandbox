/*
	@author: John Blake Caven
	@date: 2-7-22
	@name:five.c

	
*/


#include <stdio.h>

int main(void) {
	int num[5];
	int i;
	for (i = 0; i < 5; i+=1) {
		printf("Enter a number: ");	
		scanf("%d", &num[i]);
	}
	int j;
	for (j = 4; j >=0; j-=1) {
		printf("%d ", num[j]);
	}
	printf("\n");
	return 0;
}
