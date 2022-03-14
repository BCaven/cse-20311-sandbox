/*
	@author: John Blake Caven

	@date: 1/25/22
	
	Lab 2 | Part 1: Multiplication Table

	Goal: Given a number of rows and columns, make a multiplication table of that size



*/


#include <stdio.h>

int main() {
	int r,c;
	

	// get rows and columns
	printf("Input rows and columns\n");
	scanf("%d %d", &r, &c);

	// print table:
	printf("*");
	int i, j; // as much as I like java for loops, I dont want to deal with the extra flags atm
	for (i = 0; i < c; i+=1) {
		printf("\t%d", (i+1));
	}
	printf("\n   ");
	for (i = 0; i < c; i+=1) {
		printf("--------");
	}
	printf("\n");
	for (i = 0; i < r; i+=1) {
		printf("%d |", i+1);
		for (j = 0; j < c; j+=1) {
			printf("\t%d", ((j+1)*(i+1)));
		}
		printf("\n");
	}
	
	
	
	return 0;
}
