#include <iostream> 
using namespace std; 

/*

----- Virtual Functions -----

A virtual function in C++ is a member function in a base class, which is further overriden in derived classes. 
This helps in enabling runtime polymorphism, which means the function to be executed is determined at runtime,
not compile time as the function that gets called depends on the actual object type, not the pointer or reference type. 

--- Virtual Function Declaration --- 

A virtual function is declared in the base class using the virtual keyword. 

    class BaseClassName {
    public: 
        virtual void func_name(){
            // implementation
        }
    };

--- How Virtual Functions Work ---

In C++, Virutal Functions allow runtime polymorphism, which means the function, that gets called depends on the
actual object type, not the pointer or reference type, and this is done by using a mechanism called vtable (virtual table)
and vptr (virtual table pointer).

> Virtual Table (VTable) and Virtual Pointer (VPTR) < 

    Virtual Table is a table of function pointers, which is created for each class that has virtual functions, it stores
    addresses of virtual functions of the class. 

    Whereas each object of that class with virtual functions contains a hidden vptr, where this vptr points to the vtable of
    its class.

> Step-by-Step Working < 

    When we declare a function as virtual in the base class, it enables dynamic binding instead of static binding. 
    For a class with virtual functions, the compiler creates a vtable, which stores pointers to those functions.

    Here each object of a class with virtual functions has a vptr, which points to the class's vtable. 

    Then a base class pointer uses vptr to fetch the correct function from the vtable at runtime, ensuring the derived class's
    overriden function is called. 

--- Explanation ---

Firstly, a base class name shape is created with virtual function draw(), therefor it will set up the mechanism of Vtable for this class.
Now the circle class inherits from shape and overrides draw(), so when a circle object is used, then its draw() function is called. 
Similar to the circle, the square class will also override the draw() function. 

--- Rules for Virtual Functions ---

Virtual function must be declared in the base class using the "virtual" keyword. If virtual is omitted, overriding will not work dynamically.
Virtual functions must be accessed through a base class pointer or reference. if it is accessed directly using an object then compile-time 
binding will occur. 

With a virtual function, a base class must also have a virtual destructor to prevent memory leaks. In case the destructor is not virtual then
only the base class destructor will be called, causing a memory leak. 

A Class with a pure virtual function becomes an abstract class and cannot be instantiated and If a derived class does not override a pure
virtual function, It also becomes abstract. 

Virtual can be both public and private where public can be accessed using an object or pointer but it can still be inherited and overridden in
the derived class. 

Constructors, Static, and Friend Functions cannot be virtual. 

*/

class shape{
    public: virtual void draw(){
        cout << "Creating a shape!" << endl;
    }
};

class circle: public shape {
    public: void draw(){
        cout << "Creating a Circle!" << endl;
    }
};

class square: public shape {
    public: void draw(){
        cout << "Creating a Square!" << endl;
    }
};

int main(){
    shape * shapePtr;
    circle c; 
    square s;

    shapePtr = &c;
    shapePtr -> draw();

    shapePtr = & s;
    shapePtr -> draw();

    return 0;
}