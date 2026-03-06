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

--- Advantages of Delegating Constructors ---

> Centralized Initialization,
    By consolidation initialization logic into a single constuctor, your code becomes easier to read and maintain

> Avoidance of Redundancy,
    Reusing constructor logic eliminates duplicated code.

> Ease of Modification, 
    Changes to initialization logic need to be made only in the primary constuctor.

*/

#include <iostream>
#include <string>

using namespace std; 

class Student{
    public:
        Student(const std::string& name, int age, double grade)
            : name(name), age(age), grade(grade) {}
        
        Student(const std::string& name, int age)
            : Student(name, age, 0.0) {}
        
        Student(const std::string& name)
            : Student(name, 18, 0.0) {}
        
        void display() const {
            std::cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade <<"\n";
        }

    private:
        std::string name;
        int age;
        double grade;
};

int main(){

    Student s1("John", 20, 90.5);
    Student s2("Dick", 22);
    Student s3("Harry");

    s1.display();
    s2.display();
    s3.display();

    return 0;
}