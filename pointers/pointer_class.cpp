#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
class Animal {
public:
    std::string name;
    int age;

    Animal(std::string n, int a) : name(n), age(a) {}

    void display() {
        std::cout << "Animal Name: " << name << "\nAge: " << age << std::endl;
    }
};
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

}
int main() {
    // Creating an object dynamically
    Animal* animalPtr = new Animal("Lion", 1025);

    // Accessing members using pointer
    std::cout << "Using Pointer: " << std::endl;
    animalPtr->display();
    printPointerInfo(animalPtr, sizeof(Animal));


    // Modifying properties through pointer
    animalPtr->name = "Tiger";
    animalPtr->age = 255;
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "After Modification: " << std::endl;
    animalPtr->display();
    printPointerInfo(animalPtr, sizeof(Animal));

    // Modifying properties through pointer
    animalPtr->name = "Alpaca";
    animalPtr->age = 22;
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "After Modification: " << std::endl;
    animalPtr->display();
    printPointerInfo(animalPtr, sizeof(Animal));

    // Releasing memory
    delete animalPtr;
    animalPtr = nullptr;

    return 0;
}