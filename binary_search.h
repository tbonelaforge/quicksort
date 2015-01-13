#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#include "sortable.h"

int binary_search(struct sortable *, void *);
int binary_search_slice(struct sortable *, int, int, void *);
int determine_final_index(struct sortable *, int, int, void *);

#endif
