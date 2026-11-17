
#include <iostream>
#include "../include/DynamicArray.h"

int main() {

    // Create an integer dynamic array.
    DynamicArray<int> numbers;

    std::cout << "Initially empty: "
              << numbers.empty() << "\n";

    // Insert three numbers.
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "Size: " << numbers.size() << "\n";
    std::cout << "Capacity: "
              << numbers.getCapacity() << "\n";

    // Display the elements.
    std::cout << "Original array: ";

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers.at(i) << " ";
    }

    std::cout << "\n";

    // Test deep copying.
    DynamicArray<int> copied = numbers;

    copied.at(0) = 99;

    std::cout << "Original first value: "
              << numbers.at(0) << "\n";

    std::cout << "Copied first value: "
              << copied.at(0) << "\n";

    // Test removal.
    numbers.removeAt(1);

    std::cout << "After removing index 1: ";

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers.at(i) << " ";
    }

    std::cout << "\n";

    // Test invalid access.
    try {
        numbers.at(100);
    }
    catch (const std::out_of_range& error) {
        std::cout << "Error safely handled: "
                  << error.what() << "\n";
    }

    return 0;
}
