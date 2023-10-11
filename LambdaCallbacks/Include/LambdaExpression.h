
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
*/

#include <iostream>

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

}


