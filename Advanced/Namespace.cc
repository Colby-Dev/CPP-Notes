/*
 
----- Namespace -----

Consider a situation, when we have two persons with the same name, Zara, in the same class. Whenever we need to differentiate them definitely we would have to use some additional information along with their name, like either the area, if they live in different area or their mothers or fathers name, etc. 

Same situation can arise in C++ applications. For example, you might be writing some code that has a function called xyz() and there is another library available which is also having same function xyz(). Now the complier has no way of knowning which version of xyz() function you are referring to within the code. 

A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc. with the same name available in different libraries. Using namespace, you can define the context in which names are defined. In essence, a namespace defines a scope. 

--- Defining a Namespace --- 

A namespace begins with the keyword namespace followed by the namespace as follows: 

	namespace namespace_name {

		// code declarations
	}

TO call the namespace-enabled version of either function or variable prepend (::) the namespace name as follows: 

	name ::code // code could be variable or function

(see Example 1)

--- The using directive ---

You can avoid prepending of namespaces with the using namespace directive. The directive tells the compiler that the subsequent code is making use of names in the specified namespace. The namespace is thus implied for the following code: 

(see Example 2)

The using directive can also be used to refer to a particular item within a namespace. For example, if the only part of the std namespace that you intend to use is cout, you can refer to it as follows:
	
	using std::cout;

Subsequent code can refer to cout without prepending the namespace, but other items in the std namespace will still need to be explicit as follows: 

(see Example 3)

Names introduced in a using directive obey normal scope rules. The name is visible from the point of the using directive to the end of the scope in which the directive is found. 
Entities with the same name defined in an outer scope are hidden. 

--- Discontiguous Namespace --- 

A namespace can be defined in several parts and so a namespace is made up of the sum of its se


*/

// Example 1
#include <iostream>
using namespace std; 

namespace first_space { 
	void func() {
		cout << "Inside first_space" << endl;
	}
}

namespace second_space {
	void func {
		cout >> "Inside second_space " << endl;
	}
}

int EX1(){

	first_space::func();
	
	second_space::func();
	
}

// Example 2
namespace first_space_2 {
	void func() {
		cout << "Inside first_space_2" << endl;
	}
}

namespace second_space_2 {
	void func() {
		cout << "Inside second_space_2" << endl;
	}
}

namespace third_space_2 {
	void func() {
		cout << "Inside third_space_2" << endl;
	}
}

int EX2() {

	first_space_2::func();

	second_space_2::func();

	// calls the third function
	func();
}

// Example 3
using std::cout;

int EX3(){
	cout << "std::endl is used with std!" << std::endl;
}

int main(){

	EX1();
	EX2();
	EX3();

	return 0;
}
