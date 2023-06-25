/**
 * Rule of three
 *  - if one of the three have been user defined the creat all
 *      - constructor, destructor, copy constructor
*/

class Integer
{
private:
    int * m_int;
public:
// user defined constructor
    Integer(){ 
        m_int = new int(0); 
    };
    Integer(int i){ 
        m_int = new int(i); 
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

    return 0;
}

