#include "Account.h"
#include <string>
// use of final here will nto allow any other classes to derive from this class
class Checking final : public Account
{
private:
public:
    //Checking(const std::string &name, float balance);
    // inherited base class constructor
    using Account::Account;
    
    void Withdraw(float amount) override;
};

/**
 * Error Message is this is un commented:
 * ----------------------------------------------------------------------------------+
 * +    a 'final' class type cannot be used as a base classC/C++(1904)               +
 * +    class Checking                                                               +
 * +    use of final here will nto allow any other classes to derive from this class +
 * +---------------------------------------------------------------------------------+
*/
// class chackingV2 : public Checking
// {
// }