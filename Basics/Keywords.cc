#include <iostream>

using namespace std;

int main(){

    //Storage Class Keywords:

    - auto, The complier automatically deduces the variable's type

    - register, It suggest that the variable should be stored in a CPU register for faster access

    - static, It indicates tat the variable retains its value even after the scope in which it was defined ends

    - extern, It declares a variable that is defined in another translation unit

    - mutable, It allows a member of a class to be modified even if the object is a constant. 
    

    //Modifiers:

    - const, It indicates that a varaible's value cannot be changed after intialization. 

    - volatile, It indicates that a vartiable's value may change unexpectedly, preventing certain compiler optimizations

    - signed, It indicates that a data type can hold both positive and negative values

    - unsigned, It indicates that a data type can only hold non-negative values

    - short, It indicates a shorter version of the interger type

    - long, It iindicates a longer version the interger type
    
    

    //Functions

    - inline, Suggests to the compiler to attempt to expand the function line, reducing the overhead of a function call.

    - virtual, Indicates that a function can be overridden in derived classes

    - explicit, Prevents implicit conversions for contructors or conversion operators. 
    
    //Class and Object Keywords

    - Class Definitions: class,struct,union,enum
    - Namespace Management: namespace, this
    - Memory Management: new, delete

    //Access Specifiers

    - Public
    - Protected
    - Private 

    //Exception Handling Keywords

    - Try, It defines a block of code to be tested for exception
    - Catch, It defines a block of code that handles exceptions thrown by a corresponding try
    - Throw, Used to signal the occurrence of an exception

    //Operator Keywords

    - sizeof
    - typeid
    - alignof
    - alignas 

    //Namespace Keywords

    - namespace, Defines a scope that can contain identifiers to avoid name collisions
    - using, Allows the use of names from a namespace without qualification

    //Type Casting Keywords

    - static_cast, It performs a complie-time type check and conversion
    - dynamic_cast, Safely converts pointers or references within an inheritance hierachy
    - const_cast, It adds or removes const or volatile qualifers
    - reinterpret_cast, It converts any pointer type to any other pointer type with no safety checks.

    //Miscellaneous Keywords 

    - using, typedef
    - Type Traits, decltype, static_assert
    - Casting Operators, static_cast, dynamic_cast, const_cast, reinterpret_cast

    
    




}