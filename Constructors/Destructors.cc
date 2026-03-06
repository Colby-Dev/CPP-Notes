/* 

----- Destructors in C++ -----

A destructor is a special member function of a class that is executed automatically whenever an object of its
class goes out of scope of whenever the delete expression is applied to a pointer to the object of that class. 

    class_name {
        public:
            ~class_name();
    }
    
    class_name :: ~class_name(){
    
    }

--- Defining a Destructor Inside a Class ---

In this example, we have used above syntax for defining a destuctor manually inside a class. Here, destructor is
not needed, we have used destructor just to illustate how a destructor is defined inside a class: 

    class Example {
        public:
            Example(void)
            {
                cout << "Constructor is called" << endl;
            }

            ~Example(void)
            {
                cout << "Destructor is called" << endl;
            }
    };

--- Defining a Destructor Outside a Class ---

The example below demonstrates how to define a destructor (Example) outside the class using scope resolution operator.
But first, it needs to be declared inside the class. 

    class Example {
        public:

            Example(void)
            {
                cout << "Constructor is called" << endl;
            }
            
            ~Example();
    };

    Example :: ~Example(void)
    {
        cout << "Destructor is called" << endl;
    }

--- Why Do We Need Custom Desturctors? ---

C++ provides a default destructor for every class as the classes are created. The default destructor cleans up the statically
allocated memory. But, if we have used a pointer for dynamic memory allocation using new, then we need to define a custom destructor
with delete operator to clean up the memory. 

    class Example {
        private:
            int *ptr;
        
        public:
            Example()
            {
                ptr = new int;
                *ptr = 42;
                cout << "Constuctor of Ex is called with ptr Value = " << *ptr << endl;
            }
            
            ~Example()
            {
                delete ptr;
                cout << "Destructor of Ex is called" << endl;
            }
    };

--- Properties of Destructors in C++ ---

Destructors in C++ have the following properties:

> Destuctors are automatically called when an object goes out of scope.

> Destuctor has the same name as the class and is neoted using the ~ sign. 

> It is automatically created when a class is created. 

> Destructors do not have any return type and do not accept any parameters / arguments.

> You can not define more than one destructor.

> Destructors cannot be inherited. 

> Destructors cannot be overloaded. 

--- C++ Destructor for Dynamic Objects ---

For objects that are created using dynamic memory allocation, you need to manually call the destructor using delete. In the example,
we have manually deleted the object using the delete operator:

    class MyClass
    {
        public:
            MyClass()
            {
                cout << "Constructor called" << endl;
            }
            
            ~MyClass()
            {
                cout << "Destructor called" << endl;
            }
    };

    int main(){
        cout << "Creating an object using dynamic memory allocation" << endl;

        MyClass *obj = new MyClass();

        cout << "Object created" << endl;

        delete obj;
        cout << "Object destroyed manually using delete" << endl;
        return 0;
    }

--- Destructor Call Order for Multiple Objects ---

Destructors are called in reverse order of construction for multiple objects. In example below, we can see that destructors are
called in the reverse order: 

    

*/