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

This is a simple way to 

*/


#include <iostream> 
using namespace std; 

