
/**
 * Static Assert
 * 
 * Evaluates expressions at compile time
 * Accepts an expression and a user defined message
 * If the expression fails it return the message
*/

#include <type_traits>
#include <string>
#include <iostream>

// modify this function to include static asserts 
template <typename T>
void checkType_assert() {
    static_assert( std::is_integral<T>::value, "T is an integral type" );
    static_assert( std::is_floating_point<T>::value, "T is a floating type" );
    static_assert( std::is_arithmetic<T>::value, "T is neither an integral or floating type" );
}

void StaticAssert_main()
{
    // commenting out as they are designed to fail in compilation
    // checkType_assert<int>();    // Prints: T is an integral type.
    // checkType_assert<double>(); // Prints: T is a floating point type.
    // checkType_assert<char>();   // Prints: T is an integral type.
    // checkType_assert<std::string>(); // Prints: T is neither integral nor floating point type.
}
