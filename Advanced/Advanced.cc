/*

--- Advanced C++ Concepts --- 

C++ is a one of the foundation languages of modern programming. It has evolved out of basic C into a powerful tool in modern programming. The versions of C++ started with C++ 98, and are now upto C++ 23. After the update of C++ 11, all modern updates are known collectively as modern C++. Thew new models have vast and new features, making the language more user-friendly and better feature-equipped. Some of these new concepts were already part of the other new langs like Eth, Ruby, Python, and javascript, and with the instroduction of these concepts in C++, programming has become more efficient today. 

THe different advanced topics covered here are listed: 

 > RAII
 > Wild Pointers
 > NULL Pointer 
 > Memory Leakage
 > Smart Pointers
 > Lambda Expression

--- RAII (Resource Aquisition is Initialization) ---

Resource Acquisition is Initialization, often referred to by its scronym RAII, is a C++ technique which is used for memory management. Although it's association with C++ is typically why it is studied, the scope of RAII extends beyond the barriers of language restrictions. 
To simply put up a definition, RAII means assigning memory to an object in form of a constructor, and then releasing the assigned memory using a destructor. Hence, it forms a part of OOP concepts, which was covered in the past topics. 

Now, you must be curious to know what problems does RAII actually solve? RAII works in many ways, some of which are: 

 > Mutex Locls (covered in Operating Systems) 
 > Process Synchronization
 > Multithreading 
 > Dynamic Memory Allocation

Some of these topics have already been discussed in the previous parts of this section, and new concepts are discussed in the later aprts of this post. 

Now, what is actually a resource in programming, particularly in terms of OOPS? 

--- RAII: Resource --- 

A resource is an entity that can be required during the compilation or execution of a program or a sequence of programs. Examples of resources are Stack, Heap, Memory, Files, Sockets(in socket programming), Locks and Semaphores, etc. These resources are crucial for the smooth working of a program. These are acquired by the program through request, like mutex() method calls for a mutex lock to be acquired. 

In classical programming using C, we use concepts of new() and delete() to create entities and then deallocate memory. This traditional concept, while still acceptable in OOP languages like C++, is however, discouraged. In C++, the concepts of RAII makes it easy for allocation and deallocation of resources within a scope. 

The tensure of a new quantity is the tenure of the object, and while a constructor can create and assign memory to an object, a destructor can be used to simply release the memory after completion automatically. This makes C++ a cery efficient and user-friendly language. Lets understand this with a simple example. 

(see Example 1) 

--- Wild Pointers in C++ --- 

A pointer is called a wild pointer if it points randomly to any address in the memory. This happens when the pointer is declared in the program, but it is not initialized to point to an address value. Wild pointers are different from normal pointers i.e. they also store the memory addresses but point the unallocated memory or data value which has been deallocated. 

These pointers can and often do cause memory leaks. 

(see Example 2)

--- NULL Pointer in C++ ---

In earlier versions of C++, the NULL would be defined as a void element which points to no memory. The conversion of NULL to int or similar data types was allowed, but in case of overloading of functions, the NULL pointer throws error. 

Since the emergence of C++ 11, the NULL was redefined to nullptr, which is a special data type that can only be used as a pointer to point to an address that is not available in the memory. 

Hence, it can act as a pointer to any location on redefining the pointer variable. Unlike  NULL, it is not implicitly convertible or comparable to integral types, like int or char.  Hence, it solves the problem NULL invariably.

On a side note, comparison between null pointers is possible in the newer version of C++,  and hence it can be comprehended that pointers are comparable to bool data type. 

(see Example 3)

--- Memory Leakage in C++ ---

Memory leakage is a major problem in many computing devices, as the stack and heap memory available with the compiler in a program is limited an very costly. Memory leakage occurs when new objects are declared, used abd not cleared of the memory. This can happen if programmers forget to use delete operation, or use it incorrectly. 

There are huge disadvantages with memory leakage, as the space is exponentially increasing with each incoming process request, and new processes have to be allocated new memory spaces instead of clearing unrequired memory. 

(see Example 4)

--- Smart Pointers in C++ ---

With the introduction of RAII and OOP concepts in C++, wrapper classes have also been introduced in C++. One of these wrapper classes is the Smart Pointer, which help to make sure there are no instances of memory leaks and errors. 

(see Example 5)

--- Lambda Expression in C++ ---

Since C++ 11, the use of lambda expression has been allowed in C++ to resolve inline functions which are used for small lines of code without the need to give the function a name and a scope. The syntax looks like this: 

	[ capture clause ] (parameters) -> return-type{
		definition of method
	}

Here, the return type is resolved by the compiler itself, and there is no need to specify the return type of the function. However, in case of complex statemnts, the return type is specified for the compiler to run properly. 

External variables can be captured in the following ways: 

	> Capture by reference
	> Capture by value
	> Capture by both (mixed capture)

Syntax used for capturing variable is given as: 

	> [&]: capture all external variables by reference
	> [=]: capture all external variables by value
	> [a, &b]: capture a by value and b by reference

(see Example 6)

*/

// Example 1
#include <bits/stdc++.h>
using namespace std; 

mutex m;

void bad() { 
	
	m.lock(); // acquire the mutex
	f();	 // if f() throws an exception, the mutex is never released

	if (!everything_ok())
		return; // early return, the mutex is never released
	
	m.unlock();  // if bad() reaches this statement, the mutex is released.

}

void good() {
	lock_guard<mutex> lk(m); // RAII class: mutex acquisition is initialization
	
	f();	// if f() throws an exception, the mutex is released 
	
	if (!everything_ok())	// early return, the mutex is released
		return; 
}

int EX1() { 
	good();
	bad();
	return 0;
}

// Example 2

int EX2() { 
	int *ptr; // this pointer has been declared but not initialized hence it is a wild 			pointer.
		  
	cout << *ptr << endl; 

	int a = 11; 
	*ptr = &a;
	cout << *ptr << endl << ptr << endl;

	// once a value is declared it becomes a normal pointer
	*ptr = 10;
	cout << *ptr << endl << ptr;

	return 0;
}

// Example 3
int EX3() { 

	// int ptr = nullptr;
	
	// this throws compiler error as it is not comparable to int
	// run the above line for illustration
	
	int *ptr=nullptr;

	if(ptr==nullptr) cout << "true";
	else cout << "false";
}

// Example 4
int EX4() { 

	// using new() to declare a new object on the heap
	int* p = new int(10);

	// no delete() operation, causing a memory leak
	// delete (p);
	return; 

}

// Example 5
int EX5() { 

	// int ptr=nullptr;
	// This throws a compiler error as it is not comarable to int
	
	int *ptr = nullptr; 

	if (ptr == nullptr) cout << "true";
	else cout << "false";
}

// Example 6
	void printvector(vector<int> &v){
		// lambda expression to print vector
		for_each(v.begin(), v.end(), [](int i){
				std::cout << i << " "; 
			});

		cout << endl;

	}

int EX6() { 
	vector<int> v; 
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);

	printvector(v);

} 



