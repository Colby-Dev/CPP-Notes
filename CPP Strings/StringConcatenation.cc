#inclue <iostream>

using namespace std;

/*
 ----- String Concatenation -----
 The process of adding an element to an existing element. In this context,
 string concatenation is the method by which two (or more) strings can be added  to one another. Hence, the resultant string is the combination of the initial
 string and the added string.

 string::append()
 '+' operator
 strcat() function 
 range based loop 
 
 
 */

int main(){

	// using the append method

	string initial_string("I love TP.");
	string new_string("I am new here.");

	initial_string.append(new_string);
	cout<< initial_string << endl;

	return 0;
}
