#include <iostream>

using namespace std; 

/* 
----- Decision Making -----
Decision making structures require that the programmer specify one or more conditions
to be evaluated or test by the program, along with a statement or statements to be executed
if the condition is determined to be true, and optionally, other statments to be executed
if the condition is determined to be false. 

if, if ... else, switch, nested ifs, nested swtich, ? (if else turney)


*/

int main(){

    int a = 10;
    int b;

    std::cout << "Enter a number: " << endl;
    std::cin >> b;

    if (a != b){
        std::cout << "Correct";
    }
    else {
        std::cout << "Error";
    }

    return 0;

}