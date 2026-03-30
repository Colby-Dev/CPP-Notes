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





*/