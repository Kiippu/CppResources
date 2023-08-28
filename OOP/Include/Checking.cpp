#include "Checking.h"

// s

void Checking::Withdraw(float amount)
{
    if((m_balance - amount) >= 50.f)
        Account::Withdraw(amount);
    else
        std::cout << "Denied - Balance will fall below limit" << std::endl;
}
