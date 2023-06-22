
/**
 * Static member and methods .h
 *  - can not be initialized inside a class
 *  - no user initialization inits the default value
 *  - members and methods belong to class and not objects
 *  - methods do not have access to this->
 *  - cannot access non-static members of the class
*/

class StaticMemberAndMembers
{
    // Declaration of static member
    static int m_count;
    // initialization in the class like below would not compile
    // static int m_count{10};

    // Declaration of static method
    static void SetCount(int i); 
    // initialization in the class like below would not compile
    // static void SetCount() {};
};

int StaticMemberAndMembers::m_count = 10;

void StaticMemberAndMembers::SetCount(int i)
{
    StaticMemberAndMembers::m_count = i;
}

