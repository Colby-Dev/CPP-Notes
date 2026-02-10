#include <iostream>

using namespace std;

int main(){
    //Char data type in C++ can be a wide range of alphanumeric characters.
    //Typically holds single characters, and escape sequences

    char ch;
    cout<<ch;

    //Char can also hold ASCII values
    char ascii = 67;
    cout<<ascii;

    //You can also cast int on symbols which returns the ASCII value
    char ascii2 = '$';
    cout<<int(ascii2);

    //Chars can also hold escape sequences making it useful in text formatting
    char tab = '\t';
    cout<<"tab"<<tab<<"inbetween ";

    return 0;
}