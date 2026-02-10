#include <iostream> 


using namespace std; 

/*
------ Function Overriding ------
Function overriding is a concept of oop which allows a derived class to redefine a function thatis already defined in the base class. The name and parameters stay the same, but the derived
class changes its behavior to suit their specific needs. 

In short, function overriding occurs when the functionality of the base class is redefined by
the derived class. When an object of the dervied class is created, it will call the updated
function from the derived class, meaning the base class function (a) is overridden by the 
derived function (b). 

--- Overriding vs Overloading ---
Although function overriding and function overloading are key-concepts in oop they serve
different purposes. 

> Overriding allows derived class to get new implementation of method to its previously defined
  base class, as having different scopes (base class and derived class) where it resolved at
  runtime polymorphism (dynamic binding), it only takes place in presence of inheritance and can
  overridden just once, where execution speed is relatively slower. 

> Overloading enables you to create multiple functions with the same name but different parameter lists
  within the same scope. It is resolved at compile time polymorphism (static binding), where presence of inheritance is not important.
  These functions can be overloaded multiple times and execution speed tends to be faster comparatively.

--- Advanced Overriding Concepts ---

> Virtual Destructor - Makes sure the destructor of the derived class is removed through a base class pointer. This avoids resource leaks.

> Covariant Return Value Types - Allow derived classes to override a method and return a more specific type than the base class method. 

> Overriding and final Keyword alternate word - The 'final' keyword stops any further subclassing of a class or overriding of a method.

> Virtual Inheritance - It ensures that when a class inherits from several base classes which have a common ancestor, only a single instance of that common base is created.

--- Advantages of Overriding ---

> Polymorphism - Overriding enables polymorphism by letting objects of different derived classes be treated as instances of a base class. This allows dynamic method binding at runtime			where the correct methjod implementation is chose on the object type, thus enhancing flexibility and adaptability, making it a fundamental component of polymorphism

> Code Reusability - Developers can utilize existing code by inheriting methods from a base class and customizing them in derived classes. This approach fosters a more streamlined and 		    organized code structure. 

> Maintainability - Overriding promotes a modular design by encapsulating various functionalities within distinct classes. This approach simplifies understanding, maintaining,
		    updating, and extending the code. 

> Design Patterns - Overriding plays a key role in the Template Method Pattern by defining the overall structure of an algorithm in a base class, while permitting subclasses to
		    override specific steps.

> Memory Management - When using inheritence and dynamic memory allocation, virtual destuctors are vital for proper memory management. Overriding the destructor in derived classes
		      ensures that resources allocated by the base and derived classes are correctly deallocated, which prevents memory leaks and ensures clean resource release. 


*/

class Shape {
	public: 
		virtual void draw() const {
			cout << "Drawing a shape" << endl;
		}
};

class Circle: public Shape{
	public: 
		void draw() const override {
			cout << "Drawing a circle" << endl;
		}
};

class Square {
	public: 
		virtual void draw() const{
			cout << "Drawing a Square" << endl;
		}

};

int main(){
	Shape* shapePtr;
	Circle circle;
	Square square;


	shapePtr = &circle;
	shapePtr -> draw();

	shapePtr = &square;
	shapePtr -> draw();

	return 0;

};
