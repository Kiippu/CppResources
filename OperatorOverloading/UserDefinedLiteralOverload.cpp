
/**
 * User Defined Lieterals
 *  - should begin with an underscore
 *  - you can not redefine built in literal suffixes
 *  - only the following types can be used to make userdefined literals 
 *      - ULL, LONG DOUBLE, const * char, char
 *  - literal operator functions cannot be member functions
*/

class Distance
{
    long double m_kilometers;
public:
    Distance(long double km) : m_kilometers{km}
    {}
};
// make user defined literal for Miles
Distance operator"" _mi(long double val)
{
    return Distance{ val * 1.6 };
}
// make user defined literal for centimeters
Distance operator"" _cm(long double val)
{
    return Distance{ val * 10000 };
}
Distance operator"" _cm(unsigned long long val)
{
    return Distance{ static_cast<double>(val) * 10000.0 };
}

int main(int argc, char const *argv[])
{
    // use centimeters literal double
    Distance distance0 {10000.0_cm};
    // use centimeters literal ULL
    Distance distance1 {10000_cm};
    // use miles literal double
    Distance distance2 {580.0_mi};
    return 0;
}
