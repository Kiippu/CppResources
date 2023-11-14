/**
 * HEADING: std::variant
 * 
*/

#include <variant>
#include <iostream>
#include <string>

struct visitorFn
{
    void operator()(const std::string) const
    {}
    void operator()(const int) const
    {}
    void operator()(const char) const
    {}
};

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

        // how to actively modify the members of with a visitor objects
        std::visit( []( auto &x){
            // fid type and make the type decay to the R value as it is a reference
            using T = std::decay<decltype(x)>;
            // check types abd do stuff it type
            if constexpr (std::is_same_v<T, int>)
            {
                x = 1000;
            }
            else if constexpr (std::is_same_v<T, std::string>)
            {
                x = "hello";
            }
            else if constexpr (std::is_same_v<T, char>)
            {
                x = 's';
            }
        }, v); 

        // Can also be done with a functor struct
        std::visit(visitorFn{} , v);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}