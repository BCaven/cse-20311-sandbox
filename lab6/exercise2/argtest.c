// argtest.c
#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("The executable (argv[0]) is: %s\n", argv[0]);
 
  printf("It read in %d arguments:\n", argc-1);
  int i;
  for (i = 1; i < argc; i++) {
    printf("\t argv[%d]: %s\n", i, argv[i]);
  }

  return 0;
}

