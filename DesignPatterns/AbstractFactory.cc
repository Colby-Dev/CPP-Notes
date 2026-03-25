/*

----- Abstract Factory Design Pattern -----

The Astract Factory is a creational design pattern that provides an interface with methods for a particular type of object, but it allows subclasses to alter the type
of objects that will created. The Abstract Factory pattern is used when we have multiple families of related or dependent objects and we want to create them without 
specifying their concrete classes. 

In other words, it is a factory of factories. In the last chapter, we discussed the Factory Method pattern which isused to create objects of a single family. But in
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

In this approach, we create an abstract factory interface which is used for defining the methods for creating family of related objects. 

*/