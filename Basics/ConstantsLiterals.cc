#include <iostream>

using namespace std;

int main(){
    //int lterals 
    212;
    215u;
    0xFeeL;

    //floating point literals
    3.14159;
    314159E-5L;

    //boolean literalls
    true;
    false;

    //Character literals, stored in char type
    'x';
    '\t'; //escape sequence

    //Example #1
    // cout << "Hello \tWorld \a";
    // return 0;

    //String Literals
    
    "hello, dear";

    "hello, \
    dear";

    "hello, ""d" "ear";

    //Defining constants, two ways to do it: 
    #define Length 10
    const int Width = 10;
    int area; 

    area = Length * Width;
    cout << area;

}