/// Function
int square(int x)
{
    return (x * x);
}

/**
 * Macro
 *  - test substitution
 *  - error prone due to above
 *  - does not have an address
 *  - can not be used for functions on classes
*/
#define subtract(x, y) (x *-y)

/**
 * Inline Function
 *  - Must be defined in the header
 *  - Requests the compiler to replace the call with  its test body
 *      - request may fall if
 *          - a large function
 *          - too many conditionals 
 *          - recursive
 *          - functions invoked through pointers
 *      - modern compilers may inline without asking to.
 *  - Function overhead is reduced
 *      - stack memory  for arguments not required
 *      - No need to save address
 *  - has function schematics
 *  - has an address
 *  CON:
 *      - Excessive inlining may increase binary size
 * */ 
inline int add(int x, int y)
{
    return (x + y);
}

int main(int argc, char const *argv[])
{
    int g{5};
    /// Use of non inline function
    // Behavior: This has over head where the main function must call 
    // the fuction and hold an address to return to. 
    square(g);

    /// Macro
    // Behavior: text substitution. After compilation the code (g -g) will be added  to this code block
    subtract(g, g);

    /// Inline function
    // 
    add(g,g);
    return 0;
}
