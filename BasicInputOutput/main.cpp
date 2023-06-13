#include <iostream>

int main(){
    // console out with insert operator
    std::cout << "What is your first name?" << std::endl;
    // console in with extraction operator
    // cin will exit on space characters
    char buffer[128];
    std::cin >> buffer;
    // to read a full string is use getline()
    std::cout << "What full name?" << std::endl;
    // getline args:
    // Buffer - variable to store input
    // Length - number of characters to read
    // Delimiter - what character indicates the input is complete
    std::cin.getline(/*Buffer*/buffer,/*Length*/128,/*Delimiter*/'/n');
}