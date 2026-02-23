#include <iostream>

using namespace std;

/*

----- Class Access Modifiers -----

C++ access modifiers are used for data hiding implementation. Data hiding is one of the
important features of OOP, which allows functions of a program to access directly the
internal representation of a class type. The access restriction to the class members is
specified by the labeled public, private, and protected sections within the class body.

The keywords private, public, and protected are called access specifiers. 

A class can have multiple public, protected, and private sections within the class body. 
Each section remains in effect until either another section label or the closing right brace
of the class is seen. The default access for members and classes is private. 

--- Public Access Modifier --- 

The public access modifier defines public data members and member functions that are accessible
from anywhere outside the class but within a program. You can set and get the value of public 
variables without any member function.

    class Line {
        public:
            double length;
            void setLength(double len);
            double getLength(void);
    };

    void Line::getLength(void){
        return length
    };

    void Line::setLength(double len){
        length = len;
    };

    int main(){
        Line line;

        line.setLength(6.0);
        cout << "Length of line is: "<< getLength<< endl;

        line.length = 10.0;
        cout << "Length of line: " << line.length << endl;

        return 0;
    }

--- Private Access Modifier ---

The private access modifier defines private data member and member functions that cannot be
accessed, or even viewed from outside the class. Only the class and friend functions can access
private members. 

By default all the members of a class would be private, for example in the following class width
is a private member, which means until you label a member, it will be assumed a private member.

    class Box {
        private:
            
            double width;

        public:

            double length;
            void setWidth(double wid);
            double getWidth(void);
    };

    void Box::getWidth(void){
        return width;
    }

    void Box::setWidth(double wid){
        width = wid;
    }

    int main(){
        Box box;

        box.length = 10.0 <- This is fine because its public

        box.width = 10.0 <- This is NOT fine because its private

        box.setWidth(10.0)
        cout << "Width of box: "<< box.getWidth() << endl;

        return 0;
    }

--- Protected Access Modifier ---

The protected access modifier defines protected data members and member functions that 
are very similar to a private member, but it provides one additional benefit that they can be accessed
in child classes, which are call derived classes. 

You will learn derived classes and inheritance in next chapter. For now you can check following example
where I have derived one child class SmallBox from a parent class Box.

    class Box {
        protected:
            double width;
    };

    class SmallBox:Box {
        public:
            void setSmallWidth(double wid);
            double getSmallWidth(void);
    };

    void setSmallWidth(double wid){
        width = wid;
    }
    
    double getSmallWidth(void) {
        return width;
    }

    int main(){
        SmallBox box;

        box.setSmallWidth(5.0);
        cout << "The box width is: " << box.getSmallWidth() << endl;

        return 0;
    }


*/

int main(){


}