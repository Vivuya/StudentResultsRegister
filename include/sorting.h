
#ifndef SORTING_H
#define SORTING_H

template <typename T, typename Compare>
void insertionSort(T* arr, int n, Compare comp) {

    for (int i = 1; i < n; i++) {

        T key = arr[i];

        int j = i - 1;

        while (j >= 0 && comp(key, arr[j])) {

            arr[j + 1] = arr[j];

            j--;
        }

        arr[j + 1] = key;
    }
}



template <typename T, typename Compare>
void merge(T* arr, T* temp, int left, int mid,
           int right, Compare comp) {

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {

        if (comp(arr[j], arr[i])) {
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

template <typename T, typename Compare>
void mergeSortRecursive(T* arr, T* temp,
                        int left, int right, Compare comp) {

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSortRecursive(arr, temp, left, mid, comp);

    mergeSortRecursive(arr, temp, mid + 1, right, comp);

    merge(arr, temp, left, mid, right, comp);
}

template <typename T, typename Compare>
void mergeSort(T* arr, int n, Compare comp) {

    if (n <= 1) {
        return;
    }

    T* temp = new T[n];

    mergeSortRecursive(arr, temp, 0, n - 1, comp);

    delete[] temp;
}

#endif
