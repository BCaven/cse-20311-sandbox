#include <stdio.h>
#include <math.h>


int main() {
	int sumSquare = 0;
	float sumRoot = 0;
	int i;
	for (i = 1; i <= 10; i++) {
		printf("%d", i);
		sumSquare += i*i;
		sumRoot += sqrt(i);
	}
	printf("\n");
	printf("Sum of the squares: %d\nSum of the roots: %f\n", sumSquare, sumRoot);
	
	
	
	return 0;
}
