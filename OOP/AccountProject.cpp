//#include "Include/Checking.h"
#include "Include/Savings.h"
#include "Include/Transactions.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    std::string name{"Kory"};
    //Checking acc{name,100};
    Savings acc{name,100,0.05};
    Transactions(&acc);
    return 0;
}
