/**
 * 
 * 
*/

class aClass 
{
    int i;
public:
    // adding explicit qualifier disallows Implicit casting
    // explicit aClass(int a){ i = a; };
    aClass(int a){ i = a; };

    // BAD - user type cast to primitive
    operator int(){ return i;}
    // BEST - force only explicit user->primitive casting
    explicit operator float(){ return i;}

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

    /* code */
    return 0;
}
