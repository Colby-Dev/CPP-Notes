#include <iostream>

using namespace std;

/* 
----- Enumeration (Enum) -----
Enums are user-defined data types, where it consists of set named integral constants.

To create an enumeration (enum),use the enum keyword followed by the name of the enumeration
and a list of the named vales further enclosed within curly braces.

-> Accessing Enumeration
------------------------------
You can access enumeration (enum) by declaring it with a variable name
inside the int main() body and calling it as per requirement. 

-> Types of C++ Enumeration
------------------------------
> Unscoped, traditional form of enumeration. 
Defined using enum keyword with enumerator names declared within the enclosing scope.
Since the enumerator names are added to the surrounding scope, which can lead to name collisons. 

> Scoped, defined using the enum class. They provide better type safety and are more organized, 
where their enumerator names are scoped within the enum. This means, keeping their labels within a specific group, 
so you need to mention the group name when you use them. 


Features                     | Unscoped Enums        | Scoped Enums
_____________________________|_______________________|___________________________________
Scope of Enumerators         | Global scope          | Scoped within the enum type
_____________________________|_______________________|___________________________________
Name of Conflicts            | Possible              | Avoided
_____________________________|_______________________|___________________________________
Implicit Conflicts           | Yes                   | No
_____________________________|_______________________|___________________________________
Type Safety                  | Less                  | More
_____________________________|_______________________|___________________________________
Underlying Type              | Default is int        | Custom type can be specified
_____________________________|_______________________|___________________________________

-> Enum as Function Parameters
------------------------------------
You can pass enums as parameters to functions. 
To pass enum as parameter in function, you need to specify the enum name
along its instance.


*/

enum class Color {
    Red,
    Green,
    Blue
};

int main(){

    Color myColor = Color::Blue;
    if (myColor == Color::Blue){
        cout << "The color is Blue!"<<endl;
    }
    else{
        cout <<" The color does not match!"<<endl;
    }

    return 0;

}