#include <iostream> 

using namespace std;

// ---- Declaring Multiple Variables in C++ ----
// This is executed using a comma (,) seperated listing of vars with different names.
// THe data types must be the same for all variables to be declared. 

int main(){

    //Example of multiple declarations
    int x,y,z;

    x = 10;
    y = 20;
    z = 30;

    // Example of multiple initializations
    int a = 10, b = 20, c = 30;

    // Eample of multiple initializaitons of te same value
    int e,f,g;
    int e=f=g= 100;

    int *i = &x;

    cout<<i;

}