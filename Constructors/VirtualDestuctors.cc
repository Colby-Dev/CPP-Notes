/*

----- Virtual Destructors -----

A virtual destructor is a destructor declared within the base class with the virtual keyword. When deleting a derived class object using a pointer to a
base class, the base class should be defined with a virtual destructor. 

Virtual destructors help prevent the problem of memory leaks and undefined behavior. If a virtual destructor is not used, then only the base class destructor
is called, and the resources of derived class is not cleaned up. 

    class Base {
        public:
        virtual ~Base() { 
            // base class destructor 
        }
    };

--- Why We Need Virtual Destructors? ---

Given below are the reasons why virtual destructors are needed: 

> When you not use a virtual base class destructor while deleting a derived class object, it results in undefined behavior. 

> Virtual destructors make sure to delete the object of derived class too while deleting the base class object. 

> It avoids memory leaks

> Virtual destructors maintain the order of execution of destructors i.e., first derived class, then base class.

--- When to Use Virtual Destructors? ---

> If a virtual function is used, then use virtual destuctor. Since, virtual functions are used in polymorphism to override base class. Using a virtual
  destructor can free up memory of both, base and derived class.

> In inheritance, make the destructor of base class a virtual destructor as the destructor of derived class is skipped and only the base class destructor
  is called, it may cause a memory leak. 

> If abstract base or pure virtual function is used, then use virtual destructor on base class. 

--- Virtual Destructor Table (Vtable) ---

In C++, virtual table (vtable) is lookup table which is used by the compiler to implement virtual functions or virtual destructors. For each class that
has at least one virtual function or virtual destructor, the compiler will create a vtable for that class. 

A vtable has pointers to all virtual functions and the virtual destructor of a class. In a class, each object has a hidden pointer known as vptr or 
vitual pointer. This vptr points to the vtable of the class, which is then used to call the respective destructor. 

--- Conclusion ---

The virtual destructor is used when working with inheritance and polymorphism. Its main purpose is to make sure that the destructors of derived classes
are also called when an object is deleted through a base class pointer. This prevents memory leaks and undefined behavior. 


*/



#include <iostream> 

using namespace std; 

int main() { 


}