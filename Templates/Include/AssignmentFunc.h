#include <cstddef>
#include <utility>

template<typename T>
T Add (T x, T y)
{
    return (x+y);
}



template<typename T, typename >
T ArraySum (const T* arr, size_t arrSize)
{
    T count{0};
    for (size_t i = 0; i < arrSize; i++)
    {
        count += arr[i];
    }
    return count;
}

template< typename T >
T Max(T x, T y)
{
    return x > y ? x : y;
}
// template explict specialization
template<> const char* Max<const char*>(const char* x, const char* y);

template< typename T >
T Max(const T *arr, size_t arrSize)
{
    T count{0};
    for (size_t i = 0; i < arrSize; i++)
    {
        if(count < arr[i])
            count = arr[i];
    }
    return count;
}

template <typename T>
std::pair<T,T> MinMax(const T *arr, size_t arrSize)
{
    std::pair<T,T> pair{};
    if(arrSize)
    {
        pair.first = arr[1];
        pair.second = arr[1];
    }
    for (size_t i = 0; i < arrSize; i++)
    {
        if(arr[i] < pair.first)
            pair.first = arr[i];
        if(arr[i] > pair.second)
            pair.second = arr[i];
    }
    return pair;
}

