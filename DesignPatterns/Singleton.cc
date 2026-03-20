#include <iostream> 
using namespace std; 

/* 

----- Singleton Pattern in C++ -----

A singleton pattern is a design pattern which allows to create only one object of a class.
Instead of allowing the class to create multiple instances everytime it is called, the singleton
pattern ensures that only one instance of the class is created and it also provides it a global
access point so that it can be acessed anywhere in the code. 

The singleton pattern is useful when exactly one object is needed coordinate actions across the
system. For example, imagine you are in a office you need to use a printer Instead of having a 
printer for each employee, you can have a single printer that is shared by all employees. This way
you can ensure only one person can use the printer at a time and save resources. 

--- Key Points of Singleton Pattern ---

> It restricts the instantiation of a class to one single instance. 

> It provides a global access point to that instance.

> It if often used for managing shared resources such as DB connections, configuration settings, and
  logging. 

> It can be implemented using lazy initialization, where the instance created only when it is needded
  for the first time. 

--- Implementation of Singleton Pattern ---

There are several ways to implement the Singleton Pattern in C++. Some of the important and common
implementations are: 

    * Lazy Initialization Singleton
    * Eager Initialization Singleton 
    * Mayers' Singleton

Mostly, the lazy initialization singleton is used as it is more efficient and it also saves memory.
However, the eager initialization singleton is simpler and it is also thread-safe. The Mayers' singletonimplementation is a very good modern approach for creating singleton classes in C++/ 

--- Lazy Initialization Singleton --- 



*/
