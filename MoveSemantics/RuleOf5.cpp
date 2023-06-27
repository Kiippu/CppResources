
/**
 * Rule of five 
 * Required when class:
 *  - has resources (pointers, file handle, socket)
 *  - needs to assign values on creation or delete on destruction
 * 
 * This deems the class to have ownership semantics and you must provide the following
 *  - Destructor
 *  - Copy constructor
 *  - copy assignment operator
 *  - Move constructor
 *  - Move assignment operator
 * 
 * This ensures proper handling of resources
 * 
 * Rule of Zero:
 * If a class had no ownership semantics. do not create any. let the compiler 
 * synthesize the functions.
 * 
*/
#include "iostream"

/// rule of zero
// All fuctions are synthesized
class Integer0
{
public:
    Integer0(){};
    Integer0(int i) {std::cout << "Integer(int i)" << std::endl;}
    void print(){};
};

/**
 * Rule of 5 - Custom Copy Constructor/Assignment
 * compiler deleted the following automatically:
 *  - Move Assignment 
 *  - Move Constructor
*/
class Integer1
{
public:
// copy constructor
    Integer1(const Integer &other){ std::cout << "Integer(const Integer &other)" << std::endl; }
//  and/OR copy assignment
    Integer1 & operator=(const Integer1&){ std::cout << "copy assignment" << std::endl; }
// 0r default impl or either
    // Integer1 & operator=(const Integer1&) = default;
    // Integer1(const Integer1 &other) = default
};

/**
 * Rule of 5 - Custom move constructor
 * compiler deleted the following automatically:
 *  - Copy Assignment 
 *  - Copy Constructor
 *  - Move Assignment
*/
class Integer3
{
public:
/// Move Constructor
    Integer3(Integer &&other) { std::cout << "Integer(Integer &&other)" << std::endl; }
};

/**
 * Rule of 5 - Custom move assignment
 * compiler deleted the following automatically:
 *  - Copy Assignment 
 *  - Copy Constructor
 *  - Move Constructor
*/
class Integer4
{
public:
/// Move Constructor
    Integer4 & operator=(Integer4 &&other) { std::cout << "move assignment" << std::endl; }
    // 0r default impl
    // Integer4 & operator=(Integer4 &&other) = default;
};

/**
 * Rule of 5 - Custom Destructor
 * compiler deleted the following automatically:
 *  - Move Assignment
 *  - Move Constructor
*/
class Integer
{
public:
// destructor
    ~Integer(){ std::cout << "~Integer()" << std::endl; }
};
