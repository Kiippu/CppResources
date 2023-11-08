
#include "include/Attributes.h"
#include "include/FeatureMacros.h"
#include "include/ifSwitchInitialization.h"
#include "include/StructuredBindings.h"
#include "include/ClassTemplateArgumentDeduction.h"
#include "include/Folding.h"
#include "include/ConstexprIf.h"
#include "include/Optional.h"
#include "include/Variant.h"
/**
 * HEADING: inline variables
 *  allows for globals to break the one definition rule and cause linker errors.
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

// Constant expression  lambdas
auto sum = [](int y, int x){
    return x+y;
};
auto result = sum(2,3);             // this will not implicitly be constexpr - load value form address of sim()
constexpr auto result2 = sum(2,3);   // this is implicitly a constexpr

/**
 * HEADING: Copy Elision/Omission
 *  - c++17 this is now mandatory in compilers
 *      - Mandatory in initializing expressions where you initialize an L-value with a R-value
 *  - Copy Elision, also known as copy omission, is a compiler optimization 
 *    technique that avoids unnecessary copying of objects. It enhances the 
 *    efficiency of code by saving both space and time, making 'return by value' 
 *    or 'pass-by-value' feasible in practice. It's important to note that copy 
 *    elision is the only optimization that can change observable side-effects.
*/

int main(int argc, char const *argv[])
{
    // shows attribute for complier warnings
    Attributes_main();
    // feature macros
    FeatureMacros_main();
    // if switch initialization
    ifSwitchInitialization_main();
    // structured bindings
    StructuredBindings_main();
    // Class template argument deduction
    ClassTemplateArgumentDeduction_main();
    // template folding
    Folding_main();
    // Constexpr if
    ConstexprIf_main();
    // Optional types
    Optional_main();
    // variant types
    Variant_main();
    return 0;
}
