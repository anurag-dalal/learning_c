#include <stdio.h>
int main(){
    int x = 5;
    printf("x = %d\n", x); // prints 5
    int *p = &x;
    *p = 10; // change value of x to 10
    printf("x = %d\n", x); // prints 10
    int **pp = &p; // pointer to pointer
    int ***ppp = &pp; // pointer to pointer to pointer

    printf("Address of x = %p, value of x = %d\n", &x, x); // prints address of x and value
    printf("Address of p = %p, value of p = %d\n", &p, p); // prints address of p and value
    printf("Address of pp = %p, value of pp = %d\n", &pp, pp); // prints address of pp and value
    printf("Dereferencing of p = %d\n", *p); // prints x
    printf("Dereferencing of pp one time = %d, two time = %d\n", *pp, **pp); // prints x
    printf("Dereferencing of ppp one time = %d, two time = %d, three time = %d\n", *ppp, **ppp, ***ppp); // prints x
}