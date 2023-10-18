
#include <iostream>
#include <list>
#include <thread>


constexpr int SIZE = 9999;
std::list<int> g_list;

void Download()
{
    std::cout << "THREAD: Start download function..." << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        g_list.push_back(i);
    }
    std::cout << "THREAD: Finished download function" << std::endl;
}

void StdLibThreads_main()
{
    
    std::cout << "MAIN THREAD: run thread" << std::endl;
    std::thread downloadThread0(Download);
    std::cout << "MAIN THREAD: waiting for thread to join, main thread blocked..." << std::endl;
    downloadThread0.join();
    std::cout << "MAIN THREAD: run another thread but detach. main thread will not wait now" << std::endl;
    g_list.clear();
    std::thread downloadThread1(Download);
    downloadThread1.detach();
    std::cout << "MAIN THREAD: process will close before detached thread  finishes" << std::endl;
}

