/**
 * Casting operators
 *  - dont use c style casting
 *      - removed qualifiers (const)
 *      - does not check validity of cast
 * 
 * operators
 *  - static_cast       for primitives into same types
 *  - reinterpret_cast  for primitives into differing types 
 *  - const_cast        for primitives into same types and discarding qualifiers
 * 
 * NOTE: makes it easier to find casting when searching
 * 
*/

int main(int argc, char const *argv[])
{
    int a = 5, b = 6;
    // cast primitives into same types
    float f = static_cast<float>(a)/b;
    // cast primitives into differing types 
    char* p = reinterpret_cast<char*>(&a);
    // cast primitives into same types and discarding qualifiers
    const int x = 1;
    int* p = const_cast<int*>(&x);
    return 0;
}
