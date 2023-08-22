/**
 * like a structure or class but all members share the same memory
 * disadvantage
 *  - no way to know that type the union is holding or the active member
 *  - nested types in the union with a non-default constructor deletes the default constructor of the union
 *  - can not assign user defined types directly to a union member.
 *  - user defined types are not destroyer implicitly
 *  - no base class or contain virtual functions
*/

#include <string>

union test{
    int i;
    char c;
    test (): c{'a'} {

    }
    ~test(){

    }
};

union UDT{
    std::string s;
    UDT(){
        // need user defined constructor/destructor
    }
    ~UDT(){

    }
};

int main(int argc, char const *argv[])
{
    test t;
    UDT udt;

    // must use placement new operator
    // s var does not exist yet. only the memory allocation is done.
    //  "placement new operator" only initializes memory but does not allocate
    // specify the address of the string object with new operator and construct the object in that memory
    new (&udt.s) std::string{"Hello World"};
    // remember to delete the union memory

    return 0;
}
