#include <iostream>

using namespace std;
/* 

---- Modifier Types ----

C++ allows the char, int, and double data types to have modifiers
preceding them. A modifier is used to alter the meaning of the base
type so that it more precisely fits the needs of various situations.

Data type modifiers:
-------------------
* Signed
* Unsigned
* Long
* Short

Type Qualifiers:
----------------
* Const - Objects of type const cannot be changed by the program
* Volatile - The modifier volatile tells the compiler that a var's value may be changed.
* Restrict - A pointer qualified by restrict is initially the only means by which the object it points to can be accessed

*/ 

int main(){

    short int i; //signed short int

    short unsigned j; //unsigned short int

    j = 50000;
    i = j;
    
    cout << i << " " << j;

    return 0;

}