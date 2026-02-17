#include <iostream>

using namespace std;

/*

----- Deferencing -----

Dereferencing is the process that helps in accessing the value that a pointer points to.
Where pointers store the memory address of that particular value. To access of modify
the value stored at that address, you can use the derefence operator denoted by (*). 

--- Dereferencing to Read a Value ---

Here is the syntax to access the value, which is stored at the address the pointer points to: 

    Type value = *pointer; 

--- Dereferencing to Modify a Value --- 

Syntax of dereference operator to modify the value at the address the pointer points to: 

    *pointer = newValue;


*/

int main(){

    int number = 42; 
    int *ptr = &number;

    cout << "Original Value: " << *ptr << endl;
    
    *ptr = 100;
    cout << "Modified Value: " << number << endl;
    return 0;
}