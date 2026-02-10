#include <iostream> 

using namespace std; 
/*
----- Functions -----
A function is a group of statments that together perform a task. Every program
has at least 1 function main().

A function declaration tells the compiler about a function's name, return type, and parameters. A function definition provides the actual body of the function. 


A function must have:

Return type - A value may be returned. The data type of the value the function
returns. Some functions perform the desired operations wihtout returning a
value. In this case the return type is void. 

Function Name - This is the actual name of the function. The function name and 
the parameter list together constitute the function signature.

Parameters - A placeholder. When a function is invoked, you pass a value to the parameter. This value is referred to as actual parameter or argument. The
parameter list refers to the type, order, and number of the parameters of a
function. Parameters are optional;

Function Body - The function body contains a collection of statements that
define what the function does.

----- Function Args -----
If a function is to use arguments, it must declare variables that accept the 
value of the arguments. These variables are called the formal parameters of the
function. 

Call by Value - This method copies the actual value of an argument into the
formal parameter of the function. 

Call by Pointer - This method copies the address of an argument into the formal
parameter. Inside the function, the address is used to access the actual 
argument used in the call. This means that changes made to the parameter affect the argument. 

Call by Reference - This method copies the reference of an argument into the
formal parameter. Inside the function, the reference is used to access the
actual argument used in the call. This means that changes made to the param
affect the argument.

---- Default Values for Parameters ----

When you define a function, you can specify a default value for each of the lastparameters. This value will be used if the corresponding argument is left blank when calling to the function. 

This is done by using the assignment operator and assigning values for the arguments in the function definition. If a value for that parameter is not passed
when the function is called, the default given value is used, but if a value is
specified, this default value is ignored and the passed value is used instead.



*/

//Example of the function called max
int max(int num1, int num2){
	
	int result;
	if (num1 > num2){
		result = num1;
	}
	else{
		result = num2;
	}

	return result;
}

//Example of default values

int sum(int a, int b = 20){

	int result;
	int result = a + b;

	return result;	
}


int main(){

	std::cout << max(100, 30);

	//local var decl
	int a = 100;
	int b = 200;
	int result;

	result = sum(a, b);
	cout << result <<endl;

	// using the default param
	result = sum(a);
	cout << result << endl;
	
return 0;
	
}
