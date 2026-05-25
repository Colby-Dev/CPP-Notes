/*
 
----- Preprocessor -----

The preprocessors are the directives, which give instructions to the compiler to preprocess the information before actual complication starts. 

All preprocessor directives begin with #, and only white-spaced characters may appear before a preprocessor directive on a line. Preprocessor directives are not C++ statements, so they do not end in a semicolon. 

You already have seen a #include directive in the examples. This macro is used to include a header file into the source file. 

These are number of preprocessor directives supported by C++ like #include, #define, #if, #else, etc. 

--- The #define Preprocessor --- 

The #define preprocessor directive creates symbolic constants. The symbolic constant is called a macro and the general form of the directive is: 

	#define macro-name replacement-text

When this line appears in a file, all subsequent occurrences of macro in that file will be replaced by replacement-text before the program is compiled. 

(see Example 1)

--- Function Like Macros --- 

You can use #define to define a macro which will take argument as follows: 

(see Example 2)

--- Conditional Compliation --- 

There are several directives, which can be used to compile selective portions of your program's source code. This process is called conditional compilation. 

The conditional preprocessor construct is much like the if selection structure. Consider the following preprocessor code: 

	#ifndef NULL
		#define NULL 0
	#endif

You can compile a program for debugging purpose. You can also turn on or off the debugging using a single macro as follows: 

	#ifdef DEBUG
		cerr << "Variable x = " << x << endl;
	#endif 

This causes the cerr statement to be compiled in the program if the symbolic constant DEBUG has been defined before directive #ifdef DEBUG. You can use #if 0 statement to comment out a portion of the program as follows: 

	#if 0
		code prevented from compiling 
	#endif

(see Example 3)




*/


// Example 1
#include <iostream>
using namespace std; 

#define PI 3.14159

int public EX1() { 
	cout << "Value of PI: " << PI << endl;
}

// Example 2
#define MIN(a,b) (((a)<(b)) ? a : b)

int EX2() { 

	int i, j;

	i = 100; 
	j = 30;

	cout << "The minimum is " << MIN(i,j) << endl;

}

// Example 3
#define DEBUG
#define MIN(a, b) (((a)<(b)) ? a:b)

int EX3() { 
	int i, j;
	i = 100; 
	j = 30;

	#ifdef DEBUG
		cerr << "Trace: inside main function" << endl;
	#endif
	
	#if 0
		cout << MKSTR(HELLO C++) << endl;
	#endif

		cout << "The minimum is " << MIN(i,j) << endl;
	
	#ifdef DEBUG 
		cerr << "Trace: Coming out of main function" << endl;
	#endif

}



int main() { 

	EX1();
	EX2();
	EX3();
	return 0;
}

