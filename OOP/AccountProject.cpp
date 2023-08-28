//#include "Include/Checking.h"
#include "Include/Savings.h"
#include "Include/Transactions.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    // inheritance
    std::string name{"Kory"};
    //Checking acc{name,100};
    Savings acc{name,100,0.05};
    Account *pAccount2 = &acc;
    Transactions(&acc);
    const std::type_info &ti = typeid(*pAccount2);
    // type check any type to make sure the class has the features required.
    if(ti == typeid(Savings))
        std::cout << "Minimum Balance: " << pAccount2->GetInterestRate() << std::endl;

    // Up casting               GOOD
    Account *pAccount = &acc;
    // down casting             GOOD
    Savings *sav = static_cast<Savings*>(pAccount);

    // Object slicing           BAD!
    //  when we assign a derived class to a base class object
    Account acc_slice = acc;
    //  by object slicing we have fit the memory for the larger derived class 
    //      into the smaller memory foorpribt of the base class.
    //  This is valid but the comiler will remove the exess memory from Savings
    //      removing m_rate from the objects memory.  


    return 0;
}
