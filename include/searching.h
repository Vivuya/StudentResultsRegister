
#ifndef SEARCHING_H
#define SEARCHING_H

template <typename T, typename Compare>
int binarySearch(T* arr, int n, const T& target, Compare comp) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (!comp(arr[mid], target) &&
            !comp(target, arr[mid])) {

            return mid;
        }

        if (comp(arr[mid], target)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

#endif
