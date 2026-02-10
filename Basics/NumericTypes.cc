#include <iostream>

using namespace std;

//Used to handle numerical data like integers (signed and unsigned)
int main(){
    //Int, takes numeric values from -2^31. Takes 4 bytes in the memory
    int test_var;

    //---- Variations on Int ----

    //short int, used for smaller number as it only takes 2 bytes in memory (-2^15)
    short int test_short;

    //long int, used for bigger numbers, with memory space of 4bytes up to 8bytes
    long int test_long;

    //long long int, used for large numbers with memory of 8bytes to 16bytes (-2^63)
    long long int test_long_long;

    //unsigned int, used to store only non-negative value, and take up the same space
    unsigned int un_test_var;

    //unsigned short int, used to store only non-negative value and take up same memory as a long it
    unsigned long int un_test_long_var;

    //unsigned long long int, used to store only non-negative valye and take up the same as a long long int
    unsigned long long int un_test_long_long_var;

    //---- other numeric data ----

    //float, used for floating point elements, takes up 4 bytes of memory.
    float float_name = 1.120123;

    //double, used to store floating point elements, with double precision as compared to float. Takes up 8 Bytes.
    double double_name = 3.231;

    //long double, takes up 16 bytes
    long double long_double_name = 1234.123456789;

};