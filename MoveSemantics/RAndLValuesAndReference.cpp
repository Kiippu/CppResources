
int Add(int x, int y)
{
    return x+y;
}

int& Transform(int &x)
{
    x *=x;
    return x;
}

int main(int argc, char const *argv[])
{
    // R-Value reference will bind to a R-value 
    int &&r1 = 10;
    int &&r2 = Add(3,2);

    int x = 0;
    // does not compile as Right value reference can not take L value
    // int &&r3 = x;

    // L-value reference will always bind to a L-value 
    int &ref = x;
    return 0;
}