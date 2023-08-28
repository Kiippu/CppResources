#include "Checking.h"

// s

Checking::Checking(const std::string &name, float balance, float minBal)
    : m_minimumBalance(0), Account(name,balance)
{
}

void Checking::Withdraw(float amount)
{
    if((m_balance - amount) >= 50.f)
        Account::Withdraw(amount);
    else
        std::cout << "Denied - Balance will fall below limit" << std::endl;
}

float Checking::GetMinimumBalance() const
{
    return m_minimumBalance;
}
