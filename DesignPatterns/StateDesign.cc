/* 

----- State Design Pattern -----

The State Design Pattern is a way to let an object change how it behaves when its state changes. Instead of using lots of if-else or switch statements, you put the different behaviors into separate state classes.
This makes your code cleaner and easier to understand.

In this pattern, you have a mian class (called the context) that keeps track to its current state. When something happens, the context asks its current state what to do. If the state changes, the context just
switches to a different state object. This way, the object can change its behavior at any time, just by changing its state. 

--- Key Components of the State Design ---

The state design pattern is made up of a few important parts that work together to make your code easier to manage and understand.

1) Context - This is the main object you work with. It keeps track of what state it is in right now. When something happens, the context asks its current state what to do next. The context is also in charge of 
             switching to a different state when needed. 

2) State Interface - This is like a blueprint that says what actions every state should be able to do. All the different states must follow this blueprint and provide their own versions of these actions. 

3) Concrete State Classes - These are the actual states your object can be in. Each state class has its own way of handling things. For example, the "Idle" state will do something different than the "Dispensing"
                            state when you press a button.

4) State Transition - This is how the contect changes from one state to another. When something happens (like inserting money), the context will switch to a new state so it can behave differently.

*/

#include <iostream>
using namespace std;

class stateInterface { 
    public: 
        virtual void insertMoney() = 0;
        virtual void selectItem() = 0;
        virtual void dispenseItem() = 0;
        virtual ~stateInterface() {};
};

class VendingMachine;

class IdleState : public stateInterface { 
    private: 
        VendingMachine* vendingMachine;
    public: 
        IdleState(VendingMachine* vm) : vendingMachine(vm) {}
        void insertMoney() override {};
        void selectItem() override {
            cout << "Please insert money first." << endl;
        }
};

class hasMoneyState : public stateInterface { 
    private: 
        VendingMachine* vendingMachine;
    public: 
        hasMoneyState(VendingMachine* vm) : vendingMachine(vm) {}
        void insertMoney() override{
            cout << "Money already collected." << endl;
        }
        void selectItem() override {};
        void dispenseItem() override {
            cout << "Please select an item first" << endl;
        }
};

class DispensingState : public stateInterface { 
    private:
         VendingMachine* vendingMachine;
    public: 
        DispensingState(VendingMachine* vm) : vendingMachine(vm) {}
        void dispenseItem() override{ 
            cout << "Dispensing Item" << endl;
        }
};