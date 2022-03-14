#include <stdio.h>
#include <math.h>

/*
	@author: John Blake Caven
	@date: 2-6-22
	@name: polar.c
	
	Fun Comp Lab 3:
		Part 2: quadrant and polar coordinates

*/

int get_quadrant(double x, double y);
double get_radius(double x, double y);
double get_angle(double x, double y);
void show_info(int a, double x, double y);

int main(void) {

	double x;
	double y;
	printf("x, y\n");
	scanf("%lf %lf", &x, &y);
	show_info(get_quadrant(x, y), x, y);
	return 0;
}
/* 
	

// quadrants:

   2  |   1
------|-------
   3  |   4

*/

int get_quadrant(double x, double y) {
	if (x >= 0) {
		if (y >= 0) {
			return 1;
		} else {
			return 4;
		}
	} else {
		if (y >= 0) {
			return 2;
		}
	} 
	return 3;
}
double get_radius(double x, double y) {
	double a = sqrt((x*x) + (y*y));
	return a;
}
double get_angle(double x, double y) {
	double a = atan(y/x);
	double b = (a * 180) / M_PI; // now in degrees
	/*
		need to check what quadrant it is in to change what the angle is from the positive x-axis

	*/
	switch (get_quadrant(x, y)) {
		case 1: // quad 1, no change needed
			return b;
			break;
		case 2: // quad 2, 180-b
			return 180 + b; 
			break;
		case 3: // quad 3
			return 180 + b;
			break;
		case 4: // quad 4
			return 360 + b;
			break;
		default:
			break;
	}
	return 0.0;
}
void show_info(int a, double x, double y) {
	printf("The point (%.2lf, %.2lf) is in quadrant %d\n", x, y, a);
	// TODO: polar coordinate print
	printf("The polar coordinate of (%.2lf, %.2lf) is (%.2lf, %.2lf) in the form (radius, angle in degrees)\n", x, y, get_radius(x, y), get_angle(x, y));
	return;
}
