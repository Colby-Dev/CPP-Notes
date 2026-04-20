/* 

----- Mediator Design -----

Mediator Design Pattern is a way to make communication between different objects or classes much simpler. Instead of having every object
talk directly to every other object, which can get confusing, we use a special class called the mediator. The mediator acts like a middleman
and handles all the messages between objects. This makes the code easier to manage and change later because the objects don't need to know 
about each other. 

A simple example would be a control tower at an airport. While the actions and functions of the planes may influence other planes they are
coordinated by the control tower. Each plane would be an object or class, while the mediator class would be the middleman coordinating the 
different objects so that all planes would only talk to the control tower and not each other. 

In programming, this pattern works just like a control tower. It helps different parts of a program communicate in an organized way, making 
the whole system easier to understand and maintain. 

--- Components of Mediator Design Pattern ---

Mediator - Think of this as the main organizer or the middleman. It's a special class that helps different parts of the program talk to each other.
           Instead of everyone talking to everyone, they all talk to the mediator. 

ConcreteMediator - This is the real middleman in action. It knows about all the different parts (objects) and helps them send messages to each other.
                   If one part wants to talk to another, it tells the mediator, and the mediator passes the message along. 

Colleague - These are the different parts or objects in your program that need to communicate. Each one knows about the mediator, but they don't know
            about each other. If they want to send message, they go through the mediator.

ConcreteColleague - These are the actual objects doing the work in your program. They use the mediator to talk to other objects. For example, in a chat
                    room, each user is a ConcreteColleague, and they send messages through the chat room (the mediator)

--- Implementation of Mediator Design Pattern --- 

1) Create the Mediator Interface - This is like making a set of rules for how the middleman (mediator) will help others talk to each other. It just says
                                   what the mediator should be able to do, but not how. 

2) Make the Real the Mediator Class - Here, you actually build the middleman. This class knows about everyone who needs to talk and helps them send messages
                                      to each other. 

3) Create the Colleague Interface - This is a simple plan for all the people (objects) who want to talk to each other. It says what each one should be able to do,
                                    like send a message. 

4) Build the Real Colleague Classes - Now you make the actual people (objects) who will use the mediator to talk. Each one uses the middle instead of talking directly to others. 

5) See How it Works Together - Put everything together and show how the objects use the mediator to send messages. THis is where you see the pattern in action,
                               just like people using a group chat to talk instead of calling each other one by one. 

--- Pros and Cons of Mediator Design Pattern ---

Pros: 

    > Makes it easier for different parts of your program to work together without being directly connected. This means if you change one part you don't have to change all the others. 

    > Puts all the rules for how things talk to each other in one placem so it's simpler to see and fix how communication works. 

    > Helps different parts of your program talk to each other, even if they don't know aout each other at all. 

    > Makes your code easier to read and understand because everything goes through the mediator. 

    > If you want to change how things communicate, you only need to update the mediator, not every single part.

Cons: 

    > If too many things depend on the mediator, it can become overlaoded and slow things down.

    > Adds an extra step (the mediator) between objects, which can make the program a bit more complicated. 

    > If you're not careful, the mediator can become too big and hard to manage. 

    > Because messages go through the mediator, it can be harder to figure out where a problem is if something goes wrong. 

    > Sometimes, using a mediator too much can make the other parts less independent and flexible. 

--- Conclusion --- 

In this chapter, we have learned about the Mediator Design Pattern, its components, implementation in C++, pros and cons, and real-world examples. The Mediator Design Pattern is a powerful
tool for managing complex communication between objects while promoting loose coupling and maintainability. By using this pattern, developers can create more flexible and scalable systems 
that are easier to understand and maintain. 

*/

#include <iostream>
#include <string>
#include <vector> 
using namespace std; 

// Mediator Interface
class ChatMediator { 
    public: 
        virtual void showMessage(const string &user, const string &message) = 0; 
};

// Concrete Mediator
class ChatRoom : public ChatMediator { 
    private: 
        vector<string> users;
    public: 
        void addUser(const string &user){
            users.push_back(user);
        }
        void showMessage(const string &user, const string &message) override { 
            cout << user << ": " << message << endl;
        }
};

// Colleague Interface 
class User { 
    protected: 
        ChatMediator *mediator;
        string name; 
    public: 
        User(ChatMediator *med, const string &n) : mediator(med), name(n) {}
        virtual void sendMessage(const string &message) =0;
};

// Concrete Colleague
class ChatUser : public User { 
    public: 
        ChatUser(ChatMediator *med, const string &n) : User(med, n) {}
        void sendMessage(const string &message) override { 
            mediator->showMessage(name, message);
        }
};

int main() { 
    ChatRoom chatRoom;

    ChatUser user1(&chatRoom, "Alice");
    ChatUser user2(&chatRoom, "Bob");
    ChatUser user3(&chatRoom, "Charlie");
    chatRoom.addUser("Alice");
    chatRoom.addUser("Bob");
    chatRoom.addUser("Charlie");
    user1.sendMessage("Hello, everyone!");
    user2.sendMessage("Hi Alice!");
    user3.sendMessage("Hey folks, what's up?");

    return 0;
}

