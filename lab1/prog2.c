#include <stdio.h>

#include <math.h>
// dont forget to compile with the -lm when compiling
// so it would be: gcc -o prog2.c prog2 -lm

int main() {
	// using curly brackets on new lines is gross.
	
	/*
	Equation I want to use:
		vector cross product?
			
		
	*/
	
	// vector cross product
	
	int v1x, v1y, v1z, v2x, v2y, v2z;
	printf("Enter the vector components of two 3D vectors in the format\nx1 y1 z1 x2 y2 z2\n");
	scanf("%d %d %d %d %d %d", &v1x, &v1y, &v1z, &v2x, &v2y, &v2z);
	
	int i = (v1y * v2z) - (v1z * v2y);
	int j = -1 * ((v1x * v2z) - (v1z * v2x));
	int k = (v1x * v2y) - (v2x * v1y);

	printf("Cross product of the two vectors: <%d, %d, %d>\n", i, j, k);
	
	return 0;
}
