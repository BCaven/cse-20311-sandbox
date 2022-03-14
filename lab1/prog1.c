#include <stdio.h>

int main() {
	int td, ep, fg, s;
	printf("Please enter the number of touchdowns, extra points, field goals, and safeties\n");
	scanf("%d %d %d %d", &td, &ep, &fg, &s);
	int t = (td*6) + (ep*1) + (fg*3) + (s*2);
	printf("Total number of points scored by the Irish: %d\n", t);
	
	
	

	return 0;
}
