#include <iostream> 

using namespace std; 
/*

----- Unions ------

A union is a user-defined data type that allows you to store different data types in the same memory location.
However, the union can store only one of its member variables at a time, which means that if you assign a value toone member, the previous value stored in another member is overwritten. Where the size of a union is determined bythe size of its largest member. 

--- Union Declaration ---

To declare a union, use the union keyword followed by the tag_name (union name) and then declare the union memberswith their data types inside the curly brackets. Close the declaration with a semicolon.

	union UnionName {
		dataType1 member1;
		dataType2 member2;
		};

--- Declaring Union Variable --- 

After declaring a union, you need to declare its variable to access and manipulate its members:

	union_name variable; 

--- Accessing Union Members --- 

You can access union members using the dot operator (.) after declaring a union variable. 

	union_variable.member

--- Anonymous Unions ---

Anonymous unions are a special type of union which dont have a name. This helps in simplifying code by allowing 
you to direct access to union members without specifying the union variable name. 


--- Union-like Classes ---

A union-like class is defined as a class that includes at least once anonymous as a member. The data members
defined within these anonymous unions are known as variant members. It is the data structures that encapsulate theconcept of a union but provide additional features for type safety and usability. 

These typically use a combination of member variables and a mechanism (like an enum) to track which type is
currently active. 


*/


#include <cstring>

union Data {
	int    intValue;
	float  floatValue;
	char   strValue[50];

};


int main(){

	Data data;
	data.intValue = 2006;

	cout << "TP was founded in "<< data.dataValue << endl;


	data.floatValue = 100.012;
	cout << "My float value is " << data.floatValue << endl;

	strcpy(data.strValue, "hello world!");
	cout << data.strValue << endl;

	return 0;

}
