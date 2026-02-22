#include <iostream>

using namespace std;

/*
------ Classes and Objects ------

The main purpose of C++ programming is to add object orientation to the C programming language and classes are the central feature of
C++ that supports object oriented programming and are often called user-defined types.

A class is used to specify the form of an object and it combines data representation and methods for manipulating that data into one neat
package. The data and functions within a class are called members of the class.

--- C++ Class Definitions --- 

When you define a class, you define a blueprint for a data type. This doesn't actually define any data, but it does define what the class
name means, that is, what an object of the class will consist of and what operations can be preformed on such an object. 

A class definition starts with the keyword class followed by the class name; and the class body, enclosed by a pair of curly braces.
A class definition must be followed by a semicolon or a list declarations. For example, we defined the Box data type: 

    class Box{
    
        public:
            double length;
            double breadth;
            double height;
    
    };

The keyword public determines the access attributes of the member of the class that follows it. A public member can be accessed from
outside the class anywhere within the scope of the class object. You can also specify the members of a class as private or protected 
which we will discuss in a sub-section. 

--- Define C++ Objects ---

A class provides the blueprints for objects, so basically on object is created from a class. We declare objects of a class with exactly
the same sort of declaration that we declare variables of basic types: 

    Box Box1;
    Box Box2;

Both of the objects Box1 and Box2 will have their own copy of data members. 


--- Accessing the Data Members ---

The public data members of objects of a class can be accessed using the direct member access operator (.) example :

    Box1.height = 5.0

*/

class Box {
    public:
        double length;
        double breadth;
        double height;
};

int main() {
    Box Box1;
    Box Box2;
    double volume = 0.0;

    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    Box2.height = 10;
    Box2.length = 12;
    Box2.breadth = 13;

    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Volume of Box1: " << volume << endl;

    return 0; 

}