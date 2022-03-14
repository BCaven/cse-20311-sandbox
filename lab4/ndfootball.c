/*
	@author: John Blake Caven
	@date: 2-13-22
	@name: ndfootball.c

	Lab 4 : Part 3
	
	Notre Dame football statistics

*/

#include <stdio.h>
#include "nd_data.h"

void getRecord(int y);
void getYearWins(int w);
void getYearLosses(int l);
void getWinningSeasons();
void yearsWithMoreLosses();
void menu();
int main(void) {
	
	int c;
	int z;
	while(1) {
		menu();
		scanf("%d", &c);
		switch(c) {
			case 1:
				printf("What year do you want the record for?\n");
				scanf("%d", &z);
				getRecord(z);
				break;
			case 2:
				printf("What is the minimum number of wins?\n");
				scanf("%d", &z);
				getYearWins(z);
				break;
			case 3:
				printf("What is the minimum number of losses?\n");
				scanf("%d", &z);
				getYearLosses(z);
				break;
			case 4:
				getWinningSeasons();
				break;
			case 5:
				yearsWithMoreLosses();
				break;
			case 6:
				printf("Bye!\n");
				return 0;
				break;
			default:
				printf("Sorry, that option is not on the menu.\n");
				break;
			
		
		}	
	}
	return 0;
}
void menu() {
	printf("\n- - - - - - - - - -\n");
	printf("Notre Dame Football\n");
	printf("- - - - - - - - - -\n");
	printf("1) Get the record of a specific year\n");
	printf("2) Get years with at least a certain number of wins\n");
	printf("3) Get years with at least a certain number of losses\n");
	printf("4) Get years with undefeated seasons\n");
	printf("5) Get years with losing seasons\n");
	printf("6) Quit\n");
	printf("Please enter one of the above options:\n");
}
void getRecord(int y) {
	if (y-1900 >= 0 && y-1900 < sizeof(wins) / sizeof(wins[0])) {
		printf("In year %d there were %d wins and %d losses.\n", y, wins[y-1900], losses[y-1900]);	
	} else {
		printf("Sorry the year you entered is not in the list\n");
	}
}
void getYearWins(int w) {
	int a[sizeof(wins)/sizeof(wins[0])];
	int i;
	int c = 0;
	for (i = 0; i < sizeof(wins)/sizeof(wins[0]); i+=1) {
		if (w <= wins[i]) {
			a[c] = i + 1900;
			c += 1;
		}	
	}
	a[c] = -1;
	if (a[0] == -1) {
		printf("There were no years with at least %d wins\n", w);
		return;
	}
	printf("Years with at least %d wins:\n", w);
	c = 0;
	while (a[c] != -1) {
		printf("%d ", a[c]);
		c += 1;
	} 
	printf("\n");
}
void getYearLosses(int l) {
	int a[sizeof(wins)/sizeof(wins[0])];
	int i;
	int c = 0;
	for (i = 0; i < sizeof(wins)/sizeof(wins[0]); i+=1) {
		if (l <= losses[i]) {
			a[c] = i + 1900;
			c += 1;
		}
	}
	a[c] = -1;
	if (a[0] == -1) {
		printf("There were no years with at least %d losses\n", l);
		return;
	}
	printf("Years with at least %d losses:\n", l);
	c = 0;
	while(a[c] != -1) {
		printf("%d ", a[c]);
		c += 1;
	}
	printf("\n");
}
void getWinningSeasons() {
	int a[sizeof(wins)/sizeof(wins[0])];
	int i;
	int c = 0;
	for (i = 0; i < sizeof(wins)/sizeof(wins[0]); i+=1) {
		if (losses[i] == 0) {
			a[c] = i + 1900;
			c += 1;
		}
	}
	a[c] = -1;
	printf("Years with no losses:\n");
	c = 0;
	while(a[c] != -1) {
		printf("%d ", a[c]);
		c += 1;
	}
	printf("\n");
}
void yearsWithMoreLosses() {
	int a[sizeof(wins)/sizeof(wins[0])];
	int i;
	int c = 0;
	for (i = 0; i < sizeof(wins)/sizeof(wins[0]); i+=1) {
		if (losses[i] > wins[i]) {
			a[c] = i + 1900;
			c += 1;
		}
	}
	a[c] = -1; // -1 is indicator for the end of the list
	printf("Years with more losses than wins:\n");
	c = 0;
	while(a[c] != -1) {
		printf("%d ", a[c]);
		c += 1;
	}
	printf("\n");
}
