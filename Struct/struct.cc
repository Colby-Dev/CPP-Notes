#include <iostream> 

using namespace std; 

/*
----- C++ Structures (struct) -----

C++ structures are user-defined types to group related variables of different types togehter under a single
name. Structures are also known as structs. 

Structures are used to represent a record. 

--- Defining a Structure ---

To define a structure, you must use the struct statement. The struct statement defines a new data type, with more than one member. 

struct [tag]{
};

The tag is optional and each member definition is a normal variable definition. At the end of the struct
definition, before the final semicolon, you can specify one ore more structure variables but this is optional

--- Accessing Structure Members --- 

To access any members of a stucture, we use the member access operator(.). The member access operator is 
coded as a period between the structure variable name and the structure member that we wish to access. You
would use struct keyword to define variables of structure type.  


--- Structure as Function Arguments ---

You can pass a structure as a function argument in very similar way as you pass any other variable or pointer. 
You would access structure variables in the similar way as you accessed in this example: 

	struct example {char name[50]}
	strcpy(example.name, "test");

--- Pointers to Structures ---

You can define pointers to structures in very similar way as you define pointer to any other variables as follows:
	
	struct example *struct_pointer;

Now you can store the address of a structure variable in the above defined pointer variable. To find the address
of a structure variable, place the '&' operatior before the structure's name as follows: 

	struct_pointer = &Example1;

To access the members of a structure using a pointer to that structure, you must use the -> operator: 

	struct_pointer -> title; 


--- typedef keyword ---

There is an easier way to define structs or you could "alias" types you create. Example:

	typedef struct {
		char title[50];
		char author[50];
		char subject[100];
		int  book_id;
		} Books;

*/

#include <cstring>

void printBook( struct Books *books);

struct Books {
	char title[50];
	char author[50];
	char subject[100];
	int book_id;

};

int main(){
	struct Books Book1;
	struct Books Book2;
	
	// Book 1 specification
	strcpy(Book1.title, "Learn Cpp");
	strcpy(Book1.author, "Test");
	strcpy(Book1.subject, "C++");
	Book1.book_id = 78473875;

	//Book 2 specification
        strcpy(Book2.title, "Cpp");
        strcpy(Book2.author, "Test2");
        strcpy(Book2.subject, "C++ too");
        Book2.book_id = 23444231;

	printBook(&Book1);

	printBook(&Book2);	

	return 0;
}

int printBook(struct Books *book){

	cout << "Book title: " << book -> title << endl;
	cout << "Book author: " << book -> author << endl;
	cout << "Book subject: " << book -> subject << endl;
    cout << "Book ID: " << book -> book_id << endl;	


}



