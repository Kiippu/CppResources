
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
 *   - wait_until() - used to wait a specific time from chrono::now()
 * 
 * HEADING: std::promise
 *  - is a shared state
 *  - can be accessed by another thread ia std::future 
 *  - promise and future are 2 end points of the communication
 *  - these are threadsafe
 *  - promise objects can only be used once
 * 
*/

#include <future>
#include <thread>
#include <iostream>

void ExceptionExample(std::promise<long long> &prom)
{
    auto fut = prom.get_future();
    try
    {
        std::cout << "[task-ExceptionExample] waiting for promise" << std::endl;
        auto size = fut.get();
        std::cout << "[task-ExceptionExample]  promise acquired" << std::endl;
    }
    catch(std::exception& e)
    {
        std::string msg = e.what();
        std::cout << "[task-ExceptionExample] Exception: " << e.what() << std::endl;
    }
    
}

long long Operation(long long size)
{
    int sum{0};
    for (long long i = 0; i < size; i++)
    {
        sum++;
    }
    return sum;
}

long long Operation2(std::promise<long long> &prom)
{
    auto fut = prom.get_future();
    std::cout << "[promise task] waiting for promise" << std::endl;
    auto size = fut.get();
    std::cout << "[promise task] promise returned" << std::endl;
    long long sum{0};
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


    // promise example
    std::promise<long long> data;
    auto futPromExample = std::async(std::launch::async, Operation2, std::ref(data));
    std::cout << "[main] sleep main to half promise" << std::endl;
    std::this_thread::sleep_for(1s);
    std::cout << "[main] setting promise data" << std::endl;
    data.set_value(99999999);
    std::cout << "[main] promise task done" << std::endl;

    // promise with exception
    // throwing exception in one thread and the promise will know 
    // it is not getting the data due to exception
    std::promise<long long> data2;
    auto futPromExample2 = std::async(std::launch::async, ExceptionExample, std::ref(data2));
    try
    {
        throw std::runtime_error{"Data not available"};
    }
    catch(/*std::exception& e*/ ... )
    {
        data2.set_exception(std::current_exception());
    }
    
    
}