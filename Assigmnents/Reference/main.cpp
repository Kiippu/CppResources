/**
 * Implement the following functions 
 * //Add two numbers and return the result through a reference parameter
 *      void Add(int a,int b, int &result) ;    
 * //Find factorial of a number and return that through a reference parameter
 *      void Factorial(int a, int &result) ;    
 * //Swap two numbers through reference arguments
 *      void Swap(int &a, int &b) ;
 * 
*/

#include <iostream>

void Add(int a,int b, int &result)
{
    result = a + b;
}

void Factorial(int a, int &result)
{
    int factorial{a};
    do { result += factorial; } while(factorial--);
}

void Swap(int &a, int &b)
{
    int c{a};
    a = b;
    b = c;
}

int main(int argc, char const *argv[])
{
    // swap 2  pointer values
    int a{2};
    int b{7};
    std::cout << a << " " << b << std::endl; 
    // pass Referents to function
    Swap( a, b);
    std::cout << a << " " << b << std::endl; 
    // fatorial
    int result{0};
    int fac{3};
    // pass Referents to function
    Factorial( fac, result);
    std::cout << "Factorial of " << fac << " is " << result << std::endl; 
    return 0;
}
