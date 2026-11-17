#include <stdexcept>
#include <iostream>
#include "../include/DynamicArray.h"
#include "../include/Sorting.h"
#include "../include/Searching.h"

struct Ascending {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

int main() {

    std::cout << "COURSEWORK TESTS\n";
    std::cout << "================\n";

    // TEST 1: Empty array
    DynamicArray<int> numbers;

    std::cout << "\nTest 1 - Empty array: ";

    if (numbers.empty() && numbers.size() == 0) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 2: One element
    numbers.push_back(50);

    std::cout << "Test 2 - One element: ";

    if (numbers.size() == 1 && numbers.at(0) == 50) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 3: Duplicate values
    numbers.push_back(50);

    std::cout << "Test 3 - Duplicate values: ";

    if (numbers.size() == 2 &&
        numbers.at(0) == numbers.at(1)) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 4: Remove first element
    numbers.removeAt(0);

    std::cout << "Test 4 - Remove first element: ";

    if (numbers.size() == 1 && numbers.at(0) == 50) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 5: Remove last element
    numbers.push_back(80);
    numbers.removeAt(numbers.size() - 1);

    std::cout << "Test 5 - Remove last element: ";

    if (numbers.size() == 1 && numbers.at(0) == 50) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 6: Sorted input
    int sorted[] = {10, 20, 30, 40, 50};

    insertionSort(sorted, 5, Ascending{});

    std::cout << "Test 6 - Already sorted input: ";

    if (sorted[0] == 10 && sorted[4] == 50) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 7: Reverse sorted input
    int reversed[] = {50, 40, 30, 20, 10};

    mergeSort(reversed, 5, Ascending{});

    std::cout << "Test 7 - Reverse sorted input: ";

    if (reversed[0] == 10 && reversed[4] == 50) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 8: Search for existing value
    int searchArray[] = {10, 20, 30, 40, 50};

    int found = binarySearch(
        searchArray, 5, 30, Ascending{}
    );

    std::cout << "Test 8 - Existing value search: ";

    if (found != -1 && searchArray[found] == 30) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 9: Search for missing value
    int missing = binarySearch(
        searchArray, 5, 99, Ascending{}
    );

    std::cout << "Test 9 - Missing value search: ";

    if (missing == -1) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }

    // TEST 10: Invalid array index
    std::cout << "Test 10 - Invalid index: ";

    try {
        numbers.at(100);
        std::cout << "FAILED\n";
    }
    catch (const std::out_of_range&) {
        std::cout << "PASSED\n";
    }

    // TEST 11: Invalid removal index
    std::cout << "Test 11 - Invalid removal: ";

    try {
        numbers.removeAt(100);
        std::cout << "FAILED\n";
    }
    catch (const std::out_of_range&) {
        std::cout << "PASSED\n";
    }

    // TEST 12: Empty array removal
    DynamicArray<int> emptyArray;

    std::cout << "Test 12 - Remove from empty array: ";

    try {
        emptyArray.removeAt(0);
        std::cout << "FAILED\n";
    }
    catch (const std::out_of_range&) {
        std::cout << "PASSED\n";
    }

    return 0;
}
