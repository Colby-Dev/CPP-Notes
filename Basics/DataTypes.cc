#include <iostream> 

using namespace std;

int main(){

/*  C++ offers the programmer a rich assortment of built-in
    as well as user defined data types. 

    Several of the basic types can be modified using one or more
    modifiers:

    - signed
    - unsigned
    - short
    - long
*/
//Example:

cout << "Size of char: " << sizeof(char)<< endl;
cout << "Size of Int: " << sizeof(int) << endl;

//Unsigned

std::cout << "Unsigned Int Max "<< std::numeric_limits<unsigned int>::max() << endl; 

//example function calls
func2();
ref_func();

//Class Construct Ex
Vehicle car;
car.engine = "I have an engine, I am a car. ";
car.print();

//Struct Ex
struct_example object;
object.grade = 10;
object.name = "Colby";

cout<<object.name<<endl;
cout<<"Show the int: "<<object.grade;

// Union Ex
union U_example E;
E.ex1 = 123;
cout<<"Value of ex1 initially is: "<<E.ex1<<endl;

E.ex2 = 456;
cout<<"When we change ex2, the value of ex1 is: "<<E.ex1<<endl;

//Enum Ex
enum enum_name Lang;
Lang=python;
cout<<"I love the "<<Lang+1<<"!!!";

return 0;
}

//Derived Data Types
/*
    Data types which are obtained from pre-defined types in C++
    are known as Derived Data Types. These can be classified as:

    - Function
    - Array
    - Pointer
    - Reference

*/
//Function:

string func(int n ){
    if(n%2) return "Number is Odd";
    else return "Number is Even";
}

//Array:

int array[3] = {1,2,3};

//Pointer:

int func2(){

int a = 20;
int *p= &a;

cout << "Address of variable a: "<< p << endl;
cout << "Value of variable a: "<< *p << endl;

return 0; 

}

//Reference:
int ref_func(){
    int c=11;
    int& refer=c;

    cout<<"Initially value of integer is: "<<c<<endl;

    refer=121;
    cout<<"After changing value using refer variable: "<<c<<endl;

    return 0;
}

// ---- User-Defined Data Types ----
// Data types which are defined in OOP as a custom data type which is used to construct object.

//Class constructor (see line 31 for call) 
class Vehicle{
    public:
        string engine;
    
    void print(){
        cout<<engine<<endl;
    }
};

// Structure (struct) introduces multiple primitive data types
// (see line )
struct struct_example{
    int grade;
    string name;
};

// Union, is similar to a structure. Memory location of all variables is same and all variabls share the same reference
union U_example{
    int ex1, ex2;
};

// Enumeration (Enum) is a UDT that is used to give a name to integer constants in a program
enum enum_name{
    C, java, python
};

//typedef creates a new name for an existing type using simple syntax
typedef int feet;
feet distance;

//Enum Types, declares an optional type name and set of zero or more identifiers. 
enum color {red, blue = 7, green} c;
int numb8 = green;

