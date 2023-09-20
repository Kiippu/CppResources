#include <iostream>
template<typename T, int size>
class Stack
{
    T m_buffer[size];
    int m_top{ -1 };
public:
    Stack() = default;
    //Stack( const Stack &obj)          // short hand
    Stack( const Stack<T,size> &obj)    // long hand
    {
        m_top = obj.m_top;
        for (size_t i = 0; i <= m_top; ++i)
        {
            m_buffer[i] = obj.m_buffer[i];
        }
    }
    void Push(const T& elm)
    {
        m_buffer[++m_top] = elm;
    }
    T&& Pop();
    const T&Top() const
    {
        return m_top;
    }
    bool IsEmpty() const
    {
        return m_top == -1;
    }
    static Stack Create();
};

template <typename T, int size>
T&& Stack<T, size>::Pop()
{
    return std::move(m_buffer[m_top--]);
}

template <typename T, int size>
Stack<T, size> Stack<T, size>::Create() // MUST write in long hand
{
    return Stack<T,size>();
}


void ClassTemplates_main()
{
    // cant make a stack of 10 into stack of 5
    //Stack<float,5> s = Stack<float,10>::Create();
    Stack<float,10> s = Stack<float,10>::Create();
    auto stk = Stack<float,10>::Create();
    stk.Push(3);
    stk.Push(6);
    stk.Push(4);
    stk.Push(1);
    auto stkCpy(stk);
    while (!stkCpy.IsEmpty())
    {
        std::cout << stkCpy.Pop() << ", ";
    }
    
}

