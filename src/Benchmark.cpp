
#include <iostream>
#include <chrono>
#include <random>
#include "../include/sorting.h"

struct Ascending {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

int main() {
    int sizes[] = {1000, 2000, 4000, 8000,
                   16000, 32000, 64000};

    const int repetitions = 3;

    std::mt19937 generator(42);
    std::uniform_int_distribution<int> distribution(1, 1000000);

    std::cout << "SORTING ALGORITHM BENCHMARK\n";
    std::cout << "===========================\n";
    std::cout << "Average time over 3 repetitions (milliseconds)\n\n";

    std::cout << "Size\tInsertion Sort\tMerge Sort\n";

    for (int n : sizes) {
        double insertionTotal = 0.0;
        double mergeTotal = 0.0;

        int* original = new int[n];
        int* insertionData = new int[n];
        int* mergeData = new int[n];

        for (int i = 0; i < n; i++) {
            original[i] = distribution(generator);
        }

        for (int r = 0; r < repetitions; r++) {

            for (int i = 0; i < n; i++) {
                insertionData[i] = original[i];
            }

            auto start = std::chrono::high_resolution_clock::now();

            insertionSort(insertionData, n, Ascending{});

            auto finish = std::chrono::high_resolution_clock::now();

            insertionTotal +=
                std::chrono::duration<double, std::milli>(
                    finish - start
                ).count();

            for (int i = 0; i < n; i++) {
                mergeData[i] = original[i];
            }

            start = std::chrono::high_resolution_clock::now();

            mergeSort(mergeData, n, Ascending{});

            finish = std::chrono::high_resolution_clock::now();

            mergeTotal +=
                std::chrono::duration<double, std::milli>(
                    finish - start
                ).count();
        }

        std::cout << n << "\t"
                  << insertionTotal / repetitions << "\t\t"
                  << mergeTotal / repetitions << "\n";

        delete[] original;
        delete[] insertionData;
        delete[] mergeData;
    }

    return 0;
}
