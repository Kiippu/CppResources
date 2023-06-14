/// Uniform initalization
// single syntax to initalize all types
/**
 *  Advantages:
 *      - Uniform int for all types
 *      - Forces initialiazation of both scalar and array types
 *      - Show errors when incompatable types are initalized
 *      - Prevent narrowing conversions e.g using a a float to init an int 
*/

#include <string>

int main()
{
    /// uninitalized
    int b;
    char arr1[8];
    
    /// Copy Initialization - Should be avoided!
    int a = 5;
    std::string s1 = "str";
    char arr2[8] = {'\0'};
    char arr3[8] = {'a','b','c'}; // Aggrgate Initalization
    char arr4[8] = {"abcd"};

    /// Uniform Initalization
    // UNCOMMON - Direct initalization
    int b1(5); 
    std::string s2("str");
    // Value initialization
    int b1{};
    char e1[8]{};
    // Direct initialization
    int b2{5};
    char e2[8]{"Hello"};

    
}
