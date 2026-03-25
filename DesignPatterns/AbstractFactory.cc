/*

----- Abstract Factory Design Pattern -----

The Astract Factory is a creational design pattern that provides an interface with methods for a particular type of object, but it allows subclasses to alter the type
of objects that will created. The Abstract Factory pattern is used when we have multiple families of related or dependent objects and we want to create them without 
specifying their concrete classes. 

In other words, it is a factory of factories. In the last chapter, we discussed the Factory Method pattern which issued to create objects of a single family. But in
Abstract Factory pattern, we can create objects of multiple families.

Imagine you are building your dream house, and you have two choices for furniture: Modern or Victorian. Each type has its own matching set of items like a chair, or sofa, 
and a coffee table. Instead of picking each item one by one and possibly making a mix-match, you use a furniture factory that gives you the full set in one style. If you
want Modern, you get all Modern. If you want Victorian, you get all Victorian items. The Abstract Factory pattern works the same way: It gives you a whole set of related
objects in one style, so everything fits together perfectly. 

--- Implementation of Abstract Factory Pattern ---

> Conventional Abstract Factory, It uses classic interface and concrete factories. 

> Registry-base Abstract Factory, It uses a registry of factories to create objects of different families. 

Concrete Factory means a class which implements the Abstract Factory interface and is responsible for creating the objects of a particular family. The client code uses
the abstract factory interface to create the objects without knowing the concrete classes. 

--- Conventional Abstract Factory Implementation ---

In this approach, we create an abstract factory interface which is used for defining the methods for creating family of related objects. Then, we create concrete factory
classes that implement the abstract factory interface and provide the implementation for creating the objects of a particular family.
*/

/*
Example: 

    class Chair {
        public:
            virtual string getType() = 0;
    };

    class Sofa {
        public:
            virtual string getType() = 0;
    };

    class ModernChair : public Chair {
        public:
            string getType(){
                return "Modern Chair";
            }
    };

    class ModernSofa : public Sofa {
        public: 
            string getType() {
                return "Modern Sofa";
            }
    };

    class VictorianChair : public Chair {
        public:
            string getType(){
                return "Victorian Chair";
            }
    };

    class VictorianSofa : public Sofa {
        public:
            string getType(){
                return "Victorian Sofa";
            }
    };

    class FurnitureFactory { 
        public:
            virtual Chair* createChair() = 0;
            virtual Sofa* createSofa() = 0;
    };

    class ModernFurnitureFactory : public FurnitureFactory {
        public: 
            Chair* createChair() {
                return new ModernChair();
            }
            
            Sofa* createChair() { 
                return new ModernSofa();
            }
    };

    class VictorianFurnitureFactory : public FurnitureFactory {
        public: 
            Chair* createChair(){
                return new VictorianChair();
            }
            
            Sofa* createChair(){
                return new VictorianChair();
            } 
    };

    int main() { 
        FurnitureFactory* factory;
        Chair* chair;
        Sofa* sofa;

        factory = new ModernFurnitureFactory();
        chair = factory->createChair();
        sofa = factory->createSofa();

        cout << "Chair: " << chair->getType() << endl;
        cout << "Sofa: " << sofa->getType() << endl;

        factory = new VictorianFurnitureFactory();
        chair = factory ->createChair();
        sofa = factory -> createSofa();

        cout << "Chair: " << chair->getType() << endl;
        cout << "Sofa: " << sofa->getType() << endl;

        return 0;
    }
*/
/*
--- Registry based Abstract Factory Implementation ---

This is a similar approach we have discussed in the Factory Method pattern. In this approach, we create a registry of factories that can create objects of different families. 
The registry is a map that maps the family name to the corresponding factory. The client code uses the registry to get the factory for a particular family and then uses the
factory to create the objects. 

(example shown below)

--- When to use Abstract Factory Pattern ---

Following are important scenarios where we can use Abstract Factory Pattern: 

> When the system needs to be independent of how its products are created, composed, and represented. 

> When the system is configured with one of multiple families of products. 

> When we want to provide a library of products, and we want to reveal just their interfaces, not their implementations. 

> When we want to ensure that the client code uses only objects from the same family. 

--- Conclusion --- 

Abstract Factory is a creational software design pattern that provides an interface for generating families of related or dependent objects without revealing their concrete classes.
It is used when we have multiple families of related or dependent objects and want to create them without having their concrete classes defined. The Abstract Factory pattern conceals
the objects' construction and offers loose binding of the concrete classes and the client code, and it also satifies the Open / Closed Principle, because it is feasible to add new
families of related objects without altering the code. 

*/

#include <iostream>
#include <string>
#include <map>

using namespace std; 

class Car {
    public: 
        virtual string getType() = 0;

};

class SUV : public Car {
    public: 
        string getType(){
            return "SUV";
        }
};

class Sedan : public Car{
    public:
        string getType(){
            return "Sedan";
        }
};

class CarFactory{
    public: 
        virtual Car* createCar() = 0; 
};

class SUVFactory : public CarFactory {
    public:
        Car* createCar() { 
            return new SUV();
        }
};

class SedanFactory : public CarFactory { 
    public: 
        Car* createCar(){
            return new Sedan();
        }
};

class CarFactoryRegistry {
    private: 
        map<string, CarFactory*> registry;
    
    public: 
        void registerFactory(string type, CarFactory* factory) { 
            registry[type] = factory;

        }

        CarFactory* getFactory(string type){
            return registry[type];
        }
};

int main(){
    CarFactoryRegistry registry;
    registry.registerFactory("SUV", new SUVFactory());
    registry.registerFactory("Sedan", new SedanFactory());

    CarFactory* factory;
    Car* car;

    factory = registry.getFactory("SUV");
    car = factory->createCar();
    cout << "Created car of type: ";
    cout << car->getType() << endl;

    factory = registry.getFactory("Sedan");
    car = factory->createCar();
    cout << "Created car of type: ";
    cout << car->getType() << endl;

    return 0;
}