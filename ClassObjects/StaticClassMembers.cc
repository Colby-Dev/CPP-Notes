#include <iostream> 

using namespace std; 

/*

----- Static Members of a Class -----

We can define class members static using static keyword. When we declare a member of a class as static it means no matter how many objects
of the class are created, there is only one copy of the static member. 

A static member is shared by all objects of the class. All static data is initialized to zero when the first object is created, if no other
initilization is present. We can't put it in the class definition but it can be initialized outside the class as done in the following
example by redeclaring the static variable, using the scope resolution operator :: to identify which class it belongs to. 

    class Box {
    
        public:
            static int objectCount;

        Box(double 1 = 2.0, double b = 2.0, double h = 2.0){
            cout << "Constuctor called." << endl;
            length = l;
            breadth = b;
            height = h;

            objectCount+++;
        }
        double Volume(){
            return length * breadth * height;
        }
    };

     int Box::objectCount = 0;

     int main(void){
        Box Box1(3.3, 1.2, 1.5);
        Box Box2(8.5, 6.0, 2.0);

        cout << "Total object: " << Box::objectCount << endl;

        return 0;
     }

--- Static Function Members ---

By declaring a function member as static, you make it independent of any particular object of the class. A static member function can be
called even if no objects of the class exist and the static functions are accessed using only the class name and the scope resolution
operator ::

A static member function can only access static data memeber, other static member functions and any other function from outside the class.

Static member functions have a class scope and they do not have access to the this pointer of the class. You could use a static member function
to determine whether some objects of the class have been created or not. 

    class Box {
        public:
            static int objectCount;

        Box(double 1 = 2.0, double b = 2.0, double h = 2.0){
            cout << "Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;

            objectCount++;
        }
        double Volume(){
            return length * breadth * height;
        }
        static int getCount(){
            return objectCount;
        }
    private:
        double length;
        double breadth;
        double height;
    };

    int Box::objectCount = 0;
    
    int main(void){
        cout << "Intial Stage Count: " << Box::getCount() << endl;

        Box Box1(3.3, 1.2, 1.5);
        Box Box2(8.5, 6.0, 2.0);

        cout << "Final Stage Count: " << Box::getCount() << endl;

        return 0;
    }

*/