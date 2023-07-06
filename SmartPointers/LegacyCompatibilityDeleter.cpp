/**
 * Create a custom deleter
 * WHY:     legacy may use malloc and it requires free() to be used on it.
 *          a default smart pointer does not call the correct deleter for malloc
 * RESULT:  undefined behaviour. memory leaks.
 * FIX:     add a custom deleter for the smart pointer
 * 
 * NOTE:    std::make_ functions can nt implement custom deleter functions
 * 
 * IMPORTANT:   using std::make_ functions will reduce calls to new and delete
 *              using new for a smart pointer will result in another call(new) 
 *              to create the smart pointer control block(ref_count etc).
 * 
*/
#include <cstdlib>
#include <iostream>
#include <memory>

struct Free
{
    void operator()(int*p)
    {
        free(p);
        std::cout  << "struct: pointer freed" << std::endl;
    }
};
void MallocFree(int* p)
{
    free(p);
    std::cout  << "func: pointer freed" << std::endl;
}


int main(int argc, char const *argv[])
{
    // create a unique ptr out with defined allocation of resources
    
    // Unique ptrs
    // use a struct where acceptable
    std::unique_ptr<int, Free> p1 {(int*) malloc(4), Free{}};
    // functions area also acceptable
    std::unique_ptr<int, void(*)(int*)> p2 {(int*) malloc(4), MallocFree};

    // shared ptrs - remove shared_ptr temp arg
    std::shared_ptr<int> p3 {(int*) malloc(4), Free{}};
    // functions area also acceptable
    std::shared_ptr<int> p4 {(int*) malloc(4), MallocFree};

    return 0;
}
