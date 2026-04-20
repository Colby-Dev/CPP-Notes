/* 
----- Iterator Design Pattern-----

Iterator Design Pattern is a behavioral design pattern that helps you move through a collection of items-like a list, stack, or tree without needing to know how the collection is built on the inside.
Imagine you have a box full of different objects, and you want to look at each one, one by one, without having to open the box and figure out how everything is arranged. The Iterator pattern gives you
a simple way to do this, making it easier to work with all kinds of collections in a consistent way. 

This pattern is especially useful when your application uses many different types of collections. Instead of writing separate code to loop through each type, you can use the Iterator pattern to create
a common approach for all of them. This not only saves time but also makes your code cleaner and easier to update in the future. If you ever change how a collection is stored, you won't have to rewrite 
the code that goes through its elements. 

For example, think about a music playlist app. You might have playlists stored as arrays, linked lists, or even trees. With the Iterator pattern, you can play songs from any playlist in the same way, 
without worrying about how the playlist is organized behined the scenes. This makes your program more flexible and much easier to maintain. 

--- Key Components of the Iterator Pattern --- 

> Iterator - Think of this as a guide that helps you move through a collection, one item at a time. The Iterator lays out the basic step you need, like checking if there are more items to see (hasNext()) 
             and getting the next item in line (next()). It doesnt care what's inside the collection or how it's organized. It just gives you a simple way to look at each item, one after another. 

> Concrete Iterator - This is the actual helper that knows how to walk through a specific collection, like a list of books or a playlist of songs. It remembers where you are in the collection and knows how
                      to get to the next item. For example, if you're flipping through a stack of cards, the Concrete Iterator keeps track of which card you're flipping through a stack of cards, the Concete Iterator
                      keeps track of which card you're on and helps you move to the next one. 

> Aggregate - This is just a fancy word for any group or collection of items like a bookshelf full of books or a playlist full of songs. The Aggregate sets the rule that says, "If you want to look through my items, 
              you have to use an iterator." It provides a way to get an iterator so you can start exploring the collection. 

> Concrete Aggregate - This is the actual collection itself, like your bookshelf or playlist. It holds all the items and knows how to give you an iterator that can walk through them. For example, your Library class
                       might store a bunch of book titles and provide a way to get an iterator so you can read each title one by one. 

--- Implementation of Iterator Pattern ---

In this example, we will implement the Iterator Design Pattern to traverse a collection of books in a library. We will take example of a simple library system where we have a collection of books and we want to iterate
through them using the Iterator pattern. 

1) Start by outlining what it means to move through a collection, and define an Iterator interface. This interface should include methods such as next() to get the next item, and hasNext() to check if there are more items to visit. 

2) Next, create a class that actually implements this Iterator interface for your specific collection. For example, if you have a list of books, this class will know how to go from one book to the next and keep track of 
   where you are in the list. 

3) Then, define an Aggregate interface. This is just a way to say that any collection (like a library of books) should be able to give you an iterator so you can look through its items.

4) After that, make a concrete class for your collection-like a Library class for books-that implements the Aggregate interface. This class will store your items and provide a way to create an iterator for them. 

5) Finally, use the iterator in your main code to go through the collection. The beauty here is that you don't need to know how the collection is organized inside; you just use the iterator to access each item one by one, making your
   code much simpler and easier to manage. 

--- Pros and Cons of Iterator Patterns --- 

Pros: 

    > Makes it much easier to go through complex data structures, like trees or graphs without having to understand their internal details

    > Encourages code reuse by letting you use the same approach to loop through different types of collections.

    > Keeps the way collections are stored private, so you can change internal structure later without affecting the rest of your code. 

Cons: 

    > Sometimes, having many different iterator classes can make the codebase more complicated than necessary. 

    > The extra layer of abstraction can slow things down a bit, especially if you only need to work with simple collections. 

    > For very simple collections, using an iterator might be overkill and less efficient then direct access. 

--- When to Use the Iterator Pattern --- 

If you're working with several different types of collections-like arrays, linked lists, or trees-and you want to loop through all of them using the same simple approach, the Iterator pattern is a great fit. It saves you from having to
write separate, complicated code for each collection type. 

When you want to keep the inner workings of your collections private, so that the rest of your program doesn't need to know or care about how the data is actually stored. This means you can change the way your collection is built later, 
without breaking any code that uses it. 

If you need to offer multiple ways to go through your collection-like moving forward, backward, or skipping certain items-the Iterator patter lets you create different iterators for each scenario, making your code more flexible and user-friendly.

When your collections are complicated, such as trees or graphs, and you want to make it as easy as possible for someone else (or even yourself in the future) to use them. The Iterator pattern hides the complexity and lets you focus on what
you want to do with each item, not how to get to it. 

--- Conclusion --- 

The Iterator Design Pattern is a practical and widely used solution for working with collections of data. By separating the way you access items from the way they are stored, it makes your code more flexible, easier to maintain, 
and ready for future changes. Whether you're building a playlist app, managing a library of books, or working with any kind of collection, the Iterator pattern helps you keep your code clean and adaptable.


*/

#include <iostream>
#include <vector> 
using namespace std; 

// Iterator Interface
class Iterator { 
    public: 
        virtual bool hasNext() = 0; 
        virtual string next() = 0;
};

// Concrete Iterator
class BookIterator : public Iterator { 
    private: 
        vector<string> books;
        int position;
    
    public: 
        BookIterator(vector<string> b) : books(b), position(0) {}
        bool hasNext() override { 
            return position < books.size();
        }
        string next() override {
            return books[position++];
        }
};

// Aggregate Interface 
class Aggregate { 
    public: 
        virtual Iterator* createIterator() = 0;
};

class Library : public Aggregate { 
    private: 
        vector<string> books;
    public: 
        void addBook(string book){
            books.push_back(book);
        }
        Iterator* createIterator() override { 
            return new BookIterator(books);
        }
};

// Client Code
int main() { 
    Library library;
    library.addBook("The Great Gatsby");
    library.addBook("1984");
    library.addBook("Limitless");

    Iterator* iterator = library.createIterator();

    cout << "Books in the Library: " << endl;
    while (iterator->hasNext()) { 
        cout << iterator->next() << endl;
    }

    delete iterator;
    return 0;
}
