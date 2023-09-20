#include <iostream>
#include <vector>

template<class T>
class PrettyPrinter
{
    T *m_data;
public:
    PrettyPrinter(T *data) : m_data(data) 
    {}
    void Print()
    {
        std::cout << "{" << *m_data << "}" << std::endl;
    }
    T GetData()
    {
        return *m_data;
    }
    void SetData(T *data)
    {
        m_data = data;
    }
};
// explicit specialization of an object that only needs a function overridden
template<>
void PrettyPrinter<std::vector<int>>::Print()
{
    std::cout << "{";
    for (const auto& obj : *m_data)
    {
        std::cout << obj;
        if (obj != m_data->back())
            std::cout << ",";
    }
    std::cout << "}";
}
template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print()
{
    std::cout << "{\n";
    PrettyPrinter<std::vector<int>> vec{nullptr};
    for (auto& obj : *m_data)
    {
        vec.SetData(&obj);
        std::cout << "\t";
        vec.Print();
        if (obj != m_data->back())
            std::cout << "," << std::endl;
    }
    std::cout << "\n}" << std::endl;
}

// Template Explicit specialization for char* whole class needs to be overridden!!
template<>                      // NOTE: this empty template pack
class PrettyPrinter<char*>      // NOTE: specialization made here for char*
{
    char* m_data;
public:
    PrettyPrinter(char* data) : m_data(data) 
    {}
    void Print()
    {
        std::cout << "{" << m_data << "}" << std::endl;
    }
    char* GetData()
    {
        return m_data;
    }
};

void ExplicitSpecializationTemplates_main()
{
    int data0 = 89;
    PrettyPrinter<int> p0{&data0};
    p0.Print();
    // without template specialization made for char* this 
    // only prints a char and have to of temp char
    char* data1 = {"Kory Smith"};
    PrettyPrinter<char*> p1{data1};
    p1.Print();
    // STL object
    std::vector<int> vec0{2,3,4,5,6};
    PrettyPrinter<std::vector<int>> p2{&vec0};
    p2.Print();
    std::cout << std::endl;
    // STL object of STL objects
    std::vector<std::vector<int>> vec1{{1,2,3},{4,5,6}};
    PrettyPrinter<std::vector<std::vector<int>>> p3{&vec1};
    p3.Print();
}