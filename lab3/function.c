#include <stdio.h>

float perimeter(float l, float w);
float area(float l, float w);
int main(void) {
	float length = 0;
	float width = 0;
	printf("Length:\nWidth:\n");
	scanf("%f %f", &length, &width);
	float a = area(length, width);
	float p = perimeter(length, width);
	printf("Area: %.2f\nPerimeter: %.2f\n", a, p);
	return 0;
}
float perimeter(float l, float w) {
	return (2*(l+w));
}
float area(float l, float w) {
	return (l*w);
}
