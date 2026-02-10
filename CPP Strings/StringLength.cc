#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
----- String Length -----

Length of a string is the number of characters present in the string. These 
characters can be of the data type char, and these include all alphanumeric
elements, symbols and miscellaneous characters. In C++ there are two types of 
strings, Character Arrays and String objects which are built-in objects of
<string> class.

The length of a string also includes white spaces, but in case a string includesterminating character "\0", the string ends at that character and the count of 
length is terminated just before that character.


*/


int main() {

// Example of strlen()

	char love[]="I love TP";
	cout << "length of string love: "<<strlen(love);

// Example of string::size()

	string test = "I love TP";
	cout << "Length of string test: "<<test.size();

// Example of string::length()

	cout << "Length of string test: "<<test.length();

// Example of while loop

	int count, i = 0;
	while(test[i])
		count++, int++;
	cout<<"Length of string test: " <<count;

// Example of a for loop
	int new_count = 0;
	for(int x=0; test[x] != '\0'; x++){
		count ++;

	}
	cout<<"Length of new_count: " << count;
	return 0;

}
