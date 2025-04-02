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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <integer>" << std::endl;
        return 1;
    }

    int num = std::stoi(argv[1]);
    printPointerInfo(&num, sizeof(num));
    return 0;
}