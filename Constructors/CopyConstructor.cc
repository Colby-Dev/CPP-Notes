#include <iostream> 

using namespace std;

/*
----- Copy Constructor -----

The copy constructor is a constructor that creates an object by initializing it with an object of the same class which has been created previously. 
The copy constuctor is used to - 

> Initialize one object from another of the same type. 

> Copy an object to pass it as an argument to a function. 

> Copy an object to return it from a function. 

If a copy constuctor is not defined in a class, the compiler itself defines one. If the class has pointer variables and has some dynamic memory allocation,
then it is a must to have a copt constuctor. 

    classname (cosnt classname &obj){
    }

--- Copy Constructor to Create New Object ---

You can create a new object by using the existing object through the concept of a copy constructor. 

The copy constructor is used to create a new object as a copy of an existing object. 

--- Implicit vs Explicit Copy Constructors --- 

> Implict Copy Constuctor, 

    If the user doesn't define their own copy constuctor, then the compiler automatically provides an implicit copy constuctor. It preforms a shallow copy of the object,
    which means that it copies the values of each member of the object to the new object. It is called when:

        - When a user passes an object by value to a function. 
        - When the user returns an object by value from a function. 
        - When the user initializes an object with anoither object of the same type (copy initialization)

> Explicit (User-Defined Copy Constructor),

    It is the user-defined constuctor. This gives access to customize the copy behavior like creating a deep copy instead of the default shallow copy.

        MyClass obj1(10);
        MyClass obj2 = obj1;  <--- Explicit copy constructor
 
--- Rule of Three/Five ---

The Rule of Three and Rule of Five suggest while defining a copy constructor (ClassName(const ClassName& other)) you should also define:

    Rule of Three: 

        -> desturctor (~ClassName())
        -> and copy assignment operator (ClassName& operator = (const ClassName& other)). to ensure that memory is correctly managed. 

    Rulle of Five: 

        -> move constructor (ClassName(ClassName&& other))
        -> move assignment operator (ClassName& operator = (ClassName&& other)).

These special member functions are necessary for the proper management of dynamic memory and other and other resources like file handling
or network connections in a class. 

----- Deep Copy vs Shallow Copy -----

In C++, deep copy and shallow copy are different ways of copying objects and thry are important when a class involves dynamic memory management. 

> Shallow Copy 

    it occurs when an object is copied in such a way that both original and copied objects share the same resources. This means that the copy constuctor or copy
    assignment operator simply copies the values of data memebers (like pointer), without allocating new memory or making independent copies of the resources. 

> Deep Copy

    it occurs when an object is copied by allocating new memory for its own copy of the resoruces, making sure that original and copied object is completely
    independent. Avoids double-free or dangling pointers. 

*/

class MyClass{
    private: 
        int* data;

    public:

        //Constructor
        MyClass(int value) {data = new int(value);}

        //Deep Copy Constructor
        MyClass(const MyClass& other) { data = new int (*other.data)}

        ~MyClass() { delete data;}

        void showData() const { const << "Data: " << *data << endl;}
};

int main(){

    MyClass obj1(42);
    MyClass obj2 = obj1;

    obj1.showData();
    obj2.showData();

    return 0;
}