/**
 * Non type Template Arguments
 * an expression that is computed at compile time in a template arg list
 * must be constant(address,ref,integral, nullptr, enum)
 * used in std::begin and std::end
*/
#include <iostream>

template<int size>
void PrintSize()
{
    char buf[size];
    std::cout << size << std::endl;
}

// adding argument size to function
// template<typename T>
// T Sum(T *pArr, int size)
// {
//     T result{};
//     for (size_t i = 0; i < size; i++)
//     {
//         result += pArr[i];
//     }
//     return result;    
// }

// using non type template args to specify size 
template<typename T, int size>
T Sum(T (&pArr)[size])
{
    T result{};
    for (size_t i = 0; i < size; i++)
    {
        result += pArr[i];
    }
    return result;    
}


void NonTypeTemplate_main()
{
    PrintSize<7>();
    int arr[]{1,2,3,4};
    int (&ref)[4] = arr;
    //int sum = Sum(arr, 4);
    int sum = Sum(arr);
    std::cout << sum << std::endl;
}
