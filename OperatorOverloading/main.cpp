#include <iostream>


class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer(){
        std::cout << "Integer()" << std::endl;
        m_pInt = new int(0);
    };
	//Parameterized constructor
	Integer(int value) {
        std::cout << "Integer(int)" << std::endl;
        m_pInt = new int(value);
    };
	//Copy constructor
	Integer(const Integer &obj){
        std::cout << "Integer(const Integer&)" << std::endl;
        m_pInt = new int(*obj.m_pInt);
    };
	//Move constructor
	Integer(Integer &&obj) {
        std::cout << "Integer(int&&)" << std::endl;
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
    };

	int GetValue()const{
        return *m_pInt;
    };
	void SetValue(int value){
        std::cout << "~Integer()" << std::endl;
        delete m_pInt;
        m_pInt = new int(value);
    };

	~Integer(){
        std::cout << "~Integer()" << std::endl;
        delete m_pInt;
    };

	//Copy assignment operator
	Integer & operator =(const Integer &a) {
        // check if the argument is itself
        if (this != &a) {
            delete m_pInt;
            m_pInt = new int(*a.m_pInt);
        }
        return *this;
    };
	//Move assignment operator
	Integer & operator =(Integer &&a) {
        // check if the argument is itself
        if (this != &a) {
            delete m_pInt;
            m_pInt = a.m_pInt;
            a.m_pInt = nullptr;
        }
        return *this;
    };

    // single argument as it is on a class
    Integer operator +(const Integer & a) const
    {
        return {*a.m_pInt + *m_pInt};
    }

    // pre increment
    Integer & operator ++()
    {
        ++(*m_pInt);
        return *this;
    };
    // post increment - note: the signature is modified by using the arg int
    Integer operator ++(int)
    {
        Integer temp{*this};
        ++(*m_pInt);
        return temp;
    };

    // Comparison operator
    bool operator ==(const Integer & obj)const
    {
        return (*obj.m_pInt == *m_pInt);
    };

    // function call operator
    void operator()()
    {
        std::cout << "Hello" << std::endl;
    }
};

// global operator overload for +
// only one is allowed in this scope - ambiguity
// note: needs 2 arguments
// Integer operator +(const Integer & a, const Integer & b)
// {
//     return {a.GetValue() + b.GetValue()};
// }

// ostream overloading
// uses in std::cout << aVariable ;
std::ostream & operator <<(std::ostream & out, const Integer &a)
{
    out << a.GetValue();
    return out;
}
// istream overloading
// std::cin

std::istream & operator >>(std::istream & in, Integer &a)
{
    int x;
    in >> x;
    a.SetValue(x);
    return in;
}



int main(int argc, char const *argv[])
{
    // create 2 vars
    Integer a{4}, b{7};
    // use operator overloaded + 
    Integer c = a + b;
    // preincrement - more expensive
    ++c;
    // post increment
    c++;
    // comparison will work. its expands to - a.operator+ 5
    Integer sum1 = a + 5;
    // this expression will not work. it expands to - 5 a.operator+
    // a global operator overload will be needed - line 92
    //Integer sum2 = 5 + c;
    // 
    
    if(c == a){}
    // ostream operator
    std::cout << sum1 << std::endl;
    // istream operator
    std::cin >> sum1;
    std::cout << sum1 << std::endl;
    // function operator 
    sum1();
    return 0;
}
