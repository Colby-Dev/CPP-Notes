#include <iostream> 
using namespace std; 

/* 

----- Pure Virtual Functions and Abstract Classes -----

A pure virtual function is a virtual function in C++ for which we need not write any function definition
and only have to declare it, where it is declared by assigning 0 in declaration. To declare a virtual function, 
use the "virtual" keyword. 

Whereas, an abstract class is a class in C++ which have at leat one pure virtual function. 

    virtual return_type func_name(parameters) = 0;

    where: 
        - return_type, is the return type of the function
        - func_name, is the name of the function
        - parameters, is the list of parameters the function
        - =0 syntax indicates that the function is pure virtual, which has no definition in the base class. 

--- Key Features of Abstract Clases ---

> Abtract classes can have normal functions and variables too,
  along with a pure virtual function. 

> Abstract class cannot be instantiated, but pointer and references
  of Abstract class type can be created. 

> Abstract classes are mainly used for Upcasting so that their derived
  classes can use its interface. 

> If an Abstract Class has a derived class, it must implement all pure 
  virtual functions, or else they will become Abstract too. 

> We cant create an object of abstract class as we reserve a slot for
  pure virtual function in Vtable, but we dont put any address, so Vtable
  will remain incomplete. 

*/

class Shape {
    public: virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    public: void draw() override{
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
    public: void draw() override{
        cout << "Drawing Rectangle" << endl;
    }
};

class Triangle : public Shape {
    public: void draw() override{
        cout << "Drawing Triangle" << endl;
    }
};

int main() { 
    Shape * shapes[] = {
        new Circle(),
        new Rectangle(),
        new Triangle()
    };

    for (Shape * shape: shapes){
        shape -> draw();
    }

    for (Shape * shape: shapes){
        delete shape;
    }
    
    return 0;
}