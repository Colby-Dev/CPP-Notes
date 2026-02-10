#include <iostream> 

using namespace std;

/* 
----- Defining Numbers in C++ -----
You have already defined numbers in various examples given in previous chapters.
The number data types. (short, int, long, float, etc.)

-> Math Operations in C++
-------------------------------
In addition to the various functions yo ucan create, c++ also includes some useful functions.
These are available in standard C++ and are built in. 

Function                     | Purpose       
_____________________________|________________________________________________________
double cos(double)           | This function takes an angle (as a double) and returns the cosine
_____________________________|_________________________________________________________
double sin(double)           | This function takes an angle (as a double) and returns the sine
_____________________________|_________________________________________________________
double tan(double)           | This function takes an angle (as a double) and returns the tangent
_____________________________|_________________________________________________________
double log(double)           | This function takes a number (as a double) and returns the natural log
_____________________________|_________________________________________________________
double pow(double, double)   | The first is a number you wish to raise and the second is
                             | the power you wish to raise it to
_____________________________|__________________________________________________
double hypot(double, double) | The first is a number you wish to raise and the second is
                             | the power you wish to raise it to
_____________________________|_________________________________________________
double sqrt(double)          | You pass this function a number and it gives you the sqrt
_____________________________|_________________________________________________
int abs(int)                 | This function returns the absolute value of an integer that 
                             | is passed to it. 
_____________________________|_________________________________________________
double fabs(double)          | This function returns the absolute value of any 
                             | decimal number passed to it.  
_____________________________|_________________________________________________
double floor(double)         | Finds the integer which is less than or equal to the argument passed to it 
_____________________________|_________________________________________________

-> Random Numbers in C++
------------------------------
There are many cases where you will wish to generate 
a random number. THere are actually two functions you
will need to know about rnd number generation.The first,
rand() this function will only return a pseudo random number.
srand() fixes this. 

*/

int main(){

    int i, j;
    srand((unsigned)time(NULL));
    for(i = 0; i < 4; i++){
        j = rand();
        cout<<"Random Number: " << j <<endl;
    }
    return 0;

}