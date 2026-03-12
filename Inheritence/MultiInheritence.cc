#include <iostream> 

using namespace std;

/*

----- Multiple Inheritance -----

Multiple inheritance in C++ is a feature that allows a class to inherit from more than one base class,
which means a derived class can have multiple parent classes and inherit attributes and behaviors from
all the base classes. 

--- Implementing Multiple Inheritance ---

To implement multiple inheritance, you need to specify multiple base classes in the derived class and
declare it using a comma-separated list. 

    class Base1{
        // Base class 1 members
    };

    class Base2{
        // Base class 2 members
    };

    class Derived: public Base1, public Base2{
        // Derived class members
    };

--- Challenges in Multiple Inheritance ---

Multiple inheritance in C++ allows a class to inherit from more than one base class which provides flexibility
and reuseability. However, it also introduces several challenges: 

> Ambiguity - When two or more base classes have members with the same name cause ambiguity. 

> Diamond problem - It arises when a class inherits from two classes that both inherit from a common base class
                    which causes ambiguity and conflicts due to multiple copies of the base class, which is ultimately
                    known as the Diamond problem. 

--- Ambiguity in Multiple Inheritance ---

If two or more base classes have members (functions or variables) with the same name, the complier won't be able to decide
which one to use, which ultimately leads to ambiguity. This can be resolved using scoped resolution: 

    class Derived: public Base1, public Base2{
        public:
            void show(){
                Base1::show(); // Explicitly calls Base1's show function
                Base2::show(); // Explicitly calls Base2's show function
            }
    };

--- Diamond Problem in Multiple Inheritance ---

A diamond problem in C++ occurs when a class inherits from two classes that both inherit from a common base class, which
ultimately creates ambiguity in the inheritance heirarchy as the derived class now has two copies of the common base class,
leading to conflicts. The solution for this problem is to use virtual: 

    class Base {
        public:
            void show() {
                cout << "Base show" << endl;
            }
    };

    class Derived1: virtual public Base {};
    class Derived2: virtual public Base {};

    class Final: public Derived1, public Derived2 {};

    int main(){
        Final obj;
        obj.show();
        return 0;
    }

--- Benefits of Using Multiple Inheritance ---

> Code reusability, as it allows developers to use existing classes to create new classes with combined functionalities. 

> It models real-world entities more accurately, where a derived class may have characteristics of multiple base classes. 

> It enables a more flexible and modular design

*/

class Car{
    public: 
        void drive(){
            cout << "Driving on land" << endl;
        }
};

class Boat{
    public:
        void sail(){
            cout << "Sailing on water" << endl;
        }
};

class Transport: public Car, public Boat{
    public: 
        void use(){
            drive();
            sail();
        }
};

int main(){
    Transport vehicle;
    vehicle.use();
    return 0;
}