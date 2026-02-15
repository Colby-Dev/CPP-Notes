#include <iostream> 

using namespace std; 


/*
 
----- Array Decay -----

Array decay refers to the loss of type and dimensions of an array. The array is treated as a pointer to the 
first element instead of the whole array in some cases, like when we pass an array to a function by pointer
or value. As a result, the original array's size and type information are lost. 

Due to this decay, sizeof operator no longer gives the full size of the array instead it returns the size of the pointer. It causes incorrect behavior in functions that are dependent on knowing the number of elements.

--- When does an array decay occur in C++? ---

An array decay can occur in following scenarios: 

> Passing an Array to a Function

> Assigning an Array to a Pointer

> Using an Array in Pointer Arithmetic

--- Passing an Array to a Function ---

While passing an array to a function, the array automatically decays into a pointer. After the decay, the
function does not receive the size of the array, and only receives a pointer pointing to first element of thearray. 

--- Assigning an Array to a Pointer --- 

You can assign an array to a pointer in C++ When you assign an array to a pointer, the array automatically
decays to a pointer. 

--- Using an Array in Pointer Arithmetic --- 

You can use pointer arithmetic to access array elements using arithmetic operations like addition and
substraction. This leads to array decay as the array loses its size information. 



----- Problems Caused by Array Decay in C++ -----


> Cannot Determine Array Size Inside Function, The array is decayed into a pointer when an array is passed as 						    a function parameter. The pointer only stores the address and 						 has no information about the number of elements in the array, 						      so the sizeof() function gives the size of a pointer and array
					       can not be determined. 

> Cannot Copy Arrays Using = Operator, You cannot use the "=" operator to copy one array to another array as 				  	    the array decays into a pointer. The ' = ' operator copies the address 					 but we can not reassign the array memory as it is already fixed. 

> Cannot Compare Arrays Directly, Arrays can not be compared directly using comparison operators (==, !=)
				  because when array names are used they decay to pointers. Even after arrays 				       having same elements, it will return false as the memory address will
				  differ and it will compare the memort address of the pointers.


--- Solution of Array Decay ---

> Passing Array Size as Separate Parameter, To avoid array decay you can pass the array size as a parameter
					    along with the array as the size of the array does not get lost.


> Using std::array and std::vector, You can use std::arry and std::vector to avoid the array decay as these
				    are objects in C++ and not arrays, so array decay does not occur. 


--- Conclusion ---

An array decay in C++ refers to the loss of dimension and type of an array that occurs due to various reasonssuch as, when an array is passed to a function, an array assigned to a pointer, or used in pointer 
arithmetic. It may cause various problems that we highlighted in this chapter along with their solutions. 

*/

#include <array>

void printArray(array <int, 5> arr){
	cout << "Array size: " << arr.size() << endl;
	cout << "Elements: ";
	for (int num : arr){
		cout << num << " ";
	}
	cout << endl;
}

int main(){
	array<int, 5> stdArr = {1, 2, 3, 4, 5};
	printArray(stdArr);

	return 0;
}
