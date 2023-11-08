/**
 * HEADING: if constexpr 
 *  - for templates where all conditionals will be evaluated at compile time 
 *  - this will make only the valid conditional statements be compiled and the 
 *      rest of the conditional will be omitted. 
 *  - All code must be valid code
*/
#include <type_traits>

template<class T>
void Print(T const & value)
{
    // without this constexpr all conditional statements will be evaluated
    // and some will not be  correct for particular types
    constexpr if( std::is_pointer_v<T>)
    {
        // do something with the pointer
    }
    else if constexpr( std::is_array_v<T>)
    {
        for (auto v : value)
        {
            // do some thing with array value
        }
    }
    else{
        // to some thing with other values
    }
}

void ConstexprIf_main()
{
    // because this Print() is constexpr it can be used for all of these valid
    Print(5);
    int val{5};
    Print(val);
    Print(&val);
    int a[] = {1,2,3,4,5};
    Print(a);

}