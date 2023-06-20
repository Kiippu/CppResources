 /**
  * Namespace
  *  - named declaration region used for declaring types
  *  - types are not visible  outside the namespace
  *  - prevents name clashes
  *  - helps modularize code
 */

namespace math 
{
    void add(){};
    // nested name space
    namespace imperial
    {
        void add(){};
    }
}
// anonymous namespace
namespace
{
    void log(){};
}
 
 int main(int argc, char const *argv[])
 {
    // access to anonymous namespace
    log();
    // access to math namespace
    math::add();
    // import one function name space
    using math::add;
    // use imported function
    add();
    // access to nested imperial namespace
    math::imperial::add();
    return 0;
 }
 