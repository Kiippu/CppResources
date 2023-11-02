
#include "include/Attributes.h"
#include "include/FeatureMacros.h"
#include "include/ifSwitchInitialization.h"

/**
 * HEADING: inline variables
 * allows for globals to break the one definition rule and cause linker errors.
*/
// these globals if in a header will be inlined to each 
//      file that uses it and no linker errors will occur
inline int c{0};
inline static int f{0};
class testInline
{
    inline static int l {0};    // must state inline here
    int x = 9;                  // implicitly is inline!
    constexpr static int k{0};  // implicitly is inline!
};

// nested namespaces
namespace A{                // old way
    namespace B{ 
        namespace C{ 
            void Foo(){};
        }
    }
}
namespace A::B::C           // NEW WAY!
{ 
    void Foo1(){}; 
}

int main(int argc, char const *argv[])
{
    // shows attribute for complier warnings
    Attributes_main();
    // feature macros
    FeatureMacros_main();
    // if switch initialization
    ifSwitchInitialization_main();
    return 0;
}
