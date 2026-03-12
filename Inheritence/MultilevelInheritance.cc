#include <iostream> 

using namespace std; 

/*

----- Multilevel Inheritance -----

Multilevel inheritance is a type of inheritance, where a class derived from another derived class, creating a cahin of
inheritance that allows it to pass down its properties and behaviors through multiple levels of classes or inherit from
its predecessor.

--- Implementing Multilevel Inheritance ---

> baseClass, is the top-level class from where other classes derive
> derivedClass1, is the class that inerits from baseClass
> derivedClass2, inherits from derivedClass1, creating a multilevel structure

    class baseClass{
        // Here's a base class members
    };

    class derivedClass1: public baseClass {
        // Members of derivedClass1
    };

    class derivedClass2: public derivedClass1{
        // Members of derivedClass2
    };

--- Block Diagram of Multilevel Inheritance ---

Class Shape --> Class Polygon --> Class Triangle
(Base Class) --> (First derived Class) --> (Second derived Class)

As per above diagram, "Shape" is the base class, and it is deriving over to "Polygon" class, and "Polygon" class is further deriving
over "Triangle" class in order to implement multilevel inheritance

*/

class Shape {
    public:
        void display(){
            cout << "This is a shape." << endl; 
        }
};

class Polygon : public Shape {
    public: 
        void sides(){
            cout << "This is a Polygon." <<endl;
        }
};

class Triangle : public Polygon {
    public:
        void type(){
            cout << "This is a Triangle." << endl;
        }
};


int main(){

    Triangle RightTriangle;
    RightTriangle.display();
    RightTriangle.sides();
    RightTriangle.type();
}