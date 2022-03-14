#include <stdio.h>

/*
	@author: John Blake Caven
	@date: 2-6-22
	@name: menucalc.c
	
	Lab 3:
		Part 3: text menu calculator

*/

int calc(void);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main(void) {

	calc();
	return 0;
}
int calc(void) {
	// TODO: option select
	printf("- - - - - - - - - - - - - - - - - - - - - - -\n\n");
	printf("1) add\n2) subtract\n3) multiply\n4) divide\n5) End\n");
	int o = 0; // option chosen
	scanf("%d", &o);
	if (o == 5) {
		printf("bye!\n");
		
		return 0;
	}
	double a = 0;
	double b = 0;
	double div = 0;
	if (o >=1 && o <= 4) {
		printf("First value: ");
		scanf("%lf", &a);
		printf("Second value: ");
		scanf("%lf", &b);
		printf("\n");
	}
	switch (o) {
		case 1:
			printf("%.2lf + %.2lf = %.2lf\n", a, b, add(a, b)); 
			break;
		case 2:
			printf("%.2lf - %.2lf = %.2lf\n", a, b, subtract(a, b));
			break;
		case 3:
			printf("%.2lf * %.2lf = %.2lf\n", a, b, multiply(a, b));
			break;
		case 4:	// those -0 / 0 values better be distinct...
			div = divide(a, b);
			if (div == 9999999999) {
				printf("You cannot divide by zero\n");
				break;
			} else {
				printf("%.2lf / %.2lf = %.2lf\n", a, b, div);
			}
			break;
		default:
			printf("Sorry that option is not on the list.\n");
			break; // its polite...
	}
	calc(); // hehe...
	return 0;
}
double add(double a, double b) {
	return a + b;
}
double subtract(double a, double b) {
	return a - b;
}
double multiply(double a, double b) {
	return a * b;
}
double divide(double a, double b) {
	if (b == 0 || b == -0) {
		return 9999999999; // using that as an error code
	}
	if (a == 0 || a == -0) {
		return 0;
	}
	return a / b;
}
