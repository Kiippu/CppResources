#include <iostream>
#include <fstream>
#include <string>

void readBinaryVar()
{
    // write to file text
    std::ofstream textStream{"data"};
    textStream << 123456789;
    // write to file in  binary
    std::ofstream binstream{"binaryFile", std::ios::binary | std::ios::out};
    int num{123456789};
    binstream.write((const char*)&num, sizeof(num));
    binstream.close();
    // read binary back
    int result{0};
    std::ifstream input("binaryFile", std::ios::binary | std::ios::in);
    input.read((char*)&result, sizeof(num));
    input.close();
    std::cout << result << std::endl;
}

void readBinaryStruct()
{
    struct Record
    {
        int id{};
        char ch[10];
    };
    // write struct to binary
    std::ofstream binstream{"binaryFile", std::ios::binary | std::ios::out};
    Record record{123456789, "Kory"};
    binstream.write((const char*)&record, sizeof(Record));
    binstream.close();
    // read struct in binary
    Record recordNew;
    std::ifstream input("binaryFile", std::ios::binary | std::ios::in);
    input.read((char*)&recordNew, sizeof(Record));
    std::cout << recordNew.ch << " : " << recordNew.id << std::endl;


}

int main(int argc, char const *argv[])
{
    readBinaryVar();
    readBinaryStruct();
    return 0;
}
