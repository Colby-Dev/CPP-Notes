#include <iostream>
#include <sstream>
#include <string>

using namespace std; 

/*
 ------ String Functions ------
 
 String is an object of the <string> class, and hence, it has a variety of functions that users can 
 utilize for a variety of operations. Some of these functions are as follows:
 
 Function     |  Description
 -------------|----------------
 length()     | This function returns 
 	      | the length of the string
 -------------|---------------------------------
 swap()       | This function is used to swap the
	      | values of 2 strings
 -------------|---------------------------------
 size()       | Used to find the size of string
 -------------|---------------------------------
 resize()     | This function is used to resize the 
              | length of the string up to the given
	      | number of characters.
 -------------|---------------------------------
 find()       | Used to find the string which is
	      | passed in parameters
 -------------|---------------------------------
 push_back()  | This function is used to push the 
 	      | character at the end of the string 
 -------------|---------------------------------
 pop_back()   | This function is used to pop the last 
 	      | character from the string
 -------------|---------------------------------
 clear()      | This function is used to remove all 
 	      | the elements of the string
 -------------|---------------------------------
 replace()    | This function is used to replace each 
 	      | element in the range (first, last) that
	      | is equal to old value wit new value
 -------------|---------------------------------
 substr()     | This function is used to create a 
              | substring from a given string
 -------------|---------------------------------
 compare()    | This function is used to compare two 
 	      | strings and returns the result in the 
	      | form of an integer
 -------------|---------------------------------
 erase()      | This function is used to remove a certain 
 	      | part of a string
 -----------------------------------------------


 ------ String Concatenation ------

 String concatenation is a way to add two string together. This can be done using two ways:

 > Addition Operator
 > Append() Method

 ------ String Input in C++ ------

 Strings can be taken as an input to the program, and the most common way to do this is by using cin method. 
 There are three methods to take a string as an input, and these methods are given as follows: 

 > cin (cin >> string_name);
 > getline() (getline(cin, string_name);)
 > stringstream (Stringsteam object_name(string_name);)



 */

int main(){

	string s = "Hey, I am at TP";
	stringstream object(s);
	string newstr;
	while (object >> newstr){
	
		cout << newstr << " ";
	}

	return 0;
}
