#include <iostream>

using namespace std; 

/* 
----- Storage Classes -----
A storage class defines the scope (visibility) and life-time of variables
and/or functions within a program. These specifiers precede the type 
that they modify. There are the following storage classes: 

*/

int main(){ 

// Auto - default storeage for all local vars
// ------------------------------------------

int mount;

// Register - (depricated) storage class is used to define local variables that should be stored in a register instead of ram.
// ------------------------------------------

//register miles;

// Static - the storage class instructs the complier to keep local variable in existence during the life-time of the program 
// instead of creating and destroying it each time it goes into and out of scope. 
// It causes only one copy of that member to be shared by all objects of its class.
// ------------------------------------------

static int count = 10; // local static variable

// Extern - the extern storage class is used to give a ref of a global variable that is visible to all program files.
// when you use the extern storage, the variable cannot be initialized as it points to the variable name at the storage location.
// this is commonly used when there are 2 or more files. 
// ------------------------------------------

extern void write_extern();

// Mutable - only applies to class objects. It allows an object to override const member function
// ------------------------------------------


}