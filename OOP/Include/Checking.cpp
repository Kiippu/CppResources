#include "Checking.h"

Checking::Checking(const std::string &name, float balance)
    : Account(name, balance)
{
}

void Checking::Withdraw(float amount)
{
    if((m_balance - amount) >= 50.f)
        m_balance -= amount;
    else
        std::cout << "Denied - Balance will fall below limit" << std::endl;
}
