#include <iostream>

using namespace std;

/* 
----- References vs Pointers -----
A reference is another name for an already existing variable. 
A pointer refers to a location of an object in memory.
References cannot be null, initialized when it is created, and cannot refer to another object.

A variable name is a label attached to the variable's location in memory.
A reference is a second label attached to that memory location.

References are usually used for function argument lists and function return values.
passing references as function params is much safer as it only references the vaue.

*/


int i = 17; 
int& r = i;



main(){

    cout << "This is a reference to int i: "<<r<<endl;
    return 0;

}