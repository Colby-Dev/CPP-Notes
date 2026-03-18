#include <iostream> 
using namespace std; 

/*

----- Data Encapsulation -----

> Program statements (code), This is the part of a program that performs actions and they are called functions

> Program data, The data is the information of the program which gets affected by the program functions. 

Encapsulation is an OOP concept that binds together the data and functions that manipulate the data, and that keeps both safe from outside interference and misuse.
Data encapsulation let to the important OOP concept of data hiding. 

Data encapsulation is a mechanism of bundling the data, and the functions that use them and data abstraction is a mechanism of exposing only the interfaces and hiding
implementation details from the user.

C++ supports the properties of encapsilation and data hiding through the creation of user-defined types, called classes. We already have studied that a class can contain
private, protected and public members.

    class Box {
        public: 
            double getVolume(void){
                return length * breadth * height;
            }

        private: 
            double length;
            double breadth;
            double height;
    };

The variables length, breadth, and height are private. This means that they can accessed only by other members of the Box class, and not by any other part of your program. 
This is one way encapsulation is achieved.

To make parts of a class public, you must declare them after the public keyword. All variables or functions defined after the public specifier are accessible by all over functions
in your program. 


*/