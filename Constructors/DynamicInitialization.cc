/*

----- Dynamic Initialization Using Constructors in C++ -----

In C++, Dynamic initialization is the process of initializing variables or objects at runtime using constuctors. 

Where constuctors play an important role in object creation and can be used to initialize both static and dynamic
data members of a class. 

While creating an object, its constuctor is called and if the constuctor contains logic to initialize the data
members with values, is known as dynamic initalization. This is helpful because here the value is calculated,
retrieved, or determined during runtime, which is more flexible than static initialization.

    ClassName* objectName = new ClassName(constuctor_arguments);

*/


#include <iostream>
using namespace std;

class Rectangle { 
    public: 
        int width, height;

    Rectangle(int w, int h) : width(w), height(h) {}

    void display(){
        cout << "Width: " << width << ", Height: " << height << endl;
    }
};

int main() {

    Rectangle* rect = new Rectangle(10, 5);

    rect->display();

    delete rect; 

    return 0;
}