#include "Savings.h"

Savings::Savings(const std::string &name, float balance, float rate)
    : Account(name, balance), m_rate(rate)
{
}

Savings::~Savings()
{
}

void Savings::AccumulateInterest()
{
    m_balance += (m_balance * m_rate);
}

float Savings::GetInterestRate() const
{
    return m_rate;
}
