#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

void quicksort(int *, int);
void quicksort_slice(int *, int, int);
int partition(int *, int, int, int);
int pick_midpoint(int, int);
void swap(int *, int, int);
void print_array(int *, int);

#endif
