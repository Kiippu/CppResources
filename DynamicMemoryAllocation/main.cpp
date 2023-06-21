#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    p = NULL;

    /// realloc
    p = (int*)realloc(p, sizeof(int));
    // reallocate 10 times sizeof int
    // p = (int*)realloc(p, 10 * sizeof(int));
    *p = 123;
    printf("realloc value: %d,  Address = %p \n", *p, p);
    free(p);

    printf("End - C-style memory allocation \n\n");
}

/**
 * Dynamic memory allocation - new and delete
 *  - new - allocates memory on the heap
 *  - delete - deallocates memory on the heap
 * Characteristics:
 *  - new is an operator and can be overloaded
 *  - size of the allocation i ascertained from type
 *  - can be a class as it can call constructor
 *  - can init memory on creation
 *  - throws an exception instead of a runtime error  
*/
void CppOperatorNewDelete()
{
    printf("Begin - C++ dynamic memory allocation \n");

    int *p = new int();
    printf("new uninitialized value: %d,   Address = %p \n", *p, p);
    delete p;   // delete memory allocated before using it again
    printf("new uninitialized value: %d,   Address = %p \n", *p, p);

    p = new int(5);
    printf("new initialized value: %d,   Address = %p \n", *p, p);
    // trying to access a nullptr will result in an exception
    // p = nullptr;
    // printf("new initialized value: %d,   Address = %p \n", *p, p);
    delete p;
    p = nullptr;
    
    printf("End - C++ dynamic  memory allocation \n\n");
}

/**
 * Dynamic memory allocation for arrays
*/
void CppOperatorNewDeleteArray()
{
    printf("Begin - C++ dynamic memory allocation for arrays \n");
    int *p = new int[5];
    // using uniform initialisation
    //int *p = new int[5]{ 1, 2, 3, 4, 5 };
    printf("uninitialized array pointer value: %d,   Address = %p \n", *p, (void*)&p);
    for(int i = 0 ;i < 5; ++i)
    {
        p[i] = i;
        printf("Array value at index[%d]: %d,   Address = %p \n", i, p[i], (void*)&p[i]);
    }
    delete []p;
    printf("End - C++ dynamic memory allocation for arrays \n\n");
}

void CppOperatorNewDeleteArrayStrings()
{
    printf("Begin - C++ dynamic memory allocation for STRING arrays \n");
    // always allocate enough memory for the string and the terminating character
    // see below 4 have been allocated for the three letters of C++ and in termination char
    char *p = new char[4];
    strcpy( p, "C++");
    printf("char * array: %d,   Address = %p \n", *p, (void*)&p);
    printf("char * array value: %s\n", p);
    printf("End - C++ dynamic memory allocation for STRING arrays \n\n");
    delete []p;
}

void CppOperatorNewDelete2D()
{
    printf("Begin - C++ dynamic memory allocation for 2D arrays \n");
    // need to make each row in the array 
    int *p1 = new int[3];
    int *p2 = new int[3];
    // add all of the pointer arrays to a pointer to pointers
    int **arr = new int *[2]; 
    arr[0] = p1;
    arr[1] = p2;
    printf("array[0] garbage value: %d,   Address = %p \n", *arr[0], (void*)&arr[0]);
    printf("array[1] garbage value: %d,   Address = %p \n", *arr[1], (void*)&arr[1]);
    // assign a value to a spot in the array
    arr[1][2] = 90;
    printf("array[1][2] value: %d,   Address = %p \n", arr[1][2], (void*)&arr[1][2]);
    // delete 2D array - must be in same order it was created
    delete []arr[0];    // OR delete []p1;
    delete []p2;        // OR delete []arr[1];
    // then delete 2D array
    delete []arr;

    printf("End - C++ dynamic memory allocation for 2D arrays \n\n");
}


int main(int argc, char const *argv[])
{
    CStyleMemoryAllocation();
    CppOperatorNewDelete();
    CppOperatorNewDeleteArray();
    CppOperatorNewDeleteArrayStrings();
    CppOperatorNewDelete2D();
    return 0;
}
