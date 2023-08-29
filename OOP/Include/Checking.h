#include "Account.h"
#include <string>
// use of final here will nto allow any other classes to derive from this class
// class Checking final : public Account
class Checking : public Account
{
private:
    float m_minimumBalance;
public:
    // inherited base class constructor
    using Account::Account;
    Checking(const std::string &name, float balance, float minBal);
    
    void Withdraw(float amount) override;
    float GetMinimumBalance() const;
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