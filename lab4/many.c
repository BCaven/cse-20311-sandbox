#include <stdio.h>

int main(void) {
	int num[20];
	int n = 0;
	int i;
	while (i != -1) {
		scanf("%d", &i);
		num[n] = i;
		n+=1;
	}
	// print
	int j;
	for (j = n-2; j >= 0; j-=1) {
		printf("%d ", num[j]);
	}	
	printf("\n");
	return 0;
}
