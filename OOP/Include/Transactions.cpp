#include <iostream>
#include "Account.h"

void Transactions(Account* acc)
{
    std::cout << "Transaction started"<< std::endl;
    std::cout << "Initial balance: " << acc->GetBalance() << std::endl;
    acc->Deposit(100);
    acc->AccumulateInterest();
    acc->Withdraw(170);
    std::cout << "Interest Rate: " << acc->GetInterestRate() << std::endl;
    std::cout << "Final balance: " << acc->GetBalance() << std::endl;
};
