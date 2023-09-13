#ifndef BINARY_FILE_UTIL_H
#define BINARY_FILE_UTIL_H

#include <string>
#include <filesystem>

enum class STATUS
{
    Success         = 0xff,
    Error           = 0x01 
};
enum COPY_FLAG : int
{
    Recursive       = 0x01,
    RelativePath    = 0x02,
    binary          = 0x04
};

class binaryFileUtil
{
private:
    uint m_copyFlag;
    std::filesystem::path m_hmDir;

public:

    binaryFileUtil(std::string homeDir);
    binaryFileUtil();

    int GetConfigFlags() const;

    STATUS Duplicate(std::string fromDir, 
        std::string toDir, 
        int flagConfig = 0x0);
private:

    STATUS CopyFile(std::filesystem::path src, std::filesystem::path dest);
    STATUS CopyFolderContents(std::filesystem::path src, std::filesystem::path dest);

};


#endif