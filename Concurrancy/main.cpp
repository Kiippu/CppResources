
#include "Include/stdLibThreads.h"
#include "Include/ReturningValueFromThreads.h"
#include "Include/ThisThreadNamespace.h"
#include "Include/TaskBasedConcurrency.h"

int main(int argc, char const *argv[])
{
    // low level threading
    StdLibThreads_main();
    // returning data from low level threading
    ReturningValueFromThreads_main();
    // namespace functions to get addition data from threads
    ThisThreadNamespace_main();
    // high level wrappers for threads - future and promise
    TaskBasedConcurrency_main();
    return 0;
}
