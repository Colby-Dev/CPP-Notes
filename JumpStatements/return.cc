#include <iostream>

using namespace std; 

/*
------ Return ------

The return statement in C++ is used to exit a function and to send a value back to the
function's caller which is optional depending on requirement. It plays very important
role in controlling the flow of a program and making sure that functions will provide
results to other parts of the code. 

------ Key Aspects -----

> Function Termination, When a return statment is executed, the function exits immeediately
 			and optionally sends value back to the caller. 

> Returning Types:
	Return by Value - In this specified value in statement is sent back to the caller. 
			  This is essential for function which perform calculations or need
			  provide results.
	
	No Return Value (void) - The functions which are declared with void, the return
				 statement can be used without an expression to exit
				 function early. 

> Multiple return statement, A function may consist of multiple return statements, which we
			     generally get to see within conditional statements.


> Returning Objects, Functions can return objects which can be useful returning multiple values
		     encapsulated in a class or struct

> Early Exit, The return statement can be used to exit a function early, 
	      which is useful for error handling or special conditions

------ Return Types and Value Handling in C++ ------

In C++, the return type of function determines what kind of value (if any) a function
will return to the caller. Proper handling of return types and values is important for
making sure that functions behave as expected and integrate smoothly with other parts
of the program. 

> Primitive Data Types, the basic built-in types provided by C++. 
		        Common exmaples are like int, double, char etc

> User-Define Types, User-defined types structs and classes. 
  		     These types allow you to define complex data structure
		     and customize them as per your specific requirements.


> References and Pointers, References and pointers are used to refer to variables 
			   or objects without making any copies. Which can be useful for efficiency and east to 
			   modify the original data when needed.		     
*/

int main(){

//Example with Struct

struct Point {

	int x;
	int y;
};
Point createPoint(int x, int y){

	Point p;
	p.x = x;
	p.y = y;
}

Point p = createPoint(10,20);
cout << "Point coordinates: (" << p.x << ", " << p.y << ")"<< endl;
return 0;

}
