#include <iostream>
#include <string>

using namespace std; 

/*
 
 ------ C++ Strings ------
 The C-style character string originated within the C lang and continues to be supported within C++. This string is actually a one-dimensional array of characters which is terminated by a null
 character '\0'. Thus a null-terminated string contains the characters that comprise the string 
 followed by a null.

 The following declaration and initialization create a string consisting of the word "Hello". 
 To hold the null character at the end of the array, the size of the character array containing the  string is one more than the number of characters in the word "Hello".

 char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

 char greeting[] = "Hello";

 C++ will automatically place the \0 null character at the end of strings when 
 initialized in the array.

      C style String Functions    
 --------------- | ---------------
 strcpy(s1, s2)  | Copies string s2 into string s1.
 --------------- | ----------------
 strcat(s1, s2)  | Concatenates string s2 onto the end of string s1. 
 --------------- | ----------------
 strlen(s1)      | Returns the length of string s1
 --------------- | ----------------
 strcmp(s1, s2)  | Return 0 if s1 and s2 are the same; < 0 if s1 < s2; > 0 if s1 > s2;
 --------------- | ----------------
 strchr(s1, ch)  | Returns a pointer to the first occurrence of string s2 in string s1
 --------------- | ----------------
 strstr(s1, s2)  | Returns a pointer to the first occurance of string s2 in string s1

 
 ----- The String Class in C++ -----
 The standard C++ library provides a string class type that supports all the operations 
 mentioned above, additionally much more functionality.
 
 strings can be created using char strings:
 char s[5] = {'h','e','l','l','o',\0}

 or

 delcaring strings using the string keyword:
 string s = "a merry tale";

 ----- Traversing a String (Iterate Over a String) -----
 
 > Using looping statements, traversing a string using for loops while loops using a pointer to the  first and the last index the string. 

 > Using iterators, using range based loops we can iterate over the string using iterators. This is  achieved using the ":" operatior while a running a range based loop.  

 ----- Accessing Characters of String -----

 We can access the cahracters of a string using both iterators and pointer to the indices of the string. 
 
 */



int main(){

//Example string functions

	char str1[10] = "Hello";
	char str2[10] = "World";
	char str3[10];
	int len;

	//copy str1 into str3
	strcpy(str3, str1);
	cout << "strcpy( str3, str1) : "<< str3 << endl;

	//concatenates str1 and str2
	strcat(str1, str2);
	cout << "strcat( str1, str2) : "<< str1 << endl;

	//total length of str1 after concatenation
	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;

	

//Example of string class

	string string1 = "Hello";
	string string2 = "World";
	string string3;
	int len2;

	// copy str1 into str3
	string3 = string1;
	cout << "str3: " << string3 << endl;

	// concatenates str1 and str2
	string3 = string1 + string2;
        cout << "String1 + String2: " << string3 << endl;

	// total length of string3 after concatenation
	len2 = string3.size();
	cout << "string3.size() : " << len2 << endl;

// Iterating over a string:

	string S = "Hey, I am at TP.";
	for(int i = 0; i<S.length(); i++){
	
		cout<<S[i]<<" ";
	}
	cout << endl;

	for(char c:S){
	
		cout<<c<<" ";
	}

// Accessing Characters of String

	string exS = "Hello";
	cout << exS << endl;
	for(int i = 0; i < exS.length(); i++){	
		exS[i] = 'A';
	}
	cout << exS << endl;

	for(char &c:exS){
	
		c = 'B';
	}
	cout << exS << endl;


	return 0;
}

