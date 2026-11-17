
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>
#include <utility>

template <typename T>
class DynamicArray {

private:
    T* data;
    int count;
    int capacity;

    // Increase the capacity when the array becomes full.
    void grow() {

        int newCapacity = (capacity == 0) ? 1 : capacity * 2;

        T* newData = new T[newCapacity];

        for (int i = 0; i < count; i++) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

public:

    // Constructor: create an empty dynamic array.
    DynamicArray()
        : data(nullptr), count(0), capacity(0) {
    }

    // Copy constructor: create an independent deep copy.
    DynamicArray(const DynamicArray& other)
        : data(nullptr), count(other.count), capacity(other.capacity) {

        if (capacity > 0) {
            data = new T[capacity];

            for (int i = 0; i < count; i++) {
                data[i] = other.data[i];
            }
        }
    }

    // Copy assignment operator.
    DynamicArray& operator=(const DynamicArray& other) {

        if (this == &other) {
            return *this;
        }

        DynamicArray temporary(other);
        swap(temporary);

        return *this;
    }

    // Swap the contents of two dynamic arrays.
    void swap(DynamicArray& other) noexcept {

        std::swap(data, other.data);
        std::swap(count, other.count);
        std::swap(capacity, other.capacity);
    }

    // Destructor: release dynamically allocated memory.
    ~DynamicArray() {
        delete[] data;
    }

    // Add a new record to the end of the array.
    void push_back(const T& value) {

        if (count == capacity) {
            grow();
        }

        data[count] = value;
        count++;
    }

    // Remove a record at a given index.
    void removeAt(int index) {

        if (index < 0 || index >= count) {
            throw std::out_of_range("Invalid removal index");
        }

        for (int i = index; i < count - 1; i++) {
            data[i] = data[i + 1];
        }

        count--;
    }

    // Access an element with bounds checking.
    T& at(int index) {

        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    // Read-only element access.
    const T& at(int index) const {

        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    // Return the number of stored elements.
    int size() const {
        return count;
    }

    // Return the allocated capacity.
    int getCapacity() const {
        return capacity;
    }

    // Check whether the array is empty.
    bool empty() const {
        return count == 0;
    }

    // Return the index of the first matching element.
    template <typename Predicate>
    int findIndex(Predicate predicate) const {

        for (int i = 0; i < count; i++) {

            if (predicate(data[i])) {
                return i;
            }
        }

        return -1;
    }

    // Provide access to the underlying array for sorting.
    T* raw() {
        return data;
    }

    const T* raw() const {
        return data;
    }
};

#endif
