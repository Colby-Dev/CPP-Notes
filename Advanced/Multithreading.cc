/* 

----- Multithreading -----

Multithreading is a specialized form of multitasking and a multitasking is the feature that allows your computer to run two or more programs concurrently. In general, there are two types multitasking: process-based and thread-based. 

Process-based multitasking handles the concurrent execution of programs. Thread-based multitasking deals with the concurrent execution of pices of the same program. 

A multithreaded program contains two or more parts that can run concurrently. Each part of such a program is called a thread, and each thread defines a separate path of execution. 

Before C++11, there is no built-in support for multithreaded applications. Instead, it relies entirely upon the operating system to provide this feature. 

This tutorial assumes that you are working on Linux OS and we are going to write multi-threaded C++ program using POSIX. POSIX Threads, or Pthreads provides API which are available on many UNIX-like POSIX systems such as FreeBSD, NetBSD, GNU/Linux, MAC OS X and Solaris. 

--- Creating Threads --- 

The following routine is used to create a POSIX thread: 

	#include <pthread.h>
	pthread_create (thread, attr, start_routine, arg)

Here, pthread_create creates a new thread and makes it executable. This routine can be called any number of times from anywhere within your code. The maximum number of threads that may be created by a process is implementation dependent. Once created, threads are peers, and may create other threads. THere is no implied heirarchy or dependency between threads. 

--- Terminating Threads --- 

There is following routine which we use to terminate a POSIX thread: 

	#include <pthread.h>
	pthread_exit (status)

Here pthread_exit is used to explicitly exit a thread. Typically, the pthread_exit() routine is called after a thread has completed its work and is no longer required to exist. 

If main() finishes before the threads it has created, and exits with pthread_exit(), the other threads will continue to execute. Otherwise, they will be automatically terminated when main() finishes. 


*/

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
	long tid;
	tid = (long)threaded;
	cout << "Hello World! Thread ID, " << tid << endl;
	pthread_exit(NULL); 
}
