
/**
 * 
*/


class Integer
{
private:
    int m_int{0};
public:
// forcing the creation of a compiler synthesized constructor
    Integer() = default;
// user constructor
    Integer(int i){ 
        m_int = i; 
    };

// copy constructor - delete
// this class will not produce a synthesized copy constructor by default
    Integer(const Integer &other) = delete;
};

int main(int argc, char const *argv[])
{
    Integer i;
    // the copy of the below constructor will result in a error
    // Integer i1(i);
    
    return 0;
}
