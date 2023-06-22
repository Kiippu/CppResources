#include <iostream>

void swap(int& a, int& b)
{
    std::cout << "stage 1:\n" << "a: " << a << ", b: " << b <<  std::endl; 
    a = a + b;
    std::cout << "stage 2:\n" << "a: " << a << ", b: " << b <<  std::endl; 
    b = a - b;
    std::cout << "stage 3:\n" << "a: " << a << ", b: " << b <<  std::endl; 
    a = a - b;
    std::cout << "stage 4:\n" << "a: " << a << ", b: " << b <<  std::endl; 
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << "hello world" << std::endl; 
    int i{1};
    int k{4};
    swap(i,k);
    return 0;
}
