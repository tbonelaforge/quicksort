
#include "binary_search.h"
#include "sort_util.h"

int binary_search(struct sortable * self, int begin, int end, void * target) {
    int m;
    int comparison;

    if (begin == end - 1) {
        return determine_final_index(self, begin, end, target);
    }
    m = pick_midpoint(begin, end);
    comparison = (*self->comp)(self->elements[m], target);
    if (comparison < 0) {
        return binary_search(self, m, end, target);
    } else { // comparison >= 0
        return binary_search(self, begin, m, target);
    }
}

int determine_final_index(struct sortable * self, int begin, int end, void * target) {
    void * begin_element = self->elements[begin];
    void * end_element = self->elements[end];
    int compare_to_begin = (*self->comp)(target, begin_element);
    int compare_to_end = (*self->comp)(target, end_element);

    if (compare_to_begin <= 0) { // No elements less than targets.
        return -1;
    }
    if (compare_to_end <= 0) { // target between beginning and ending index.
        return begin; // Greatest index i having value(i) < target.
    }

    // Otherwise, we have target > ending index
    return end;
}
