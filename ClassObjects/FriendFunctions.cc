#include <iostream>

using namespace std;

/*
----- Friend Function -----

A friend function of a class is defined outside that class scope but it has the right
access all private and protected members of the class. Even though the prototypes for
friend functions appear in the class definition, friends are not member functions.

A friend can be a function, function template, member function, or a class or class
template, in which case the entire class and all of its members are friends.

    class Box {
        double width;

        public: 
            double length;
            friend void printWidth(Box box);
            void setWidth( double wid );
    };

To declare all member functions of class ClassTwo as friends of class ClassOne, place a 
following declaration in the definition of class ClassOne - 

    friend class ClassTwo;

--- Accessing Private and Protected Members ---

The private and protected members of a class are not accessible outside of the class. 
Still, if you want to access them, you can use the friend function. The friend function
provides the ability to directly access the class's private and protected members.

----- Friend Function vs Member Function ----- 

In C++, both friend functions and member functions are used to access and manipulate
the data of a class, but still, they have significant differences in their scope and usage.

--- Friend Function --- 





*/

int main(){

}