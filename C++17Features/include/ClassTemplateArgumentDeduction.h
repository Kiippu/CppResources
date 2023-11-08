#include <mutex>
#include <string>
#include <vector>

template<typename T>
class Data 
{
public:
    Data(const T &t)
    {

    }
};
Data(const char *) -> Data<std::string> ;
Data(int) -> Data<long> ;

void ClassTemplateArgumentDeduction_main()
{
    //  template type is being deduced to long and string in stead of int and const schar*
    Data d1{5};
    Data d2{6.5};
    Data d3 = d1;
    Data d5{"Hello"};
    Data d4 = new  Data{"hello"};

    // old way
    std::pair<int, int> p1{2,3};
    std::pair<int, int> p2 = std::make_pair(2,3);
    // new way
    std::pair p3{3,4};
    std::vector p4{3,4};

    std::mutex m;
    // old way
    // std::lock_guard<std::mutex> lock1(m);
    // new way
    std::lock_guard lock2(m);



}