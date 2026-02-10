#include <iostream>

using namespace std;

/* 
----- Enum Classes -----
An enum is a user defined data type formed by named integral constant.
However, enum types from tradition have the disadvantage of potential name
clashes and absence of type safety. 

To solve this this problem, the concept of enum class,
which is also referred to as scoped enumerations. 

When you declare the enum class without specifying any underlying type,
then by default is set to int. This means that each enumerator's value will be 
stored as int (4 bytes)

*/

enum class Day {

    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday

};

int main(){

    Day today = Day::Friday;
    if (today == Day :: Friday){
        cout << "Today is Friday!" << endl;
    }

    return 0;
}