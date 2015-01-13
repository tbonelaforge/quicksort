#include <stdio.h>

#include "quicksort.h"
#include "sort_util.h"
#include "sortable.h"

void quicksort(struct sortable * self) {
    int i = 0;
    int j = self->how_many_elements - 1;

    return quicksort_slice(self, i, j);
}

void quicksort_slice(struct sortable * self, int i, int j) {
    int pivot_index;
    struct partition part;

    if (i >= j) {
        return;
    }
    pivot_index = pick_midpoint(i, j);
    part = fat_partition(self, i, j, pivot_index);
    quicksort_slice(self, i, part.low - 1);
    quicksort_slice(self, part.high + 1, j);
}

struct partition fat_partition(struct sortable * self, int i, int j, int p) {
    struct partition part;
    int k = i;
    int comparison;
    void * pivot_element = self->elements[p];

    while (k <= j) {
        comparison = (*self->comp)(self->elements[k], pivot_element);
        if (comparison < 0) {
            swap(self, k, i);
            i += 1;
            k += 1;
        } else if (comparison > 0) {
            swap(self, k, j);
            j -= 1;
        } else { // Leave this element to swapped to the middle later.
            k += 1;
        }
    }
    part.low = i;
    part.high = j;
    return part;
}

void swap(struct sortable * self, int i, int j) {
    void * temp = self->elements[i];
    self->elements[i] = self->elements[j];
    self->elements[j] = temp;
}
