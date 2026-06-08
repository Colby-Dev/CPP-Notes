/*
 
----- Chain of Responsibility -----

The Chain of Responsibility pattern is a behavioral design pattern which allows you pass an object of a request through a chain of potential handlers until one of them handles the request. This pattern decouples the sender of a request from its receiver by giving multiple objects a chance to handle the request. 

In this pattern, each handler in the chain has a reference to the next handler. When a request is received, the handler decides either to process the request or to pass it to the next handler in the chain. This continues until a handler processes the request or the end of the chain is reached. 

--- Components of the Chain of Responsibility Pattern --- 

There are three main components in the Chain of Responsibility pattern we have listed them below: 

> Handler, It can be an abstract class or it may be an interface which defines a method for handling requests 
	   and a method for setting the nect handler in the chain. 

> Concrete Handler, These are the classes that implement the handler interface and provide specific 
		    implementations for handling requests. Each concrete handler decides whether to process the
		    request or pass it to the next handler. 

> Client, The client is responsible for creating the chain of handlers and initiating the request processing by
	  sending the request to the first handler in the chain. 

--- Implementation of the Chain of Responsibility Pattern --- 

Now, let's implement the Chain of Responsibility pattern in C++. 

In this example, we will take a real-world scenario where, we have a support ticket system. The tickets can be handled by different levels of support staff based on the priority and complexity of the issue. 

(see Example 1)

--- Conclusion ---

In this chapter, we've seen what the Chain of Responsibility pattern is, how it works, and how to use it in C++. It's a handy way to keep your code flexible and easy to maintain by letting requests find the right handler without everyone needing to know about each other. 

*/

// Example 1
#include <iostream> 
#include <string> 
using namespace std; 

// Abstract Handler
class SupportHandler { 
	protected: 
		SupportHandler* nextHandler; 

	public: 
		SupportHandler() : nextHandler(nullptr) {}
		void setNextHandler(SupportHandler* handler) { 
			nextHandler = handler; 
		}

		virtual void handleRequest(const string& issue, int priority) = 0; 
}; 

// Concrete Handler: Level 1 Support
class Level1Support : public SupportHandler { 
	public: 
		void handleRequest(const string& issue int priority) override { 
			if (priority == 1) { 
				cout << "Level 1 Support handled the issue: " << issue << endl;

			}
			else if (nextHandler) { 
				nextHandler->handleRequest(issue, priority);
			}
		}
};

class Level2Support : public SupportHandler { 
	public: 
		void handleRequest(const string& issue, int priority) override { 
			if (priority == 2) { 
				cout << "Level 2 Support handled the issue: " << issue << endl;
			}
			else if (nextHandler) { 
				nextHandler->handleRequest(issue, priority);
			}
		}
};

class Level3Support : public SupportHandler { 
	public: 
		void handleRequest(const string& issue, int priority) override { 
			if (priority == 3) { 
				cout << "Level 3 Support handled the issue: " << issue << endl;
			}
			else if (nextHandler) { 
				nextHandler->handleRequest(issue, priority);
			}
		}
};

int main() { 
	// Create handlers
	Level1Support level1;
	Level2Support level2;
	Level3Support level3;

	// Set up the chain of responsibility
	level1.setNextHandler(&level2);
	level2.setNextHandler(&level3);

	// Create some support requests
	level1.handleRequest("Password reset", 1);
	level1.handleRequest("Software installation", 2);
	level1.handleRequest("System crash", 3);

	return 0; 
}
