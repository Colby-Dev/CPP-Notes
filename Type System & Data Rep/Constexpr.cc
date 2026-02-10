#include <iostream>

using namespace std; 

/* 
----- Constexpr Specifier -----
The constexpr specifier calculates the value of a variable 
or the return value of a function at compile time. 

Calculating the values during compilation time improves the performance of the code. 
It helps in faster execution of programs; 
since the value is already known during compliation.

------ Why we need constexpr in C++ ------

-> Performance optimization
----------------------------
All the overhead of calculating
mathematical expressions has now shifted from 
runtime to compile time. This helps in faster
execution of program, as no computation is 
needed at runtime. 

-> Better compile-time constant
-------------------------------
Features such as array size, switch case labels, 
and template parameters require value during compilation
which can be provided using contexpr specifier, but there is no 
guarantee with the const keyword. 

-> Decalring Variables with constexpr
-------------------------------------
You can use contexpr specifier to decalre a variable. 
The rule for decalring a variables with constxpr is that it should
be initialized with a constant expression. 

-> Functions with Constexpr Specifier
-------------------------------------
You can use constexpr to define a function. The parameter and return type
of the function should be of literal type. (int, double, char, bool).
The function cannot have any side effects. 
A constexpr function can only call other constexpr functions, not simple functions.

-> Contructors with Constexpr Specifier
-----------------------------------------
The constexpr specifier can be used to create classes, objects, and declare a constructor. 
To declare a constructor, we must:

> Use literal type parameters
> Cannot have virtual base classes
> Only other constexpr constuctors and functions can be called
> Cannot have mutable data members
> Cannot have a try/catch

-> Use Cases of Constexpr Specifier
------------------------------------
There are multiple practicial use cases of constexpr specifier
in various scenarios. Here are some of the uses mentioned below: 

> Array Sizes at Compile-time
> Mathematical Computations
> Using Constexpr in Switch Case Labels 

-> Difference between Const and Constexpr
-----------------------------------------
Const              | Constexpr
-------------------|---------------------
Values can be      | Values must be evaluated
evaluated at       | at compile time.
compile time or    |  
run time           |
-------------------|--------------------

-> Limitations of Constexpr Specifier
----------------------------------------
There are various advantages of using a constexpr specifier
such as reducing the runtime overhead and increasing the 
performance but there are some limitations too that are 
mentioned: 

> The input and output operation (cin/cout) cannot be used in constexpr functions
> It does not support dynamic memory allocation
> One constexpr function can only call another constexpr function. 
  We can not call other normal functions.
> There is no support for exception handling. 
> Function parameters or return type can only be of literal type. 


*/
//Example
constexpr int sum (int a, int b){
    return a + b; 
}

int main(){

    constexpr int x = sum(10,2);
    cout << "10 + 2 = " << x << endl;
    return 0;
}