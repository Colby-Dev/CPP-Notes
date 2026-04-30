/*
 
----- Reading From File -----

File I/O (Input / Output) in C++ is the process of reading and writing to files. C++ provides this for handling files through the standard library with <fstream> header file. 
File I/O allows programs to persist data, interact with external resources, and store/retrieve information beyond the scope of program execution. 

--- Types of File Streams ---

There are 3 primary types of file streams, where each is associated with different operations: 

 > ifstreams (Input File Streams) - This is used for reading data from a file. 
 
 > ofstreams (Output File Streams) - This is used for writing data to a file. 

 > fstream (File Stream) - This is used for both input and output operations on a file. It combines the functionality of both ifstream and ofstream. 

 --- Basic Steps in File I/O ---

Heres the given basic steps in file I/O:

  > Opening a File:
  	Before reading or writing to a file, it must be opened using one of the file stream classes. If the file is successfully opened, 
	the program will proceed with I/O operations. 

  > Performing File Operations:
  	You can read from or write to a file using the appropriate methods. 

  > Closing the File: 
  	After the file operations are completed, you should close the file to make sure that all data is flushed and the file is properly released. 

--- Reading with ifstream (Stream Extraction Operator) ---

Using stream extraction operator (>>) is the simplest way to read data from a file in C++. This operator reads formatted data from a file, 
similar to how data is read from standard input. (see example 1)

--- Using getline() to Read Line ---

If you want to read an entire line or text, including steps you can use the getline() function. This function will read characters from the file
until a newline character (\n) is encountered. (see example 2)

--- Reading Binary Files (using read()) --- 

The above discussed methods are for text files, for binary files you can use the read() function to read raw binary data from a file. (see example 3) 

--- Handling Errors in File I/O ---

Handling errors is important to ensure that your program behaves correctly when files are not available, can't be opened, or when unexpected 
conditions occur during reading/writing. 

	> Checking for Errors with fail(), eof(), and good()

		fail() - Checks if a non-recoverable error occurred during I/O.
		eof() - Checks if the end of file (EOF) was reached. 
		good() - Returns true if no error has occurred. 
	
	> Handling End of File (EOF)

		When reading from a file, it's important handle the case when you reach the end of the file. The standard approach is to used
		eof() or std::getline() operators, which automatically stop when the end of the file is reached. 

	> Handling I/O Errors Gracefully
		
		During file operations, you should check for fail() or bad() states to detect errors like unexpected end-of-file or data 
		corruption. 

*/

#include <fstream>
#include <iostream>
#include <string>

// Example 1: Reading with ifstream
int example1(){
	std::ifstream inputFile("example.txt"); // Open the file for reading

	if (!inputFile){
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	std::string word;
	while (inputFile >> word){ // Reads until a whitespace is encountered
		std::cout << word << std::endl;
	}

	inputFile.close();
	return 0;
}

// Example 2: Using getline() to Read Lines
int example2(){
	std::ifstream inputFile("example.txt");

	if (!inputFile){
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		std::cout << line << std::endl;
	}

	inputFile.close();
	return 0;
}


// Example 3: Reading from Binary Files
int example3(){
	std::ifstream file("example.bin", std::ios::binary);

	if (!file){
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	file.seekg(0, std::ios::end);
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	char* buffer = new char[size];
	file.read(buffer, size);

	for (std::streamsize i = 0; i < size; ++i){
		std::cout << std::hex << (0xFF & buffer[i]) << " ";
	}

	delete[] buffer;
	file.close();
	return 0;
}
