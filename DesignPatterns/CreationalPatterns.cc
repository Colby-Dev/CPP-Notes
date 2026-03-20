/*

----- Creational Design Patterns -----

The Creational Design Patterns is a category of design patterns which are all about how we can create objects.
Instead of letting the code decide directly which class to make and how to make it, creational design patterns
provides different ways to create object. Using these patterns, we can make our system independent of how its
objects are composed or created and also how they are represented. 

If you make instances of classes directly everytime, you will make your code dependent on those classes(tighly coupled).
This will make it difficult to change or extend your system in the future. Creational design patterns help to solve this
problem by providing a way to create objects while hiding the creation logic from the client. 

The work of creational design patterns is similar to delivery service - they provide a way to create objects without
exposing the creation logic to the client, and refer to the newly created object using a common interface. 

--- Types of Creational Design Patterns ---

There are 5 main types of creational deisgn patterns: 

    - Singleton Pattern
    - Factory Method Pattern
    - Builder Pattern
    - Prototype Pattern

--- When to use Creational Design Patterns? ---

> If you require your code to produce objects but you don't wish it fixed on a specific class.

> Support multiple groups for related objects and easily toggle between such groups in your program. 

> When you won't know until at program run time what type of object is needed.

> If building an object requires many complicated steps that shouldn't be scattered everywhere. 

> To ensure there is just a single copy of something in an entire program. 

> If object creation requires a large number of choices which would render the constructor cumbersome. 

> Waste less time or memory by duplicating an object in use instead of creating a brand-new object. 

--- Conclusion ---

In conclusion, creational design patterns are powerful tools that can help you create flexible and 
maintainable code. By using these patterns, you can decouple your code from the specific classes that are
instantiated, making it easier to change and extend your system in the future. 

*/

#include <iostream> 
#include <string>

using namespace std; 

class Pizza{
    public: 
        virtual string getType() = 0;
};

class Margherita : public Pizza {
    public:
        string getType(){
            return "Margherita";
        }
};

class Pepperoni : public Pizza {
    public: 
        string getType(){
            return "Pepperoni";
        }
};

class PizzaFactory {
    public:
        static Pizza* createPizza(string type){
            if (type == "Margherita"){
                return new Margherita();
            } else if (type == "Pepperoni"){
                return new Pepperoni();
            } else {
                return nullptr;
            }
        }
};

class PizzaBuilder {
    private: 
        Pizza* pizza;
    
    public:
        PizzaBuilder() {
            pizza = nullptr;
        }
        void createPizza(string type){
            pizza = PizzaFactory::createPizza(type);
        }
        Pizza* getPizza(){
            return pizza;
        }
};

class PizzaSingleton {
    private: 
        static PizzaSingleton* instance;
        PizzaSingleton() {}
    
    public: 
        static PizzaSingleton* getInstance(){
            if (!instance){
                instance = new PizzaSingleton();
            }
            return instance;
        }
};

PizzaSingleton* PizzaSingleton::instance = nullptr;
int main(){
    PizzaBuilder builder;
    builder.createPizza("Margherita");
    Pizza* pizza = builder.getPizza();
    if (pizza) {
        cout << "Pizza Type: " << pizza->getType() << endl;
    } else {
        cout << "Invalid Pizza Type" << endl;
    }
    PizzaSingleton* singleton = PizzaSingleton::getInstance();
    return 0;
}