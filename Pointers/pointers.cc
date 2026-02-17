#include <iostream>

using namespace std; 

/*
------ Pointers ------

Pointers are easy and fun to learn. Some C++ tasks are performed more easily with pointers, and other C++ tasks,
such as dynamic memory allocation, cannot be performed without them. 

As know every variable is a memory location and every memory location has its address defined which
can be accessed using ampersand (&) operator which denotes an address in memory. Consider the following which will print the
address of the variable defined: 

    int  var1;
    char var2[10];

    cout << "Address of var1 variable: ";
    cout << &var1 << endl;


--- What are Pointers? ---

A pointer is a variable whose value is the address of another variable. Like any variable or constant, you must declare
a pointer before you can work with it. The general form of a pointer variable declaration is:

    type *var-name;

Here, type is the pointer's base type; it must be a valid C++ type and var-name is the name of the pointer variable.
The asterisk you used to decalre a pointer is the same asterisk that you use for multiplication. However, in this
statement the asterisk is being used to designed a variable as a pointer: 

    int *ip;
    double  *dp;
    float *fp;
    char *ch;

The actual data type of the value of all pointers, whether integer, float, character, or otherwise, is the same, a long
hexadecimal number that represents a memory address. The only difference between pointer of different data types is
the data type of the variable of constant the pointer points to. 

--- Using Pointers in C++ ---

There are few important operations, which we will do with the pointer very frequently. 

 > We define a pointer variable.
 > Assign the address of a variable to a pointer.
 > Finally access the value at the address available in the pointer variable.

 This is done by using uary operator * that returns the value of the variable located at the address specified by its operand.

--- Pointers in C++ ---

> Null Pointers - a constant with a value of zero defined in several standard libraries. 

> Pointer Arithmetic - there are four arithmetic operators that can be used on pointers (++, --, +, -)

> Pointers vs Arrays - there is a close relationship between pointers and arrays

> Array of Pointers - you can define arrays to hold a number of pointers

> Pointer to Pointer - C++ allows you to have pointers on a pointer and so on 

> Passing Pointers to Functions - Passing an argument by reference or by address both enable the passed argument to be
                                  changed in the calling function by the called function.

> Return Pointer from Functions - C++ allows a function to return a pointer to local variable, static variable and dynamically
                                  allocated memory as well.
*/


int main(){

    int var = 20;
    int *ip;

    ip = &var;

    cout << "Value of var variable: ";
    cout << var << endl;

    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    cout << "Value of *ip variable: ";
    cout << *ip << endl;

    return 0;
}
