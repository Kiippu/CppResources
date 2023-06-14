 
 /**
  * Implement the following functions using pointer arguments only
  * //Add two numbers and return the sum
  *     int Add(int *a, int *b) ;    
  * //Add two numbers and return the sum through the third pointer argument
  *     void AddVal(int *a, int *b, int *result); 
  * //Swap the value of two integers
  *     void Swap(int *a, int *b) ;  //Swap the value of two integers
  * //Generate the factorial of a number and return that through the second pointer argument
  *     void Factorial(int *a, int *result);       
  * 
 */
 
 #include <iostream>
 
 int add(int *a, int *b)
 {
    return (*a + *b);
 }

 void addVal(int *a, int *b, int *result)
 {
    *result = (*a + *b);
 }

 void swap(int *a, int *b)
 {
    int c = *a;
    *a = *b;
    *b = c;
 }

 void Factorial(int *a, int *result)
 {
    int factorial{*a};
    do { *result += factorial; } while(factorial--);
    
 }

 int main(int argc, char const *argv[])
 {
    // swap 2  pointer values
    int a{2};
    int b{7};
    std::cout << a << " " << b << std::endl; 
    swap( &a, &b);
    std::cout << a << " " << b << std::endl; 
    // fatorial
    int result{0};
    int fac{3};
    Factorial( &fac, &result);
    std::cout << "Factorial of " << fac << " is " << result << std::endl; 
    return 0;
 }
 