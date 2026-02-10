#include <iostream>

using namespace std; 
/*
----- Recursion Function -----
Recusion is a programming technique where a function calls itself over again and again with 
modified arguments until it reaches its base case, where the recursion stops.

It breaks a problem down into smaller, more manageable sub-problems, recusion allows for elegantand better solutions to complex problems. 

A recursive function is a function which is particularly used for recursion where a function
calls itself, either directly or indirectly, to address a problem. It must include at least one
base case to terminate the recursion and one recursive case where the function invokes itself. 

1) Base Case - Its a case where recursion stops or ends after reaching that particular condition

2) Recursive Case - Its a case where a function calls itself over again with decremented value
		    until and unless it reaches its base case. 

----- Calling Recursive Function -----
Calling a recursive function is just like calling any other function, where you will use the
function's name and provide the necessary parameters in int main() body.

----- Types of Recursion -----

1) Direct Recursion: 

> Simple Direct Recursion, the function calls itself with a simpler or smaller instance of the 
			   problem. It is user for solving problems like factorial calculation, 			   fibonacci sequence generation, etc. 


> Tail Recursion, A form of direct recursion where the recursive call is the last operation in
		  the function. It is used for solving accumlative calculations and list
		  processing problems. 

> Head Recursion, The recursive call is made before any other operation in the function.
		  Processing occurs ater the recursive call returns. It is used for tree 
		  traversales and ouput generation.

> Linear Recursion, Each function call generates exactly one recursive call, forming a linear
		    chain of calls. It is used for simple counting or summing. 

2) Indirect Recursion: 

> Mutual Recursion, two or more functions call each other in a recursive manner, forming a 
		    cyclic dependency. It is used for even and odd number classification and
		    grammar parsing. 

> Nested Recursion, The nested recursion is a form of indirect recursion where a recursive
		    function makes another recursive call inside its own recursive call. It is 
	    	    used for solving complex mathematical and algorithimic problems. 

----- Advantages of Recursion -----

> Simplicity and reduced boilerplate code, Recursion helps to simplify solving problems which
					   have a built-in recursive structure, like working
					   with trees or solving combinatorial problems by
					   making it easier to understand and implement.

> Backtracking, Recursion is a great fit for backtracking algorithms, which involve examining
		all possible solutions to find one which meets certain criteria.

> Effective solutions for divide-and-conquer problems, Recursion works perfectly for 
						       divide-and-conquer algorithms, where 
						       problems are broken down into smaller
						       sub parts and are solved one by one. This						       makes problem solving more efficient and 						       easy. 

----- Recursion vs Iteration -----

Recustion is a method where a function calls itself over again and again with modified argumentsuntil it reaches its base case which stops the recursion. Whereas, an iteration involves using loops (for, while, do-while) where it involves repeatedly executing blocks of code until a
certain condition is met. 

> Recursion: 

	- The problems which can be divided into similar sub-problems or which have natural
	  recursive patterns such as tree traversal or combinational tasks and manageable path.

	- When a user needs simple, cleaner and readable code as it provides clean proper
	  arranged code. 
	
> Iteration: 

	- Iterative solutions are generally more efficient in terms of memory and execution time	  and which involves simple repetition. 

	- For the problems which require simple looping because iteration is usually more
	  straightforward and efficient. 
	
	- Iteration is more stable for problems which require a large number of repetitions, as 	  it doesn't risk stack overflow. 

----- Limitations of Recursion -----

Memory Consumption, Each recursive call adds a new frame to the call stack, which can consume
		    a significant amount of memory. 

Stack Overflow Risk, As recursion relies on call stack to manage function calls, Deep recursion
		     can lead to stack overflow as it exceeds the stack size limit. 

Performance Overhead, Recursive functions can be less efficient than iterative ones because they 		      involve overhead from multiple function calls and managing the call stack, 		      which can significantly impact performance, especially with deep recursion

Debugging Complexity, Debugging recursive code can be challenging, especially when dealing with 
		      complex recursion or large recursion depths. It needs careful handling of 		      base cases and logic. 

Space Complexity, Due to the call stack in recursion, it can lead to consuming alot of memory. 



*/



int main(){

// Tail Recursion
int factorial(int n, int result = 1){

	if (n <= 1){
		return result;
	} else {
		return factorial(n - 1, n * result);
	}
}	

}
