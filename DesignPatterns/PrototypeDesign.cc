/* 

----- Prototype Design Pattern -----

Consider a scenario where you have an object and your friend asks you to create its replica. How would you do that? You are probably thinking of creating a new object and
then copying the values from the existing object to the new object. That is some good thinking but, what if the existing objects have some fields that are private and not
visible outside the class. And also, you would have to know the class of the existing object to create a new object of the same class, which makes your dependent on the 
class of the object. In such cases, we need to use the Prototype Pattern.

The Prototype Pattern allows us to make copies from an actualy object. It declares a common interface for all objects and those objects support cloning themselves.
This means the object itself is responsible for creating a copt of itself is responsible for creating a copy of itself. The client code can use the common interface to clone
the object without knowing the class of the object. This interface has only one method, which is clone(). The clone() method is responsible for creating a copy of the object
and returning it to the client code. 

Whichever object that supports cloning is called a prototype. If the objects have too many fields and many different types of configurations, then you can just clone them. 
We can implement the Prototype Pattern in the following two ways: 

> Basic Prototype Pattern, This is the simple way without any registry. 

> Prototype Pattern with Registry, This approach uses a registry to keep track of all prototypes. 

--- Basic Prototype Pattern ---

The following illustration shows the steps for implementing the Basic Prototype Pattern:

    Define Prototype Interface -> Create Concrete Prototype Class -> Client Requests Object -> Cloned Object Returned

--- Conclusion --- 

We learned what is the Prototype Pattern and how to implement it in C++. We also saw two different ways of implementing the pattern, with basic and registry. The pattern is a
powerful design that allows us to create copies of existing objects without knowing their class. It helps in reducing memory usage and decoupling the client code from the class
of the object. 

*/

#include <iostream>
#include <string>
#include <memory> 
using namespace std; 

class VirtualMachine { 
    public: 
        virtual unique_ptr<VirtualMachine> clone() const = 0;
        virtual void showConfig() const = 0;
        virtual ~VirtualMachine() = default;

};

class LinuxVM : public VirtualMachine { 
    string os; 
    int ram;
    int cpu; 
    public: 
        LinuxVM(string os, int ram, int cpu) : os(move(os)), ram(ram), cpu(cpu) {}

        unique_ptr<VirtualMachine> clone() const override{ 
            cout << "Cloning Linux VM..." << endl;
            return make_unique<LinuxVM>(*this);
        }

        void showConfig() const override{
            cout << "Linux VM - OS: " << os
                 << ", RAM: " << ram << "GB, CPU: " << cpu 
                 << " cores" << endl; 
        }
};

class WindowsVM : public VirtualMachine { 
    string os; 
    int ram; 
    int cpu; 
    public: 
        WindowsVM (string os, int ram, int cpu) : os(move(os)), ram(ram), cpu(cpu) {}
        
        unique_ptr<VirtualMachine> clone() const override { 
            cout << "Cloning Windows VM..." << endl; 
            return make_unique<WindowsVM>(*this);
        }

        void showConfig() const override{ 
            cout << "Windows VM - OS: " << os
                 << ", RAM: " << ram << "GB, CPU: " << cpu
                 << " cores" << endl;
        }
};

int main(){ 
    unique_ptr<VirtualMachine> linuxVM = make_unique<LinuxVM>("Unbuntu 20.04", 8, 4);
    unique_ptr<VirtualMachine> windowsVM = make_unique<WindowsVM>("Windows 10", 16, 8);

    cout << "Original VMs: " << endl; 
    linuxVM->showConfig();
    windowsVM->showConfig();

    cout << "\nCloning VMs:" << endl;
    auto clonedLinuxVM = linuxVM->clone();
    auto clonedWindowsVM = windowsVM->clone();

    cout << "\nCloned VMs: "<< endl;
    clonedLinuxVM->showConfig();
    clonedWindowsVM->showConfig();

    return 0;
};