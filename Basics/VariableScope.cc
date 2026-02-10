#include <iostream>

using namespace std;

// --- Scope ---
    // The scope is a region of a program where variables can be declared such as
    // Local variables take preference, when global and local vars are named the same

    // -> Inside a function or a block which is called local vars
    // -> In the definition of function parameters which is called formal params
    // -> Outside of all function which is called global variables

    //Example: 

    int globalVar = 20; // Global Variable

int main(){
    
    int localVar = 10; // Local Variable

    cout << localVar;

    // ---- Local Variables ----
    // Variables that are declared inside a function or block are local variables.
    // They can be used only by statements are inside that function or block of code. 
    // Local variables are not known to functions outside their own. 
    
    int a, b; // Declaration

    a = 10; // Initialization
    b = 20;

    x = a + b; // Initialization of global var x

    cout<<::x; // returns the decalared global var
    cout<<x; //returns the initialized local var

    return 0;
}

// ---- Global Variables --- 
// Global variables are defined outside of all the functions, usually on top of the program.
// The global variables will hold their value throughout the life-time of the program
// It can be accessed by any function by using the :: operation. 

int x; // Declaration

// --- Initializing Local and Global Variables ---
// When a local variable is defined, it is not initialized. Global vars are initialized as:

// Data Type | Initializer
// --------- | ----------
// int       | 0
// char      | '\0'
// float     | 0
// double    | 0
// pointer   | NULL 