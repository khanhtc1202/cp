#include "sort.h"

#define LOAD_ARRAY_ITEMS(index, s_flag, count, des_array, src_array) ({\
    for(index = 0; index < count; index++) \
        des_array[index] = src_array[s_flag + index]; \
})

#define LOAD_REMAINING_ITEMS(src_index, des_index, count, des_array, src_array) ({\
    while(src_index < count) {\
        des_array[des_index] = src_array[src_index]; \
        src_index++; \
        des_index++; \
    } \
})

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *a, int n) {
    int tmp;
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void selectionSort(int *a, int n) {
    int i, j, min;

    for(i = 0; i < n; i++) {
        min = i;
        for(j = i+1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        swap(&a[min], &a[i]);
    }
}

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // load items
    LOAD_ARRAY_ITEMS(i, l, n1, L, arr);
    LOAD_ARRAY_ITEMS(j, m+1, n2, R, arr);

    // merge arrays back to arr
    i = j = 0;
    k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // load the whole part of halve that ordered to merged array ( arr <= L or arr <= R )
    // k is now on index of the merged array
    // i, j are now on index of ordered halve
    LOAD_REMAINING_ITEMS(i, k, n1, arr, L);
    LOAD_REMAINING_ITEMS(j, k, n2, arr, R);
}

void mergeSort(int *a, int left, int right) {
    if(left < right) {
        int m = left + (right - left) / 2;

        mergeSort(a, left, m);
        mergeSort(a, m+1, right);

        merge(a, left, m, right);
    }
}

int partition (int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int *a, int low, int high) {
    if(low < high) {
        int p_index = partition(a, low, high);

        quickSort(a, low, p_index - 1);
        quickSort(a, p_index + 1, high);
    }
}
