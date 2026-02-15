#include <iostream>
#include <ctime>

using namespace std; 
/*
 ----- Return Array from Function in C++ -----

 C++ does not allow to return an entire array as an argument to a function. However, you can
 return a pointer to an array by specifying the array's name without an index. 

 If you want to return a single-dimension array from a function, you would have to declare a 
 function returning a pointer as in the following example:

 int * myFunction() {
 	.
	.
	.
}

--- Second point ---

 Second point to remember is that C++ does not advocare to return the address of a local variable
 to outside of the function so you would have to define the local variable as static variable. 

 Now, consider the following function, which will generate 10 random numbers and return them using an array and call this function as follows:

 */

int * getRandom(){
	static int r[10];

	srand( (unsigned)time(NULL) );
	
	for (int i = 0; i < 10; ++i){
		r[i] = rand();
		cout << r[i] << endl;
	}
	return r;
}



int main(){

	int *p;

	p = getRandom();

	for ( int i = 0; i < 10; i++){
		cout << "*(p + "<< i << "): ";
		cout << *(p+i) << endl;
	}
	return 0;

}
