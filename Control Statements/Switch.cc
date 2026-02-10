#include <iostream> 
using namespace std;

/* 
----- Switch -----
A switch statment allows a variable to be tested for equality
against a list of values. Each value is called a case, and the variable being switch on is checked for each case

The expression used in a switch statment must be an integral or enum type.
You can have any number of case statements within a switch. 

*/

int main(){

    char grade;

    cout<<"Enter your grade: "<<endl;
    std::cin>>grade;

    switch (grade)
    {
    case 'A':
        cout<<"Great!";
        break;
    case 'B':
        cout<<"Good";
    case 'C':
        cout<<"Average";
    case 'D':
        cout<<"Poor";
    case 'F':
        cout<<"Fail";
    default:
        break;
    }

    return 0;

}