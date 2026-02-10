#include <iostream> 

using namespace std;

/*
----- Continue Statement -----

The continue statement works somewhat like the break statement. 
Instead of forcing termination, however, continue forces the next iteration of the loop to take place,
skipping any code in between.

For the for loop, continue causes the conditional test and increment portions of the loop to  
execute. For the while and do ... while loops, program control passes to the  conditional test.

*/

int main(){

        int a = 10;

        do {
           if(a == 15){
                a = a + 1;
                continue;
                }
                cout << "value of a: " << a << endl;
                a = a + 1;
        }
        while(a < 20);
        return 0;
}
                                                                                                                                                                