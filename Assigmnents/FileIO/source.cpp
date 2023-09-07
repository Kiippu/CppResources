#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

struct File
{
    int a;
    long e;
    float b;
    double c;
    char d;
};
void CopyFiles(std::string pathStr)
{
    std::filesystem::path path{pathStr};
    // write structs to binary
    std::ofstream build{path, std::ios::binary | std::ios::out};
    File record{129, 312312, 34.89f, 7483.837648263, 'h'};
    for (size_t i = 0; i < 123; i++)
    {
        build.write((const char*)&record, sizeof(File));
    }
    build.close();

    // copy/read
    std::filesystem::path path_output{pathStr + "Copy"};
    std::ofstream output{path_output, std::ios::binary | std::ios::out};
    std::ifstream input(path, std::ios::binary | std::ios::in);
    // get size of binary file
    size_t count{std::filesystem::file_size(path)};
    count /= sizeof(File);
    // read out 
    File file;
    for (size_t i = 0; i < count; i++)
    {
        input.read((char*)&file, sizeof(File));
        output.write((const char*)&file, sizeof(File));
    }
    output.close();
    input.close();

}

int main(int argc, char const *argv[])
{
    CopyFiles("binaryFile");
    return 0;
}
