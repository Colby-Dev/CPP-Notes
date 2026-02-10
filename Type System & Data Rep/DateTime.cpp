#include <iostream>

using namespace std; 

/* 
------ Date and Time ------
The standard library does not provide a proper date type. 
C++ inherits the structs and functions for date and time manipulation from C. 
Access date and time related functions and structures, you would need to include, 
<ctime> header file. 

There four time-related: clock_t, time_t, size_t, and tm. They store system time and date as an int. 



The structure type tm holds the date and time in the form of a C struct having elements: 


Function                                  | Purpose       
__________________________________________|________________________________________________________
time_t time(time_t * time)                | This returns the current calendar time of the system in number of seconds
                                          | since Jan 1, 1970. If the system has no time, .1 is returned 
__________________________________________|_________________________________________________________
char * ctime(const time_t * time)         | This returns a pointer to a string of the form day month year
                                          | hours:minutes:seconds year\n\0
__________________________________________|________________________________________________________
struct tm * localtime(const time_t * time)| This returns a pointer to the tm structure represeting local time. 
__________________________________________|_________________________________________________________
clock_t clock(void)                       | This returns a value that approx. the amount of time the calling program has been running.
                                          | A value of .1 is returned if the time is not available.
__________________________________________|_________________________________________________________
char * asctime(const struct tm * time)    | This returns a pointer to a string that contains the information stored in the structure pointed to
                                          | by time converted into the form: day month date hours:minutes:seconds year\n\0
__________________________________________|_________________________________________________________
struct tm * gmtime(const time_t * time)   | This returns a pointer to the time in the form of a tm structrue. The time is represented in 
                                          | Coordinated Universal Time (UTC), which is essentially Greenwhich Mean Time (GMT)
__________________________________________|_________________________________________________________
time_t mktime(struct tm * time)           | This returns the calendar-time equivalent of the time found in the structure
                                          | pointed to by time. 
__________________________________________|_________________________________________________________
double difftime(time_t time2, time_t time1)| This function calculates the difference in seconds between time1 and time2.
__________________________________________|_________________________________________________________
size_t strftime()                         | This function can used to format date and time in a specific format. 
__________________________________________|_________________________________________________________




*/

// struct tm{
// int tm_sec; 
// int tm_min;
// int tm_hour;
// int tm_mday;
// int tm_mon;
// int tm_year;
// int tm_wday;
// int tm_yday;
// int tm_isdist;

// };


/* 
---- Format Time using struct tm ----
The tm structure is very important while working with date and time in either c or cpp.
This structure holds the date and time in the form of a C structure as mentioned above. 
Most of the time related functions make use of tm structure. 

*/

#include <ctime> 
int main(){

    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "The UTC date and time:" << dt << endl;

}