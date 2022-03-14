#include <stdio.h>

void main(void) {

   printf("Traffic today");
   printf(" is very light\n");
   int num;
   printf("Input a number: ");
   scanf("%d", &num);
   printf("\n");
   printf("Your number is %5d \n", num); // formatting integers
	/*
	using %d you can tell the compiler to use a fixed width for the number
	by adding a number between the % and d

	this looks like: "%3d"
	

	basic formatting keys:
		%f = floats
		%d = ints(?)
		%lf = long float // basically uses more memory to allow for larger numbers <- best practice for doubles
		
		six digits are given afte decimal by default
		
		

		%	
	
	More formatting:
	%9.2f
	#.# <- spaces before decimal.places after decimal
		- do not need the # before the decimal place if you are only looking to round
		- rounds up
	*/
		
	/*
		Formatting:
		%9.2f
		9 = total width (including signs, punctuation, numbers, etc)
		2 = number of decimal places
		

		Common trends:
			Have a prompt (print statement) before an input to 
			indicate where it is
			
			The user almost never functions as intended

			& = address of (a variable)
			
			Whitespace is not a delimiter in C (including inputs)
		
	*/
   int a = 1;
   int b = 2;
   int c = 3;
   printf("a: %d\nb: %d\nc: %d\n", a, b, c);
   

   double test = 12.3456;
   printf("Formatted: %4.2lf", test);
   printf("\n");
   // general formatting tips: if you do not end the program output
   // with a new line it will put the terminal input on the same line
   // which is gross
}
ex
