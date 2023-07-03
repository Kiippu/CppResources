/**
 * explicit and implicit casting
 * adding explict qualifier disallows Implicit casting
 * implicit casting
 *  - compiler casts primitive into user defined - unnecessary or unwanted copying could occur
 * Explicit casting
 *  - force the compiler to only cast using explicit casting
 *      - no copy constructor is used in the creation of this object
 * 
*/

class aClass 
{
    bClass k;
    int i;
public:
    // adding explicit qualifier disallows Implicit casting
    // explicit aClass(int a){ i = a; };
    aClass(int a){ i = a; };

    // BAD - user type cast to primitive
    operator int(){ return i;}
    // BEST - force only explicit user->primitive casting
    explicit operator float(){ return i;}

    // cast this class in to another to aClass can be cast to bClass
    operator bClass()
    {
        return k;
    }
};

class bClass
{
    int x{5};
};

int main(int argc, char const *argv[])
{
    // Explicit initialization
    aClass a1{ 5 };
    // Initialization
    // Implicit cast initialization
    aClass a2 = 5;
    // Assignment
    // Implicit cast initialization
    a1 = 7;

    // Implicit cast - user type into primitive
    // can be confusing as it is kinda ambagious
    int b = a1;
    // best to force explicit casting
    float b = static_cast<float>(a1);

    // this is possible if aClass has th operator == overloaded
    // bClass bTemp;
    // if (a2 == bTemp)
    // {   
    // }

    /* code */
    return 0;
}
