#include "Include/Checking.h"
//#include "Include/Savings.h"
#include "Include/Transactions.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    // inheritance
    std::string name{"Kory"};
    //Checking acc{name,100};
    Checking acc{name,100,100.f};
    Account *pAccount2 = &acc;
    Transactions(&acc);

    // type check any type to make sure the class has the features required.
    // const std::type_info &ti = typeid(*pAccount2);
    // if(ti == typeid(Checking))
    //     std::cout << "Minimum Balance: " << pAccount2->GetInterestRate() << std::endl;
    
    // or use dynamic cast instead
    if(const auto ptr = dynamic_cast<Checking*>(pAccount2))
        std::cout << "Minimum Balance: " << ptr->GetMinimumBalance() << std::endl;

    // Up casting               GOOD
    Account *pAccount = &acc;
    // down casting             GOOD
    Checking *sav = static_cast<Checking*>(pAccount);

    // Object slicing           BAD!
    //  when we assign a derived class to a base class object
    Account acc_slice = acc;
    //  by object slicing we have fit the memory for the larger derived class 
    //      into the smaller memory footprint of the base class.
    //  This is valid but the compiler will remove the excess memory from Savings
    //      removing m_rate from the objects memory.  


    return 0;
}
