#include <iostream> 

using namespace std; 
/*
------ Smart Pointers -----

A smart pointer is a class template that wraps around a raw pointer. It is used in memory management to clear
the dynamically allocated memory automatically when it is no longer needed. This prevents memory leaks and dangling
pointers. They are implemented as templates in the Standard Template Library (STL) 

> Memory leak: we need to manually clear the dynamically allocated memory. Memory leak occurs when the dynamically
               allocated memory is not cleared.

> Dangling Pointer: It is a pointer that points to the memory address that has been cleared earlier but it still
                    pointing to that deallocated memory address. 

--- Types of Smart Pointers ---

Smart pointers are of 4 types that are mentioned below. You need to use <memory> header to use these smart pointers: 

> The auto_ptr Pointer
> The unique_ptr Pointer
> The shared_ptr Pointer
> The weak_ptr Pointer

--- Auto_atr Pointer ---

The auto_ptr is a type of smart pointer that automatically manages memory. It is now deprecated since C++ 11, and removed
in C++ 17 as it uses copy assignments operator to transfer ownership autiomatically without warning and the original pointer becomes null
unexpectedly. This leads to unexpected null pointer access and program can crash. 

--- Unique_ptr Pointer ---

The unique_ptr is a smart pointer that owns only one object at a time. It does not copy the pointers from one pointer to other.
It transfers its ownership using std::move() function and automatically deletes the memory when the pointer goes out of scope.
It solves the problem of auto_ptr and prevent memory leaks. You can use unique_ptr for single ownership. 

--- Shared_ptr Pointer ---

A shared_ptr is a smart pointer that allows multiple pointers to share ownership of the same object using reference counting,
unlike unique_ptr where only one pointer can have the ownership of an object. 

It maintains a reference count to keep a track of number of pointers sharing one object. The reference count is decreased when a
shared_ptr is destoryed and the object is automatically deleted when count reaches zero. You can use shared_ptr when you need multiple owners
of the same object. 

--- Weak_ptr Pointer ---

A weak_ptr is a non-owning pointer to an object. Unlike shared_ptr, it does not increase the reference count of an object,
and it can detect if the object has been destroyed. You can access the object using weak_ptr, but first you must lock the weak_ptr.
By locking you get a temporary shared_ptr. It is used to avoid the circular dependency between shared_ptr objects.





*/

#include <memory>


int main(){

    shared_ptr<int> owner = make_shared<int>(400);
    weak_ptr<int> observer = owner;
    cout << "Ref count: " << owner.use_count() << endl;

    if (auto locked = observer.lock())
    {
        cout << "Obj value: " << *locked << endl;
    }
    owner.reset();
    cout << endl;

    return 0;
     
}