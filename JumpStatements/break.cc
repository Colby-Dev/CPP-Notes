#include <iostream>

using namespace std;

/* 
----- Break Statement -----
When the break statement is encountered inside a loop, the loop is immediately
terminated and program control resumes at the next statement following the loop.

It can be used to terminate a case in the switch statement.

*/

int main(){

    int a = 0;

    while (a < 10)
    {
       std::cout<<a;
       a++;
    }
    
    return 0;
    
}