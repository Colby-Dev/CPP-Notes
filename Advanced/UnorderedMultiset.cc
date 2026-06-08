/*

----- Unordered Multiset -----

> std::unordered_multiset, An unordered_multiset is a container by the Standard Template Library (STL) in C++, which stores elements without any particular order an allows multiple occurrences or duplicate values of the same element. The <unordered_set> header file is used for both unordered_set and unordered_multiset containers. 

	#include <unordered_set>
	std::unordered_multiset<type> container_name;

(see Example 1)

--- Member Functions of unordered_multiset ---

> The insert() function, the insert() function is used to add one or more elements to the unordered_multiset, 
			 allowing duplicity. 

			 unordered_multiset<type> ums;
			 ums.insert(element);
			 ums.insert({element1, element2, ...});

> The find() function, The find() function is used to check if an element exists in the unordered_multiset. 
		       It returns an iterator to the element if found otherwise, it returns end().

		       auto it = ums.find(element);
		       // Returns iterator to element or ums.end()

> The count() function, The count() function returns the number of occurrences of an element in the 
			unordered_multiset. Since this function allows duplicacy, it will return the total 
			count of that element in the container.

			size_t count = ums.count(element);
			// Returns number of occurrences of element
			
> The erase() function, The erase() function removes one or more elements from the unordered_multiset. 
			You can remove specific elements by value or use an iterator to remove a single element.
			For duplicates, only one occurrence will be removed for each call.

			ums.erase(elements); // Removes one occurrence of element
			ums.erase(it); // Removes the element at iterator 'it'
			ums.erase(ums.begin(), ums.end()); // Removes all elements in the range 
							
> The find()/count() function, This function will check if an element exist in the container. 

			       list.count(element); // for lists
			       string.count(substring); // for strings

> The size() function, The size() function returns the number of elements currently in the unordered_multiset.

		       size_t size = ums.size();
		       // Returns the number of elements in the set

> The begin()/end() function, To iterate you can use iterators or range-based loops over the elements in an 
			      unordered_multiset. begin() and end() are used for accessing the first and last 
			      elements.

			      for (auto it = ums.begin(); it != ums.end(); ++it) 
			      { // Accessing each element via *it }

--- unordered_set vs. unordered_multiset --- 

> unordered_set, A container that stores unique elements only, no duplicates are allowed. 

> unordered_multiset, A container that allows multiple occurrences of the same element

--- Average Time Complexity of unordered_multiset --- 

> unordered_multiset, implemented by using a hash table data structure. This results in fast access because 
		      elements are hased into "buckets" based on their hash values. This unordered_multiset 
		      provides constant time complexity i.e., O(1), for some generic operations like lookups, 
		      insertions, and deletions.

> Hash collisions, lead to the worst complexity O(n). This is because, in a collision, multiple elements are
		   hashed into the same bucket, which results in a linear search through all the elements in 
		   that bucket. tis overall results in a significant degradation of performance. 

*/

#include <unordered_set>
#include <iostream> 
#include <string>

using namespace std; 


// Example 1
int EX1() { 
	// Declare unordered_multisets for integers and strings 
	
	unordered_multiset<int> ums_int = {1, 2, 3, 3};
	unordered_multiset<string> ums_str = {"apple, banana", "apple"};

	// Display both sets together (merged display) 
	cout << "Merged unordered_multiset (Integers and Strings): ";
	for (const auto& elem : ums_int) {
		cout << elem << " ";
	}

	for (const auto& elem : ums_str) { 
		cout << elem << " ";
	}
	cout << endl;

}


