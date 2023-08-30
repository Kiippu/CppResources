#include <iostream>
#include <vector>

// compiler knows this may not have an exception in it
// do this as we are using the std::cout lib and it may throw an exception
void Test(int x) noexcept(false)
{
    std::cout << x << std::endl;
}
// tells compiler to use the noexcpt use in the function Test()
int Sum(int x, int y) noexcept(noexcept(Test(x)))
{
    Test(x);
    return x + y;
}

// we can trust this does nto throw an exception
// make this function with true
// if this function wa dto throw it would result in CTD
float multi(float x, float y) noexcept // noexcept(true)
{
    return x * y;
}

class A 
{
    std::vector<int> v{};
public:
// hover this destructor - by default it is noexcept [inline A::~A() noexcept]
    A(){};
    ~A(){
    }

    /**
     * NOTE: it is good to use noexcept on move constructor!!! 
     *  as it allows members of args(&&other) holding STL contains to use move schematics over copy if it can.
     *  in some operations stl containers may need to make copies of these objects but if the option to 
     *  move is available it will take this instead. 
     *  BUT only if the noexcept specifier is true!!!
    */
    A(A&&other) noexcept {}
	A & operator =(A &&a) noexcept {return *this;}
};

void run()
{
    A a{};
    // see the Test and Sum noexept are false 
    std::cout << std::boolalpha << noexcept(Test(5)) << std::endl;
    std::cout << std::boolalpha << noexcept(Sum(5,5)) << std::endl;
    // see the A::~A and multi noexept are true 
    std::cout << std::boolalpha << noexcept(multi(5.f,5.f)) << std::endl;
    std::cout << std::boolalpha << noexcept(a.~A()) << std::endl;
    try
    {
        Sum(3,5);
    }
    catch(int x)
    {
        std::cerr << x << '\n';
    }
    
}
