#include <stdio.h>
#include <math.h> // dont forget the -lm flag

/*
	@author: John Blake Caven
	@date: 1-30-22
	
	Program: ASCII Plot




*/

int main(void) {
	float i = 0;
	int r = 0;
	printf("Range: ");
	scanf("%d", &r);
	printf("Plot for | 2sin(2i) - x^2 + 4/(x+1) + cos(2x) | from 0 to %d\n", r);
	printf("     X     Y\n");
	float maxX = 0;
	float maxY = 0;
	float minX = 0;
	float minY = 3; // value of Y when X = 0
	for (i = 0; i < r; i += .2) {
		// function: abs( x^2 + 4/(x+1) + cos(x*2)) <- using radians
		float a = (2*sin(2*i)) - (i*i) + (4.0/(i+1)) + cos(i);
		if (a < 0) {
			a = a * -1;
		}

		printf("%6.2f %6.2f  ", i, a);
		int j;
		// printf("a: %5.2f  ", a); // debugging
		int b = floor(a);
		for (j = 0; j < b; j += 2) {
			printf("#");	
		}
		
		printf("\n");
		if (a > maxY) {
			maxY = a;
			maxX = i;
		} else if (a < minY) {
			minY = a;
			minX = i;
		}
		
	}
	printf("Maximum x: %5.2f Maximum y: %5.2f\nMinimum x: %5.2f Minimum y: %5.2f\n", maxX, maxY, minX, minY);

	return 0;
}
