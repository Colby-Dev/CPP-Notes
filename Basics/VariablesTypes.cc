#include <iostream>

using namespace std;

extern int testInt;

int funcTest();

int main(){
    //A variable provides us with named storage that our programs can manipulate.
    //Each variable has a specific type which determines the size and layout of the variables memory.

    //---- Variables examples ----
    int age;
    int _age;
    int student_age;
    int studentAge;

    //----Variable Definition in C++ ----
    // A variable definition tells the complier where an how much storage to create for the variable
    // The definition specifies a data type, and contains a list of one or more variables of that type

    int i, j, k; //Instructs complier to declare and define the variables. 
    char c, ch;
    float f, salary;
    double d;

    //Variables with static storage that are not initialized are implicitly initialized with NULL (bytes value = 0)
    //Non static variables are initialized as undefined

    //Extern allows us to define the variable first, then initialize a value to it aftwards
    //testInt is actually defined in the first part of the program outside of main()
    testInt = 10;

    //This can also apply to functions
    int i = funcTest();
}

int funcTest(){
    return 0;
}
