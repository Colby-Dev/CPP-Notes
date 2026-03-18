/*

----- Interfaces in C++ (Abstract Classes) -----

An interface describes the behavior of capabilities of a C++ class without committing to a particular
implementation of that class. 

The C++ interfaces are implemented using abstract classes and these abstract classes should not be
confused with data abstraction which is a concept of keeping implementation details separate from 
associated data. 

A class is made abstract by declaring at least one of its functions as pure virtual function. A pure
virutal function is specified by placing "=0" in its declaration: 

    class Box{
        public:
            virtual double getVolume() = 0;

        private: 
            double length;
            double breadth; 
            double height;
        
    };
    
The purpose of an abstract class (ABC) is to provide an appropriate base class from which other classes
can inherit. Abstract classes cannot be used to instantiate objects and serves only as an interface. 
Attempting to instantiate an object of an abstract class causes a compilation error. 

Thus, is a subclass of an ABC needs to be instantiated, it has to implement each of the virtual functions,
which means that is supports the interface declared by the ABC. Failure to override a pure virtual function
in a derived class, then attempting to instantiate objects of that class, is a complie error. 

Class that can be used to instantiate objects are called concrete classes.

--- Designing Strategy ---

An object oriented system might use an abstract base class to provide a common and standardized interface
appropriate for all external applications. Then, through inheritance from that abstract class, derived classes
are formed that operate similarly. 

The capabilities offered by the external applications are provided as pure virtual functions in the abstract
base class. The implementations of these pure virtual functions are provided in the dervied classes that correspond
to the specific types of the application. 

This architecture also allows new applications to be added to a system easily, even after the system has been defined. 

*/
#include <iostream> 
using namespace std;

class Shape{
    public:
        virtual int getArea() = 0;
        void setWidth(int w){
            width = w;
        }

        void setHeight(int h){
            height = h;
        }
    
        protected: 
            int width;
            int height;
};

class Rectangle: public Shape {
    public: 
        int getArea(){
            return (width * height);
        }
};

class Triangle: public Shape {
    public: 
        int getArea(){
            return (width * height) / 2;
        }
};

int main(void){
    Rectangle Rect;
    Triangle Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);

    cout << "Total Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(5);

    cout << "Total Triangle area: " << Tri.getArea() << endl;

    return 0;

};