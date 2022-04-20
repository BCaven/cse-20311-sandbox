#include <iostream>
using namespace std; // defines cout, endl, cin

/*
C++ supports function overloading

So far it looks identical to java overloading

*/

/*
c++ is backwards compatable with C
(pretty much any C command can be used in cpp)


compiler is 'g++'


*/

/*
If you dont use namespace:

for every cout, endl, cin

std::cout << "not using namespace";



compromise:

using std::cout;
using std::cin;
using std::endl;
...
for every single outside thing you use

instead of 'using namespace std;'

*/


/*
if you want to use c libraries:

include <cstdio> // <- instead of <stdio.h>
include <cmath> // <- instead of <math.h>



*/

void passReference(int &);
void func(int, int *, int &);

void func(int &);
void func(double &);


int main(void) {

    int a = 10;

    cout << "Hello world\n";

    cout << "a is " << a << "\n";

    /*
    Easy way to think about it: sending info to cout

    cout << "send this " << "then this " << "then this";

    prints: "send this then this then this"

    endl == "/n"
    
    */
    cout << "haha " << 1.34 << " wow it is so cool " << -1.0 << " passing all the stuff" << endl;

    /*
    cin >> variable_storing_the_value;
    
    */
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "n is " << n << endl;
    cout << "passing by reference\n";
    passReference(n);
    cout << "n is " << n << endl;
    int A = 10, B = 20, C = 30;
    func(A, &B, C);
    cout << A << " " << B << " " << C << endl;


   return 0;
}

void passReference(int &a) {
    a = a*2;
}
void func(int x, int *y, int &z) {
    x += 1;
    *y += 2;
    z += 3;
}