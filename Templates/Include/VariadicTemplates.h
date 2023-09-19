
#include <iostream>

// this is the - Base case function
// the base case function breaks the recursion
void Print(){};
void PrintAgain(){};

// Template parameter pack
template<typename T, typename... params>
// Function parameter pack
void Print(T first, params... args)
{
    std::cout << first << std::endl;
    Print(args...);
}

// Template parameter pack
template<typename T, typename... params>
// Function parameter pack
/**
 * NOTE: && is used to make all left values be passed as left values 
 * and all right values be passed as right values.
*/
void PrintAgain(T&& first, params&& ... args)
{
        std::cout << first;
    if(sizeof...(args) /* OR sizeof(params)*/ != 0)
        std::cout << ", ";
    // perfect forwards values
    PrintAgain(std::forward<params>(args)...);
}


void VariadicTemplate__main()
{
    std::cout << "VariadicTemplate__main" << std::endl;
    Print(1, 4.5, 3L, 'K', "Kory");
    PrintAgain(1, 4.5, 3L, 'K', "Kory");
    // this function is recursive and builds on the stack
    /*
    1. Print(1, 4.5, 3L, 'K', "Kory")
    2. Print(4.5, 3L, 'K', "Kory")
    3. Print(3L, 'K', "Kory")
    4. Print('K', "Kory")
    5. Print("Kory")
    6. Print()                          // NOTE this exit function must exist!
    
    */
}