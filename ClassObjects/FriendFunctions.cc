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

A friend Function is a non member function that is declared inside a class using "friend" keyword, it has special
access to the class's private and protected members. Since it's not a member it is not special access to the class's
private and protected members. Since it's not a member it is not bound to a specific object, can't overloaded based on objects,
not use this pointer, and cannot be inherited by derived classes. They are defined outside the class but declared inside it. 

--- Member Function --- 

Whereas the member function is defined within the class and operates using this pointer. It can access all members of the class
(private, protected, and public), and as it is tied to class objects, it can be overloaded and inherited by derived classes. 

----- Friend Classes -----

In C++, a friend class is a class that gives access to private and protected members of another class. When a class declares another class as a friend,
the second class (the friend) can directly access the private and protected members of the first class. 

This concept is similar to friend functions, but here the friend is an entire class rather than a specific function. 


*/

class ClassB;

class ClassA{
    private:
        int dataA;
    
    public:
        ClassA() : dataA(42) {}
        friend class ClassB;
};

class ClassB{
    public:
        void showDataFromA(const ClassA& objA){
            cout << "Data from ClassA: " << obj.dataA << endl;
        }
};

int main(){
    ClassA objA;
    ClassB objB;

    objB.showDataFromA(objA);

    return 0;
}