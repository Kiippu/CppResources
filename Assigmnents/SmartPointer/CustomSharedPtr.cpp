/**
 * 
*/

#include <iostream>
#include <assert.h>

struct ControlBlock
{
    int ref_count;
    std::string name;
};

template <class type>
class Shared_ptr
{
private:
    type *m_data;
    ControlBlock* m_state;
public:
    Shared_ptr() : m_data{nullptr}, m_state{new ControlBlock{1, "temp"}} 
    {
        std::cout << "Shared_ptr()" << std::endl;
        std::cout << "ref_count now: " << m_state->ref_count << std::endl;
    };
    Shared_ptr(type data, const char* name) : m_data(new type(data)), m_state{new ControlBlock{1, name}} 
    {
        std::cout << m_state->name << ": Shared_ptr(type data)" << std::endl;
        std::cout << m_state->name << ": ref_count now: " << m_state->ref_count << std::endl;
    }
    ~Shared_ptr()
    {
        // no control block but data exists
        assert(!(!m_state && m_data));

        std::cout << "~Shared_ptr()" << std::endl;
        if(m_state)
        {
            std::cout << m_state->name << ": ~Shared_ptr()" << std::endl;
            --m_state->ref_count;
            std::cout << m_state->name << ": ref_count now: " << m_state->ref_count << std::endl;
        }
        else
        {
            std::cout << "~Shared_ptr()" << std::endl;
            std::cout << "No control block - no name"  << std::endl;
        }

        if(!m_state || !m_state->ref_count)
        {
            std::cout << "Try to delete m_data.. "  << std::endl;
            if(m_data)
            {
                delete m_data;
                std::cout << "m_data deleted.. "  << std::endl;
            }
            else
                std::cout << "m_data is nullptr.. "  << std::endl;
        }
    }
    // copy constructor
    Shared_ptr(const Shared_ptr & obj)
    {
        m_data = obj.m_data;
        m_state = obj.m_state;
        ++m_state->ref_count;
        std::cout << m_state->name << ": Shared_ptr(const Shared_ptr & obj)" << std::endl;
        std::cout << m_state->name << ": ref_count now: " << m_state->ref_count << std::endl;
    }
    // copy assignment
    Shared_ptr & operator=(const Shared_ptr& obj)
    {
        // check if the argument is itself
        if (this != &obj) {
            // check if data is already kept
            // decrement counter and if 0 then delete old data
            if(m_data && (--m_state->ref_count <= 0))
                delete m_data;
            // assign new data
            m_data = obj.m_data;
            m_state = obj.m_state;
            ++m_state->ref_count;
        }
        std::cout << m_state->name << ": Shared_ptr & operator=(const Shared_ptr& obj)" << std::endl;
        std::cout << m_state->name << ": ref_count now: " << m_state->ref_count << std::endl;
        return *this;
    }
    // move constructor
    Shared_ptr(Shared_ptr && obj)
    {
        m_data = obj.m_data;
        obj.m_data = nullptr;
        m_state = obj.m_state;
        obj.m_state = nullptr;
        std::cout << m_state->name << ": Shared_ptr(Shared_ptr &&data)" << std::endl;
        std::cout << m_state->name << ": ref_count now: " << m_state->ref_count << std::endl;
    }
    // move assignment
    Shared_ptr & operator=(Shared_ptr && obj)
    {
        // check obj isn't self
        if(this != &obj)
        {
            // check if data is already kept
            // decrement counter and if 0 then delete old data
            if(m_data && (--m_state->ref_count <= 0))
                delete m_data;
            m_data = obj.m_data;
            obj.m_data = nullptr;
            m_state = obj.m_state;
            obj.m_state = nullptr;
            std::cout << m_state->name << ": Shared_ptr & operator=(Shared_ptr && obj)" << std::endl;
            std::cout << m_state->name << ": ref_count now: " << m_state->ref_count << std::endl;
        }
        return *this;
    }

    
    void print()
    {
        std::cout << m_state->name << ": m_state->ref_count: " << m_state->ref_count << std::endl;
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
    auto ptr_a = Shared_ptr<userObj>{userObj{5},"ptr_a"};
    // copy assignment
    auto ptr_b = ptr_a;
    // copy initialization
    auto ptr_c{ptr_a};
    // move constructor
    auto ptr_d = std::move(ptr_a);
    // move assignment
    ptr_b = Shared_ptr<userObj>{userObj{10},"ptr_temp_move"};
    
    return 0;
}
