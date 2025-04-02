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
int main() {
    Animal animals[3] = {
        Animal("Lion", 5),
        Animal("Tiger", 4),
        Animal("Elephant", 10)
    };

    Animal* animalPtr = animals;
    std::cout << "Size of data: " << sizeof(Animal) << " bytes" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Pointer Address: " << animalPtr << std::endl;
        animalPtr->display();
        ++animalPtr;
    }
}