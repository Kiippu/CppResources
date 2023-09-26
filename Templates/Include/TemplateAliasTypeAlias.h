#include <vector>
const char * GetErrorMessage(int erroNo)
{
    return "Error#";
}

// parameter type is tough to recognize easily - it is a function pointer
// best to use a using alias 
void ShowError_0(const char *(*pFunc)(int))
{}
// using type def
using pFunc = const char *(*)(int);
void ShowError_1(pFunc)
{}
// can also be used with templates
template<class T>
using pFunc_T = const char *(*)(T);
// or
template<class T>
using pFunc_array = std::vector<std::vector<T>>;
// using both of these type aliasing
void ShowError_2(pFunc_array<int>, pFunc_T<float>)
{}

