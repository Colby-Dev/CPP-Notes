#include <iostream> 
using namespace std; 

/* 

----- Override Specifier -----

Function overriding is an example of run-time polymorphism in C++, where
we redefine the function of a base class in the dervied class. The function
name, return type, and parameters should be same in base as well as derived
class functions. 

--- What is override Specifier? ---

The override specifier in C++ is used to override a function and it makes sure
that overriding is done correctly. It is useful in finding the mistakes while
overriding a function. 

If the override specifier is not used while overriding, then the function will run
normally without giving any error as it will consider it a different function. So,
we use an override specifier to overcome this problem, as the compiler will generate
an error if the function is not overridden correctly. 

--- Rules of Using override Specifier ---

You need to follow some rules while using the override specifier. These rules are
mentioned below:

    - The function in the base class needs to be a virtual function. 
    - The function name and signatures (number of parameters and their types, and const)
      should be same, otherwise it will give an error. 

--- Benefits of Using override Specifier ---

The benefit of using an override specifier is that it ensures correct implementation of
the function overriding. It can solve the following issues: 

    > Typo in function calls which will default to the base class, overriding would throw and error

    > Wrong parameter types will default back to the base class, overriding would throw and error

--- Conclusion ---

The override specifier in C++ is used to avoid function overriding mistakes. It is always used with
virtual functions and ensures that the function overriding is implemented correctly without any errors. 

*/

class Animal {
    public: 
        virtual void speak() {
            cout << "Animal speaking" << endl;
        }
};

class Dog : public Animal {
    public: 
        void speak() override { 
            cout << "Dog Barks!" << endl;
        }
};

int main(){
    Animal *animal = new Animal();
    Animal *dog = new Dog();

    animal->speak();
    dog->speak();

    delete animal;
    delete dog;
    cout << endl;
}