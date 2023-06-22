
/**
 * Constructor
 *  - no return type
 *  - can be overloaded 
 *  - Default Constructor
 *      - automatically created by the compiler
 *  - Parameterized Constructor
 *      - blocks auto generation by compiler
 *  
 * Destructor
 *  - automatically created by compiler
 *  - cannot be overloaded
*/

// auto generated constructor and destructor
class ConstructorDestructor0{};

// user generated constructor and auto generated destructor
class ConstructorDestructor1 {
    ConstructorDestructor1(){}; 
};

// user generated parameterized constructor and auto generated destructor
class ConstructorDestructor2{
    ConstructorDestructor2(int a){};
};

// user generated parameterized constructor and user generated destructor
class ConstructorDestructor2
{
    ConstructorDestructor2(int a){};
    ~ConstructorDestructor2(){};
};
