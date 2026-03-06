#include <iostream> 

using namespace std; 

/* 

----- Parameterized Constructors -----

In C++, constructors are special members functions, which are called automatically, when an object is created. There are two main types of constuctors: default constuctors
and parameterized constructors. 

A default constructor is a constructor that does not take any parameters or has dfault values for all parameterized construtor. 

Whereas a parameterized constuctor is a constructor, which takes one or more parameters and is used to initialze an object with specific values passed when object
is created. 

--- Parameterized Constuctors --- 

C++ parameterized consturctor is a constructor, which accepts one or more arguments or parameters, to initialize an object with specific values, when created. 
Unlike the default constuctor, which takes no arguments, a parameterized constuctor takes one or more arguments. 

    ClassName(parameters){
        // Initialization code
    }

--- Multiple Parameterized Constructors (Constructor Overloading) ---

Constructor overloading or multiple parameterized constuctors in C++, is a concept, which allows users to define multiple constuctors in the same class with different
parameter lists, where each constructor can initalize the object differently depending on the arguments passed while creating an obejct. 

> Key points: 

    Same Constuctor Name -> All overloaded constuctors must have the sanme name as the class. 

    Different Parameters -> Constuctors must have different number or types of parameters. 

    Flexibility -> Constructor overloading also gives flexibility during object initialization by allowing the same class to be instantiated in various ways. 

--- Parameterized Constuctors with Default Arguments --- 

A parameterized constuctor with default arguments in a constuctor, which allows a user to provide default values for one or more paramenters, which means you can either
pass values while creating the object or let the constructor use the dfault values for missing parameters. 

--- Advantages of Using Parameterized Constuctors ---

Parameterized constuctors offer various benefits, which make object initialization more flexible, clean, efficient. Below we have dicussed some of the key advantages:

    > It allows flexible object initilization with simplified code, improving readability and maintainability. 

    > It prevents Objects Creation with Invalid Data, where it allows valid data only. 

    > It reduces the need for setter functions and supports constructor overloading. 

    > It also provides better memeory management (with Dynamic Memory Allocation), enforces Default Values for Missing Arguments,
      and overall improves code performance. 

*/

class MyClass{
    public:
        int a, b;

    MyClass(int x, int y){
        a = x;
        b = y;
        cout << "Parameterized constructor called" << endl;
    }

    void display(){
        cout << "a: " << a << ", b: " << b << endl;
    }

};


int main(){

    MyClass obj1(10, 20);
    obj1.display();

    return 0;
}