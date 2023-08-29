#include "Account.h"

// adding virtual so any diamond inheritance is avoided
class Savings : virtual public Account
{
private:
    float m_rate;
public:
    Savings(const std::string &name, float balance, float rate);
    ~Savings();

    // use of Override will make sure that this function signature is actually 
    //  overriding a base class method.
    void AccumulateInterest() override;
    // Use of Final will make sure the any derived classes of Savings can 
    //  not override this implementation
    float GetInterestRate() const override;
};