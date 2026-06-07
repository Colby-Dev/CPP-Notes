/*
 
----- Lambda Expression in C++ -----

A lambda expression in C++ 11 allows the user to define an anonymous function (a function without any name) inline, which captures variables from the surrounding scope. This makes them a powerful feature for various use cases, like callbacks, sorting, functional programming, etc. Syntax:

	[capture](parameters) -> return_type
	{
		function_body
	}

where: 

	> capture, specifies which variables from the outer scope are captured.
	
	> parameters, are the input parameters for lambda.

	> return_type, defines the return type of the lambda function. if the return type  			 
		       needs to be explicitly defined, it will follow this -> symbol. 
	
	> body, is the main body of the lambda, where function logic is written. 

(see Example 1)

--- Capturing Variables in Lambda Expression --- 

Capturing variables in lambda expressions allows lambda to access variables from its surrounding scope. By a capture clause, a lambda can capture variables from its surrounding scope and allow it to use those variables inside the lambda body. 

Types of Variable Capture: 

	1) Capture by value ([x]), It captures the variables by values, which means lambda 
				   gets a copy of the variables and further cannot modify
				   the original variable outside the lambda. 

				   [x](parameters) -> return_type {body}
	
	2) Capture by reference ([&x]), It captures the variables by reference, 
					which means here the lambda can access and 
					modify the original variables. 

					[&x](parameters) -> return_type {body} 

	3) Capture Specific Variables ([x, &y]), Allows mixing of capture types in the same lambda
						 Here the user can specify which variables to capture
						 by value or reference. 

						 [x, &y](parameters) -> return_type {body}

	4) Capture All Variables by Value ([=]), It captures all variables in the surrounding scope by value.

						 [=](parameters) -> return_type { body }

	5) Capture All Variables by Reference ([&]), It captures all variables in the surrounding scope 
						     by reference.

						     [&](parameters) -> return_type { body }

	6) Capture this by reference ([this]), It captures this pointer (a reference to the current object) in a
					       lambda expression. It is useful when the user needs to access 
					       member variables or functions from within a lambda in a
					       class method.

--- Return Types in Lambda Expressions --- 

in C++, lambda expressions return the value just like regular functions, and its return type can be automatically deduced by the compiler or explicitly specified by the programmer. 

> Automatic Return Type Deduction, the compiler deduces the return type based on the return expression inside the lambda

	1) Implicit Return Type,the return type is based on the return expression, which means users don't need 
				to explicitly specify the return type; It will automatically be inferred from 
				the type of the expression.

				[capture](parameters) { return expression; } 

	2) Returning References, It returns references to variables or values; for this, make sure that the 
				 referenced variable stays in scope for the lifetime of the lambda.

				 [capture](parameters) -> type& { return reference; }

	3) Returning Pointers, A lambda can also return a pointer to a variable or dynamically allocated memory.

				 [capture](parameters) -> type* { return pointer; }

	4) Type Deduction with auto, Here you can also use an auto keyword for the return type, and 
				     the compiler will deduce the correct return value type based on 
				     an expression.

				     [capture](parameters) -> auto { return value; }

> Explicit Return Type, in this the user wants to specify lambda's return type explicitly, then use -> return_type syntax. This is useful when working with any complex types and when the return isn't obvious.

				[capture](parameters) -> return_type { return expression; }

(see Example 2)

--- Recursive Lambdas ---

In C++, recursive lambda is the lambda function that calls itself over again and again during its execution until it reaches its base case. As lambda by default cannot call themselves directly, because they don't have a name. So for this, we can make lambda recursive by using a function pointer of std::function. 

(see Example 3)


*/

// Example 1
#include <iostream> 
int EX1(){ 
	// Define a lambda expression to add two numbers
	auto add = [](int a, int b){
		return a + b;
	};

	// Call the lambda expression to add two numbers
	int result = add(5,3);
	
	std::cout << "The sum of 5 and 3 is: " << result << std::endl;
}

// Example 2
using namespace std;
int EX2() { 
	int x = 5;
	int y = 10;
	auto my_lambda = [=, &x]() -> int { 
		cout << "Inside lambda:" << endl;
		// y cannot be modified as its captured by value
		// x can be modified as its captured by reference
		
		x += 10;
		cout << "Captured 'x' by reference inside lambda: " << x << endl;
		// Captured y by value, so it can't be modified here
		// Simple operation with y and a local value

		int sum = y + 5;
		cout << "Captured 'y' by value inside lambda: " << y << endl;
		cout << "Captured sum of 'y' and 5 by value inside lambda: " << sum << endl;

		return sum;

	};

	 int result = my_lambda();
	 cout << "Result returned from lambda: " << result << endl;
	 cout << "Value of 'x' outside lambda after modification: " << x << endl;
	 cout << "Value of 'y' outside lambda (no modification): " << y << endl;
}

// Example 3
#include <functional> // for std::function
int EX3(){
	// Defining the recursive lambda using std::function
	std::function<int(int)> factorial = [&](int n) -> int {
		if (n <= 1) return 1; // Base case
		return n * factorial(n - 1); // Recursive call
	};
	cout << "Factorial of 5: " << factorial(5) << endl;
}








