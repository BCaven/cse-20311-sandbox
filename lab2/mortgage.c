#include <stdio.h>
#include <math.h> // remember the -lm flag

/*
	@author: John Blake Caven
	@date: 1/24/22

	Lab 2 | Part 2: Mortgage Calculator


*/

int main() {
	float ia = 0; // initial amount
	float ir = 0; // interest rate
	float mp = 0; // monthly payment
	float tl = 0; // time length
	while (ia == 0) {	
		printf("Principal: \nInterest rate: \nDesired Monthly Payment: \n");
		scanf("%f %f %f", &ia, &ir, &mp);
	}
	float ar = ia; // amount remaining
	float mi = (ir/12)/100; // assumes that the given interest rate was per year
				// and that it was given in percent form (e.g. 5%) 
	int m = 1; // month
	
	float t = 0; // total
	if ((ar*mi)>mp) { // the total amount owed grows larger because the monthly payment does not deal with the growth from the interest
		printf("Your loan will never be paid off at that rate\n");
		return 0;
	}	
	printf("Month\tPayment\t\tInterest\tBalance\n");
	while (ar > 0) {
		float i = ar*mi;
		ar = ar + i; // add on the monthly interest increase...
		float p = mp;
		if (ar - mp > 0) {
			ar = ar - p; // subtract the monthly payment
		} else {
			p = ar;
			ar = 0;
		}
		t = t + p;
		printf("%d\t$%10.2f  $%10.2f  $%10.2f\n", m, p, i, ar);
		m = m + 1; 
	}
	float y = floor(1.0*(m-1)/12.0);
	m = (m-1) % 12;
	printf("You paid a total of $%.2f over %.0f years and %d month(s)\n", t, y, m); 


	return 0;
}
