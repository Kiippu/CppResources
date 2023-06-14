int main(int argc, char const *argv[])
{    
    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;

    int &ref_x1 = x ;
    const int &ref_x2 = x ;
    
    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x ;
    int *const ptr2 = &x ;
    const int * const ptr3 = &x ;

    
    // //Find which declarations are valid. If invalid, correct the declaration
    int const * ptr5 = &MAX ;   //const int *ptr3 = &MAX ;
    int const ptr4 = MAX ;   // int *ptr4 = &MAX ;
    
    const int &r1 = ref_x1 ;
    const int &r2 = ref_x2 ;    // int &r2 = ref_x2 ;
    
    const int *p_ref1 = ptr1 ;  // int *&p_ref1 = ptr1 ;
    int const *p_ref2 = ptr2 ;  // const int*&p_ref2 = ptr2 

    /* i is stored in read only area*/
    int const i = 10;   
    int j = 20;

    int const *ptr = &i;                // VALID - both i and ptr are int constant
    // the &j is now considered a 'const int *' by Up Qualification
    ptr = &j;                           // VALID - can change pointer address 
    
    //trying to assign a new value to the ptr's assigned referent address
    //*ptr = 100;                       // ERROR - can not assign new value
 

    // both mean the same thing
    const int abc = 1;                  // read as "abc is an integer which is constant"
    int const cba = 1;                  // read as "cba is a constant integer"
    // mutable value but can'e point pointer to a new value
    int* const bca = nullptr;           // read as "bca is a constant pointer to a (mutable) int"
    *bca = 2;                           // VALID
    //bca = &J;                         // ERROR as pointer address cant be redirected
    // const value with const pointer
    int const * const acb = nullptr;    // read as "acb is a constant pointer to const int"
    //*acb = 2;                         // ERROR - can not mutate value
    //acb = &J;                         // ERROR - can not mutate point address value
    return 0;
}

