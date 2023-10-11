
/**
 * Lambda Expression
 * - Defines an anonymous function object
 * - Short cut to a function
 * - can be passed as an argument
 * - can accept parameters and arguments
 * - Replaces function objects
 * - internally implemented as a nameless function object
 * 
 * Syntax:
 * Lambda Introducer-> [](<args>) <mutable Specification> <excp specification> -> <trailing return type> { <lambda body> }
 * 
 * 
 * capture list - only for local variables
 * - can be by copy, reference
 * - use [&] to capture all variable above lambda by reference
 * - use [=] to capture all variable above by copy
 * - use [=, &Sum] to capture one variable Sum by reference but all others by copy 
 * - use [&, Sum] to capture one variable Sum by copy and others by reference 
 * - use [this] to capture class object if lambda is in class method
*/

#include <iostream>
#include <memory>


template<class T, int size, class Callback>
void ForEach(T(&arr)[size], Callback fn)
{
    std::cout << "ForEach callback" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        fn(arr[i]);
    }
    
}

void LambdaExpression_main()
{
    // lambda function object
    auto fn0 = []()
    {
        std::cout << "Lambda has been called" << std::endl;
    };
    fn0();
    // lambda with specific type args
    auto fn1 = [](int x, int y) // -> <return type> is optional 
    {
        std::cout << "Lambda with specific type args called" << std::endl;
        return x + y;
    };
    fn1(2, 3);
    // generic lambda
    auto fn2 = [](auto x, auto y) -> double
    {
        std::cout << "Generic lambda has been called" << std::endl;
        return x + y;
    };
    fn2(0.3f, 5u);
    // use lambda in callback
    int array[] = {1,3,5,7};
    ForEach(array,
        [](auto x)
        { 
            std::cout << x << std::endl;
        }
    );
    // use lambda in callback
    int offset0 = 8;    // passed by copy - read only variable // compiler implements it with a constant modifier
    int offset1 = 2;    // passed by reference - will increment
    ForEach(array,
        [offset0, &offset1](auto x)
        { 
            std::cout << "offset0: " << offset0 << " - offset1: " << ++offset1 << " result " << (x + offset0 + offset1) << std::endl;
        }
    );
    // make all capture variables mutable
    std::cout << "all captures are mutable/copy: "  << std::endl;
    ForEach(array,
        [offset0](auto x) mutable
        { 
            std::cout << "offset0: " << ++offset0 << std::endl;
        }
    );

    // Generalize lambda capture C++14
    //  - create variables in capture list
    //  - can have same name as as initializer
    auto ptr = std::make_unique<int>(9);
    auto doSomething = [ptr = std::move(ptr)](int x) mutable
    {
        ptr = nullptr;
    };
    doSomething(67);

}


