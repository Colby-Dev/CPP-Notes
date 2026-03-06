#include <iostream> 

using namespace std; 

/*

----- Constructor with Default Arguments -----

A constuctor is a special member function in a class, which is automatically called when an object is created. 
These are used to initialize the object with values or default settings. 

Whereas default argument in C++ allow to specify default values for function or constuctor parameters.

--- Constructor with Default Arguments ---

A constructor with default arguments is a constuctor that allows for the creation of an object using optional parameters. Where the default values
for the parameters are provided, so when the user doesn't pass any values, the default value is used. 

    class ClassName {
        public:
            ClassName(param_type param_name = default_value,
                      param_type2 param_name2 = default_value2)

    };

--- Constructor with Multiple Default Arguments ---

A constructor with multiple default arguments gives the user access to specify default values for more than one parameter. This provides more flexibility
and access to pass any combination of arguments. 

--- Key Features of Constuctors with Default Arguments ---

While it is similar to regular functions, it provides more flexibility and convenience while creating objects. 

> Default values for parameters and flexibility in object creation

        Here the constructor can have default values for one or more parameters, which can be used when no argument is provided by the caller and allows multiple ways
        to create an object. 

> Avoiding multiple constuctor overloads

        You might need to load the constructor for every combination of arguments, which will make the code bulkier, but with default arguments,
        the constructor can be written once and it will handle different cases automatically.

> Order of Default Arguments

        In the case of multiple default parameters, you annot skip default arguments in the middle once you start providing defaults from the right.
        EX: 
            Box(int l = 1, int w); // Invalid 'w' has no default, but 'l' does.

> Default Arguments Can Be Used with Const Members

        If your class has const members, then default arguments can be provided in the constuctor to make initialization easier.
        EX: 
            class Box {
                public:
                    const int length, width;

                    Box(int l = 5, int w = 10) : length(l), width(w){}
            };
*/