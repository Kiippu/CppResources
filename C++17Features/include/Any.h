
/**
 * TOPIC: std::any
 * any can be any arbitrary type  in a type safe way
 * replacement for void ptr
 * contains both the value & its type
 * may allocate memory on the heap
 * throws exception of type bad_any_cast on wrong type access
*/

#include <any>
#include <iostream>

void Any_main()
{
    std::any a = 5;
    // can not doe this is we do not know the type
    // std::cout << a << std::endl;

    // we can access it with an any_cast but it throws an exception
    try
    {
        std::cout << std::any_cast<int>(a) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // or we use the value and type methods
    if (a.has_value())
    {
        if (a.type() == typeid(int))
        {
            std::cout << std::any_cast<int>(a) << std::endl;
        }
    }
    
    // now reset it and use it again
    a.reset();
    a = 'd';
    // get by value 
    auto s = std::any_cast<char>(a);
    // get by reference
    auto &f = std::any_cast<char&>(a);
    // get by pointer
    auto g = std::any_cast<char>(&a);
    
}