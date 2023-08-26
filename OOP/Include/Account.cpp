#include "Account.h"

int Account::s_ANGenerator = 1000;
Account::Account(const std::string &name, float balance)
    : m_name(name), m_balance(balance)
{
    m_accNo = ++s_ANGenerator;
}

Account::~Account()
{
}

const std::string Account::GetName() const
{
    return m_name;
}

float Account::GetBalance() const
{
    return m_balance;
}

int Account::GetAccountNo() const
{
    return 0;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float amount)
{
    if (amount < m_balance)
        m_balance -= amount;
    else
        std::cout << "Insufficient Balance" << std::endl;
}

void Account::Deposit(float amount)
{
    m_balance += amount;
}

float Account::GetInterestRate() const
{
    return 0.0f;
}
