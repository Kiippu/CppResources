
#include <thread>
#include <pthread.h>
//#include <print>
#include <iostream>

void process(){}
void ThisThreadNamespace_main()
{
    std::thread t1{process};
    auto handle = t1.native_handle();
    pthread_setname_np(handle, "customThreadName");
    auto id = t1.get_id();
    std::cout << "thread id: " << id << std::endl;
    //std::println("Thread ID: {}", id);
    auto cores = std::thread::hardware_concurrency(); // num of cores
    std::cout << "cores: " << cores << std::endl;

    t1.join();



}