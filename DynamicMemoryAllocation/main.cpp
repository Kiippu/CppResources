#include <stdio.h>
#include <stdlib.h>

/**
 * Memory management
 *  - stack
 *  - data stack - global/static
 *  - heap
*/

/**
 * C style memory allocation
 *  - malloc - allocate raw memory on the heap
 *  - calloc - allocates memory on the heap and initialize it to zero
 *  - realloc - allocates larger chunk of memory for ab existing allocation
 *  - free - deallocates/releases the memory allocated through the above function
*/
void CStyleMemoryAllocation()
{
    printf("Begin - C-style memory allocation \n");
    /// malloc
    // C-style cast as malloc in C++ of return type void
    // allocate size in bytes 
    int *p = (int*)malloc(sizeof(int));
    // allocate 5 time sizeof int
    // int *p = (int*)malloc(5 * sizeof(int));
    *p = 5;
    printf("malloc value: %d,   Address = %p \n", *p, p);
    free(p);
    // freeing a pointer  that is already freed will result in runtime error
    // free(p);
    p = NULL;
    free(p);

    /// calloc
    // allocate 5 time sizeof int
    p = (int*)calloc( 5, sizeof(int));
    *p = 70;
    printf("calloc value: %d,   Address = %p \n", *p, p);
    free(p);

    /// realloc
    p = (int*)realloc(p, sizeof(int));
    // reallocate 10 times sizeof int
    // p = (int*)realloc(p, 10 * sizeof(int));
    *p = 128;
    printf("realloc value: %d,  Address = %p \n", *p, p);
    printf("End - C-style memory allocation \n\n");
}

int main(int argc, char const *argv[])
{
    CStyleMemoryAllocation();
    return 0;
}
