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

--- The # and ## Operators ---

The # and ## preprocessor operators are available in C++ and ANSI/ISO C. The # operator causes a replacement-text token to be converted to a string surrounded by quotes. Consider the following macro definition: 

	#include <iostream> 
	using namespace std; 

	#define MKSTR(x) #x

	int main () {

	cout << MKSTR(Hello C++) << endl;

	return 0;

	} 

If we complied this code we would produce the result Hello C++. This worked since the C++ preprocessor turns this line: 

	cout << MKSTR(Hello C++) << endl;

The compiler then reads this as: 

	cout << "Hello C++" << endl;

The ## operator is used to concatenate two tokens. Here is an example: 

	#define CONCAT( x , y) x ## y 

When CONCAT appears in the program its args are concatenated and used to replace the macro. For example, CONCAT(Hello , C++) is replaced by "Hello C++" in the program as follows: 

(see Example 4)

When compiled this will produce the a string 100.

--- Predefined C++ Macros --- 

C++ provides a number of predefined macros as show in the example below: 

(see Example 5)


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

// Example 4
#define concat(a, b) a ## b

int EX4() { 

	int xy = 100; 
	cout << concat(x, y);
}

// Example 5
int EX5() { 

	cout << "Value of __LINE__ : " << __LINE__ << endl;
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	cout << "Value of __TIME__ : " << __TIME__ << endl;
}



int main() { 

	EX1();
	EX2();
	EX3();
	EX4();
	EX5();
	return 0;
}

