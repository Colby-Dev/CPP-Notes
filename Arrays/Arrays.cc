#include <iostream> 


using namespace std; 
/*
 ----- C++ Arrays -----
 C++ array stores a fixed-size sequential collection of elements of the same type. An array is used to store a collection of data, but it is often more useful  to think of an array as a collection of variables of the same type.

 Instead of declaring individual variables such as number0, number1, ..., and nummber99, you declare one array variable, such as numbers an use numbers[0].
 numbers[1], and ..., numbers[99] to represent individual variables. A specific element in an array is accessed by an index. 

 All arrays consist of contigous memory locations. The lowest address corresponds to the first element and the highest address to the last element. 

--- Declaring Arrays --- 

 To declare an array in C++, the programmer specifies the type of the elements and the number of elements required by an array: 
 type arrayName [ arraySize ];

 This is called a single-dimension array. The arraySize must be an integer constant greater than zero and type can be any valid C++ data type. For example, to  declare a 10-element array called balance of type double, use this statement: 
 double balance[10];

--- Initializing Arrays ---

 You can initialize C++ array elements either one by one or using a single statement as follows: 
 	double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0}

 The number of values between braces { } can not be larger than the number of elements that we declare for the array between square brackets [ ]. Following is  an example to assign a single element of the array. 

 If you omit the size the array, an array just big enough to hold the initialization is created. Therefore, if you write:
	double balance[] = {1000.0, 2.0, 3.4, 17.0, 50.0} This would result in --> balance[4] = 50.0;

 The above statement assigns element number 5th in the array a value 50.0. Array with 4th index will be 5th, i.e., last element because all array have 0 as the index of their first element which is also called base index. 

 --- Accessing Array Elements ---
 
 An element is accessed by indexing the array name. This is done by placing the index of the element within square brackets after the name of the array:
 	double salary = balance[9];

 The above statement will take 10th element from the array and assign the value to salary variable. Following is an example, which will use all the above
 mentioned three concepts viz. declaration, assignment and accessing arrays. 

 --- Getting Array Length --- 

 To get the length of an array, you can use the sizeof() operator by dividing the size of the array with the size of the array elements. 
 	length = sizeof(arr) / sizeof(arr[0])

 --- Changing Array Element --- 

 You can change the value of an array element by specifying its index assigning a new value.

 --- More on C++ Arrays ---
 
 > Multi-dimensional arrays, C++ supports multidimensional arrays. The simplest form of the multidimensional array is the two-dimensional array.

 > Pointer to an array, You can generate a pointer to the first element of an array by simply specifying the array name, without an index.

 > Passing arrays to functions, You can pass to the function a pointer to an array by specifying the arry's name without an index

 > Return  array from functions, C++ allows a function return an array.  
 
 */

int main(){

}
