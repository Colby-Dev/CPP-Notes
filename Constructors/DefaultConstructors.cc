#include <iostream> 

using namespace std; 

/* 

----- Default Constructors -----

Constructors are functions of a class that are executed when new objects of the class are created. The constructors have the same name as the class and no return type,
not even void. They are primarily useful for providing initial values for variables of the class. The two main types of constuctors are default constructors and parameterized
constructors. 

C++ defualt constructors do not take any parameters. If a default constuctor is not provided by the programmer explicitly, then the compiler provides a imiplicit default
constuctor. In that case, the default values of the variables are 0. 

    class MyClass{
        public:
            MyClass(){
                // Default constuctor body    
        }
    };

--- Implicit vs Explicit Default Constuctors ---

In object-oriendted programming (OOP), depending on how a default constructor is declared, it can be divided into two categories, implicit and explicit. 

> Implicit Default Constuctor, An implicit default constructor is a constructor that is automatically called by the complier when an object is created, it may
  also be invoked if the user passes arguments that would be convertible into the constuctor's parameters.

    class MyClass{
        int x;
        double y;
    };

    int main(){
        MyClass obj;
    }

> Explicit Default Constuctor, An explicit default constuctor is the one where the consturctor is not allowed to be called implicitly by the complier when performing
  automatic type conversions or copy-initializion. In other words, the user can only call directly when providing a matching argument. 

    class ClassName {
        public: 
            explicit ClassName(int x = 10);
    };

--- Default Constructor vs Parameterized Constructor ---

A default constructor is a constructor, which takes no parameter or has all its parameters set to default values.

Whereas a parameterized constuctor is a constuctor, which takes one or more arguments. It allows users to pass values during the creation of an object,
which is further used for the initialzation of an object. 

    // Default Constructor
    class ClassName {
        public: 
            ClassName() {
            
            }
    };

--- When Default Consturctor Called? ---

A default constuctor is called in various situations, mainly when an object is created without arguments. Here we will discuss more situations where the default
constuctor is invoked:

> When an Object is created without arguments. 

> When a class does not explicitly defined any constuctors. 

> In dervied classes, if the base class has default constuctor.

> When dynamically allocationg an object. 

--- Overloading the Default Constuctor ---

In C++, overloading the default constuctor is said to create multiple constuctors within a class, where each constuctor has a different parameter list,
allowing for different ways of initializing objects. 

*/

class MyClass{
    public:
        int a, b;

    MyClass() : a(0), b(0){
        cout << "Dfault constuctor called" << endl;
    }

    MyClass(int x) : a(x), b(0){
        cout << "Overloaded constructor (1 argument ) called" << endl;
    }

    MyClass(int x, int y) : a(x), b(y){
        cout << "Overloaded constructor (2 arguments ) called" << endl;
    }

    void display(){
        cout << "a: " << a << ", b: " << b << endl;
    }
};

int main() {

    MyClass obj1;
    MyClass obj2(10);
    MyClass obj3(10, 20);


    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}