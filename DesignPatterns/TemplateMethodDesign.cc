/* 

----- Template Method Design Pattern -----

The template method design pattern is a way to set up a common process that can be shared by different classes.
It gives a main method called the template method that explains the steps to complete a task. Other classes can then 
fill in the details for some of those steps in their own way, without changing the main process. This helps in reusing
code and keeping things simple as well as consistent. 

This pattern is helpful when you have a task that follows the same steps every time, but a few steps might need to be 
done differently. You can keep the main steps in one place and let other classes change only the parts they need. 
This makes the program easy to read and simple to manage. 

--- Key Parts of the Template Method Design Pattern --- 

The Template Method Design Pattern has following components that work together: 

> The Abstract Class is the main class that defines the overall process. It includes the template method, which 
  lists all the steps in order. Some steps may already have code, while others are left empty so other classes can fill
  them in later. 

> The Template Method is the main method that shows how the task should be done from start to finish. It calls smaller 
  methods for each step. Some of those smaller methods might be complete, and some might be waiting for other classes to
  finish them. 

> The Concerete Subclasses are the classes that come from the abstract class. They complete the unfinished steps by adding 
  their own code. Each subclass can do things a little differently, but they all still follow the main process written in 
  the template method. 

> The Hook Methods are optional steps that can be changed if needed. They let you add or skip small actions without touching
  the main process. THink of them like little switches you can turn on or off to change small parts of how things work. 

--- Steps to Implement the Template Method Design Pattern --- 

> First, make an abstract class that has one main method called template method. This method lists all the steps of the process,
  like a recipe. Some steps will already have code, and others will be left empty so that other classes can fill them in later. 

> Next, create subclasses that come from the abstract class. These classes will fill in the missing steps with their own code. 

> Finally, use these subclasses to run the template method. The main steps stay the same, but each subclass adds its own little changes
  to make the meal special in its own way. 

--- Conclusion --- 

The Template Method Design Pattern is a simple and practical way to keep one common process while letting different parts change only when it is needed. 
It helps you in reusing code, keeping your program organized, and make complex tasks easier to handle without repeating the same logic everywhere. 


*/

#include <iostream> 
using namespace std; 

class Meal { 
    public: 
        void prepareMeal() { 
            gatherIngredients();
            cook();
            serve();
        }

        virtual void gatherIngredients() = 0;
        virtual void cook () =0;

        void serve() {
            cout << "Serving the meal!" << endl;
        }
};

class Breakfast : public Meal { 
    public: 
        void gatherIngredients() override { 
            cout << "Gathering ingredients for breakfast: eggs, bacon, and coffee." << endl;
        }

        void cook() override {
            cout << "Cooking breakfast: frying eggs and toasting bread. " << endl;
        }
};

class Lunch : public Meal { 
    public: 
        void gatherIngredients() override { 
            cout << "Gathering ingredients for lunch: chicken, rice, and vegetables." << endl;
        }

        void cook() override { 
            cout << "Cooking lunch: Grilling chicken, and steaming vegetables." << endl;
        }
};

int main() {
    Meal* breakfast = new Breakfast();
    breakfast->prepareMeal();

    cout << endl;

    Meal* lunch = new Lunch();
    lunch->prepareMeal();

    delete breakfast;
    delete lunch;

    return 0;
}