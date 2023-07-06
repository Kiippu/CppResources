/**
 * Circular references 
 *  - destruction of one object doesn't destruct its members
 *  - smart pointer count stopping the destruction of the underlying object
 *  - See example where the destructors are never called on run.
 * 
*/

#include <memory>
#include <iostream>

class Project;
class Employee
{
public:
    std::shared_ptr<Project> m_prj;
    Employee()
    {
        std::cout << "Employee()" << std::endl; 
    }
    ~Employee()
    {
        std::cout << "~Employee()" << std::endl; 
    }
};

class Project
{
public:
    std::shared_ptr<Employee> m_prj;
    Project()
    {
        std::cout << "Project()" << std::endl; 
    }
    ~Project()
    {
        std::cout << "~Project()" << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
    // creating pointers with one count
    std::shared_ptr<Employee> emp = std::make_shared<Employee>();
    std::shared_ptr<Project> pro = std::make_shared<Project>();
    
    // assigning members each smart ptr
    // ref count being incremented to 2
    emp->m_prj = pro;
    pro->m_prj = emp;

    // on exit of scope emp and pro pointers are destroyed
    // BUT that does not release the pointers as they now have a ref count of 1 on.
    // WHY: the pointer is destroyed that points to the object. the object is only destroyed on a ref count of 0
    // FIX: imply ownership, make the members std::weak_ptr's 

    return 0;
}
