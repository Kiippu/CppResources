
#include <iostream>

class File
{
public:
    enum Type
    {
        TEXT, VIDEO
    };
    Type GetType(){return Type::TEXT;};
};

File GetFileFromPath(const char* path){return {};};

void ifSwitchInitialization_main()
{
    // contain the initialization in the if statement and it is visible to both if and else
    if(int * p = (int*)malloc(sizeof(int)) ; p != nullptr)
    {
        *p = 50;
        std::cout << "P == " << *(p) << std::endl;
        free(p);
    }
    else
    {
        // p can be used here but it is null
    }

    // initialize class in switch and use it after
    // the class it contained in teh scope of the switch now 
    switch (auto f = GetFileFromPath("C://file.text") ; f.GetType())
    {
    case File::TEXT:
        std::cout << "Is text type" << std::endl;
        break;
    case File::VIDEO:
        std::cout << "Is video type" << std::endl;
        break;
    default:
        break;
    }
}