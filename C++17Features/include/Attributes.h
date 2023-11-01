
// make error if this function is used
[[deprecated("Use new version in template")]]
int * CreateIntArray(int size)
{
    return new int[size];
}
// make error if this class is used
class [[deprecated("old shape class!")]] shape
{};
// make error if this namespace is used
namespace [[deprecated("old namespace use other")]] Test 
{};

// make error if function is not using return value
template<class T>
[[nodiscard]]
T * CreateIntArray(int size)
{
    return new T[size];
}
// can also be used with classes
class [[nodiscard]] Foo 
{};

void Attributes_main()
{
    // will not pass
    CreateIntArray(34);
    CreateIntArray<double>(34.56);
    // will pass
    auto c = CreateIntArray<double>(80.6);

}