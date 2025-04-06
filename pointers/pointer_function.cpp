#include <iostream>
using namespace std;

void Increment(int a) {
    // This function will not modify the original variable
    printf("a initial value in Increment = %d\n", a);
    a = a + 1;
    printf("a value in Increment after +1 = %d\n", a);
}

void Increment(int *a) {
    // This function will modify the original variable
    // by dereferencing the pointer
    // and changing the value at that address
    printf("a initial value in Increment with pointer = %d\n", *a);
    *a = *a + 1;
    printf("a value in Increment after +1 with pointer= %d\n", *a);
}
int main() {
    int a = 5;
    printf("a initial value in main = %d\n", a);
    Increment(a);
    printf("a final value in main after increment= %d\n", a);
    Increment(&a);
    printf("a final value in main after increment with pointer= %d\n", a);
    return 0;
}
