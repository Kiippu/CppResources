/**
 * HEADING: std::optional
 * new type that may or may not be given a value
 * will return std::nullopt == false/nullptr/0 if has no value
 * can be deep copied
 * can not store references it will be undefined behavior
 * may throw std::bad_optional_access
 * 
 * 
*/

#include <optional>
#include <iostream>

void Optional_main()
{
    std::optional<int> value;    // not assigned a   value and will be false
    if(value) {}                // FALSE
    if(value.has_value()) {}    // FALSE

    std::optional value2{5};                    // assigned a value and will be true
    // auto value3 = std::make_optional(5);     // this is older wat but valid
    if(value2) {}                               // TRUE
    if(value2.has_value()) {}                   // TRUE

    // can reassign a new value to a optional
    if(value.value_or(-1) != -1)    {
        // 2 ways to get the value out of optional
        std::cout << "no value in optional found" << std::endl;
    }  // get value or give 9999
    value = 10;
    if(value.value_or(-1) != -1)    {
        // 2 ways to get the value out of optional
        std::cout << "nullopt value so we return" << *value << " instead" << std::endl;
        std::cout << "nullopt value so we return" << value.value() << " instead" << std::endl;
    }  // get value or give 9999
    if(value) {}                    // value is now valid
    value = std::nullopt;           // assign a null back to optional
    value.reset();                  // or like this
}