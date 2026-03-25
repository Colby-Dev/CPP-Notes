/* 

----- Factory Method Pattern in C++ -----

The Factory Method Pattern is a creational design pattern that defines an interface for creating an object. It allows its subclasses to change the type of object that
will be created. 

For example, imagine you are creating an employee management system for your company, annd there are different types of employees such as full-time, part-time, and
contract employees. Each type of employee has different attributes and behaviors. Instead of creating a separate class for each type of employee, you can use the factory
method pattern to create a single interface for creating employees and then let the subclasses decide which type of employee to create. 

So, instead of calling new at the client side, we can just call a factory method which will return the object of the desired type.

--- Implementation of Factory Method Pattern ---

There are ways to implement the Factory Method Pattern. Some of the important and common implementations are: 

> Factory Method (GoF official one)
> Simple Factory (static method)
> Registry-based Factory (parameterized)

Let's discuss each of these implementations in detail. The important point to note is that the Factory Method Pattern is often used in conjunction with other design patterns
such as Singleton, Abstract Factory, and Builder patterns. 

Also, the type of implementations you choose will depend on the specific requirements of your application and the complexity of the object creation process. 

--- Implementation of Factory Method of the Official GoF Way --- 

This is an official implementation of the factory method pattern as described in the Gang of Four book. In this approach, we create an abstract class that defines the factory 
method and then create concrete subclasses that implement the factory method to create specific types of objects. 

An example would be a car factory, we have an abstract class CarFactory that defines the factory method createCar(). Then, we create concrete subclasses such as SUVFactory and SedanFactory
that implement the factory method to create specific types of cars. 

Example: 

    class Car { 

        public: 

            virtual void drive() = 0;
            virtual ~Car() {}
    };

    class SUV : public Car {
    
        public: 

            void drive(){
                std::cout << "Driving an SUV" << std::endl;
            }
    };

    class Sedan : public Car {
    
        public: 

            void drive(){
                std::cout << "Driving a Sedan" << std::endl;
            }
    };

    class CarFactory(){

        public:
            
            virtual Car* createCar() = 0;
            virtual ~CarFactory() {}
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

    int main() {
        CarFactory* factory = new SUVFactory();
        Car* car = factory -> createCar();
        car -> drive();
        delete car;
        delete factory; 

        CarFactory* factory = new SedanFactory();
        Car* car = factory -> createCar();
        car -> drive();
        delete car;
        delete factory;
    }

--- Simple Factory Pattern Implementation ---

This is a simple way to implement the factory pattern also known as Static Factory Method. In this approach, we create a single class that contians a static method to create objects
of different types based on the input parameters. Then, in the factory method, we use a switch statement of if-else statements to determine which type of object to create based on 
the input parameters. 

Let's take an example of shape factory. Here, we have a class Shape and different subclasses such as Circle and Square. We can create a static factory method in the ShapeFactory class
to create objects of these subclasses based on the input parameters.

Example: 
    
    class Shape{
        public: 

            virtual void draw() = 0;
            virtual ~Shape(){}
    };

    class Circle : public Shape{
        public: 

            void draw() {
                std::cout << "Drawing a Circle" << std::endl;
            }
    };

    class Square : public Shape {
        public: 

            void draw(){
                std::cout << "Drawing a Square" << std::endl;
            }
    };

    class ShapeFactory {
        public: 

            static Shape* createShape(const std::string& type){
                if (type == "Circle"){
                    return new Circle();
                } else if (type == "Square"){
                    return new Square(); 
                } else {
                    return nullptr; 
                };
            }
    };

    class Client { 
        public: 

            void drawShape(cosnt std::string& type){
                Shape* shape = ShapeFactory::createShape(type);
                if (shape){
                    shape -> draw();
                    delete shape;
                } else { 
                    std::cout << "Invalid shape type" << std::endl;
                }
            }
    };

int main(){
    Client client;
    client.drawShape("Circle");
    client.drawShape("Square");
    client.drawShape("Triangle"); 
}


--- Registry based Factory Pattern Implementation ---

This is more advanced way to implement the factory pattern. In this approach, we create a registry of factory methods that can be used to create objects of different
types. The registry is typically implemented as a map or dictionary that maps a string or an enum value to a factory method. This allows us to easily add new types
of objects without modifying the existing code. 

In the previous approaches, we have used block of if-else or used small factory classes for each type. But in this approach, we can centralize the creation logic in 
a single registry class. Think of its as a map where: 

    The key is the type we want (like "Cat" or "Dog")
    The value is a function that knows how to make that thing we want

It is like a notebook where you write down how to make different things. When you want to make something, you look it up in your notebook and follow the instructions.
And when you want to make something new, you just add a new entry to your notebook without changing the existing ones. 

This way, we can easily extend the facotry to create new types of objects without modifying the existing code.

--- Real World Applications of Factory Method --- 

> GUI Frameworks, Many GUI frameworks use factory methods to create UI components like buttons, text fields, etc. 

> Game Development, In game development, factory methods are used to create different types of game objects (e.g., enemies, power-ups) without specifying their concrete
                    classes. 

> Database Connections, Factory methods can be used to create database connection objects, and allows them to be used interchangeably for different types of databases.

--- Conclusion --- 

The Factory Method is a powerful creational design pattern which provides a way to create an object without exposing the creation logic to the client. We can make our 
code easy to maintain and also we can reuse it in different parts of the application. But, it is important to use the Factory Method carefully, as it can add unnecessary
complexity to the codebase, if not used correctly.

*/


#include <iostream>
#include <string>
#include <map>
#include <functional>
using namespace std; 

class Shape {
    public:
        virtual void draw() = 0;
};

class Circle : public Shape {
    public:
        void draw(){
            std::cout << "Drawing a Circle" << std::endl;
        }
};

class Square : public Shape {
    public: 
        void draw() {
            std::cout << "Drawing a Square" << std::endl;
        }
};

class ShapeFactory {
    public:
        using ShapeCreator = std::function<Shape*()>;

        static Shape* createShape(const std::string& type){
            auto it = registry().find(type);
            if (it != registry().end()) {
                return it->second();
            }
            return nullptr;
        }

        static void registerShape(const std::string& type, ShapeCreator creator){
            registry()[type] = creator;
        }
    
    private: 
        static std::map<std::string, ShapeCreator>& registry() {
            
            static std::map<std::string, ShapeCreator> instance;
            return instance;
        }
};

class Client {
    public:

        void drawShape(const std::string& type){
            Shape* shape = ShapeFactory::createShape(type);
            if (shape) {
                shape -> draw();
                delete shape;
            } else {
                std::cout << "Invalid shape type" << std::endl;
            }
        }
};

int main(){
     
    ShapeFactory::registerShape("Square", []() { return new Square(); });

    Client client;
    client.drawShape("Circle");
    client.drawShape("Square");
    client.drawShape("Triangle");

    return 0;
}
