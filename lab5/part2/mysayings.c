/**
		***	WARNING	***

			This program is not the same as the one submitted to dropbox
			I started to make changes then got lazy
			
**/


/*
	@author: John Blake Caven
	@date: 2-20-22
	@name: mysayings.c
	
	Lab 5:
	Part 2: A sayings manager

*/

#include <stdio.h>
#include <string.h>

void menu(void);
void sort(char s[50][256], int l, char name[30]);
void addLine(char s[50][256], int i, char name[30]); // I know this is probably not the best habit, but I am going to modify the original array instead of messing with C's janky system
void printSayings(char s[50][256], int l);
void sayingsContaining(char s[50][256], int l);
void saveInNewFile(char s[50][256], int l);
void rewriteFile(char s[50][256], int l, char name[30]);


int main(void) {
	char fname[30]; // file name
	char sayings[50][256]; // array of sayings
	printf("Please enter the file name: \n");
	scanf("%s", &fname); // get file name
	FILE *f;
	f = fopen(fname, "r");
	// read sayings in the file
	int i;
	if (f) {
		char l[256];
		fgets(l, sizeof(l), f);
		i = 0;
		while (!feof(f)) {
			strcpy(sayings[i], l);
			i+=1;
			fgets(l, sizeof(l), f);
		}	
		fclose(f);
	} else {
		printf("Sorry that file does not exist.\n");
		return 0;
	}
	int num = i;
	// we do not need to check if the file exists again, bc if it didnt the program would have already ended
	int usrIn;
	while (1) {
		menu();
		scanf("%d", &usrIn);
		printf("\n");
		switch(usrIn) {
			case 1:
				printf("The sayings:\n");
				printSayings(sayings, num);
				break;
			case 2:
				printf("Add a new line\n");
				addLine(sayings, num, fname);
				num += 1;
				break;
			case 3:
				printf("Search for sayings containing a certain word\n");
				sayingsContaining(sayings, num);
				break;
			case 4:
				printf("Save the sayings in a new file\n");
				saveInNewFile(sayings, num);
				break;
			case 5:
				printf("Sort the sayings in alphabetical order\n");
				sort(sayings, num, fname);
				printf("The file sorted:\n");
				printSayings(sayings, num);
				break;
			case 6:
				printf("Bye!\n");
				return 0;
				break;
			default:
				printf("Sorry that input is not understood\n");
				break;
		}		
	}
	return 0;
}

void menu(void) {
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("1. display all sayings currently in the database\n");
	printf("2. enter a new saying into the database\n");
	printf("3. list sayings that contain a given word enterd by the user\n");
	printf("4. save all sayings in a new text file\n");
	printf("5. sort the sayings by first letter of first word\n");
	printf("6. quit the program\n");
	printf("Choose one of the above options:\n");	
}
void sort(char s[50][256], int l, char name[30]) {
	int i, j;
	for (i = 0; i < l-1; i+=1) {
		for (j = i+1; j < l; j+=1) {
			if (s[i][0] > s[j][0]) {
				// swap
				char temp[256];
				strcpy(temp, s[i]);
				strcpy(s[i], s[j]);
				strcpy(s[j], temp);
			} else if (s[i][0] == s[j][0]) {
				if (strlen(s[i]) > strlen(s[j])) {
					char temp[256];
					strcpy(temp, s[i]);
					strcpy(s[i], s[j]);
					strcpy(s[j], temp);
				} else {
					char temp[256];
					strcpy(temp, s[j]);
					strcpy(s[j], s[i]);
					strcpy(s[i], temp);
				}
			}
		}
	}
	rewriteFile(s, l, name);

}
void addLine(char s[50][256], int i, char name[30]) {
	printf("Enter a new saying:\n");
	char a[256];
	fgets(a, 10, stdin); // garbage -> picks up the left over new line from scanf (My first collection was... poorly done... and fgets and scanf fight with each other)
	fgets(a, 256, stdin);
	strcpy(s[i], a);
	//printf("Entered line: %s\n", s[i]);
	FILE *f;
	f = fopen(name, "a");
	fprintf(f, s[i]);
	fclose(f);
}
void printSayings(char s[50][256], int l) {
	int i;
	for (i = 0; i < l; i+=1) {
		printf("%s\n", s[i]);
	}
}
void sayingsContaining(char s[50][256], int l) {
	printf("Enter a word to search for:\n");
	char word[256];
	scanf("%s", &word); // get the word to look for
	int check[l];
	memset(check, 0, sizeof(check));
	int num = 0;
	int c;
	int i;
	int j;
	for (c = 0; c < l; c+=1) {
		//printf("Current saying: %s\n", s[c]);
		for (i = 0; i < strlen(s[c])-strlen(word); i+=1) {
			int isFound = 0;
			for (j = 0; j < strlen(word); j+=1) {
				if (s[c][i+j] == word[j]) {
					isFound += 1;
				}
			}
			//printf("Number of characters matching: %d\n", isFound);
			if (isFound == strlen(word)) {
				check[c] = 1;
				num+=1;
				//printf("%s contains %s\n", s[c], word);
			}
		}
	}
	printf("%d sayings contained %s\n", num, word);
	if (num > 0) {
		printf("They were:\n");
		for (i = 0; i < l; i+=1) {
			if (check[i] == 1) {
				printf("%s", s[i]);
			}
		}	
	}
}
void saveInNewFile(char s[50][256], int l) {
	char name[30];
	
	printf("Enter the name of the new file\n");
	scanf("%s", &name);
	//scanf("%s", &name); // clear the **** buffer
	FILE *f;
	f = fopen(name, "w");
	int i;
	for (i = 0; i < l; i+=1) {
		fprintf(f, s[i]);
	}
	fclose(f);
}
void rewriteFile(char s[50][256], int l, char name[30]) {
	FILE *f;
	f = fopen(name, "w");
	int i;
	for (i = 0; i < l; i+=1) {
		fprintf(f, s[i]);
	}
	fclose(f);
}