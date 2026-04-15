/* 

----- Structual Design Pattern -----

The structural design patterns is a way of combining or arranging different classes and objects to form larger and complex structures to solve a particular problem in a better way.
These patterns help in simplifying the design by identifying simple ways to realize relationships between entities. 

Take an example of a Building. A building is made up of different parts like roofs, walls, doors, etc. Each part has its own characteristics and functions, but when combined,
they form a complete structure that serves a specific purpose. Similarly, in software, structual design patterns help in combining different classes and objects to create larger
structures that are easier to understand and maintain. 

Structual design patterns are all about how classes and objects are composed to form larger structures. These patterns provide a way to create relationships between objects and classes
in a way that is easy to understand and maintain. 

--- Types of Structural Design Patterns ---

There are 7 main types of structural design patterns: 

 > Adapter Pattern, Converts the interface of a class into another interface that a client expects

 > Bridge Pattern, Separates an abstraction from its implementation so that the two can vary independently

 > Composite Pattern, Composes objects into tree structures to represent part-whole structure

 > Decorator Pattern, Adds new functionality to an object dynamically without changing its structure

 > Facade Pattern, Provides a simplified interface to a complex subsystem

 > Flyweight Pattern, Reduces the memory footprint by sharing common parts of objects

 > Proxy Pattern, Provides a surrogate or placeholder for another object to control access to it. 

--- When to Use Structural Design Patterns? ---

Structural design patterns are useful in the following scenarios: 

> If you want to simplify the design of a complex system by breaking it down into smaller, more manageable parts

> Times when you think you need to improve the flexibility and maintainability of your code by creating relationships
  between objects and classes that are easy to understand and modify. 

> To optimize the performance of your code by reducing memory usage and improving access to objects. 

> When you want to add new functionality to an object dynamically without changing its structure

> To provide a simplified interface to a complex subsystem. 

> If you want to control access to an object by providing a surrogate or placeholder for it. 

> If you want to separate an abstraction from its implementation so that the two can vary independently. 

--- Pros and Cons of Structural Design Patterns --- 

Pros: 

Improves code organization
Enhances flexibility and maintainability
Facilitates code reuse 
Reduces memory usage
Provides clear structure for complex systems

Cons: 

Can introduce complexity 
May lead to over-engineering 
Can impact performance 
May require additional learning 
Can make debugging more difficult 

--- Conclusion --- 

In this chapter, we have discussed the Structural Design Patterns in C++. We have seen the different types of structural design patterns and how they can be used to create flexible and 
maintable code. We have also seen an example of how multiple structual design patterns can be used together to create a complex system. Structural design patterns are an important tool
for any software developer, and understanding them can help you create better software. 
*/

#include <iostream> 
#include <string> 
#include <vector>
#include <memory>
using namespace std; 

class MediaFile { 
  public: 
    virtual string getType() = 0; 
    virtual void play() = 0; 
    virtual ~MediaFile() = default;
};

class MP3File : public MediaFile { 
  public: 
    string getType() { 
      return "MP3";
    }
    void play() { 
      cout << "Playing MP3 file" << endl; 
    }
};

class MP4File : public MediaFile { 
  public: 
    string getType() { 
      return "MP4";
    }
    void play(){ 
      cout << "Playing MP4 file" << endl;
    }
}; 

class MediaAdapter : public MediaFile { 
  private: 
    shared_ptr<MediaFile> mediaFile;
  public: 
    MediaAdapter(shared_ptr<MediaFile> file){
      mediaFile = file;
    }
    string getType(){
      return mediaFile->getType();
    }
    void play(){
      mediaFile->play();
    }
};

class Playlist : public MediaFile{
  private:
    vector<shared_ptr<MediaFile>> mediaFiles;
  public: 
    void add(shared_ptr<MediaFile> file){
      mediaFiles.push_back(file);
    }
    string getType(){
      return "Playlist";
    }
    void play(){
      cout << "Playing playlist:" << endl;
      for (auto& file : mediaFiles){
        file->play();
      }
    }
};

