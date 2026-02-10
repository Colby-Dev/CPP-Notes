#include <iostream>

using namespace std; 

/*
 ----- Function Overloading -----
 
 Function overloading in C++ allows you to define multiple functions with the same name but
 different parameters. Function overloading is used to achieve polymorphism which is an
 important concept of OOP. 

 In the case of different functions with the same name (function overloading), when the compiler reaches a specific function call, it checks with the different function definition based on 
 parameters type, order, or number of arguments, and executes the matched function definition. 

 Function overloading in C++ is a powerful feature that allows you to use the same function name to perform different tasks based on different parameter lists. This can lead to more readable
 and maintainable code. Common use cases include: 

 > Different Data Types
 > Different Number of Parameters
 > Parameter Type and Order
 > Different Operations 
 > Variant Contexts
 
 
 
 */

void show(int a){

	cout << "Int value: "<< a << endl;
}

void show(double a){

	cout << "Double Value: "<< a <<endl;
}

int main(){
	show(10);
	show(3.14);
	return 0;
}
