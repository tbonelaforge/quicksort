#include <stdio.h>

#include "quicksort.h"


void quicksort(int * a, int n) {
    return quicksort_slice(a, 0, n - 1);
}

void quicksort_slice(int * a, int i, int j) {
    //printf("Inside quicksort_slice, got called with i = %d, j = %d\n", i, j);
    int pivot_index;
    int r;

    if (i >= j) {
        return;
    }
    pivot_index = pick_midpoint(i, j);
    //printf("Inside quicksort_slice, got pivot_index %d\n", pivot_index);
    r = partition(a, i, j, pivot_index);
    //    printf("After partitioning, got r = %d, and the array looks like:\n", r);
    //    print_array(a, 6);
    quicksort_slice(a, i, r - 1);
    quicksort_slice(a, r + 1, j);
    return;
}

int partition(int * a, int i, int j, int pivot_index) {
    int pivot_value = a[pivot_index];
    int swap_index = i;
    int k;

    swap(a, pivot_index, j);
    for (k = i; k <= j - 1; k++) {
        if (a[k] < pivot_value) {
            swap(a, swap_index, k);
            swap_index += 1;
        }
    }
    swap(a, swap_index, j);
    return swap_index;
}

int pick_midpoint(int i, int j) {
    return (j - i) / 2 + i;
}

void swap(int * a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

void print_array(int * a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

