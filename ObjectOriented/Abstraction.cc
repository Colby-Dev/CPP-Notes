/*
----- Data Abstraction -----

Data abstraction refers to providing only essential information to the outside world and hiding their background details, to represent the needed
information in program without presenting the details. 

Data abstraction is a programming (and design) technique that relies on the separation of interface and implementation. 

One example is a TV which you can change the channel or turn on and off, adjust the volume, and add external things like speakers, but you don't
know how the internal details work such as the cables or signals to display things on screen. Thus we can say this seperates the internal information
but you can still use the interfaces to interact with it without all the knowledge of how it works. 

Classes in C++ provide great level of data abstraction. They provide sufficient public methods to the outside world to play with the functionality of the object and to manipulate
object data , i.e., state without actually knowing how class has been implemented internally. 

--- Access Labels Enforce Abstraction --- 

> Members defined with a public label are accessible to all parts of the program. The data-abstraction view of a type is defined by its public members. 

> Members defined with a private lavel are not accessible to code that uses the class. The private secitons hide the implementation from code that uses the type. 

There are no restrictions on how often an access label may appear. Each access level specifies the access level of the succeeding member definitions. The specified access level remains
in effect until the next access label is encountered or the closing right brace of the class body is seen. 

--- Benefits of Data Abstraction ---

> Class internals are protected from inadvertent user-level errors, which might corrupt the state of the object. 

> The class implementation may evolve over time in response to changing requirements or bug reports without requiring change in user-level code.

By defining data members only in the private section of the class, the class author is free to make changes in the data. If the implementation changes,
only the class code needs to be examined to see what affect the change may have. If data is public, then any function that directly access the data members of the old
representation might be broken. 

--- Designing Strategy ---

Abstraction separates code into interface and implementation. So while designing your component, you must keep interface independent of the implementation so that if you change underlying
implementation then interface would remain intact. 

In this case whatever programs are using interfaces, they would not be impacted and would just need a recompilation with the latest implementation. 

*/

#include <iostream> 
using namespace std;

class Adder{
    public: 
        Adder(int i = 0){
            total = i;
        }

        void addNum(int number){
            total += number;
        }

        int getTotal(){
            return total;
        };
    
    private: 
        int total;
};

int main(){
    Adder a;

    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout << "Total " << a.getTotal() << endl;
    return 0;

}