#include <stdio.h>
int main(){
    int a = 1025;
    int *p;
    p = &a;
    printf("size of integer is %ld bytes\n", sizeof(int)); 
    printf("Address = %d, value = %d\n", p, *p);
    // Void pointer
    void *p0;
    p0 = p; // we dont need to typecast

    // uncommenting the below line will give error since p0 is not mapped to any type
    // thus we cannot dereference it
    // expression must be a pointer to a complete object type
    // printf("Address = %d, value = %d\n", p0, *p0); 

    // we can't also use pointer arithmetic, the below line will give error
    // expression must be a pointer to a complete object type
    // printf("Address = %d, value = %d\n", p0+1, *(p0+1));
} 
