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

void Optional_mai()
{
    std::optional<int> value;    // not assigned a   value and will be false
    if(value) {}                // FALSE
    if(value.has_value()) {}    // FALSE

    std::optional value2{5};                    // assigned a value and will be true
    // auto value3 = std::make_optional(5);     // this is older wat but valid
    if(value2) {}                               // TRUE
    if(value2.has_value()) {}                   // TRUE
}