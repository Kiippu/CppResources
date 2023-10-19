#include <thread>
#include <future>
#include <iostream>

int Sum(int x, int y)
{
    return (x + y);
}

void ReturningValueFromThreads_main()
{
    std::cout << "start of [ReturningValueFromThreads_main]"<< std::endl;
    // create an object that is an alias for Sum
    std::packaged_task<int(int,int)> taskSum{Sum};
    // get access to the return value in a future - must state return type in template pack
    auto fut = taskSum.get_future();
    // running the Sum function synchonously will not work!
    // auto result = fut.get();
    // run it asynchronously only
    std::cout << "start threadSum..."<< std::endl;
    std::thread threadSum(std::move(taskSum), 5, 6);
    std::cout << fut.get() << std::endl;    // NOTE: .get() is blocking!
    threadSum.join();
    std::cout << "End of [ReturningValueFromThreads_main]"<< std::endl;
}