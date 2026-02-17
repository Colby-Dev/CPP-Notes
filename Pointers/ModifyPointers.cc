#include <iostream> 

using namespace std; 
/*
----- Modify Pointers -----

A pointer is a variable that stores the memory address of another variable. Instead of holding
a data value directly, a pointer holds the memory location of the value. 

--- What is Modifying Pointers in C++? ----

Modifying the pointer value in C++ refers to the process of changing the memory address or changing
value stored at the memory address the pointer is pointing to. 

--- Approach to Modify Pointers --- 

Begin with declaring a pointer variable and initializing it. To modify the pointer's value, assign
a new address to it. If using dynamic memory, allocate new memory using new and assign its address to the pointer.
After modifying the pointer, you can dereference it to access or modify the value at the new address. 

If you allocate memory dynamically, ensure to release it using delete to prevent memory leaks. 

*/



int main(){

    int var1 = 10;
    int var2 = 20;

    int *ptr = &var1;
    cout << "Value pointed by ptr: " << *ptr << endl;

    ptr = &var2
    cout << "Value pointed by ptr after modification: " << *ptr << endl;

    int *dynamicPtr = new int(30);
    ptr = dynamicPtr;
    cout << "Value pointed by ptr after dunamic allocation: " << *ptr << endl;

    delete dynamicPtr;

    return 0;

}