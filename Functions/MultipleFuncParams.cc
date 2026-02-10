#include <iostream> 

using namespace std; 
/*
 ----- Multiple Function Params -----
 There are 2 types of passing data to multiple function parameters, as shown:

 Single Data Type for Multiple Parameters - Functions where all params are the
					    same data type

 Multiple Data Types for Multiple Parameters - Functions where params can have 
 				    	       different data types.

 ----- Passing Techniques -----
 Multiple parameters (or, single) passing techniques in C++ refer to the methods which are used to pass arguments to functions. These techniques define how the  data is transferred and manipulated within the function. Here we will discuss
 few primary techniques: 

 1) Pass by Value - A copy of the actual parameters value is passed to the 
 		    function. The changes made to the parameter inside the
		    function do not affect the original argument. It is safe
		    and straightforward but can be inefficient for large data
		    structures due to copying. 

 2) Pass by Reference - This method passes a reference to the actual parameter, 			allowing the fucntion to modify the original argument.
 			The function works with the original data rather than
			a copy. It is efficient as it avoids copying, but 
			requires careful handling to avoid unintended
			modifications.

 3) Mutable vs Immutable types - Mutable can be instances can be modified after
 				 they are created. 
				 Immutable types cant be changed after creation.
 
 ----- Types of Multiple Function Parameters -----

 Fixed number of parameters - A function with a fixed number of parameters where 			      it has a specific unchaning number of input 
 			      parameters.

 Variable number of parameters - A function that can accept a variable number of 				 parameters or arguments. This is typically 
 				 implemented using variadic functions or 
				 template parameter packs. 
 
 Default parameters - The parameters with default values that can be omitted 
 		      when calling the function. The function uses the default
		      values if no arguments are provided for those parameters.


 Named parameters - Using a struct or class you can encapsulate parameters.       
				 
 */

struct Person {

	string name;
	int age;
	double height;
};

void printPerson(const Person& p){
	
	cout << "Name: " << p.name << "Age: " << p.age << "Height: " << p.height << endl;
}

int main(){

	Person alice = {"Alice", 25, 5.9};
	printPerson(alice);
	return 0;

}
