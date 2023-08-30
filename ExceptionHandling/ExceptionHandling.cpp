/**
 * Exception Handling
 * handles errors in programs
 * exist outside of the normal functioning of the program
 * Requires immediate handling
 * 
 * Mechanism
 * - try : scope of exception handling, can contain other try-catch statements
 * - throw: throws the exception from the try block
 * - catch: handles the exception but catching its object, multiple catch statements can exist
 * 
 * Stack Unwinding
 * happens when an exception has happened and the local stack is destroyed
 * good for local variables bad for all other variables
 * no logic is ran after the exception so all manual delete's will create memory leaks
 * Note: class destructors are not ran is stack unwinding 
 *      therefore all manual deallocation logic in the destructor is not ran. 
 *      exceptions in destructors should not exit logic but be handled for safety they will CTD
 * Solution: rely on RAII for heap variables like smart ptrs 
 *              smart points and some STL containers are exception safe vector, string
 * 
 * 
 * noexcept specifier
 * indicates to compiler that this method/function does not throw exceptions
 * compiler will optimize code by forgoing the unwinding code
 * an exception in this scope will CTD
 * avoid using this when using libraries in the same scope.
*/
#include <iostream>
#include <stdexcept>
#include <exception>
#include "Include/NoExcept.h"


void processStuff()
{
    int *pArray = nullptr;// try to add value to pointer
    //tets ptr
    if(!pArray)
    {
        throw std::runtime_error("Failed to allocate memory");
    }
    // do stuff
}

int main(int argc, char const *argv[])
{
    // can write each excaption out to be caught
    // do this if more specific logic is needed
    try
    {
        processStuff();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << std::endl;
    }
    // each exception has a base class of std::exception
    // use this to catch all cases
    try
    {
        processStuff();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // this catches every exception even un documented ones - AVOID THIS!
    try
    {
        size_t count = 3;
        for (size_t i = 0; i < count; i++)
        {
            // nested exception handling
            i+=5;
            try
            {
                if(i > count)
                {
                    throw std::runtime_error("count is too high");
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                throw;
            }
        }
        
        processStuff();
    }
    catch (...)
    {
        std::cerr << "This is an error" << std::endl;
    }

    run();
    return 0;
}
