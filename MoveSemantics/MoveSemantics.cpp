#include "iostream"


class Integer
{
private:
    int * m_pInt;
public:
// user defined constructor and delegating constructors
    Integer(){
        m_pInt = new int(0); 
           std::cout << "Integer()" << std::endl;
    };
    Integer(int i) { 
        m_pInt = new int(i); 
           std::cout << "Integer(int i)" << std::endl;
    };

// copy constructor - Deep copy
    Integer(const Integer &other){
        m_pInt = new int(*other.m_pInt); 
           std::cout << "Integer(const Integer &other)" << std::endl;
    };
// destructor
    ~Integer(){ 
        delete m_pInt; 
           std::cout << "~Integer()" << std::endl;
    };

/// Move Constructor
    Integer(Integer &&other)
    {
        std::cout << "Integer(Integer &&other)" << std::endl;
        m_pInt = other.m_pInt;
        other.m_pInt = nullptr;
    }

    void setValue(int x)
    {
        *m_pInt = x; 
    }
    int getValue() const
    {
        return *m_pInt; 
    }
};


Integer Add(const Integer &a, const Integer &b)
{
    // create 1 object
    Integer temp;
    temp.setValue(a.getValue() + b.getValue());
    // move temp 
    return temp; // uses name return optimization
    // return Integer(a + b); // uses name return optimization
}

int main(int argc, char const *argv[])
{
    // create 2 objects
    Integer a(1), b(3);
    // use moved temp and getValue from it not a copy
    // u move/copy Elision
    //  - compiler skips a move or copy assignment/constructor 
    a.setValue(Add(a,b).getValue());
    return 0;
}
