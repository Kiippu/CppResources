/**
 * 
 * TOPIC: Function Pointers
 *      must be global and can not hold state
 *      Dynamic in nature 
 *      can not be inlined by complier
 *      can be specified at runtime
 *      Difficult for compiler to optimize
 * 
 * 
 * TOPIC: Function Object
 *      an object with an overloaded operator
 *      resembles a function
 *      can be used as a callback instead of a function pointer
 *      more efficient than function pointers
 *      usually implemented as structs
 *      Must be specified at compile time
 *      can be optimized by compiler and inlined
 *      faster then function pointers
 *      can store state
 * 
*/

template<class T, int size, class comparator>
void sortFunc(T(&arr)[size], comparator func)
{
    for (int i = 0; i < size; i++)
    {
        /* do sorting blah blah and use function */
        func(arr[i], 8);
    }
}

bool LessThan(int x, int y)
{
    return x < y;
}

struct Functor
{
    bool operator()(int x, int y)
    {
        return x < y;
    }
};

void FunctionObject_main()
{
    // use lessThan function
    LessThan(2,5);
    // use object function
    Functor func;
    func(2,5);
    // use array sort with both object function and function pointer
    int ar[] = {2,5,3,1,7,4};
    sortFunc( ar, func);
    sortFunc( ar, LessThan);
}