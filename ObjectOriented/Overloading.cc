#include <iostream> 

using namespace std; 

/*

----- Overloading (Operator and Function) -----

C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respectively.

An overloaded declaration is a declaration that is declared with the same name as a previously declared delcaration in the same scope, except that both delcarations have different
arguments and obviously different definition (implementation).

When you call overloaded function or operator, the complier determines the most appropriate definition to use, by comparing the argument types you have used to call the function or
operator with the parameter types specified in the definitions. The process of selecting the most appropriate overloaded function or operator is called overload resolution.

--- Function Overloading in C++ ---

You can have multiple definitions for the same function name in the same scope. The definition of the function must differ from each other by types and/or the number of arguments in
the argument list. You cannot overload function declarations that differ only by return type. 

    class printData{
        public:
            void print(int i){
                cout << "printing int: " << i << endl;
            }
            
            void print(double f){
                cout << "printing double: " << f << endl;
            }
    };

    int main(){
        printData pd;

        pd.print(5) // prints the int 

        pd.print(100.21) // prints the double
    }

--- Operators Overloading ---

You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operaotrs with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for operator being defined. Like any other function, an overloaded operator has a
return type and a parameter list:

    Box operator+(const Box&);

declares the addition operator that can be used to add two Box objects and returns final Box object. Most overloaded operators may be defined as ordinary non-member functions or as
class member functions. In case we define above function as non-member function of a class then we would have to pass two arguments for each operand as follows: 

    Box operator+(const Box&, const Box&);

*/

class Box { 
    public:
        double getVolume(void){
            return length * breadth * height;
        }
        
        void setLength(double len){
            length = len;
        }

        void setBreadth(double bred){
            breadth = bred;
        }

        void setHeight(double hei){
            height = hei;
        }

    // Overload + operator to add two Box objects
    Box operator+(const Box& b){
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;

        return box;
    }

    private:
        double length;
        double breadth;
        double height;
};


int main(){
    Box Box1;
    Box Box2;
    Box Box3;
    double volume = 0.0;

    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    volume = Box1.getVolume();
    cout << "Volume of Box1: " << volume << endl;

    volume = Box2.getVolume();
    cout << "Volume of Box2: " << volume << endl;

    Box3 = Box1 + Box2;

    volume = Box3.getVolume();
    cout << "Volume of Box3: " << volume << endl;

    return 0;
}