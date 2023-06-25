/**
 * Rule of three
 *  - if one of the three have been user defined the creat all
 *      - constructor, destructor, copy constructor
 * 
 * Delegating constructors
 *  - reduce code redundancy
 *  - one common constructor
*/

class Integer
{
private:
    int * m_int;
    int m_count;
public:
// user defined constructor and delegating constructors
    Integer()       : Integer(0)    {};
    Integer(int i)  : Integer(i, 0) {};
    Integer(int i, int cnt){ 
        m_int = new int(i); 
        m_count = cnt;
    };

// copy constructor - Deep copy
    Integer(const Integer &other){
        m_int = new int(*other.m_int); 
    };
// destructor
    ~Integer(){ 
        delete m_int; 
    };
};

int main(int argc, char const *argv[])
{
    int *p = new int(5);
    // shallow copy
    int *p1 = p;

    // deep copy
    int *p2 = new int(*p);
    Integer i1(5);
    Integer i2(i1);
    Integer i3(5, 80);

    return 0;
}

