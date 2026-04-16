/*

----- Facade Design Pattern -----

Facade Design Pattern is a structural design pattern that provides a single and simplified interface to a complex system of classes, 
library or framework. It organizes a complicated system by adding a simple interface to it.

Instead of having multiple objects to interact with, the client can interact with a single facade object which internally manages the
interactions with the complex system. 

Imagine the following big "Facade" building is like magic "Play" button for a whole toy factory. You just press that one button, and 
inside, all the machines start working together automatically to make toys, without you needing to know how each one works. 

--- Components of Facade Design Pattern ---

> Facade - This is the main part the user talks to. It provides simplified interface to bunch of subsystems. It acts as a middleman
           between client and complex system. 

> Complex System - Many classes that do the real work. These classes or we also call them subsystems are the ones who actually do the 
                   task. They can be hard to use directly without the facade.

> Client - The user. Talks only to the facade, not the complex system. Means, the client doesn't need to know about the complex system,
           it just uses the facade to get things done. 

--- Implementation of Facade Design Pattern ---

In this implementation, we will create a simple Home Theater system where we have multiple components like TV, Sound System, and DVD Player.
We will then create a Facade class that provides a simplified interface to control these components. 

    > Steps to Implement Facade Design Pattern

    1) Identify Subsystems - List all the classes or modules that perform complex operations. 

    2) Create a Facade Class - This class provides a simple interface for clients to interact with all subsystems. 

    3) Implement Methods in the Facade - Each method in the facade coordinates call to multiple subsystems. 

    4) Client Uses Facade - Instead of interacting with each subsystem seperately, the client calls methods on the Facade.

    5) Keep subsystems independent - Subsystems should remain usable independently of the facade if needed.

--- Conclusion ---

*/

#include <iostream>;
using namespace std; 
class TV {
    public: 
        void On(){
            cout << "TV is ON" << endl;
        }
        void Off(){
            cout << "TV is OFF" << endl;
        }
};

class SoundSystem { 
    public:
        void On(){
            cout << "Sound System is ON" << endl;
        }
        void Off(){
            cout << "Sound System is OFF" << endl;
        }
};

class DVDPlayer {
    public: 
        void On(){
            cout << "DVD Player is On" << endl;
        }
        void Off(){
            cout << "DVD Player is Off" << endl;
        }
};

// Facade
class HomeTheaterFacade{
    private: 
        TV* tv;
        SoundSystem* soundSystem;
        DVDPlayer* dvdPlayer;
    public:

};