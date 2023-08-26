#include <iostream>

class Account
{
    std::string m_name;
    int m_accNo;
    static int s_ANGenerator;
protected:
    float m_balance;
public:
    Account(const std::string &name, float balance);
    ~Account();
    const std::string GetName() const;
    float GetBalance() const;
    int GetAccountNo() const;

    void AccumulateInterest();
    void Withdraw(float amount);
    void Deposit(float amount);
    float GetInterestRate() const;
};
