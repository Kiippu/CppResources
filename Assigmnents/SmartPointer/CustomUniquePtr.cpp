/**
 * Custom smart pointer 
 * challenge: Create the shared, unique and weak ptr 
 * 
*/

#include <iostream>

template <class type>
class Unique_ptr
{
private:
    type* m_data;
public:
    Unique_ptr() : m_data(nullptr) {};
    ~Unique_ptr()
    {
        delete m_data;
        std::cout << "~Unique_ptr()" << std::endl;
    }
    Unique_ptr(type data)
    {
        m_data = new type(data);
        std::cout << "Unique_ptr()" << std::endl;
    }
    // can not copy pointer
    Unique_ptr(const Unique_ptr & data)  = delete;
    Unique_ptr & operator =(Unique_ptr & data) = delete;
    // can move
    Unique_ptr(Unique_ptr &&data)
    {
        m_data = data.m_data;
        data.m_data = nullptr;
        std::cout << "Unique_ptr(type &&data)" << std::endl;
    }
    Unique_ptr & operator =(Unique_ptr && data)
    {
        // check if the argument is itself
        if (this != &data) {
            delete m_data;
            m_data = data;
            data = nullptr;
        }
        std::cout << "Unique_ptr & operator =(type && data)" << std::endl;
        return *this;
    }

    explicit operator bool() const {
        return m_data;
    }
    
    type* operator->() {
        return m_data;
    }
};

struct userObj
{
    int m_id;
    void print()
    {
        std::cout << "Value: " << m_id << std::endl;
    }
};


int main(int argc, char const *argv[])
{
    // Unique Pointer example
    Unique_ptr<userObj> ptr_a{userObj{5}};

    // this copy is illegal and errors
    // auto x = ptr;
    // auto x{ptr_a};
    
    // move data from ptr_a to ptr_b
    auto ptr_b = std::move(ptr_a);
    if(ptr_a) { std::cout << "ptr_a is valid" << std::endl; }
    if(ptr_b) 
    { 
        std::cout << "ptr_b is valid" << std::endl; 
        ptr_b->print();
    }


    //ptr_b


    return 0;
}
