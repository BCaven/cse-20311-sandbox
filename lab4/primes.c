/*
	@author: John Blake Caven
	@date: 2-11-22
	@name: primes.c

	Lab 4 | Part 2: prime numbers


	I hate C. Why is it unable to return arrays
*/

#include <stdio.h>
#include <math.h> // lmao

int primes(int num);
int main(void) {
	int i = primes(0);
	int n = 0;
	while (i != -1) { // function returns -1 when there are no more primes
		printf("%5d ", i);
		n += 1;
		i = primes(n);
		if (n % 10 == 0) { // line break every 10th item
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}
int primes(int num) {
	// make array of 1s
	int isPrime[1000];
	int i;
	for (i = 0; i < 1000; i+=1) {
		isPrime[i] = 1;
	}
	isPrime[0] = 0;
	i = 2;
	int j;
	int s = 1000;
	int b = sqrt(1000);  // trying too hard
	// remove all multiples from the list
	// O(sqrt(n)n) <- big sad
	for (j = 2; j < b; j+=1) {
		for (i = 2; (i*j) <= 1000; i+=1) { 			// ok this is actually kinda cool
			isPrime[(i*j)-1] = 0; //mark all non-primes	// still O(sqrt(n)n) tho...
		}		
	}
	// make an array of just the primes
	int a[1000];
	int n = 0;
	for (i = 0; i < 1000; i+=1) {
		if (isPrime[i] == 1) {
			a[n] = i + 1;
			n+=1;
		}
	} 
	a[n]=-1;
	
	//printf("s:%d\n", s);
	if (num > n-1) {
		return -1; // all primes have been found
	}
	return a[num]; // coding with c makes me tired	
}


