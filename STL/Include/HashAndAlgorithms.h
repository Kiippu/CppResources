/**
 * Hash
 * can hash values including objects(classes/structs)
 * can be used to make user defined maps etc
*/

#include <iostream>
#include <string>
#include <unordered_set>

class Employee
{
    std::string m_name;
    int m_id;
public:
    Employee(std::string const& name, int id) : m_name(name), m_id(id){};
    std::string const& GetName() const {return m_name;}
    int const GetId() const {return m_id;}
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


void HashAndAlgorithms_main()
{

    // make unordered set use the user defined hash functions
    std::unordered_set<Employee, EmployeeHash, EmpEquality> uSet = {
        Employee{"Ben",12},
        Employee{"Sam",23},
        Employee{"Sally",34},
        Employee{"Jan",45},
    };

    for(auto const& x : uSet)
        std::cout << x.GetId() << " - " << x.GetName() << std::endl;
}