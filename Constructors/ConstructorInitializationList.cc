/* 

----- Constuctor Initializaiton List -----

When instantiating objects, constuctors often handle the initialization of member variables. For such members, an
initialization list for constructors provides an abbreviated and efficient way of their initialization before the
constructor's body is executed. Apart from performance, sometimes it also compulsory because of cosnt variables or
members of a base class.


--- What is a Constructor Initialization List? ---

A constructor initialization list is a procedure to initalize member variables directly, hance, there is no default
constructor that is copied and then assigned. 

    ClassName(type1 param1, type2 param2) : member1(param1), member2(param2){
            // Constructor body    
    }


--- Why Use Constructor Initialization Lists? ---

> To avoid default initialization followed by reassignment, to save time and resources.
> Its mandatory for certain types of const variables, reference members, and base class members.
> It keeps all initialization logic in one place, separate from the constructor body. 

*/

#include <iostream>
#include <string>

using namespace std;

class Student{
    public:
        Student(const std::string& name, int age) : name(name), age(age) {}

        void display() const {
            std::cout << "Name: " << name << ", Age: " << age << "\n";
        }

        private:
            std::string name;
            int age;
};

int main() {
    Student s("John", 20);
    s.display();
    return 0;
}