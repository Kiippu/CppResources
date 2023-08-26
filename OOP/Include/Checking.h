#include "Account.h"
#include <string>

class Checking : public Account
{
private:
public:
    Checking(const std::string &name, float balance);
    
    void Withdraw(float amount);
};