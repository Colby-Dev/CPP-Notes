#include <iostream>
#include <string>
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

In this approach, the instance of the class is created only when it is needed for the first time. This 
can help us in creating only one instance of the class and it also saves memory.

Following are the steps to implement Singleton Pattern in C++

> Make the constructor of the class private so that it cannot be instantiated from outside the class. 

> Then, create a static variable that holds the single instance of the class. 

> Create a static method that returns the instance of the class. This method checks if the instance is
  already created, if not it creates one and returns it. Otherwise, it simply returns the existing
  instance. 



--- Eager Initialization Singleton ---

In this approach, we create the instance of the class at the time of class loading. THis approach is simpler and it is also thread-safe.
However, the drawback of this approach is that the instance is created even if it is not used, which can lead to resource wastage. 
So if you are sure that the instance will be used, then this approach is a good choice. 


 --- Mayers' Singleton Implementation --- 

 The Mayers' Singleton implementation is a very good modern approach for creating singleton classes in C++. This approach uses a static local variable inside the
 getInstance() method to hold the single instance of the class. The instance is created when the method is called for the first time and it is destroyed automatically
 when the program exits. This approach is thread-safe and it also ensures that only one instance of the class is created. 

 --- Use cases of Singleton Pattern --- 

 > Logger class - As we have seen in the examples, the logger class uses the singleton pattern, so 


*/
// ---------------------------------------- //
// Lazy Initialization Singleton: 

// 	class Logger {
// 		private:
// 			static Logger* instance;
// 			Logger() {}

// 		public:
// 			static Logger* getInstance() {
			
// 			    if (instance == nullptr) {
			    	
// 			    	instance = new Logger();
// 				}
// 				return instance;
// 			}

// 			void log(string message){
// 				cout << "Log: " << message << endl;
// 			}
// };

// Logger* Logger::instance = nullptr;

// int main() {

// 	Logger* logger = Logger::getInstance();
// 	logger->log("This is a log");

// 	Logger* logger = Logger::getInstance();
// 	l1->log("This is another log message");

// 	return 0;
// }




// ---------------------------------------- //
// Eager Initalization Example: 

	// class Logger { 
	// 	private: 
	// 		static Logger* instance;
	// 		Logger() {}

	// 	public: 
	// 		static Logger* getInstance(){
	// 			return instance;
	// 		}

	// 		void log(string message){
	// 			cout <<"Log: " << message << endl;
	// 		}
	// };

	// Logger* Logger::instance = new Logger();

	// int main(){
	// 	Logger* logger = Logger::getInstance();
	// 	logger->log("This is a log message.");

	// 	Logger* l1 = Logger::getInstance();
	// 	l1->log("This is another log message.");
		
	// 	return 0;
	// }


// ---------------------------------------- //
// Mayers' Singleton Example:

	class Logger { 
		private:
			Logger() {}
		
		public: 
			static Logger& getInstance(){
				static Logger instance;
				return instance;
			}

			void log(string message){
				cout << "Log: " << message << endl;
			}
	};

	int main() { 
		Logger& logger = Logger::getInstance();
		logger.log("This is a log message.");
		
		Logger& l1 = Logger::getInstance();
		l1.log("This is another log message.");

		return 0;
	}