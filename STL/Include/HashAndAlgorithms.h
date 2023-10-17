/**
 * Hash
 * can hash values including objects(classes/structs)
 * can be used to make user defined maps etc
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

class Employee
{
    std::string m_name;
    std::string m_code;
    int m_id;
public:
    Employee(std::string const& name, int id, std::string code = "NA") : m_name(name), m_id(id), m_code(code){};
    std::string const& GetName() const {return m_name;}
    std::string const& GetCode() const {return m_code;}
    int const GetId() const {return m_id;}
    void Print() const{ std::cout << m_id << " - " << m_name << std::endl; }
};

struct EmployeeHash
{
    // rough imple of hash function - use boost lib for better one
    size_t operator()(Employee const& emp)const{
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());
        return s1 ^ s2;
    }
};
struct EmpEquality
{
    bool operator()(Employee const& emp1, Employee const& emp2)const{
        return emp1.GetId() == emp2.GetId() && emp1.GetName() == emp2.GetName();
    }
};

struct EmpCompare
{
    bool operator ()(Employee const& e1, Employee const& e2) const
    {
        return e1.GetId() < e2.GetId();
    }
};

// a function object with state!
struct EmpIds
{
    std::vector<int> m_ids;
    void operator()(Employee const& e)
    {
        if(e.GetCode() == "NA")
            m_ids.push_back(e.GetId());
    }
};

void HashAndAlgorithms_main()
{
    // make a custom sorting algorithm for employee
    std::set<Employee, EmpCompare> s = {
        Employee{"Ben",12},
        Employee{"Sam",23},
        Employee{"Sally",34},
        Employee{"Jan",45}
    };

    // make unordered set use the user defined hash functions
    std::unordered_set<Employee, EmployeeHash, EmpEquality> uSet = {
        Employee{"Ben",12},
        Employee{"Sam",23},
        Employee{"Sally",34},
        Employee{"Jan",45},
    };
    for(auto const& x : uSet)
        x.Print();

    
    // make a custom sorting algorithm for user defined employee
    std::vector<Employee> v = {
        Employee{"Ben",12,"C++"},
        Employee{"Sam",23},
        Employee{"Sally",34,"Java"},
        Employee{"Jan",45}
    };
    // std::sort(v.begin(), v.end()); // this errors as user defined employee can not be sorted
    std::sort(v.begin(), v.end(), [](auto const& e1, auto const& e2){
        return e1.GetName() < e2.GetName();
    });
    for(auto const& x : v)
        x.Print();

    // use build in sort algorithms
    std::vector<int> vNum = {1,2,44,6,2,76};
    std::sort(vNum.begin(), vNum.end(), std::greater<int>{});
    for(auto const& x : vNum)
        std::cout << x << std::endl;

    // count_if - counts the number of true returns from a predicate
    auto count = std::count_if(v.begin(), v.end(),[](auto const&e){
        return e.GetCode() == "NA";
    });
    std::cout << "v count: " << count << std::endl;

    // find_if - gets first found iterator if exists 
    auto itr = std::find_if(v.begin(), v.end(),[](auto const&e){
        return e.GetCode() == "C++";
    });
    if(itr != v.end())
        std::cout << "itr obj name: " << itr->GetName() << std::endl;

    // for_each - generic loop with lambda
    std::for_each(v.begin(), v.end(),[](auto const&e){
        std::cout << "name: " << e.GetName() << " id: " << e.GetId() << std::endl;
    });

    // use of function pointer that uses state to return a list
    auto foundIds = std::for_each(v.begin(), v.end(), EmpIds{});
    for(auto const& id : foundIds.m_ids)
        std::cout << id << std::endl;

}