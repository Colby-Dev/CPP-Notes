#include <iostream>

using namespace std; 

/*
----- Static Member Function -----

Static Member Function in C++ is a special kind of function that belongs to the class itself rather than any specific object. A static keyword is used to define those functions.
They can be directly called by using just the class name, without creating instance of the class which is an object.

These are only accessible within the body of the class they are defined in, thus, implementing class-wide operations and certain security measures.

    class ClassName {
        public:
            static returnType functionName(parameters) {
                *Function body*
            }
    }

--- Key features of Static Member Functions ---

> There's no access to this pointer with static functions as they're not tied to an object instance. 
> These functions can be invoked using a class name
> They can only work with static members or other static functions of the class.

--- When should these static member functions be used? ---

> Maintaining counters, and handling global configurations.
> In implementating interface methods that don't require an object state. 
> Utility or helper functions like mathematical operations, data validations, etc.

*/

class MathOp{
    public:
        static int square(int num){
            return num * num;
        }
};

int main(){
    std::cout << "Square of 2: " << MathOp::square(2) << '\n';
    return 0;
}