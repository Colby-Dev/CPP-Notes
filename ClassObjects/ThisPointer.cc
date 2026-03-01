#include <iostream> 

using namespace std; 

/*
----- This Pointer -----

Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter for all member functions.
Therefore, inside a member function, this may be used to refer to the invoking object. 

Friend functions do not have a this pointer because friends are not members of a class. Only member functions have this pointer. 

--- Return Calling Object's Reference Using this Pointer ---

To implement chain function calls, you need the reference of a calling object. You can use the "this" pointer to return the reference of the calling object.

    Test& Test::func () {
        return *this;
    }

--- Characteristics of the "this" Pointer ---

> The "this" pointer refers to the current instance of the object, where it allows the member function to access the object's attributes and methods

> The "this" pointer is implicitly passed to all non-static member functions, where you don't need to explicitly write this in code. 

> "this" points to the memory location of the current object

> If there is a name conflict between a parameter and a member variable, this can be used to differentiate the member variable from the local parameter. 

> the "this" pointer is constant (const), meaning it cannot be modified

> Since this is a pointer, it can be dereferenced to access the current object.

--- this Pointer in Const Member Functions vs Static Member Functions ---

In const member functions, this pointer is a pointer to a constant object (const MyClass*), where the object's members cannot be modified within the function,
resulting in an object remaining unchanged when calling const functions. 

Whereas static member functions don't have this pointer because they are not associated with any specific instance of the class, they belong to the class itself
and can only access static members or methods, as they do not operate on object-specific data. 

--- Common Use Cases of this Pointer ---

In C++, this pointer is a special pointer, which refers to the current instances of a class in non-static member functions. Here we will see its common use cases:

> this pointer helps in precenting self-assignment in assignment operators making sure that an object doesn't assign itself to itself. 

> this pointer makes method chaining possible by returning the current object (usually through *this), allowing you to call several methods on the same object in a single
  line of code. 

> It allows for direct access to the object's members within member functions. 

> It is important in copy constuctors and assignment operators, as it helps return the current object during assignments.

> It is also useful in Polymorphism, Inherited Classes, and Implement Fluent Interfaces, allowing smooth method chaining

--- Limitations of this Pointer ---

The "this" pointer is a powerful deature in C++, but it has certain limitations and potential pitfalls that developers should keep in mind to prevent errors or
unexpected behavior. 

> this pointer isn't available in static member functions because static functions are tied to the class itself, not to any specific object. 

> It can help differentiate between member variables and local variables when their names overlap. However, if a local variable shadows a member variable,
  it can still lead to confusion or ambiguity. 

> this pointer always refers to the current object, but using it after the object is destroyed or while it's being destroyed can cause undefined behavior. 

> When dealing with multiple inheritance, conflicts can occur if different base classes share members with identical names. This can make it unclear which member
  the this pointer is pointing to, leading to ambiguity

> Returning *this from a temporary object can be risky since it might leave behind a dangling reference, which could cause unexpected or undefined behavior

*/

class MyClass {
    public:
        MyClass(int val) : data(val) {}

        void printData() const {
            std::cout << "Data: " << data << std::endl;
        }

        static void showMessage() {
            std::cout << "This is a static function!" << std::endl;
        }

        private:
            int data;
};

int main(){
    MyClass obj(5);

    obj.printData();

    MyClass::showMessage();

    return 0;
}