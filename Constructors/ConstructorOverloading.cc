#include <iostream> 

using namespace std; 

/* 
----- Constuctor Overloading -----

In C++, constructor overloading is a concept in OOP, where the user can defined multiple constuctors with the same name in a class with each having a different parameter list.

    class ClassName {
        public: 

            // Constructor with no parameters (default constuctor)
            ClassName() {
                // Initialization code 
            }
        
            // Constructor with one parameter
            ClassName(type param1){
                // Initialization code using param1
            }

            // Constuctor with two parameters
            ClassName(type param1, type param2) {
                // Initialization code using param1 and param2
            }
            
            // Constructor with more params 
            ClassName(type param1, type param2, type param3){
                // Initialzation code using param1, param2, and param3
            }
    };
    
----- Example of Constructor Overlaoding -----

In this example, we will see how Constructor overloading allows the "Rectangle class" to have multiple constructors, each with a different parameter list. When we create
an object of the rectangle class, the complier automatically chooses the constuctor that perfectly fits based on the arguments passed, showing how constuctor overloading
provides flexibility. 

    class Rectangle { 
        public: 
            int length, width;

        Rectangle() {
            length = 1;
            width = 1; 
        }
        
        Rectangle(int side){
            length = side; 
            width = side;
        }

        Rectangle(int l, int w){
            length = l;
            width = w;
        }
        
        void displayArea(){
            cout << "Area: " << length * width << endl;
        }
    };


int main(){

    Rectnagle rect1;
    Rectangle rect2(5);
    Rectangle rect3(5, 3);

    rect1.displayArea();
    rect2.displayArea();
    rect3.displayArea();

    return 0;
}


--- Benefits of Constructor Overloading ---

Constructor Overloading providers various benefits, making it an essential feature for creating flexible and efficient classes. 

1) Flexibility in Object Initialization, 
        It gives you multiple ways of initializing an object or Multiple Initialization Options. 

2) Cleaner and Readable Code with enhance Code Maintainability,
        By providing different ways of initializing an object, it reduces the need for multiple setter methods or complex initialization logic,
        avoids redundancy, and provides simpler object creation, which ultimately gives cleaner and more readable code and easier to modify. 

3) Encapsulation of Initialization Logic,
        It also encapsulates the initialization logic within the constructor, which means the initialization logic is managed inside the constuctor
        rather than being spread aceoss various methods or outside the class. 

4) Simplifies Object Cloning (Copy Constructors),
        Constructor overloading allows to defined copy constructor to handle both shallow and deep copying objects, this makes sure that the object
        is copied.

*/

    class Rectangle { 
        public: 
            int length, width;

        Rectangle() {
            length = 1;
            width = 1; 
        }
        
        Rectangle(int side){
            length = side; 
            width = side;
        }

        Rectangle(int l, int w){
            length = l;
            width = w;
        }
        
        void displayArea(){
            cout << "Area: " << length * width << endl;
        }
    };


    int main(){

        Rectnagle rect1;
        Rectangle rect2(5);
        Rectangle rect3(5, 3);

        rect1.displayArea();
        rect2.displayArea();
        rect3.displayArea();

        return 0;
    }