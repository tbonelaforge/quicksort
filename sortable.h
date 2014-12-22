#ifndef _SORTABLE_H_
#define _SORTABLE_H_

typedef int (*ptr2comparator)(void *, void *);

struct sortable {
    void ** elements;
    int how_many_elements;
    ptr2comparator comp;
};

#endif
