#include <iostream>
#include <string>

uisng namespace std;
/*
------ String Compare ------
String comparison can be done by using built-in operators such as
==, !=, < , and > or by the the compare() method. But by default these 
comparisons are case-sensitive, which means "i" and "I" are considered different


----- Comparing C-Style Strings -----
You can use the strcmp() function from the <cstring> library to compare two
strings. It will return -1 for less than, 0 for equals, 1 for greater than. 

The strcoll() function compares two C-strings according to the current locale,  which is useful for internationalization. It behaves similary to strcmp() but takes into account locale-specific rules. 

----- Comparing std::string -----
For comparing std::string objects have various methods that give different ways of accessing their equality or relative order. 

Comparison Operators --> ==, !=, < , > , etc. 

Compare Method --> string_1.compare(string_2)




*/


int main(){

	//Example of Compare Method

	string string_1 = "A";
	string string_2 = "B";

	cout << string_1.compare(string_2) << endl;

	return 0;

}
