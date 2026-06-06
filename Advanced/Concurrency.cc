/*
 
----- Concurrency -----

Concurrency refers to the ability of a system which allows one to manage multiple tasks or processes at any given time and allow them to progress without waiting for each other to complete. Tasks in concurrent systems may overlap in execution, which ultimately helps improve efficiency and resource utilization, especially in environments such as operating systems, databases, and web servers. 

--- Concurrency in C++ --- 

In C++, concurrency helps developers create applications that can perform multiple operations and helps in improving their efficiency and responsiveness. Concurrency can occur in various ways, like through multi-threading, asynchronous programming, or distributed systems. 

--- Concurrency vs Parallelism --- 

Concurrency is the ability to manage different tasks or processors in an overlapping manner, meaning that tasks can be startd, executed and complete at different times. This means the tasks may not run simultaneously but their execution can overlap in time, making efficient use of available resources.

Whereas, Parallelism is a subcategory of concurrency where tasks are actually executed concurrently on different processors or cores in order to improve performance. 

Concurrency deals with structure and task management, while parallelism focuses on simultaneous execution to speed up computation. 

--- Threads ---

A thread represents the smallest unit of execution within a process, which allows multiple tasks to run independently and concurrently. The <thread> library is used to create and manage threads. Threads run in parallel and share the same memory space

(see Example 1)

--- Thread Synchronization in C++ --- 

Thread synchronization in C++ is a mechanism that manages the access of shared resources by multiple threads to prevent data races, inconsistencies, and undefined behavior. It makes sure that only one thread can access a resource at a time or that specific operations are performed in a specific order, especially when multiple threads are executing concurrently. 

--- Key Methods of Thread Synch in C++ ---

The following are some of the key methods of thread synch in C++

  > Mutex (<mutex> Library), A mutex (mutual exclusion) is a locking mechanism that limits access to shared resources so that only one thread can access it at a time. If one thread locks a mutex, other threads trying to lock the same mutex are blocked until the mutex is unlocked. 

 	std::lock_guard, is a basic automatic lock manager, which locks a mutex when created and unlocks it when it goes out of scope.


	std::unique_lock, is more flexible and allows manual unlocking and re-locking

  > Condition Variables (<condition_variable> Library), It enables threads to wait until certain conditions are met, which facilitates communication between threads. 

  	std::condition_variable, is typically used with std::uinque_lock <std::mutex> and provides wait(), notify_one(), and notify_all() functions for blocking and resuming threads based on specific conditions. 

  > Atomic Variables (<atomic> Library), Atomic operations are another way to ensure thread safety witout using mutexes. 

  	An atomic variable guarantees taht any read-modify-write operations are down without interference from other threads, which can be useful for simple data types like ints or bools. 

	Atomic operations include fetch_add, load, store, and compare_excahnge

  > Sempahore, A semaphore is a synchronization primitive that manages access to shared resources in a concurrent system, like multithreaded or multiprocess environment. A semaphore is essentially an integer value that controls access to resources. It operates on two main operations: 

  	Wait (P or acquire): Decreases the semaphore value. 

	Signal (V or release): Increases the semaphore value. 

--- Asynchronous Execution in C++ --- 

In C++, std::future and std::promise are mechanisms which are used for asunchronous programming that help manage data or result in communication between threads, allowing one thread to provide a result (via std::promise) and another to retrieve it (via std::future). These are part of the C++ 11 standard and are found in the <future> header. 

--- Key Components for Asynchronous Programming --- 

 > std::future, It represents a future result of an asynchronous operation. A thread can retrieve the result from a future once it's available, and if the result isn't ready, the std::future::get() - Function will block until the value is computed. 

 > std::promise, It is used to set a value or an exception that can later be retrieved via a std::future.

 > std::async, It is used to launch a task asynchronously. It returns a std::future that can be used to obtain the result of the task once it's completed. 
  

*/

// Example 1

#include <iostream>
#include <threads>

void hello(){
	std::cout << "Hello Learner!" << std::endl;
}

int EX1(){
	std::thread t(hello);
	t.join(); // Wait for the thread to finish 
}

int main() { 
	EX1();

	return 0;
