
/**
 * Initializer list - std::initializer_list
 *  - Lightweight proxy object that represents ab array of objects
 *  - constructed automatically from a braced list of elements {9,9,0}
 *      - auto
 *      - ranged for loop
 *      - constructor
 *      - function
 *  - not a true container bit similar behaviour
 *  - provides access to its elements through iterators 
 *  - #include <initializer_list>
*/

#include <initializer_list>
#include <assert.h>

class AClass
{
    int  m_list[10];
public:
    AClass(std::initializer_list<int> items)
    {
        assert(items.size() < 10);
        // use iterators in initializer_list
        auto itr = items.begin();
        while (itr != items.end())
        {
            m_list[0] = *itr++;
        }
        // ranged for loop 
        for( const auto x : items)
        {
            // do something
        }
        itr = items.begin();
        for (int i = 0 ; i < items.size(); ++i)
        {
            m_list[i] = *itr++;
        }

    }
};

int main(int argc, char const *argv[])
{
    // user defined initializer list where previously not possible.
    AClass obj{23,23,43,2};
    /* code */
    return 0;
}
