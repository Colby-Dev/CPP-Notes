#include <iostream>
#include <bits/stdc++.h>


using namespace std;

/*
-------- Basic Input/Output --------

The C++ standard libraries provide an extensive set of input/ouput capabilities.
C++ I/O occurs in streams, which are sequences of bytes. 

If bytes flow from a flow from a device this is called Input Operation.
If bytes flow from from main memory to a device this is call Output Operation.

---- Header File & Function and Description ----

<iostream> = Defines standard input, output, un-buffered standard er, buffered stream manipulators

<iomanip> = This file decalres services useful for performance formatted I/O with so called parameterized stream manipulators

<fstream> = This file declares services for user-controlled file processing.

<bits/stdc++.h> = This header file includes the most standard C++ libraries, without having to specifiy each library

*/


int main(){

    /* 
     ---- Standard Output Stream (cout) ----
     The predefined object cout is an instance of ostream class.
     The object is said to be connected to the standard output device.
     The compiler also determines the data type of variable to be output.
     The compiler selects the appropriate stream insertion operator to display the value.

    */

    char str[] = "Hello C++";
    cout << "Values of str is: "<< str<< endl;

    /*

    ---- The Standard Input Stream (cin) ----
    The cin object is an instance of istream class.
    The cin object is said to attached to the standard input device.
    The cin is used in conjunction with the stream extraction operator (>>).

    The complier also determines the data type of the entered value and selects the appropriate stream extraction operator. 
    therefore:

     cin >> name >> age;
     
     is the same as:

     cin >> name; 
     cin >> age; 

    */

    char name[50];
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Your name is: " << name << endl;

    /*
    ---- Standard Error Steam (cerr) ----
    The predefined object cerr is an instance of ostream class. 
    The cerr object is said to be attached to the standard error device, 
    which is also a display screen but the object cerr is unbuffered and each stream insertion to cerr causes its output to appear immediately

    The cerr is also used in conjunction with the stream insertion operatior as shown in the following example:
    
    */

    char str[] = "Unable to read .... "; 
    cerr << "Error Message "<<str <<endl;

    /* 
    ---- Standard Log Stream (clog) ----
    The predefined object clog is an instance of ostream class. 
    Clog is attached to the standard error device. 
    Clog object is buffered.

    This means the clog could cause the output to be held in a buffer until its filled or flushed
    */
    
    char str[] = "Unable to read....";
    clog << "Error message: " << str << endl;

    //Typically is good practice to display error messages using cerr stream
    // using clog should be for log messages. 

    /*
    ---- Input/Output Using bits/stdc++ ----

    The bits/stdc++.h is a non-standard header file. It is a specific GCC header file
    that includes most of the C++ libraries. 
    
    */
    

}