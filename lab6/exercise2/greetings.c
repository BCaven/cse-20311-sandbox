// greetings.c
// simple example to showcase the use of argc/argv

#include <stdio.h>

int main(int argc, char *argv[])
{
   if (argc == 1) {  // user just types the executable, nothing else
      puts("you need to enter a name");
      return 1;
   } else if (argc > 2) {  // user types more than one name after executable
      puts("too many names");
      return 2;
   } else {  // user correctly typed only one name after executable; argv[1] is that name
      printf("hello %s, how are you?\n", argv[1]);
   }

   return 0;
}

