/* 
 
----- Signal Handling -----

Signals are the interrupts delivered to a process by the operation system which can terminate a program prematurely. You can generate interrupts by pressing Ctrl+C on the system. 

There are signals which can not be caught by the program but there is a following list of signals which you can catch in your program and take appropriate actions based on the signal. These signals are defined in C++ header file <csignal> 

--- The signal() Function --- 

C++ signal-handling library provides function signal to trap unexpected events. Following is the syntax of the signal() function: 

	void (*signal (int sig, void (*func)(int)))(int); 

Keeping it simple, this function receives two arguments: first argument as an integer which represents signal number and second argument as a pointer to the signal-handling function. 

Let us write a simple C++ program where we will catch SIGINT signal using signal() function . Whatever signal you want to catch in your program, you must register that signal using signal function and associate it with a signal handler. Examine the following example: 

(see Example 1) 

--- The raise() Function --- 

You can generate signals by function raise(), which takes an integer signal number as an argument and has the following syntax. 

	int raise(signal, sig);

Here, sig is the signal number to send any of the signals: SIGINT, SIGABRT, SIGFPE, SIGLL, SIGSEGV, SIGTERM, SIGHUP. Following is the example where we raise a signal internally using raise() function as follows: 

	(see Example 2)


*/

// Example 1
#include <iostream>
#include <csignal> 

using namespace std; 

void signalHandler (int signum) {
	cout << "Interrupt signal (" << signum << ") recived. \n";

	exit(signum);
}

int EX1(){

	signal(SIGINT, signalHandler);

	while(1) {
		cout << "Going to sleep...." << endl;
		sleep(1);
	}

}

void signalHandler2 (int signum) {
	cout << "Interrupt signal (" << signum << ") recieved.\n";

	exit(signum)

}

int EX2() { 

	int i = 0; 
	singal(SIGINT, signalHandler2);

	while(++i) { 
		cout << "Going to sleep..." << endl;
		if(i == 3) { 
			raise(SIGINT);
		}
		sleep(1);
	}

	return 0;
}
