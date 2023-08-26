#include "Include/Checking.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    std::string name{"Kory"};
    Checking acc{name,1000};
    std::cout << "Initial balance: " << acc.GetBalance() << std::endl;
    acc.Deposit(200);
    acc.Withdraw(380);
    std::cout << "Initial balance: " << acc.GetBalance() << std::endl;
    return 0;
}
