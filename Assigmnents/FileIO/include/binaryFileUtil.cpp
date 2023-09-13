#include "binaryFileUtil.h"
#include <iostream>
#include <fstream>
#include <string>

binaryFileUtil::binaryFileUtil(std::string homeDir)
    : m_hmDir(homeDir), m_copyFlag(0x0)
{
}

binaryFileUtil::binaryFileUtil()
    : binaryFileUtil(std::filesystem::current_path()) 
{
}

int binaryFileUtil::GetConfigFlags() const
{
    return m_copyFlag;
}

STATUS binaryFileUtil::Duplicate(std::string fromDir, std::string toDir, int flagConfig)
{
    std::filesystem::path path_dest{fromDir};
    std::filesystem::path path_src{toDir};

    // default is copy path/file as text no recursively
    if(flagConfig == 0x00)
    {
        std::ifstream input{path_dest, std::ios::binary};
        std::ofstream output{path_src, std::ios::binary};
        
        size_t count{std::filesystem::file_size(path_src)};
        char *p = new char(count);
        input.read(p, count);
        output.write(p, count);
        delete []p;
        output.close();
        input.close();
    }
    
    return STATUS::Success;
}

STATUS binaryFileUtil::CopyFile(std::filesystem::path src, std::filesystem::path dest)
{
    if(!src.has_extension() || dest.has_extension())
        return STATUS::Error;

    std::ofstream output{dest, std::ios::binary | std::ios::out};
    std::ifstream input(src, std::ios::binary | std::ios::in);

    // get size of binary file
    size_t count{std::filesystem::file_size(src)};
    char *p = new char(count);
    if(p && input && output)
    {
        input.read(p, count);
        output.write(p, count);
        delete []p;
        output.close();
        input.close();
    }
    else
        return STATUS::Error;
    return STATUS::Success;
}
