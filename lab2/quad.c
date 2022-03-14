#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c;
	printf("Enter the coefficients a, b, and c\n");
	scanf("%f %f %f", &a, &b, &c);
	/*
		Quadratic formula:
		-b +- sqrt(b^2-4ac) / 2a
		
	*/
	
	// calc roots
	float r1t, rb, r1, r2t, r2;
	float inner = (b*b) - (4*a*c);
	if (inner >= 0) { // check if the roots exist
		// root 1		

		r1t = (-1.0*b) + sqrt(inner);
		rb = 2 * a;
		r1 = r1t / rb;
		printf("Root 1: %f\n", r1);
		
		// root 2
		r2t = (-1.0*b) - sqrt(inner);
		if (r2t != r1t) {
			printf("Root 2: %f\n", r2t/rb);
		} else {
			printf("There is only one root\n");
		}
	} else {
		printf("There are no real roots\n");
	}	

	
	return 0;
}
