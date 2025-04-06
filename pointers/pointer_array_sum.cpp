/**
 * This program demonstrates the behavior of passing arrays to functions in C++.
 * It highlights the difference between passing an array without its size and 
 * passing an array along with its size as a separate argument.
 *
 * Key Points:
 * 1. When an array is passed to a function, it decays into a pointer. 
 *    Therefore, `sizeof(A)` inside the function will return the size of the pointer 
 *    (8 bytes on a 64-bit system) instead of the size of the entire array.
 * 2. To correctly calculate the size of the array, the size must be passed as a 
 *    separate argument to the function.
 *
 * Function Details:
 * - `SumOfElements(int* A)`:
 *   - Demonstrates the incorrect usage of `sizeof(A)` to determine the size of the array.
 *   - `sizeof(A)` returns 8 (size of a pointer on a 64-bit system), leading to incorrect results.
 * - `SumOfElements(int A[], int size)`:
 *   - Demonstrates the correct way to pass the size of the array as a separate argument.
 *   - This ensures the function can iterate over the array correctly.
 *
 * Output Explanation:
 * - In `main()`, `sizeof(A)` correctly calculates the size of the array (20 bytes for 5 integers).
 * - In `SumOfElements(int* A)`, `sizeof(A)` returns 8 bytes (size of a pointer on a 64-bit system).
 * - In `SumOfElements(int A[], int size)`, the size is passed explicitly, ensuring correct behavior.
 *
 * Notes:
 * - Always pass the size of the array explicitly when working with functions to avoid 
 *   unexpected behavior due to pointer decay.
 * - The program includes print statements to demonstrate the sizes and behavior at runtime.
 */
#include <stdio.h>


int SumOfElements(int* A) {
    int i, sum = 0;
    int size = sizeof(A) / sizeof(A[0]); // Potential issue here
    for (i = 0; i < size; i++) {
        printf("In SumOfElements(int A[]), size of A = %d, A[0] = %d\n", sizeof(A), sizeof(A[0])); // This will give the size of the array
        sum += A[i];
    }
    return sum;
}
int SumOfElements(int A[], int size) {
    int i, sum = 0;
    printf("In SumOfElements(int A[], int size), size of A = %d, A[0] = %d\n", sizeof(A), sizeof(A[0])); // This will give the size of the array
    for (i = 0; i < size; i++) {
        sum += A[i];
    }
    return sum;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    printf("In main(), size of A = %d, A[0] = %d\n", sizeof(A), sizeof(A[0])); // This will give the size of the array
    int total = SumOfElements(A);
    printf("Sum of elements when size is not passed = %d\n", total);
    // The above call will not work as expected because sizeof(A) in the function
    // will not give the correct size of the array. It will give the size of a pointer.
    // The correct way to pass the size of the array is to pass it as a separate argument.
    // Correct usage:
    int size = sizeof(A) / sizeof(A[0]);
    total = SumOfElements(A, size);
    printf("Sum of elements = %d\n", total);
    // The above call will work as expected because we are passing the size of the array
    // as a separate argument.
    return 0;
}