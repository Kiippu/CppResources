
#include <sstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    int a{1}, b{5};
    int sum = a + b;

    // insert primitives into stream
    std::stringstream ss;
    ss << "sum of " << a << " and " << b << " equals " << sum  << std::endl;
    // extract string data 
    auto str = ss.str();
    
    // extract number s from string stream
    std::string data {"12 56 78"};
    std::stringstream ss1;
    int c{0};
    int sum1{0};
    ss1.str(data);
    // get each value with space delimiter
    while (ss1 >> c)
    {
        sum1 += c;
    }
    std::cout << sum1 << std::endl;
    

    return 0;
}
