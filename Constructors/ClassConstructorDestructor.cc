#include <iostream> 

using namespace std; 

/*
----- Class Constructor and Destructor -----

A class constructor is a special member function of a class that is executed whenever we create new
objects of that class. 

A constructor will have exact same name as the class and it does not have any return type at all,
not even void. Constructors can be very useful for setting initial values for certain member variables.

    class Line {
        public:
            void setLength(double len);
            double getLength(void);
            Line();
        private:
            double length;
    };

    Line::Line(void){
        cout << "Object is being created" << endl;
    }
    void Line::setLength(double len){
        length = len;
    }
    
    int main(){
        Line line'

        line.setLength(6.0);
        cout << "Length of line: " << line.getLength() << endl;
        return 0;
    }

--- Parameterized Constructor ---

A defualt constuctor does not have any parameter, but if you need, a consturctor can have parameters.
This helps you to assign initial value to an object at the time of its creation.

    Line::Line(double len){
        cout << "Object is being created, length = " << len << endl; 
        length = len;
    }

--- The Class Destuctor --- 


*/

int main(){

}