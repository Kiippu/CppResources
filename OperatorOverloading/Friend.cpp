/**
 * Friend class members
 *  - allows globals methods access private class accessors/mutators
 *  - allows other classes to access another classes privates
*/
class aClass
{
private:
    int m_privateInt{};
public:
    // make any function with this signature a friend of this class and
    // have access to this classes private/protected members/methods 
    friend void getStuff(aClass & obj);
    friend class bClass;
};

class bClass 
{
public:
    void getAClassStuff(aClass & obj)
    { 
        obj.m_privateInt = 9;
    };
};

// global function wants to access  the argument objects private class
void getStuff(aClass & obj)
{ 
    obj.m_privateInt = 9;
};

int main(int argc, char const *argv[])
{
    aClass object1;
    // global method has access
    getStuff(object1);
    bClass object2;
    // a friend class has access to aClass object
    object2.getAClassStuff(object1);
    return 0;
}

