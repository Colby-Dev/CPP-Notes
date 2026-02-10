#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime> 

using namespace std; 

/* 
------ Manipulators ------
Manipulators, in C++ are special functions or objects that are used with insertion (<<) and extraction (>>)
operatiors (cin/cout) to control the input and output streams. You can change the format to display the output
or how to read an input. The manipulators are declared in <iostream> and <iomanip> headers. 

*/

int main(){

    /* 
----- Output Stream ------
The output stream manipulators are used to control display properties
such as field width, fill characters, and numeric display options. 

Manipulators  | Definition       
______________|________________________________________________________
endl          | It inserts a newline and flushes the output buffer
______________|_________________________________________________________
setw(n)       | It sets the field width for the next output operation 
______________|_________________________________________________________
setfill()     | It sets the fill character  
______________|_________________________________________________________
showpoint     | It displays decimal point for floating point numbers 
______________|_________________________________________________________
noshowpoint   | It hides the decimal point
______________|_________________________________________________________
showpos       | It is used for displaying '+' sign for positive numbers
______________|_________________________________________________________
noshowpos     | It hides '+' sign for positive numbers 
______________|_________________________________________________________
flush         | It flushes the output stream without newline
______________|_________________________________________________________
ends          | It is used for inserting a null character and then flushes 
______________|_________________________________________________________


    */
//Example of setw(): 
cout << setw(10) << 40 << "(Field width 5) using setw()" << endl;

/*
----- Input Stream ------
The input manipulators control whitespace and also handles input stream during read operations.


Manipulators  | Definition       
______________|________________________________________________________
ws            | It removes the whitespace character
______________|_________________________________________________________
noskipws      | It avoids skipping whitespaces
______________|_________________________________________________________


*/
//Example of ws
string text = "     A B";
istringstream iss(text);
char ch;

iss >> ws >> ch;
cout << "Using ws: '" << ch << "'" << endl;

/*
----- Alignment Stream ------
Alignment manipulators are used to control alignment of output within its field width.

Manipulators  | Definition       
______________|________________________________________________________
left          | It left aligns the output within field width
______________|_________________________________________________________
right         | It right aligns the output within field width
______________|_________________________________________________________
internal      | It is used to insert padding between sign and value 
______________|_________________________________________________________


*/
//Example of left

int num = 123;
int negNum = -123;
cout << "Left aligned : '" << left << setw(5) << num <<"'" <<endl;

/*
----- Floating Point Stream ------
Floating point manipulators are used to control the decimal precision and set the notation
to represent the decimal numbers

Manipulators     | Definition       
_________________|________________________________________________________
setprecision(n)  | It left aligns the output within field width
_________________|_________________________________________________________
fixed            | It represents the given number in fixed-point notation
_________________|_________________________________________________________
scientific       | It represents the given number in scientific notation
_________________|_________________________________________________________


*/
// Example 
double DoubNumb = 1.412344321;
cout << "Fixed: " << fixed << setprecision(3) << DoubNumb << endl;

/*
----- Numeric Base and Case Manipulators ------
The numeric base manipulators are used to convert and set the base of the given number. 
Case manipulators specifies whether you want your hex and scientific output in uppercase or lowercase

Manipulators     | Definition       
_________________|________________________________________________________
dec              | It sets the given value as decimal output. 
_________________|_________________________________________________________
oct              | It sets the given value as octal output
_________________|_________________________________________________________
setbase          | It is used for setting the numeric base as 
                 | decimal, octal, or hexadecimal in the output
_________________|_________________________________________________________
showbase         | It is used to display the base prefix in the output
_________________|_________________________________________________________
noshowbase       | It hides base prefix in the output
_________________|_________________________________________________________
uppercase        | It represents hex and scientific in uppercase
_________________|_________________________________________________________
nouppercase      | It represents hex and scientific in lowercase
_________________|_________________________________________________________


*/
// Example: 
int number = 255;

cout << "\nDisplaying base prefix using showbase: " << endl;
cout << showbase;
cout << "Decimal: " << dec << number << ", "
     << "Octal: " << oct << number << ", "
     << "Hex: " << hex << number << endl;

/*
----- Boolean ------
Boolean manipulators are used to represent the boolean values 
as either true/false or 0/1

Manipulators  | Definition       
______________|________________________________________________________
boolalpha     | It displays booleans as true/false
______________|_________________________________________________________
noboolalpha   | It displays booleans as 0/1
______________|_________________________________________________________

*/ 
//Example

cout << "Using boolalpha for comparison" << endl;
int a = 10, b = 20, c = 10;

cout<< boolalpha;
cout << "a = "<< a;
cout << "a == b: "<< (a == b)<<endl;

/*
----- Time and Date ------
You can format time in the given format or parse the formatted
time and date using time and date manipulators.

Manipulators  | Definition       
______________|________________________________________________________
put_time      | It is used to format and output time in the specified format.
______________|_________________________________________________________
get_time      | It is used for paring the formatted time input 
______________|_________________________________________________________

*/ 
//Example

time_t now = time(0);
tm * ltm = localtime(&now);

cout << "Current date and time using put_time: " << "\n";
cout << put_time(ltm, "%Y-%m-%d") << endl;

return 0;

}
