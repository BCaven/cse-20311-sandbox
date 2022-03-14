/*
	@author: John Blake Caven
	@date: 2-18-22
	@name: letterfreq.c

	Lab 5: Part 1
		Justifying Scrabble's Letter Values

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>	// look up what this actually does... :D


int addChar(char c);

int main(void) {
	int count[26] = {0};
	FILE *f;
	char fname[30];
	printf("Enter the file name:\n");
	scanf("%s", &fname);
	
	f = fopen(fname, "r");
	char ch = fgetc(f);
	int t = -1; // total number of characters
	while (ch != EOF) {
		if (addChar(ch) != -1) {
			count[addChar(ch)] += 1;
		}
		t+=1;
		ch = fgetc(f);
	}
	fclose(f);
	int tl = 0; // total number of letters
	int i;
	for (i = 0; i < sizeof(count)/sizeof(count[0]); i+=1) {
		tl += count[i];
	}
	printf("------ results for %s ------\n", fname);
	printf("Total number of characters: %d\n", t);
	printf("Total number of letters: %d\n", tl);
	printf("Count of characters:\n");
	
	int j;
	char a;
	for (j = 0; j < 26; j+=1) {
		//printf("why\n");
		int temp = j + 65;
		int why = count[j];
		printf("%5c : %d", temp, why);
		if (j % 5 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	/*
	for (i = 0; i < sizeof(count)/sizeof(0); i = i + 1) {
		char a = i + 65;
		printf("%5s: %d", a, i);
		if (i % 5 == 0) {
			printf("\n");
		}	
	}
	*/
	printf("Percents of characters:\n");
	for (i = 0; i < 26; i = i + 1) {
		double percent = ((1.0 * count[i]) / (tl * 1.0)) * 100.0;
		printf("%5c: %%%.1lf", i+65, percent);	
		if (i % 5 == 0) {
			printf("\n");
		}
	}
	return 0;
}

int addChar(char c) {
	int a = c;
	if (a >= 65 && a <= 90) {
		return a-65;
	} else if (a >= 97 && a <=122) {
		return a-97;
	}
	return -1;	
}
