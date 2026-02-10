#include <iostream>

using namespace std;

/*
----- Loops -----
There may be a situation, when you need to execute a block of code several number of times.
In general, statements are executed sequentially.

while, for, do ... while, nested

> Loop Control Statements 
Loop control statements change execution from its normal sequence. When execution leaves a 
scope, all automatic objects that were created in that scope are destroyed. 

break statement - Terminates the loop or switch statement 
                  and transfers execution to the statement immediately 
                  following the loop or switch.

continue statement - Causes the loop to skip the remainder of its body 
                     and immediately retest its condition prior to reiterating

goto statement - Transfers control to the labeled statement. 
                 Though it is not advised to use goto statement in your program. 

*/

int main(){

    int i = 0;
    do{
        cout<<"Success!";
        i++;
    }
    while ( i < 10);

    return 0;
}