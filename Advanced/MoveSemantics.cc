/*

----- Move Semantics -----

Move semantics are used in C++ to transfer the ownership of resources from one object to another instead of copying them. It imporoves the performance as it avoids unnecessary copying of objects, reducing memory usage, improves efficiency, and efficiently handles the temporary objects like rvalue. 

--- Why Move Semantics are Needed? ---

Before C++11, we used to copy the resource an it was less efficient and created duplicates. In C++11, move 
semantics were introduced to solve this problem of memory overhead and reducing the duplicates. Here are reasons why we need move semantics: 

 > Move semantics avoid copying of resources. It helps in avoiding duplicates and cause less memory overhead.

 > It handles temporary objects like rvalues. 

 > It improves the performance by moving the resources instead of copying. 

--- Expression Types in C++ ---

An expression in C++ means any valid combination of variable, operator, constant, and function call that can give result. There are two types of expression which are as follows: 

 > lvalue Expression, an lvalue is a type of expression in which object has a memory address and can be modified if it is not const. Example of lvalue can be a variable, array elements, and many more. 

 an lvalue reference is used to create a referance to an lvalue. It is denoted by (&) and is used for implementing copy semantics. 

 > rvalue Expression, an rvalue is a type of expression that does not have a memory address and it represents a value that generally appears on the right side. It is a temporary expression that is about to get destroyed. Example of rvalue can be a constant, temporary object, and many more. 

 an rvalue reference 


*/
