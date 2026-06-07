/*

----- nullptr in C ++ -----

The nullptr keyword in C++ represents a null pointer value which was earlier represented using NULL or 0. It was introduced in C++ 11 and is of type std::nullptr_t. The nullptr is a type-safe pointer that is implicitly convertible and can be compared to any pointer. 

	int* ptr = nullptr; // ptr is a null pointer of type int*

(see Example 1)

--- Why Do We Need nullptr? --- 

We need nullptr because of the following problems caused by using NULL or 0

	> Ambiguity in Function Calling
	> Problem in Function Overloading
	> Type-Safety Problem

--- Ambiguity in Function Calling --- 

Calling a function with value '0' to represent NULL creates an ambiguity because compiler treats '0' as an integer value rather than a null pointer. In the following example, we are calling display() function passing value as '0'. It calls the function that has an int parameter rather than calling the function that has a pointer in its parameter. 

The solution to this issue is to use nullptr to call the display() function that has a pointer in its parameter. 

(see Example 2)

--- Problem in Function Overloading ---

If you call an overloaded function with NULL value, it will cause a compliation error. The NULL is valid for both parameters that is int and int*. So, in this confusion compiler throws an error below will be the solution to this issue. 

(see Example 3)

--- Type Safety Problem --- 

The NULL is treated as an integer since it is defined with '0'. It creates the same ambiguity as the above two problems. It is solved using nullptr is type-safe unlike NULL and it is implicitly convertible to any pointer type. 
(see Example 4)

--- Nullptr Use Cases --- 

The main purpose of the nullptr is to assign a null value to any pointer. Here are some use cases where a nullptr can be used. 

	> Resetting Pointers After Deletion, A pointer needs to be assigned to a null value after 
					    deletion to avoid a dangling pointer. Here is an example 
					    to reset pointer to null after cleaning up the memory.

					    (see Example 5)

	> Checking Pointer Validity, You should first check that the pointer is not null before accessing 
				     it to avoid creashes. Here is an example to check if the pointer ptr 
				     is a null pointer or not.

				     (see Example 6)


*/

// Example 1

#include <iostream>
using namespace std; 

int EX1() { 
	int *ptr = nullptr; // ptr is a null pointer

	if (ptr == nullprt)
	{
		cout << "Pointer is null." << endl;
	}
	else
	{
		cout << "Pointer is not null." << endl;
	}

	int x = 10;
	ptr = &x;

	if (ptr != nullptr)
	{
		cout << "Pointer now points to: " << *ptr << endl;
	}

};

// Example 2

void display(int n){
	cout << "Calling display function with int" << endl; 
}

void display(int *p){
	cout << "Calling display function with int*" << endl;
}

int EX2() { 
	display(nullptr);
}

// Example 3

class Demo { 
	public: 
		void show(int n)
		{
			cout << "Calling show() function with int" << endl;
		}

		void show(int *p)
		{
			cout << "Calling show() function int*" << endl;
		}
};

int EX3() { 
	Demo obj; 
	obj.show(nullptr); // Correctly calls int* function
	}

// Example 4

int EX4() { 
	int* ptr = nullptr;

	cout << "Comparing with NULL" << endl;
	if (ptr == NULL) { 
		cout << "NULL is TRUE" << endl;
	} else { 
		cout << "NULL is FALSE" << endl;
	}

	cout << "\nComparing with nullptr" << endl;
	if (ptr == nullptr) { 
		cout << "nullptr is TRUE" << endl;
	} else { 
		cout << "nullptr is FALSE" << endl;
	}

	int value = 0;

	// NULL will be treated as integer 0
	if (value == NULL) { 
		cout << "value(0) = NULL is TRUE" << endl;
	}
};

// Example 5

int EX5(){ 
	int *ptr = new int(57);
	cout << "Value: " << *ptr << endl;

	delete ptr; // Free memory
	ptr = nullptr; // Resetting pointer
	
	if (ptr == nullptr)
		cout << "Pointer reset successful." << endl;
}


