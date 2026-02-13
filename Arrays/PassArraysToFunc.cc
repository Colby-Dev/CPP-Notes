#include <iostream> 

using namespace std; 

/*
----- Passing Arrays to Functions -----

C++ does not allow to pass an entire array as an argument to a function. However, you can pass a pointer to an array by
specifying the array's name without an index. 

If you want to pass a single dimension array as an argument in a function, you would have to declare function formal 
parameter in one of following three ways and all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be recived. 

--- Way 1 ---

Formal parameters as a pointer as follows: 

void myFunction(int *param) {
	.
	.
	.
}

--- Way 2 ---

Formal parameters as a sized array as follows:

void myFunction(int param[10]) {

	.
	.
	.
}

--- Way 3 ---

Formal parameters as an unsized array as follow:

void myFunction(int param[]) {

	.
	.
	.
}




Now, consider the following function, which will take an array as an argument along with another argument and based on
the passed argument along with another argument and based on the passed arguments, it will return average of the numbers
passed through the array: 

*/


double getAverage(int arr[], int size) {
	int i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i){
		sum += arr[i];
	}

	avg = double(sum) / size; 
}



int main(){

	int balance[5] = {1000, 2, 3, 17, 50};
	double avg;

	avg = getAverage(balance, 5);

	cout << "Average value is: " << avg << endl;

	return 0;

}
