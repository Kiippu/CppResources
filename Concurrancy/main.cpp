
#include "Include/stdLibThreads.h"
#include "Include/ReturningValueFromThreads.h"
#include "Include/ThisThreadNamespace.h"

int main(int argc, char const *argv[])
{
    StdLibThreads_main();
    
    ReturningValueFromThreads_main();

    ThisThreadNamespace_main();
    return 0;
}
