/**
 * HEADING: Feature Test Macros
 * Feature test macros in C++ are a way to check the availability 
 * of certain language or library features. They are predefined 
 * macros that correspond to various C++ language and library 
 * features introduced in C++11 or later.
*/
#include <iostream>

#ifdef __has_include
#   if __has_include(<filesystem>)
#       include <filesystem>
        namespace fs = std::filesystem;
#   else 
#       include <experimental/filesystem>
        namespace fs = std::experimental::filesystem;
#   endif
#endif

void FeatureMacros_main()
{
    fs::path p{"C:"};

    // year and month this feature was added to language YYYYMM
    std::cout << "Year YYYYMM inline var was added: " << __cpp_inline_variables << std::endl;
    std::cout << "Year YYYYMM lambdas were added: " << __cpp_lambdas << std::endl;
}