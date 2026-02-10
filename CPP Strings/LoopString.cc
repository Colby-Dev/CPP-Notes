#include <iostream>
#include <string>

using namespace std; 

/*

 ------ Loop Through String ------

 C++ string is an array of characters that can be extracted and manipulated with the help of various member functions. It is much more flexible and advanced
 than a traditional C-style chracter array because it supports self-memory
 management and offers many useful functions for manipulation, such as
 concatenation, substring extraction, and searching. To create an object of a
 string, you must use the std::string class from the <string> header. 

 A loop over a string is essentially an iteration or traversal process covering  each character of a string to perform diversified operations such as access,
 modification, or analysis of characters. That can be achieved using the
 different types of looping constructs, including the traditional for loops and  while loops or even range-based for loops. 

 ------ Using a range-based loops ------
 
 There is another type of control flow statement called the range-based for loop that allows for iterating over elements in a collection. It differs from the
 while and for loops because it will allow for iteration over the elements in a  collection using a much more direct and intuitive approach. 


*/


int main(){

	std::string str = "TP"; 
	for (char c : str) {

		std::cout << c << " ";
	}

	return 0;

}
