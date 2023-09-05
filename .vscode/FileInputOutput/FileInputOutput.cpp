/**
 * File I/O
 * ofstream - write to an output stream
 * ifstream - read to an output stream
 * fstream  - write/read stream
 * all include fstream header
 * all classes cna be used for text/binary I/O
 * 
 * stream state flags
 * goodbit  - no error occured                  good()
 * badbit   - irrecoverable stream error        bad()
 * failbit  - I/O opperation failed             fail()
 * eofbit   - end of file reached during input  eof()
*/

#include <iostream>
#include <fstream>
#include <string>

std::string filename{"data.text"};
std::string filename_bad{"data1.text"};

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
    std::ifstream input{filename_bad};
    // check if a file is open
    if(!input.is_open())
    {
        std::cout << "Could not open file" << std::endl;
    }
    // open the file again
    input.open(filename_bad);
    if(input.fail())
    {
        std::cout << "Could not open file again" << std::endl;
    }
    input.open(filename);
    if(input.is_open())
    {
        std::cout << "File successfully opened" << std::endl;
    }
    std::string msg;
    std::getline(input, msg);
    int value{};
    input >> value;
    input >> value;
    if(input.eof())
    {
        std::cout << "End of file encountered" << std::endl;
    }
    if(input.good())
    {
        std::cout << "I/O operations successful" << std::endl;
    }
    else
    {
        std::cout << "some I/O operations failed" << std::endl;
    } 
    // clear all bits
    input.clear();
    // reset file position to beginning
    input.seekg(0);
    if(input.good())
    {
        std::cout << "goodbit is set true all file operations have been successful since open" << std::endl;
    }
    input.setstate(std::ios::failbit);
    if(input.fail())
    {
        std::cout << "set fail bit true" << std::endl;
    }
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
