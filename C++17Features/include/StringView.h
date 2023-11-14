
/**
 * HEADING: std::string_view
 * - allows the use of character sequences without allocating memory
 * - can be considered as a kind of reference to a character sequence
 * - can be used where ever a non modifiable string is required
 * - only stores length and data
 * - it is fast and cheap
 * - however it should be used carefully as it can lead to bugs
 * 
 * PROPERTIES: 
 *  - is read only
 *  - data() method can return nullptr or a char sequence without null terminator
 *  - what it can do:
 *  -      - assign new value
 *  -      - swap values
 *  - shrink the length and move ptr to become a subset of chars
 *  - may not have a null terminator
 *  - no allocator support
 * 
*/

#include <iostream>
#include <string_view>

void StringView_main()
{
    using namespace std::string_view_literals;
    // create a string view
    std::string_view sv = "hello world";
    // assign a  string to a sv
    std::string str{"jello"};
    sv = str;
    // create a sv literal
    auto svv = "lfksdjflksd"sv;
    // get the size of the sv
    svv.length();
    svv.size();
    // get the underlying character set
    svv.data();
    // print the current sv subset
    std::cout << svv << std::endl;
    // access index in character set
    svv[0];
    svv.at(0);
    // find a sub set of chars in set
    auto x = svv.find("djf");
    if (x != std::string::npos)
    {
        // do something
    }
    // get a sub string
    auto svvv = svv.substr(0,5);
    std::cout << svv << std::endl;
    // notice that the data() method does not return the substring it returns the full underlying str
    std::cout << svvv.data() << std::endl;
    // remove first  characters from sv
    svv.remove_prefix(2);
    std::cout << svv << std::endl;
    // remove last character from sv
    svv.remove_suffix(2);
    std::cout << svv << std::endl;

    
    
}