/*
 
----- Templates -----

Templates are the foundation of generic programming, a programming style that allows wiritng functions, classes, algorithms, and different code snippets that work with different data types. 

A template is a blueprint or formula for creating a generic class or a function. The library containers like iterators and algorithms are examples of generic programming and have been developed using template concepts. 

There is a single definition of each container, such as vector, but we can defined many different kinds of vectors, for example, vector <int> or vector <string>. The two keywords that are used to define a template are template and typename. 

--- Function Template --- 

Function templates define a blueprint for functions that enables a function to operate on different data types without rewriting the same logic. 

	template <template identifier> function_decalaration;

Here the 'template' keyword declares the generic function and 'typename' keyword specifies the type to be used for the parameter. 

(see Example 1)

--- Class Template ---

Similarly, class templates also define a blueprint for creating classes that can work with any data type. 

	template <class type> class class-name {

	.

	.

	.

	}

Here, type is the placeholder type name, which will be specified when a class is instantiated. You can define more than one generic data type by using a comma-separated list. 

(see Example 2)

--- Template Argument Deduction --- 

Template argument deduction is a feature that automatically deduces (understands) the data type of the argument passed to a function or class template. Instead of explicitly specifying template arguments, the compiler figures them out for you. 

--- Function Template Argument Deduction --- 

Template argument deduction is a feature that automatically deduces (understands) the data type of the argument passed to a function or class template. Instead of explicitly specifying template arguments, the compiler figures them out for you. 

(see Example 3)

In this code, we didn't write add<int>(5,3) or add <double>(3.14, 2.86). The compiler deduces the type based on the args you provide. 

--- Function Template Argument Deduction --- 

In C++ Function template argument is a feature that allows the compiler to automatically deduce the types of template parameters based on the arguments passed to the function. 

(see Example 4) 

--- Class Template Argument Deduction --- 

Class template argument deduction in C++ is a feature that enables the compiler to automatically infer template parameters for class templates from the constructor arguments when creating an object. 

(see Example 5)


*/


// Example 1
#include <iostream>
#include <string> 

using namespace std; 

template <typename T>
inline T const& Max (T const& a, T const& b) {
	return a < b ? b:a;
}

int EX1(){
	int i = 300;
	int j = 10;
	cout << "Max (i, j): " << Max(i, j) << endl;

	double f1 = 22.1;
	double f2 = 21.9;
	cout << "Max (f1, f2): " << Max(f1, f2) << endl;

	string s1 = " hello";
	string s2 = "world";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;

}

// Example 2
#include <vector>
#include <cstdlib>
#include <stdexcept>

template <class T>
class Stack {
	private: 
		vector<T> elems;
	
	public:
		void push (T const&);
		void pop();
		T top() const;

		bool empty() const { 
			return elems.empty();
		}
}

template <class T>
void Stack<T>::push (T const& elem){
	// append copy of passed element
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop () {
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}

	// remove last element
	elems.pop_back();
}

template <class T>
T Stack<T>::top () const {
	if (elems.empty()) {
		throw out_of_range("Stack <>::top(): empty stack");
	};

	// return copy of last element 
	return elems.back();
}

int EX2(){

	try {
		Stack<int> intStack;
	;	Stack<string> stringStack;

		// manipulate int stack
		intStack.push(7);
		cout << intStack.top() << endl;

		// manipulate string stack
		stringStack.push("hello");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
	}
		catch (exception const& ex) { 
			cerr << "Exception: " << ex.what() << endl;
			return -1;
		}
	}

// Example 3
template<typename T>
T add(T a, T b) {
	return a + b;
};

int EX3(){

	// The compiler deduces T as int
	auto result1 = add(5,3);

	// The compiler deduces T as double
	auto result2 = add(3.14, 2.84);
}

// Example 4
template<typename T>
void printValue(T value){
	std::cout << value << std::endl;
};

int EX4(){
	printValue(42);
	printValue("Hello");
	printValue(3.145928);

}

// Example 5
template<typename T>
class Holder { 
	public: 
		Holder(T value) : data(value) {}
		void show() const { std::cout << data << std::endl; }
	
	private: 
		T data;
};

int EX5(){

	Holder h1(42);
	Holder h2(3.12432);
	Holder h3("Hello");

	h1.show();
	h2.show();
	h3.show();

}


int main(){

	EX1();
	EX2();
	EX3();
	EX4();
	EX5();

	return 0;

}


