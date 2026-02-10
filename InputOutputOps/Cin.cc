#include <iostream>

using namespace std;

/* 
---- Cin ----

The predefined object cin is an instance of istream class that accepts user input.
The cin object is said to be attached to the standard input device, which usually is the keyboard. 

The cin object is used in conjuction with the stream extraction operator (>>).
This extracts the data from the input stream and stores the extracted data in a variable. 

Single Var: 
-----------
cin >> variable_name; 

For Multiple Vars:
------------------
cin >> variable1 >> variable2 >> ... >> variableN;


*/

// --- Function example used for inputting Array ---
int ArrayFunc(){
    
    int arr[5];
    int n = 5;

    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++){
        //Taking array elements input
        cin >> arr[i];
    }

    cout <<"Array elements: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;

}

int main(){

    //--- Example assigning vars with cin ---

    int num1;
    cout << "Enter number num1: ";
    cin >> num1;
    cout << "Num1: " << num1 << endl;

    int num2, num3;
    cout << "Enter the numbers num2 and num3: ";
    cin >> num2 >> num3;
    cout << "Num2: " << num2 << ", Num3: " << num3
         <<"\n"
         << "Sum: " << num1 + num2 + num3 << endl;

    //---- Function for Array Input ----
    ArrayFunc();
    
    return 0;

}

/* 

Commonly used cin functions: 

Functions     | Definition
______________|_________________________________________________________
cin.get()     | The cin.get() function reads a single char including 
              | whiespace from input stream.
______________|______________________________________________________
cin.getline() | It reads a line of test from user input along with
              | whitespaces until it reaches end of the line or newline 
              | character.
______________|______________________________________________________
cin.read()    | You can specify the number of characters you want to 
              | read from input stream using cin.read() function. 
______________|______________________________________________________
cin.putback() | The cin.putback() function puts a character back into the input
              | stream that was removed after using get() function to read the 
              | character.
______________|______________________________________________________
cin.peek()    | It looks at the next character in the input stream without
              | removing it unlike the get() function that removes the char.
______________|______________________________________________________
cin.good()    | It checks the state of input stream and returns true 
              | if the input stream is in a good state with no errors. 
______________|______________________________________________________
cin.bad()     | It checks the state of input stream and returns true if an error
              | occurs in the stream that can not be recovered. 
______________|______________________________________________________
cin.fail()    | It returns true for failed operations on the input stream. 
______________|______________________________________________________
cin.clear()   | It clears the error flags of the stream and reset it to good state.
______________|______________________________________________________
cin.ignore()  | The cin.ignore() function is used to skip and discard characters
              | from the input buffer so they are not read by the next input operation.
______________|______________________________________________________
cin.gcount()  | It returns the count of characters by the last unformatted input operation
              | including whitespace.
______________|______________________________________________________
cin.seekg()   | It used in file handling to set the position of the get pointer
              | in the input stream. It is generally used with file streams
              | (ifstreams)
______________|______________________________________________________
cin.eof()     | It returns true upon reaching end of file in the input stream.
______________|______________________________________________________
cin.rdbuf()   | It returns the stream buffer object of cin that can be used to read
              | from or redirect the input stream directly.
______________|______________________________________________________

*/
