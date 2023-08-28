/**
 * Polymorphism
 *  a base class is able to use its derived 
 *  class polymorphic methods when virthal 
 *  functions are called.
*/

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

    virtual void AccumulateInterest();
    virtual void Withdraw(float amount);
    virtual void Deposit(float amount);
    virtual float GetInterestRate() const;
};
