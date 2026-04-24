/* 

----- Visitor Design Patterns -----

The visitor design pattern is a way of writing code that helps you in adding new features or new types of work to your classes
withour changing those classes again and again. 

In programming, we often create classes that represent some real things like shapes, items, files, animals, or anything else. 
These classes usually have some basic data in them and maybe one or two simple functions. 
But as the project grows, we want to do more and more operations with these classes. If we keep adding all the new operations 
directly inside these classes, the classes become very big and hard to read. The visitor pattern helps us avoid making our classes
messy. 

This pattern is used when you have many different objects and want to keep adding new tasks for those objects. If you try to put every
single task inside the object classes, then those classes will become too large. The visitor pattern keeps things neat by moving into separate
visitor classes. 

--- Components of the Visitor Pattern --- 

> Visitor Interface - This is like a plan that tells which types of objects the visitor can work with. It has one visit function for each 
                      element time. Such as, visitCircle(), visitSquare(), etc. 

> Concrete Visitor - These are actual classes that do real work. For example, an AreaCalculator visitor will calculate area. A PerimeterCalculator
                     visitor will calculate perimeter. A DrawingVisitor, will draw shapes on screen, and so on.

> Element Interface - This is the main interface that all elements must follow. it usually contains only one function: accept(visitor). Every concrete
                      element must implement this. 

> Concrete Element - These are your real objects. For example, Circle, Square, and Rectangle. They store simple data like radius or side length and implement 
                     the accept method. 
        
> Object Structure - This is usually a list or collection of elements. The visitor will go through this structure and visit each element one by one.

> Client - The client sets everything up. it creates shapes, creates visitors, and asks the elements to accept the visitors. 

--- Conclusion ---

*/

#include <iostream>
#include <vector> 
#include <cmath>
using namespace std; 

// Forward declarations
class Circle;
class Square; 
class Rectangle;

class Visitor {
    public: 
        virtual void visit(Circle* c) = 0;
        virtual void visit(Square* s) = 0;
        virtual void visit(Rectangle* r) =0;

};

class Shape {  
    public: 
        virtual void accept(Visitor* v) = 0;
};

class Circle : public Shape { 
    private:
        double radius;
    public: 
        Circle(double r) : radius(r) {}
        double getRadius() { return radius; }
        void accept(Visitor* v) override { 
            v->visit(this);
        }
};

class Square : public Shape { 
    private: 
        double side;
    public: 
        Square(double s) : side(s) {}
        double getSide() { return side; }
        void accept(Visitor* v) override { 
            v->visit(this);
        }
};

class Rectangle : public Shape {
    private: 
        double width, height;
    public: 
        Rectangle(double w, double h) : width(w), height(h) {}
        double getWidth() {return width; }
        double getHeight() { return height; }
        void accept(Visitor* v) override {
            v->visit(this);
        }
};

class AreaClaculator : public Visitor { 
    public: 
        void visit(Circle* c) override { 
            double area = M_PI * c->getRadius() * c->getRadius();
            cout << "Area of Circle: " << area << endl;
        }

        void visit(Square* s) override { 
            double area = s->getSide() * s->getSide();
            cout << "Area of a Square: " << area << endl;
        }

        void visit(Rectangle* r) override {
            double area = r->getHeight() * r->getWidth();
            cout << "Area of a Rectangle: " << area << endl;
        }
};

class PerimeterCalculator : public Visitor { 
    public: 
        void visit(Circle* c) override {
            double perm = (2 * M_PI) * c->getRadius();
            cout << "Perimeter of a Circle: " << perm << endl;
        }

        void visit(Square* s) override { 
            double perm = s->getSide() * 4;
            cout << "Perimeter of a Square: " << perm << endl;
        }

        void visit(Rectangle* r) override { 
            double perm = (r->getHeight() * 2) + (r->getWidth() * 2);
            cout << "Perimeter of a Rectangle: " << perm << endl;
        }
};

int main() { 
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Square(6));
    shapes.push_back(new Rectangle(8,8));

    AreaClaculator area;
    PerimeterCalculator perm;

    for (Shape* shape : shapes) { 
        
    }

}