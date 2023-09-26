/**
 * Type Traits
 * a way to gather and manipulate information about types at compile time
 * there are three types of trait catagories
 * 1. unary type traits. 
 *      these describe a property of a type 
 *      e.g std::is_pointer<T> checks if pointer
 * 2. binary type traits. 
 *      these describe a relationship between types 
 *      e.g. std::is_same<T,U> checks if 2 types are the same
 * 3. transformation type traits.
 *      these modify a property of a type 
 *      e.g. std::add_pointer<T> makes the type a pointer T*
*/

#include <type_traits>
#include <string>
#include <iostream>

template <typename T>
void checkType() {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "T is an integral type.\n";
    } else if constexpr (std::is_floating_point<T>::value) {
        std::cout << "T is a floating point type.\n";
    } else {
        std::cout << "T is neither integral nor floating point type.\n";
    }
}

// Template Meta Programming
/** NOTE: his code results inb this error meassage:
 * TypeTraits.h:34:61: fatal error: template instantiation depth 
 * exceeds maximum of 900 (use ‘-ftemplate-depth=’ to increase the maximum)
 * 
 * Reason:  indicates that the compiler has reached its limit of nested template 
 * instantiation. This limit is set to prevent infinite recursion or excessive 
 * memory usage during compilation.
 * This error usually appears when your code has deep recursion in template instantiation, 
 * which is often the case in template metaprogramming or complex template usage boost.org.
 * 
 * Solution:
 * To resolve this error, you can increase the maximum template instantiation depth using 
 * the compiler flag -ftemplate-depth=NNN, where NNN is the new limit. For instance, 
 * if you want to increase the limit to 2000, you would use -ftemplate-depth=2000
 */ 
template <unsigned N>
struct factorial {
    static constexpr unsigned value = N * factorial<N - 1>::value;
};

int TypeTraits_main() {
    checkType<int>();    // Prints: T is an integral type.
    checkType<double>(); // Prints: T is a floating point type.
    checkType<char>();   // Prints: T is an integral type.
    checkType<std::string>(); // Prints: T is neither integral nor floating point type.

    std::cout << "Factorial of 4 is :" << factorial<4>::value << std::endl;;
    
    return 0;
}