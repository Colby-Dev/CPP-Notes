#include <iostream>

using namespace std;

/*
----- Inline Functions -----

C++ inline functions are a powerful concept that is commonly used with classes. If a function is inline, the complier places a copy of that function at each point where
the function is called at compile time. 

Any change to an inline function could require all clients of the function to be recompiled because compiler would need to replace all the code once again otherwise it
will continue with old functionality.

--- Defining an Inline Function ---

To define an inline function, place the keyword inline before the function name and define the function before any calls are made to the function. The complier can ignore
the inline qualifier in case defined function is more than a line. 

A function definition in a calss definition is an inline function definition, even without the use of the inline specifier.

    inline int Max(int x, int y){
        return (x > y) ? x : y;
    }

    int main(){
        cout << "max (20,10): " Max(20,10) << endl;
        return 0;
    }

--- Inline Function with Classes ---

By default, all the functions that are defined inside a class are implicitly inline. If you want to explicitly define a function as inline, then you have to declare a function
inside the class and write its definition outside the class. The inline keyword is used with the function definition that is outside of the class declaration. 

--- Advantages of Inline Function --- 

> In the case of an inline function, the function call overhead does not occur.

> The inline function saves the overhead of the push and pop variables on the stack, when the function is called.

> An inline function saves the overhead of a return call from a function.

> When an inline function is created, the complier may preform context specific optimization on the body of the function.
  This kind of optimization is not performed for normal functions.

> Using small inline functions may be useful for embedded systems, because inline can yield less code than the function call preamble and return

--- Disadvantage of Inline Function ---

> When we use an inline function, the size of the code is increased because the compiler replaces each function call with the inline function code.

> Large sized code takes more memory and time to compiler the code.

> The compilation process slows down because the compiler evaluates and replaces the function code at the place function calls. 

> In some of the cases, the program's performance may slow down.

> Based on the function code complexity, the compiler may ignore the inline keyword. Thus, the application of the inline function is limited.

*/

class Number {
    private: 
        int num1;
        int num2;

    public:
        void setValues(int a, int b);
        void printValues();
        inline int addNumbers();
};

void Number::setValues(int a, int b){
    num1 = a;
    num2 = b;
}

void Number::printValues(){
    cout << "Number 1: " << num1 << ", Number 2: " << num2 << endl;
}

inline int Number::addNumbers(){
    return num1 + num2;
}

int main(){

    Number n;

    n.setValues(10, 20);

    n.printValues();

    int sum = n.addNumbers();
    cout << "10 + 20: " << sum << endl;

    return 0;

}