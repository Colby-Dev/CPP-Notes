#include <iostream>

using namespace std;

/*
---- Cout in C++ ----
cout is an instance of the ostream class that displays outputs to the user.
The cout object is said to be attached to the standard output device, usually a screen. 

The cout object is used in conjunction with the stream insertion operator (<<).
This inserts the data into the output stream and displays the data on screen.

// ---- Example Vars ----

cout << variable_name;
cout << variable1 << variable2 << ... << variableN;

*/

int main(){

// ----- Displaying with cout -----

int num1 = 2;
cout << "Num1: " << num1 << endl;

int num2 = 2, num3 = 5;
cout << "Num2: " << num2 << ", Num3: " << num3 << endl;
cout << "Sum: " << num1 + num2 + num3 << endl;


// ---- Display Arrays w/ cout ----

int arr[5] = {1, 2, 3, 4, 5};
int n = 5;

cout << "Array elements: ";
for (int i = 0; i < n; i++){

    cout << arr[i] << " ";
}
cout << endl;

return 0;

}



/* 
Functions     | Definition
______________|_________________________________________________________
cout.put()    | The cout.put() function writes a single character to the
              | output stream.
______________|_________________________________________________________
cout.write()  | It writes a specified number of characters from a 
              | character array or string to the output stream
______________|_________________________________________________________
cout.flush()  | The flush() function displays all pending output by 
              | forcing the output buffer to empty immediately
______________|_________________________________________________________
cout.good()   | It checks the state of output stream and returns true if
              | an error occurs in the stream that can not be recovered.
______________|_________________________________________________________
cout.bad()    | It checks the state of output streams and returns true if 
              | an error occurs in the stream that can not be recovered.
______________|_________________________________________________________
cout.fail()   | It returns for both reoverable and non-recoverable errors
              | in the output stream.
______________|_________________________________________________________
cout.clear()  | It clears the error flags of the stream and reset it to 
              | good state. The clear () function is also used to set
              | error states of output stream. 
______________|_________________________________________________________
cout.width()  | The cout.width() function is used to set the minimum field 
              | width for the next output operation. 
______________|______________________________________________________________
                    | It sets the precision for floating-point numbers displayed in 
out.precision()     | the output stream.
____________________|_________________________________________________________
cout.fill()   | It sets the fill character that is used to pad output when the width
              | is greater than the number of characters to be displayed.
______________|_______________________________________________________________
cout.seekp()  | It used to set the position of the put pointer in the out stream.
              | It is generally used with file streams (ofstream)
______________|_______________________________________________________________
cout.tellp()  | It returns the current position of the put pointer in the 
              | output stream. It is generally used with file streams (ofstream)
______________|_______________________________________________________________
cout.eof()    | It returns upon reaching end of file in the output stream. 
______________|_______________________________________________________________
cout.rdbuff() | It returns the stream buffer object of cout that can be used to 
              | write or redirect the output stream directly. 
______________|_______________________________________________________________






*/