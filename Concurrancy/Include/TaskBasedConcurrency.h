
/**
 * HEADING: std::async
 *  - part of a high-level concurrency lib in std
 *  - it creates and executes a callable function in a separate thread
 *  - it returns a std::future object that gave gives access to the task result
 * 
 * HEADING: Launch policy
 *  - std::launch::deferred - execute this task synchonously
 *  - std::launch::async - task is executed asynchronously
 *      - if not thread can be cerated it will result in an exception 
 *  - calling std::async by default may not alway create  anew thread(compiler specific)
 * 
 * HEADING: task argument and return values
 *  - default - passed by value
 *  - must use ref and cref to pass by ref and const ref
 *  - if the task function returns a value it will be available in future obj
 * 
 * HEADING: std::future
 *  - used to communicate between threads
 *  - has a shared state std::promise - input channel
 *  - std::future - output channel
 *  - wait(3s) - used to block calling thread for a set time
 *  - wait_for(1s) - same as above but returns enum of the current shared state status
 *      - std::future_status::deferred  - the async has a deferred launch policy
 *      - std::future_status::ready     - the task has returned the value
 *      - std::future_status::timeout   - the task is still running
 *  wait_until() - used to wait a specific time from chrono::now()
 * 
*/

#include <future>
#include <thread>
#include <iostream>

int Operation(long long size)
{
    int sum{0};
    for (long long i = 0; i < size; i++)
    {
        sum++;
    }
    return sum;
}

void TaskBasedConcurrency_main()
{
    using namespace std::chrono_literals;
    auto fut = std::async( Operation, 10);   // async default
    auto fut2 = std::async( std::launch::deferred, Operation, 10000);  // call the task to be synchonous
    auto fut3 = std::async( std::launch::async, Operation, 99999999);     // call the task to be asynchronous
    // is this future valid to get data from
    // will be invalid if the future has already returned the value via .get()
    if(fut.valid())
    {
        auto resultSum = fut.get(); // get value from shared state promise
    }

    // use wait() for until operation is competed - blocking
    std::cout << "Run wait()" << std::endl;
    auto start = std::chrono::system_clock::now();
    fut2.wait();
    auto end = std::chrono::system_clock::now();
    std::cout << "Run wait() time: " << (end-start).count() << std::endl;

    // wait for 1 second and get status enum if not complete wait again
    auto status = fut3.wait_for(1s);
    std::cout << "Run wait_for()" << std::endl;
    while (status != std::future_status::ready)
    {
        std::cout << ".";
        status = fut3.wait_for(1s);
    }
    std::cout << "Run wait_for() == " << fut3.get() << std::endl;

    auto fut4 = std::async( std::launch::async, Operation, 999999999);     // call the task to be asynchronous
    // wait for 4 seconds from now and get status enum
    auto timePoint = std::chrono::system_clock::now();
    auto status2 = fut4.wait_until(timePoint + 1s);
    std::cout << "Run wait_until()" << std::endl;
    while (status2 != std::future_status::ready)
    {
        std::cout << ".";
        timePoint = std::chrono::system_clock::now();
        status2 = fut4.wait_until(timePoint + 1s);
    }
    std::cout << "Run wait_until() == " << fut4.get() << std::endl;
    
}