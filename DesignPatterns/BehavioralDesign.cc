/* 

----- Behavioral Design Pattern -----

Behavioral design patterns are ways of organising how different objects in a program communicate with each other. When a program becomes large, many objects need to exchange information 
or react to certain actions. If this communications is random or unplanned, the code becomes confusing. Behavioral design patterns give a simple and organized approach so every object
knows when to speak, when to listen, and what its role is. This makes the whole program easier to understand and work with. 

A good way to understand this is to picture a resturant. A restaurant runs smoothly only because everyone inside knows how to behave and how to talk to each other. The waiter takes orders
from customers, the chef cooks food, the cashier handles bills, and the manager watches over everything. The waiter does not suddenly start cooking, the chef cooks food, the cashier handles bills, 
and the manager watches over everything. The waiter does not suddenly start cooking, the chef does not run to take orders, and the customers don't go into the kitchen to ask what is happening. 
Everyone has a specific job and a clear way to interact. This simple structure keeps the resturant calm when many people are involved.

Now imagine if the behavior rules inside the restaurant didn't exist. Customers might walk straight into the kitchen, chefs might run to tables arguing about orders, waiters might forget who to serve
because everyone is shouting instructions. It would be a disaster. The same thing happens inside a program when communication is not planned properly. Behavioral design patterns prevent this problem
by defining clean paths of communication, just like a restaurant defines who talks to whom and when. 

For example, in the resturant a customer gives the order, the waiter handles it. The chef reacts when the waiter passes the order. The cashier reacts only after the meal is finished and bill is needed.
Everyone responds at the right moment without unnecessary connections or confusion. Behavioral design patterns create this same king of controlled flow between objects in a program. They helpcut down 
super tight connections between objects, which makes it way easier to change things later. If you want to add a new feature or tweak how something works, you only touch the part that actually needs the change,
not the whole project. 

--- Types of Behavioral Design Patterns --- 

We have total 11 types of Behavioral Design Patterns in C++, they are: 

1) Chain of Responsibility Design Pattern - Passing request through a series of handlers until one of them decides to handle it. 

2) Command Design Pattern - Turns a request into a simple object. This allows specific commands from the function doing the work. 

3) Interpreter Design Pattern - Deals with situations where you need to read, process, or understand a small language or set of rules. 

4) Iterator Design Pattern - Gives you a clean way to move through a collection (like a list or an array) wihtout exposing how that collection is built. 

5) Mediator Design Pattern - A coordinator in the middle who makes objects talk to eac other without letting them talk directly.

6) Memento Design Pattern - Saving and restoring an object's previous state without exposing its internal details. 

7) Observer Design Pattern - Connects one main objoect (subject) to many observers. When something changes in the subject, all obersers get updated.

8) State Design Pattern - Lets an object change its behavior depending on its current state. 

9) Strategy Design Pattern - Lets you swap algorithms or methods at runtime depending on the use case.

10) Template Design Pattern - Defines the main steps of a process but lets subclasses fill in the details.

11) Visitor Design Pattern - Add new operatons to a group of objects without modifying the object themselves.

--- Conclusion ---

In this chapter, we learned about behavioral design patterns and how they make communication inside a program simple and clear. We looked at patterns
like Strategy, Observer, and Template Method, and also saw how they can all work together in one simple example. These patterns make sure objects talk 
to each other in a proper way without creating confusion or messy connections. When developers use behavioral patterns, the whole program becomes easier
to understand, easier to change later, and easier to grow as new features are added. 

*/

#include <iostream>
#include <vector> 
#include <string> 
using namespace std;

// Strategy Pattern 
class AttackStrat{
    public: 
        virtual void attack() =0;
        ~AttackStrat() {}
};

class QuickAttack : public AttackStrat { 
    public: 
        void attack() override { 
            cout << "Charmander performs a quick attack!" << endl;
        }
};

class StrongAttack : public AttackStrat { 
    public: 
        void attack() override {
            cout << "Charmander performs a strong attack!" << endl;
        }
}; 

// Observer Pattern
class Observer { 
    public: 
        virtual void update(const string& msg) = 0;
        virtual ~Observer() {}
};

class Follower : public Observer { 
    private:
        string name;
    public: 
        Follower(string n) : name(n) {}

        void update(const string& msg) override{ 
            cout << name << "received update: " << msg << endl;
        }
};

class Subject { 
    private: 
        vector<Observer*> observers;
    public: 
        void addObserver(Observer* obs) { 
            observers.push_back(obs);
        }

        void notify(const string& msg) { 
            for (Observer* obs : observers){
                obs->update(msg);
            }
        }
};

// Template Method

class ActionTemplate{ 
    public: 
        void performAction(){
            prepare();
            mainAction();
            finish();
        }

    protected:
        virtual void prepare() { 
            cout << "Character prepares for action... " << endl; 
        }

        virtual void mainAction() = 0;

        virtual void finish() { 
            cout << "Character finishes action" << endl;
        }
};

class AttackAction : public ActionTemplate { 
    private: 
        AttackStrat* strategy;
    public: 
        AttackAction(AttackStrat* s) : strategy(s) {}
    
    protected: 
        void mainAction() override { 
            strategy->attack();
        }
};

class GameCharacter : public Subject { 
    private: 
        AttackStrat* strategy;
    public: 
        GameCharacter(AttackStrat* s) : strategy(s) {}

        void setStrategy(AttackStrat* s){ 
            strategy = s;
        }

        void performAttack(){
            AttackAction action(strategy);
            action.performAction();
            notify("Character performed an attack!");
        }
};

int main() { 
    // Strategies
    AttackStrat* quick = new QuickAttack();
    AttackStrat* strong = new StrongAttack();

    // Character with default attack
    GameCharacter hero(quick);

    Follower f1("Follower 1");
    Follower f2("Follower 2");

    hero.addObserver(&f1);
    hero.addObserver(&f2);

    // Perform attacks
    cout << "\n Quick Attack!" << endl;
    hero.performAttack();

    cout << "\n Switching to Strong Attack" << endl;
    hero.setStrategy(strong);
    hero.performAttack();

    delete quick;
    delete strong;
};

