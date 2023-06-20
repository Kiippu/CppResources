/**
 * Function pointers
 *  - pointer holds the address of the function
 *  - pointer type is the same as the function (return and arguments)
*/

void Add()
{ 
    // do something 
}
int Add(int a , int b)
{ 
    return a + b;
}
void Add(void(*aPtr)() , int(*bPtr) (int,int) )
{ 
    // Use void pointer arg
    aPtr();
    // Use int ptr arg
    bPtr(2,5);

}

int main(int argc, char const *argv[])
{
    // void function pointer
    void(*AddPtr) () = Add;
    // int function ptr  with args
    int(*AddPtrInt) (int,int) = Add;
    // pass pointer functions as args
    Add(AddPtr,AddPtrInt);
    return 0;
}
