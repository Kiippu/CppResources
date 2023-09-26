/**
 * Templates
 * generalizes software components
 * high performance algorithms and classes
 * Done at compile time - no runtime cost
 * 
 * Template Argument Deduction
 * Each function argument is examined
 * Each type is deducted bu the argument used
 * Type conversion are not performed
 * After deduction is done it is instantiated/added to file
 * Manually instantiating can be done like so
 *      Max<int>(5,6);
 * 
 * Template Instantiation
 * Templates act as blueprints only
 * Compiler generated code at compile time using the following ways
 *      - a function is invoked
 *          - Max(9,3)
 *      - taking the address of a function
 *          - int (*func)(int,int) = Max(9,3);
 *      - using explicit instantiation
 *          - template char Max(char y,char x);
 *      - creating explicit specialization
 *          - 
 * 
 * Explicit Specialization
 * template specialized for a particular type
 * must be defined in the .cpp file
 *
 * Perfect forwarding
 * use of std::forward to preserve the information about the types
 * useful to force move constructor
 * as the R value references are passed to a template the arguments are now passed by name to be used.
 * this forces copy constructors.
 * using std::forward will preserve the move constructor if present
*/

#include <iostream>
#include "include/AssignmentFunc.h"
#include "include/NonTypeTemplateArgs.h"
#include "include/VariadicTemplates.h"
#include "include/ClassTemplates.h"
#include "Include/ExplicitSpecializationTemplates.h"
#include "Include/ClassTemplatesPartialSpecialization.h"

int main(int argc, char const *argv[])
{
    
    std::string str0{"C"};
    std::string str1{"B"};

    // with out explicit specialization this return "B" 
    // because it compares addresses and not values
    auto x = Max(str0.c_str(), str1.c_str());

    // run non type template code
    NonTypeTemplate_main();
    // variadic templates example
    VariadicTemplate__main();
    // class templates example
    ClassTemplates_main();
    // Template specialization
    ExplicitSpecializationTemplates_main();
    // Class Templates Partial Specialization
    ClassTemplatesPartialSpecialization_main();
    return 0;
}
