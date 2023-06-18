/**
 * Function overloading
 * Key points
 *  - Must have same name
 *  - pointer/refernece arguments also participate
 *  - return type is ignored
 *  - resolved at compiler time
 *      - static polymorphism
 *      - compiler uses name mangling
 *  - Used for programer convienience 
 * 
 * extern "C"
 *  - Compiler directive applied on globel functions and variables
 *  - Supperesses NAME MANGLING on the type  on which it is applied
 *  - can be applied to only one function in a set of overloaded functions
 *  - Allows C++ functions to be called from C or other languages
 *  - Always ensure the .h Declaration and .cpp Definition includes extern "C" unless #included 
*/

int add(int a, int b)
{
    return a + b;
}
float add(float a, float b)
{
    return a + b;
}
// extern "C" will not be name mangled
// extern "C" double add(double a, double b)
// {
//     return a + b;
// }
// As we can only have one extern "C" in a file. 
// To have more than one function use extern "C" to the below:
extern "C"{
    double add(double *a, double *b)
    {
        return *a + *b;
    }
    double subtract(double &a, double &b)
    {
        return a + b;
    }
}

int main(int argc, char const *argv[])
{
    // Add integers
    int a = 1;
    int b = 2;
    int result_a = add(a,b);
    // Add floats
    float c = 1.f;
    float d = 1.f;
    float result_b = add(c,d);



    return 0;
}
