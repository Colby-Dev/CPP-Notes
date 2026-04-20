/* 

----- State Design Pattern -----

The State Design Pattern is a way to let an object change how it behaves when its state changes. Instead of using lots of if-else or switch statements, you put the different behaviors into separate state classes.
This makes your code cleaner and easier to understand.

In this pattern, you have a mian class (called the context) that keeps track to its current state. When something happens, the context asks its current state what to do. If the state changes, the context just
switches to a different state object. This way, the object can change its behavior at any time, just by changing its state. 

--- Key Components of the State Design ---

The state design pattern is made up of a few important parts that work together to make your code easier to manage and understand.

1) Context - This is the main object you work with. 

*/