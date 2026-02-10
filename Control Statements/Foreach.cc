#include <iostream> 

using namespace std;

/*
----- ForEach Loop -----
Foreach loop is also known as a range-based for loop, 
it's a way to iterate over elements through a container,
without performing extra initialization. 

The foreach loop iterates over all elements of the given container, 
first by applying the code logic then moving to the next element. 

----- Foreach Loop with Non-container Type -----
Generally, foreach loop is used for iteration for containers types like 
Array, vector, List, Deque, Set, and Map etc... 

but it can also be used for Non-container type (iterable)


*/

#include <vector> 

int main(){

    vector <int> digits = {10,20,30,40,50};
    for (int& num: digits){
        num *= 2;
    }

    for (int& num : digits){
        cout << num << " ";
    }
    cout<<endl;

    return 0 ;
}