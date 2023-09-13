
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main(int argc, char const *argv[])
{
    // make source path
    auto curDir = std::filesystem::current_path();
    std::filesystem::path source{curDir};
    source /= "CopyTextFile.cpp";

    // path to copy file
    std::filesystem::path dest{curDir};
    dest /= "Copy.cpp";

    // open this file
    std::ifstream input{source};
    if(!input)
    {
        std::cout << "Source file not found" << std::endl;
    }
    // output to this file
    std::ofstream output{dest};
    if(!output.is_open())
    {
        std::cout << "output file error" << std::endl;
        return 0;
    }

    // write each line from input until end of file is true
    std::string line;
    while (!std::getline(input, line).eof())
    {
        output << line << std::endl;
    }
    input.close();
    output.close();

    return 0;
}
