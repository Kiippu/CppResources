
#include <iostream>
#include <fstream>
#include <string>

void Write()
{
    std::ofstream out{"test.txt"};
    if(!out)
    {
        std::cout << "bad ostream" << std::endl;
        return;
    }
    std::cout << "current position put pointer: " << out.tellp() << std::endl;
    std::string msg{"this is a message input text to be read from somewhere"};
    for (char ch : msg)
    {
        out.put(ch);
    }
    std::cout << "current position put pointer insert: " << out.tellp() << std::endl;
    // move poiter 5 characters from beginning
    out.seekp(5,std::ios::beg);
    std::cout << "current position put pointer after move: " << out.tellp() << std::endl;
    out.close();
}

void Read()
{
    std::ifstream input{"test.txt"};
    if(!input)
    {
        std::cout << "bad ostream" << std::endl;
        return;
    }
    // gte current position of get pointer
    std::cout << "current position get pointer: " << input.tellg() << std::endl;
    // move poiter 5 characters backwards from end
    input.seekg(-5,std::ios::end);
    std::cout << "current position get pointer: " << input.tellg() << std::endl;
    // move poiter 5 characters from beginning
    input.seekg(5,std::ios::beg);
    std::cout << "current position get pointer: " << input.tellg() << std::endl;
    char ch{};
    while (input.get(ch))
    {
        std::cout << ch;
    }
    std::cout << std::endl;
    input.close();
    
}

void Fstream()
{
    // fstream does not make a file if it dosn't exist
    std::fstream stream{"file.txt"};
    if(!stream)
    {
        std::cout << "no file exists. will make one now" << std::endl;
        // make file and reoopen with fstream;
        std::ofstream out{"file.txt"};
        out.close();
        stream.open("file.txt");
    }
    stream << "Hello World" << std::endl;
    std::cout << "current position get fstream pointer: " << stream.tellp() << std::endl;
    // move get ptr to begining
    stream.seekg(0);
    std::cout << "current position get fstream pointer: " << stream.tellp() << std::endl;
    std::string line;
    std::getline(stream,line);
    std::cout << line << std::endl;
    std::cout << "current position get fstream pointer: " << stream.tellp() << std::endl;

}

int main(int argc, char const *argv[])
{
    Write();
    Read();
    Fstream();
    return 0;
}

