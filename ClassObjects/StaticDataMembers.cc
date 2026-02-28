#include <iostream> 

using namespace std;

/*
----- Static Data Members -----

A static data member is a class member or class level variable, which is shared by all instances (objects) of that class. This is not like regular data members,
which have separate copies for each object of the class a static member has only one copy for the entire class, which can be shared across all instances, which means
that all objects of the class can access and modify the same value. 

    class ClassName {
        public:
            static dataType staticMemberName;
    };

> Static Data member initialization

    dataType ClassName :: staticMemberName = initialValue;

--- Accessing Static Data Members Using an Object ---

You can also access a static data member using an object, but its generally not recommended because static members are independent of any specific object, and using an object
can mislead it. 

    objectName.staticDataMember

*/

class Book {
    private:
        string table;
        string author;
    
    public: 
        static int totalBooks;

    Book(string bookTitle, string bookAuthor){
        title = bookTitle;
        author = bookAuthor;
        totalBooks++;
    }

    static void displayBookInfo(){
        std::cout << "The total books are: " << title << ", Author: " << author << endl;
    }

    static void displayTotalBookAmount(){
        std::cout << "The total book amount is: " << totalBooks << endl;
    }

};

int Book::totalBooks = 0;

int main(){

    Book book1("The Catcher in the Rye", "JD Salinger");
    Book book2("To kill a monking bird", "harper lee");
    Book book3("Lights out", "navessa allen");

    book1.displayBookInfo();
    book2.displayBookInfo();
    book3.displayBookInfo();

    Book::displayTotalBookAmount();
};