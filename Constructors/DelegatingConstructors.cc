/*

----- Delegating Constuctors -----

Delegating constuctors is a feature that simplifies the way constuctors in a class handle the initialization task.
It makes it easier to maintain object initialization by reducing redundancy, and by allowing one constuctor to call
another in the same class.

--- Use of Delegating Constructors ---

In class design, multiple constructions are often used to handle different initialization scenarios. 
However, this can lead to repetitive code because each constuctor may duplicate similar initialization logic.

By using the delegating constuctors, code redundancy can be avoided. A single "main" constructor can handle most
initialization tasks, while other constructors delegate to it. 

This approach follows the DRY (Don't Repeat Yourself) principle and makes the code easier to maintain. 

*/

#include <iostream>
#include <string>

using namespace std; 

class Student{
    public:
        Student(const std::string& name, int age, double grade)
            : name(name), age(age), grade(grade) {}
}


int main(){

}