#include <iostream> 
using namespace std; 

/*

----- Final Specifier -----

The final specifier was introduced in C++11 with two main purposes: 

> The first purpose is to prevent inheritance. When a class is marked with final, 
  other classes can not inherit from it. 

> The second purpose it to avoid function overriding. When you mark a virtual function
  with final, then it can be overridden in the derived classes. 

--- Using the final Specifier with Class ---

You can mark a class as final to prevent inheritance. After marking a class as final, 
you can no longer use this class for inheritance. Other classes will not be able to inheirit them.

    class MyClass final{
        // class members
    };

> Class with final vs Class without final
-----------------------------------------

The Base class will not allow any Derived class to inherit from it. (throws an error)
Without final derived classes can inherit and override functions. 

--- Using the final Specifier with Function --- 

You can mark a function with final to avoid overriding the function. After marking a function as final,
you can no longer override that function. The function can only be made final if the function is a
virtual function. 

class Base{
    public: 
    virtual void display() final {
        // implementation
    }
};

> Function w/ final vs Function w/o final
-----------------------------------------

The final keyword is used on the functions from base classes. Even if the derived class contains the final
function. If another derived class inherits from a different derived class then the final function rules still apply. 

Without final, functions can be overridded and inherit from base classes / derived classes. 

--- Conclusion ---

The final specifier in C++ helps in preventing the inheritance of classes and the overriding of the virtual function.
In this chapter, we explained in detail how the final specifier works with class and virtual function. 
*/

class Animal {
    public: 
    virtual void makeSound(){
        cout << "Animal sound" << endl;
    }

    virtual void breathe(){
        cout << "Animal breathing" << endl;
    }
};

class Mammal : public Animal {
    public: 
    void makeSound() override{ 
        cout << "Mammal sound" << endl;
    }

    void breathe() final override {
        cout << "Mammal breathing" << endl;
    }
};

class Dog : public Mammal{
    public:
    void makeSound() override {
        cout << "Bark" << endl;
    }

    // void breathe() {
    //     cout << "Dog breathing" << endl;
    // }

};

int main(){
    Dog dog;
    dog.makeSound();
    dog.breathe();
    return 0;
}