/*

----- Files and Streams -----

So far, we have been using the iostream standard library, which provides cin and cout methods for reading from standard input and writing to standard output respectively.

This tutotial will teach you how to read and write from a file. This requires another standard C++ library called fstream which defines three new data types: 

1) ofstream - This data type represents the output file stream and is used to create files and to write information to files. 

2) ifstream - This data type represents the input file stream and is used to read information from files. 

3) fstream - This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create, write, and read files. 

To perform file processing in C++, header files <iostream> and <fstream> must be included in your C++ source file. 

--- Opening a File ---

A file must be opened before you can read from it or write to it. Either of stream or fstream object may be used to open a file for writing. And ifstream object is used to 
open a file for reading purpose only.

Following is the standard syntax for open() function, which is a member of fstream, ifstream, and ofstream objects.

    void open(const char *filename, ios::openmode mode);

Here, the first argument specifies the name and location of the file to be opened and the second argument of the open() member function defines the mode in which the file 
should be opened. 

Mode Flag and Description: 

1) ios::app - Append mode. All output to that file to be appended to the end. 

2) ios::ate - Open a file for output and move the read/write control to the end of the file.

3) ios::in - Open a file for reading

4) ios::out - Open a file for writing

5) ios::trunc - If the file already exists, its contents will be truncated before opening the file.

You can combine two or more of these values by ORing them together. For example if you want to open a file in write mode and want to truncate it in case that already exists, 
following will be the syntax: 

    ofstream outfile;
    outfile.open("file.dat", ios::out | ios::trunc);

Similar way, you can open a file for reading and wiritng purpose as follows: 

    fstream afile;
    afile.open("file.dat", ios::out | ios::in);

--- Closing a File --- 

When a C++ program terminates it automatically flushes all the streams, release all the allocated memory and close all the opened files. But it is always a good practice that
a programmer should close all opened files before program termination. 

Following is the standard syntax for close() function which is a member of fstream, ifstream, and ofstream objects: 

    void close();

--- Writing to a File --- 

While doing C++ programming, you write information to a file from your program using the stream insertion operator (<<) just as you use that operator to output information to
the screen. The only difference is that you use an ofstream or fstream object instead of the cout object. 

--- Reading from a File ---

You read information from a file into your program using the stream extraction operator (>>) just as you use that operator to input information from the keyboard. The only difference
is that you use an ifstream or fstream instead of the cin object. 

--- File Position Pointers ---

Both istream and ostream provide member functions for repositioning the file-position pointer. These member functions are seekg for istream and seekp for ostream. 

The argument to seekg and seekp normally is a long integer. A second argument can be specified to indicate the seek direction. The seek direction can be ios::beg (the default)
for positioning relative to the beginning of a stream, ios::cur for positioning relative to the current position in a stream or ios::end for positioning relative to the end of
a stream. 

The file-position pointer is an integer value that specifies the location in the file as a number of bytes from the file's starting location. Some examples of postioning the 
"get" file-position are: 

	// position to the nth byte of fileObject (assumes ios::beg)
	fileObject.seekg(n);

	// position n bytes forward in fileObject
	fileObject.seekg(n, ios::cur);

	// position n bytes back from end of fileObject
	fileObject.seekg(n, ios::end);

	// position at end of fileObject
	fileObject.seekg(0, ios::end);

*/


#include <fstream>
#include <iostream>
using namespace std;

int main () { 
    char data[100];

    // open a file
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    outfile << data << endl;

    outfile.close();

    fstream infile;
    infile.open("afile.dat");
    
    cout << "Reading from the file" << endl;
    infile >> data;

    cout << data << endl;

    infile >> data;
    cout << data << endl;

    infile.close();

    return 0;
}
