
/**
 * HEADING: StructuredBindings
 * allows initialisation of multiple variables with the elements or members of an object
 * object could be object ora a class / struct or array
 * class members should be public
 * numbers of objects should match the number of anonymous objects created
*/

#include <iostream>
#include <map>

struct person
{
    int m_age{32};
    char m_name[32] = "Kory Smith";
};


void StructuredBindings_main()
{
    person p{};
    // structured bindings for age and name
    auto [ age, name ] = p; // by value
    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl;
    auto &[ ageRef, nameRef ] = p;  // by reference
    ageRef = 79;
    std::cout << "ageRef: " << age << std::endl;
    // will not compile - must be same number of members are elements
    //auto [ age ] = p;                 FAIL
    //auto [ age, name, other ] = p;    FAIL

    // use with par value pairs
    std::pair<char,int> pair{'k',56};
    auto [error,id] = pair;

    // use it in a range based loop with a key/value pair
    // use structured bindings instead of first/second 
    std::map<char,int> arr = {{'g',9},{'d',76},{'a',3},{'r',6}};
    for (auto [err,id] : arr)
    {
        std::cout << "id: " << id << ", err: " << err << std::endl;
    }
    
}