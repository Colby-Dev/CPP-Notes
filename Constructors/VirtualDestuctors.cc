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




*/



#include <iostream> 

using namespace std; 

int main() { 


}