#include "Account.h"
#include <string>

class Checking : public Account
{
private:
public:
    //Checking(const std::string &name, float balance);
    // inherited base class constructor
    using Account::Account;
    
    void Withdraw(float amount);
};