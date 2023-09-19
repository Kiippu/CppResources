#include <string>

template<class T, class... Params>
T CreateObject(Params&& ... args)
{
    return T{std::forward<Params>(args)...};
}

class Employee 
{
    public:
    std::string m_name; int m_id; int m_salary;
    Employee(std::string name, int id, int salary) 
        : m_name(name), m_id(id), m_salary(salary)
    {}
};

class Contact 
{
    public:
    std::string m_name; int m_mob; std::string m_address; std::string m_email;
    Contact(std::string name, int mob, std::string address, std::string email) 
        : m_name(name), m_mob(mob), m_address(address), m_email(email)
    {}
};


int main(int argc, char const *argv[])
{
    auto num = CreateObject<int>(5);
    auto str = CreateObject<std::string>();
    auto emp = CreateObject<Employee>("Bob", 101, 10000);
    auto con = CreateObject<Contact>("Joey", 95984759, "a street", "email@email.com");
    return 0;
}
