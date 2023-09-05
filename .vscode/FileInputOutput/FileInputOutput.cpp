/**
 * File I/O
 * ofstream - write to an output stream
 * ifstream - read to an output stream
 * fstream  - write/read stream
 * all include fstream header
 * all classes cna be used for text/binary I/O
 * 
*/

#include <iostream>
#include <fstream>
#include <string>

std::string filename{"data.text"};

void Write()
{
    std::ofstream out{filename};
    out << "Hello World" << std::endl;
    out << 10 << std::endl;
    out.close();
}

void Read()
{
    // open file with constructor is ok
    //std::ifstream input{filename};
    // can use open() also
    std::ifstream input;
    input.open(filename);
    std::string msg;
    std::getline(input, msg);
    int value{};
    input >> value;
    input.close();
    std::cout << msg << " : " << value << std::endl;
}

int main(int argc, char const *argv[])
{
    Write();
    Read();
    /* code */
    return 0;
}
