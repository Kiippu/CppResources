#include <iostream>

template<typename T, int columns>
class PrettyPrinter1
{
    T *m_data;
public:
    PrettyPrinter1(T *data) : m_data(data) 
    {}
    void Print()
    {
        std::cout << "Columns: " << columns << std::endl;
        std::cout << "{" << *m_data << "}" << std::endl;
    }
    T GetData()
    {
        return *m_data;
    }
};
// partial specialization used here for when 80 is passed in
// partial because only part of the template is specialized
template<typename T>
class PrettyPrinter1<T,80>
{
    T *m_data;
public:
    PrettyPrinter1(T *data) : m_data(data) 
    {}
    void Print()
    {
        std::cout << "There are 80 columns here!" << std::endl;
        std::cout << "{" << *m_data << "}" << std::endl;
    }
    T GetData()
    {
        return *m_data;
    }
};

// partial specialization for types template<typename T>
template<typename T>
class SmartPointer
{
    T *m_data;
public:
    SmartPointer(T *data) : m_data(data) 
    {}
    ~SmartPointer()
    {
        delete m_data;
    }
};
// partial specialization for array types
template<typename T>
class SmartPointer<T[]>
{
    T *m_data;
public:
    SmartPointer(T *data) : m_data(data) 
    {}
    T & operator[](int index)
    {
        return m_data[index];
    }
    ~SmartPointer()
    {
        delete[] m_data;
    }
};


void ClassTemplatesPartialSpecialization_main()
{
    int data{800};
    PrettyPrinter1<int, 40> p0{&data};
    PrettyPrinter1<int, 80> p1{&data};
    p0.Print();
    p1.Print();
    SmartPointer<int[]> ptr{new int[5]};
    ptr[0] = 3;
    std::cout << ptr[0] << std::endl;

}