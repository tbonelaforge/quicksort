#include <stdio.h>

#include "binary_search.h"
#include "sort_util.h"

/* Return greatest index i such that value(i) <= target,
   Or -1, if value(i) > target for all i */
int binary_search(struct sortable * self, void * target) {
    if (self->how_many_elements <= 0) {
        return -1;
    }
    return binary_search_slice(self, 0, self->how_many_elements - 1, target);
}

int binary_search_slice(struct sortable * self, int begin, int end, void * target) {
    int m;
    int comparison;

    if (begin >= end - 1) {
        return determine_final_index(self, begin, end, target);
    }
    m = pick_midpoint(begin, end);
    comparison = (*self->comp)(self->elements[m], target);
    if (comparison <= 0) {
        return binary_search_slice(self, m, end, target);
    } else { // comparison >= 0
        return binary_search_slice(self, begin, m, target);
    }
}

int determine_final_index(struct sortable * self, int begin, int end, void * target) {
    void * begin_element = self->elements[begin];
    void * end_element = self->elements[end];
    int compare_to_begin = (*self->comp)(target, begin_element);
    int compare_to_end = (*self->comp)(target, end_element);

    if (compare_to_end >= 0) {
        return end;
    }
    if (compare_to_begin >= 0) {
        return begin;
    }
    return -1;
}
