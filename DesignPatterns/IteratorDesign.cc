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

> Concrete Iterator - 


*/