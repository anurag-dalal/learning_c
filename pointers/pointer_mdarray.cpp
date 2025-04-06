#include <iostream>
#include <bitset>
#include <iomanip>

// Function to print memory details
void printPointerInfo(void* ptr, size_t size) {
    if (!ptr) {
        std::cout << "Null pointer!" << std::endl;
        return;
    }

    std::cout << "Pointer Address: " << ptr << std::endl;
    std::cout << "Size of data: " << size << " bytes" << std::endl;

    unsigned char* bytePtr = static_cast<unsigned char*>(ptr);
    std::cout << "Value in HEX: ";
    for (size_t i = size; i > 0; --i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)bytePtr[i - 1] << " ";
    }
    std::cout << std::dec << std::endl;

    std::cout << "Value in BITS: ";
    for (size_t i = size; i > 0; --i) {
        std::cout << std::bitset<8>(bytePtr[i - 1]) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int B[2][3] = { {1, 2, 3}, {4, 5, 6} };
    printf("B: %d\n", B);
    printf("*B: %d\n", *B);
    printf("B[0]: %d\n", B[0]);
    printf("&B[0][0]: %d\n", &B[0][0]);

    // Print memory details of the pointer
    std::cout << "B: " << std::endl;
    printPointerInfo(B, sizeof(B));

    // guess the outputs will be 12 bytes of difference from B
    printf("B+1: %d\n", B+1); // moving to next 1d array of 3 integers

    printf("\n============================================================\n");
    // Print memory details of the pointer
    for (int i = 0; i < 2;  i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", &B[i][j]);
        }
        printf("\n");
    }
    printf("\n============================================================\n");
    
    printf("B+1: %d\n", B+1);
    printf("*(B+1): %d\n", *(B+1));
    printf("B[1]: %d\n", B[1]);
    printf("&B[0][1]: %d\n", &B[1][0]);

    //int C[3][2][2] = { { {1, 2}, {3, 4} }, { {5, 6}, {7, 8} }, { {9, 10}, {11, 12} } };

    
}