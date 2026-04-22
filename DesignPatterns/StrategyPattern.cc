/*

----- Strategy Design Pattern -----

THe strategy design pattern is a simple and powerful way to organize your code when you have different ways to perform the same task. It defines a family of algorithms, places each one in its own seperate class,
and lets you switch between them easily. This means you can change the algorithm's behavior without touching the main code that uses it. 

Strategy Interface - This defines a common method that every strategy (or algorithm) must follow. It ensures that all the different strategies can be used in the same way, no matter which one you choose.

Concrete Strategies - There are the actual classes that implement the Strategy Interface. Each one represents a different algorithm or way of doing a task. For exmaple, one strategy might calculate the fastest route, 
                      while another finds the most scenic one.

Context - This is main class that uses one of the strategies. It keeps a reference to a Strategy object and asks it to perform the task. The Context doesn't care which strategy it's using,
          it just knows that it can call the same method on any of them. 

In short, the Strategy Design Pattern helps you write code that's easier to update, cleaner to read and simpler to extend. When a new way of doing something comes along, you can just add a new strategy class instead
of rewriting your existing code. 

--- Implementation of the Strategy Design --- 

In this section, we will see how to implement the Strategy Design Pattern in C++ with a simple and easy-to-understand example. We'll create a Context class that can use different stratefies to perform a calculation.
Each strategy will be written in its own class, making the program flexible enough to switch between different strategies whenever needed it without changing the rest of the code. 

1) Define the strategy Interface - 

*/