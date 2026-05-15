/*

----- Move Semantics -----

Move semantics are used in C++ to transfer the ownership of resources from one object to another instead of copying them. It imporoves the performance as it avoids unnecessary copying of objects, reducing memory usage, improves efficiency, and efficiently handles the temporary objects like rvalue. 

--- Why Move Semantics are Needed? ---

Before C++11, we used to copy the resource an it was less efficient and created duplicates. In C++11, move 
semantics were introduced to solve this problem of memory overhead and reducing the duplicates. Here are reasons why we need move semantics: 

 > Move semantics avoid copying of resources. It helps in avoiding duplicates and cause less memory overhead.

 > It handles temporary objects like rvalues. 

 > It improves the performance by moving the resources instead of copying. 

--- Expression Types in C++ ---

An expression in C++ means any valid combination of variable, operator, constant, and function call that can give result. There are two types of expression which are as follows: 

 > lvalue Expression, an lvalue is a type of expression in which object has a memory address and can be modified if it is not const. Example of lvalue can be a variable, array elements, and many more. 

 an lvalue reference is used to create a referance to an lvalue. It is denoted by (&) and is used for implementing copy semantics. 

 > rvalue Expression, an rvalue is a type of expression that does not have a memory address and it represents a value that generally appears on the right side. It is a temporary expression that is about to get destroyed. Example of rvalue can be a constant, temporary object, and many more. 

an rvalue reference is used to reference rvalues or temporary objects. It is denoted by (&&) and is used for implementing move semantics. 

(see Example 1)

--- Why do Move Semantics Apply to Rvalues Only? ---

The move semantics is applied only to rvalues because the rvalues are temporary objects, that are about to get destroyed. The rvalue will not affect the program in future as they are temporary and can be changed. So, applying move semantics on rvalue to transfer the ownership won't affect the program. 

--- Implementing Move Semantics: Move Constructor ---

A move constructor is a special constructor used to transfer the ownership of resources from a temporary object or rvalue to a new object using rvalue reference. The move constructor is automatically called when initializing an object with an rvalue. 

(see Example 3)

--- Move Assignment Operator ---

The move assignment operator uses '(=)' and rvalue reference for move semantic. First, it releases the current resource of object and then take ownership of the source object's resources. 

(see Example 4)

*/

#include <iostream>
#include <cstring>
using namespace std;

// ----- Example 1 -----
int Ex1(){
	// x is an lvalue
	int x = 10;
	
	// x + 5 is an rvalue
	int y = x + 5;

	cout << "Old x: " << x << endl;
	cout << "Old y: " << y << endl;

	// Demonstrating assignments
	x = 20; // this would be an lvalue, rvalues are not assignables
	
	cout << "New x: " << x << endl;

}

// ----- Example 2 -----
void printValue(int &x){
	cout << "Calling with Lvalue reference: " << x << endl; // lvalue reference
}

void printValue(int &&x){
	cout << "Calling with Rvalue reference: " << x << endl; // rvalue reference 
}

int Ex2(){
	int a = 10;

	printValue(a); // a is an lvalue
	printValue(20); // 20 is an rvalue

	return 0;
}

// ----- Example 3 -----
class MyString { 
	private:
		char *data;
		size_t length;

	public:

		// Regular constructor
		MyString(const char *str){

			length = strlen(str);
			data = new char[length + 1];
			strcpy(data, str);
			cout << "Constructor called\n";
		}

		// Move constructor
		MyString(MyString &&other) noexcept {

			data = other.data; // transferring ownership
			length = other.length;
			other.data = nullptr;
			other.length = 0;
			cout << "Move constructor called\n";
		}

		// Destructor
		~MyString(){
			delete[] data;
			cout << "Destructor called\n";
		}

		void print() const {
			if(data)
			   cout << data << endl;
		}
};

// Function returning a temporary object(rvalue)
MyString createString(){
	return MyString("Temporary");
}

int Ex3(){

	// Calling move constructor
	MyString s1 = createString();
	s1.print();

	return 0;
}

// ----- Example 4 -----

class MyString2 {
	private:
		char *data;
		size_t length;

	public: 
		// Regular constructor
		MyString(const char* str){
			length = strlen(str);
			data = new char[length + 1];
			strcpy(data, str);
			cout << "Constructor called\n";
		}

		// Move constructor
		MyString(MyString&& other) noexcept
		{

		data = other.data;
		length = other.length;
		other.data = nullptr;
		other.length = 0;
		cout << "Move constructor called\n";
	
		}
		
		MyString& operator = (MyString&& other) noexcept {
			if (this != &other) { 
				delete[] data;
				data = other.data; // transferring ownership
				length = other.length;
				other.data = nullptr;
				other.length =0;
				cout << "Move assignment operator called\n";
			}
			return *this;
		}

		// Destructor
		~MyString() {
			delete[] data;
			cout << "Destructor called\n";
		}

		void print() const {
			if (data)
				cout << data << endl;
		}
};

int Ex4(){
	MyString s1("Hello");
	MyString s2("World");

	cout << "Before Move Assignment: \n";
	s1.print();
	s2.print();

	s1 = std::move(s2); // Move assignment operator called
	
	cout << "After move assignment: \n;
	s1.print();
	s2.print(); //s2 is now empy
	
	return 0;
}

				
	
