#include "AssignmentFunc.h"
#include <string.h>


template <>const char *Max(const char *x, const char *y)
{
    return strcmp(x,y) > 0 ? x : y;
}