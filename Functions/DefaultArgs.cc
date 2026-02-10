#include <iostream>

using namespace std;
/*
------ Default Arguments in Functions -----

Default arguments in C++ are the values that are assigned to function parameters during function decalartion. 
These default values are automatically assigned when the caller does not provide any arguments for those parameters while calling the function. 
If a value is provided by the caller during a function call, it will override the default value. 

--- Rules for Default Arguments ---

> Default Arguments must be specified in Function Declaration, not Definition - The first rule says must be specified in the function declaration (prototype), not in the function definition. In case the default argument is specified in the definition or in both the declaration and definition, then it will throw a compilation error. 

> Default Arguments must be assigned from Right to Left - When assigning the values for default arguments, it must start from the rightmost parameters to the leftmost ones, where
  the user can't skip providing parameters in the middle.

> Default Arguments cannot be Changed or Modified - Once specified default argument in the function declaration, then further it can't be changed or modified in any other 
  declaration or definition. Else it will throw an error. 

> Ambiguity with Function Overloading - Calling the default arugments from overloaded functions can cause ambiguity, making it difficult for the compiler to decide which version   of the function to call if the arguments provided are not unique. So for this ensure that functions with default arguments do not conflict with each other in overloads. 

--- Default Argument as an Expression --- 

When defining a function, the user can specify the default values for parameters, where these default values can be a constant or an expression 
(involving variables, constants, or function calls), which is evaluated when the function is called. 

--- Default Argument as a Function Call ---

Calling a function to determine the default value is known as default argument as a Function Call. This calculates the default value dynamically based on the function's logic or other parameters. 

--- Advantages of Default Arguments --- 

It simplifies the function calls by reducing the number of overloads, where users don't need to create multiple overloaded functions when one function can handle different cases by using default values parameters. 

Default arguments help avoid code duplication and reduce redundancy. 

It improves code readability and increases flexibility, which makes further easier to modify in the future. 
  
*/

//Example default function argument:

double total_price(double price, double discount = 12.0){

	return price - (price * discount / 100);
}

int main(){

	//Example default function argument call
	double price;
	cout << "Enter the price of the item: ";
	cin >> price;

	double total = total_price(price);
	cout << "The total price after a 12% discount is: " << total << endl;

	return 0;
	
}
