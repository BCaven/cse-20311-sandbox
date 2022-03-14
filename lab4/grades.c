/*
	@author: John Blake Caven
	@date: 2-11-22
	@name: grades.c
	
	Lab 4 | Part 1: a simple array

*/

#include <stdio.h>
#include <math.h>
float avg(int *g, int s);
float stdev(int *g, float a, int s);
int main(void) {
	int g[36] = { // example grades...
		100,  50,  80,  68,  78,  90,  98,   78,   86,   94,   91,  60,
		 97, 100,  85,  79,  80,  68,  92,  100,  100,  100,  100,  96,
		 99,  97, 100, 	88,  98,  99, 100,   84,   82,   91,  100,  99 	
	};
	int s = sizeof(g) / sizeof(g[0]);
	printf("Number of grades: %d\n", s);
	printf("Average: %.2f\n", avg(g, s));
	printf("Standard Deviation %.2f\n", stdev(g, avg(g, s), s));
	
}
float avg(int *g, int s) { // average function
	double a = 0;
	int i;
	for (i = 0; i < s; i = i+1) {
		a += g[i];
	}
	return a / (s * 1.0);
}
float stdev(int *g, float a, int s) { // standard deviation function
	float t = 0;
	int i;
	for (i = 0; i < s; i+=1) {
		t += ((g[i]-a) * (g[i]-a));
	}
	return sqrt( t / (s * 1.0));
}
