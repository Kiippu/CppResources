#include <sstream>


enum class Case
{
    SENSITIVE, 
    INSENSITIVE
};
 
size_t Find(
 const std::string &source,         //Source string to be searched
 const std::string &search_string,  //The string to search for
 Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
 size_t offset = 0 ) {                //Start the search from this offset
     //Implementation
     // exit early offset is larger than source length
    const auto S_LENGTH = source.length();
    if(offset >= S_LENGTH)
        return std::string::npos;
    
    if(searchCase == Case::INSENSITIVE)
    {
        int count = 0;
        const auto SS_LENGTH = search_string.length();
        char s, ss;
        // exit on finding substribg or end of source string index
        while ( count != SS_LENGTH && offset < S_LENGTH)
        {
            s = source.at(offset);
            ss = search_string.at(count);
            if(s == tolower(ss) || s == toupper(ss))
                ++count;
            else
                count = 0;
            // get new values
            ++offset;
        }
        if(count == SS_LENGTH)
            return (offset - count);
        return std::string::npos;
    }
    else
        return source.find(search_string);
    


 
     /*
     return position of the first character 
     of the substring, else std::string::npos
     */
}

int main(int argc, char const *argv[])
{
    /* code */
    const std::string source{"Hello Worl World"};
    const std::string search_string{"WOrRLD"};
    auto pos = Find(source, search_string, Case::INSENSITIVE, 0 );
    return 0;
}
