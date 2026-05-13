/* 

----- Dynamic Memory -----


A good understanding of how dynamic memory really works in C++ is essential to becoming a good C++ programmer. 
Memory in your C++ program is divided into two parts:

	The stack - All variables declared inside the function will take up memory from the stack.

	The heap - This is unused memory of the program and can be used to allocate the memory dynamically when program runs. 

Many times in programming in C++ you will not know in advance how much memory you will need to store particular information in a defined variable and the size of the required memory can be determined at run time. 

You can allocate memory at run time within the heap for the variable of a given type using a special operator in C++ which returns the address of space allocated. This operator is called new operator. 

If you are not in need of dynamically allocated memory anymore, you can use delete operator, which de-allocates memory that was previously allocated by new operator. 

--- New and Delete Operators ---

There is following generic syntax to use new operator to allocate memory dynamically for any data-type. 

	new data-type;

Here, data-type could be any built-in data type including an array or any user defined data types including class or structure. Let us start with built-in data types. For example we can define a pointer to type double and then request that the memory be allocated to execution time. We can do this using the new operator with the following statements: 

	double* pvalue = NULL; // Pointer initialized with null
	pvalue = new double; // Request memory for the variable

The memory may not have been allocated successfully, if the free store had been used up. So it is good pratice to check if new operator is returning NULL pointer and take appropriate action as below: 

	double* pvalue = NULL;
	if( !(pvalue = new double )) {
		cout << "Error: out of memory." << endl;
		exit(1);
	}

The malloc() function from C, still exists in C++, but it is recommended to avoid using malloc() function. The main advantage of new over malloc() is that new doesn't just allocate memory, it constructs objects which is prime purpose of C++. 

At any point, when you feel a variable that has been dynamically allocated is not anymore required, you can free up the memory that it occupies in the free store with the delete operator as follows: 

	delete pvalue; // Release memory pointed to be pvalue
		       
(See Example 1)

--- Dynamic Memory Allocation for Arrays --- 

Consider you want to allocate memory for an array of characters, i.e., string of 20 characters. Using the same syntax what we have used above we can allocate memory dynamically as shown below.

(See Example 2)

--- Dynamic Memory Allocation for Objects ---

Objects are no different from simple data types. For example, consider the following code where we are going to use an array of objects to clarify the concept.

(See Example 3)

If the code from example 3 were to be called it would allocate memory for the 4 constructors that are being called then it would destroy them immediately after.  

*/

// ----- Example 1 -----
#include <iostream>
using namespace std; 

int Ex1(){
	double* pvalue = NULL; // Pointer initialized with null
	pvalue = new double;  // Request memory for the variable
	
	*pvalue = 29494.99; // Store value at allocated address
	
	cout << "Value of pvalue: " << *pvalue << endl;

	delete pvalue; // free up the memory.

	return 0;

}


// ----- Example 2 -----
int Ex2(){
	char* pvalue = NULL;  // Pointer initialized with null 
	pvalue = new char[20]; // Request memory for the variable
	delete [] pvalue; // Delete array pointed to by pvalue

	// --- Multi demensional arrays --- 
	double** pvalue = NULL;
	pvalue = new double [3][4];
	delete [] pvalue;

}

// ----- Example 3 ------
class Box{
	public: 
		Box() {
			cout << " Constructor called " << endl;
		}
		~Box() {
			 cout << " Destructor called " << endl;
		}
};

int Ex3(){
	Box* myBoxArray = new Box[4];
	delete [] myBoxArray;

	return 0;

}
