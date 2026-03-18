#include <iostream> 

using namespace std; 

/*

----- Polymorphism -----

The word polymorphism means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

C++ polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

--- Virtual Function ---

A virtual function is a function in a base class that is declared using the keyword virtual. Defining in a base class a virtual function, with another version in
a derived class, signals to the compiler that we don't want static linkage for this function.

What we do want is the selection of the function to be called at any given point in the program to be based on the kind of object for which it is called.
This sort of operation is referred to as dynamic linkage, or late binding. 

--- Pure Virtual Functions ---

It is possible that you want to include a virtual function in a base class so that it may be redefined in a derived class to suit the objects of that class,
but that there is no meaningful definition you could give for the function in the base class.

class Shape{
    protected:
        int width, height;
    
    public:
        Shape(int a = 0, int b = 0){
            width = a;
            height = b;
        }

        virtual int area() = 0;
};

*/

class Shape{
    protected:
    int width, height;

    public: 
        Shape(int a = 0, int b = 0){
            width = a;
            height = b;
        }
        virtual int area(){
            cout << "Parent class area: " << width * height << endl;
            return width * height;
        };
};

class Rectangle : public Shape{
    public: 
        Rectangle(int a = 0, int b = 0):Shape(a, b){}
    
        int area (){
            cout << "Rectangle area: " << width * height << endl;
            return (width * height);
        };
};

class Triangle : public Shape{
    public: 
        Triangle(int a = 0, int b = 0):Shape(a, b){}
    
        int area (){
            cout << "Triangle area: " << (width * height) / 2 << endl;
            return (width * height / 2);
        };
};


int main(){
    Shape *shape;
    Rectangle rec(10,7);
    Triangle tri(10,5);

    shape->area();

    shape = &rec;

    shape->area();

    shape = &tri;

    shape->area();

    return 0;
}