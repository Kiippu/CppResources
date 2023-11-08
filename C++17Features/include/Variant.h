/**
 * HEADING: std::variant
 * 
*/

#include <variant>
#include <iostream>
#include <string>

void Variant_main()
{
    try
    {
        std::variant<std::string,int,char> v{'f'};  // construct variant as a char
        auto val = std::get<char>(v);               // get value from variant via type
        val = std::get<2>(v);                       // get value from variant via 2nd index

        auto activeIndex = v.index();

        auto p = std::get_if<std::string>(&v);
        auto p1 = std::get_if<char>(&v);
        if(p) // if(p == nullptr)
        {
            std::cout << "not active" << std::endl;
        }
        else if(p1)
        {
            std::cout << "value: " << *p1 << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}