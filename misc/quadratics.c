/*
	@author: John Blake Caven
	@name: quadratics.c
	@date: 2/3/22

	Lab 3	
	Exercise 1: multiple quadratic equations


*/


#include <stdio.h>
#include <math.h>


float quad(float a, float b, float c, int t); // prototype quadratic function
int main(void) {
	while (1) {
		float c1, c2, c3;
		printf("Enter a, b, and c\n");
		scanf("%f %f %f", &c1, &c2, &c3);
		if (c1 != 0.0) {
			float r1 = quad(c1, c2, c3, 0);
			float r2 = quad(c1, c2, c3, 1);
			if (((c2*c2)-(4.0*c1*c3))<0) {
				printf("No roots\n");
			} else if (r1 == r2) {
				printf("One root was found: %.2f\n", r1);
			} else {
				printf("The roots are %.2f and %.2f\n", r1, r2);
			}
		} else {
			printf("Bye!\n");
			return 0;
		}
	}

	return 0;
}
float quad(float a, float b, float c, int t) {
	float inside = (b*b) - (4 * a * c);
	if (inside < 0) {
		return 0;
	}
	if (t == 0) {
		return (((-1.0*b) + sqrt(inside)) / (2.0 * a));
	} else {
		return (((-1.0*b) - sqrt(inside)) / (2.0 * a));
	}
}
