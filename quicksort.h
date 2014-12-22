#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include "sortable.h"

struct partition {
    int low;
    int high;
};

void quicksort(struct sortable *);
void quicksort_slice(struct sortable *, int, int);
struct partition fat_partition(struct sortable *, int, int, int);
void swap(struct sortable *, int, int);

#endif
