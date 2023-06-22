
/**
 * Structure
 *  - default access is public
 *  - frequently used to represent abstract types
*/
struct point
{
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    point p{1,4};
    // access is public so members can be modified
    p.x - 9;
    p.y = 8;
    return 0;
}

